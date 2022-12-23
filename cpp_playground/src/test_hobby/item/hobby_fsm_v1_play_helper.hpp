#include <string>

#include "r2/r2_Assert.h"

#include "r2cm/r2cm_ostream.h"

namespace hobby_fsm_v1_play_helper
{
	using StateIndexT = uint32_t;

	//
	// Transition 작동 룰
	// > 기본 Transition은 State의 Enter에서 만 작동
	// > 부가 기능이 붙은 Transition은 State의 Update 에서 만 작동
	// > Event Transition 은 Event 가 발생시 작동
	//
	class Transition
	{
	public:
		Transition( const StateIndexT to_state_index ) : mToStateIndex( to_state_index )
		{}

		const StateIndexT GetToStateIndex() const
		{
			return mToStateIndex;
		}

		bool Do() const
		{
			return true;
		}

	private:
		const StateIndexT mToStateIndex;
	};

	//
	// State 는 최대한 가볍게
	//
	class State
	{
	public:
		State( const StateIndexT index ) : mIndex( index ), mTransitionContainer()
		{}

		virtual ~State()
		{}

		const StateIndexT GetIndex() const
		{
			return mIndex;
		}

		const std::vector<Transition>& GetTransitionContainer() const
		{
			return mTransitionContainer;
		}
		void AddTransition( StateIndexT to_state_index )
		{
			mTransitionContainer.emplace_back( to_state_index );
		}

		//
		// Override 4 System
		//
		virtual void Enter()
		{
			UserEnter();
		}
		virtual void Exit()
		{
			UserExit();
		}
		virtual void Update()
		{
			UserUpdate();
		}

		//
		// Override 4 User
		//
	private:
		virtual void UserEnter() {}
		virtual void UserExit() {}
		virtual void UserUpdate() {}

	private:
		const StateIndexT mIndex;
		std::vector<Transition> mTransitionContainer;
	};

	//
	// FSM 의 운용에 관련된 기능은 가급적 모두 Package 에 넣는다.
	//
	class Package : public State
	{
	public:
		Package( const StateIndexT index ) : State( index ), mStateContainer(), mCurrentState( nullptr )
		{}

		template<typename T>
		T* AddState()
		{
			std::unique_ptr<T> up = std::make_unique<T>( static_cast<StateIndexT>( mStateContainer.size() ) );
			T* ret = up.get();

			mStateContainer.emplace_back( std::move( up ) );

			return ret;
		}

		// from ~ to
		void AddTransition( StateIndexT from_state_index, StateIndexT to_state_index )
		{
			//
			// 문제 생겼을 때 편하게 따로 assert 작성.
			//
			R2ASSERT( mStateContainer.size() > from_state_index, "" );
			R2ASSERT( mStateContainer.size() > to_state_index, "" );

			mStateContainer[from_state_index]->AddTransition( to_state_index );
		}

		void SetEntryState( StateIndexT entry_state_index )
		{
			R2ASSERT( mStateContainer.size() > entry_state_index, "" );

			mCurrentState = mStateContainer[entry_state_index].get();
		}

		void Enter() override
		{
			//
			// To do
			// 1. Parent State : Enter Call
			// 2. Current State : Enter Call
			// 3. Transition : Success > 2, Failed > End
			//

			State::Enter();

			bool bWorking = false;
			do
			{
				bWorking = false;
				
				if( !mCurrentState )
				{
					mCurrentState->Enter();

					for( const auto& t : mCurrentState->GetTransitionContainer() )
					{
						if( t.Do() )
						{
							bWorking = true;
							mCurrentState = mStateContainer[t.GetToStateIndex()].get();
							break;
						}
					}
				}

			} while( bWorking );
		}
		void Exit() override
		{
			if( mCurrentState )
			{
				mCurrentState->Exit();
			}

			State::Exit();
		}
		void Update() override
		{
			if( mCurrentState )
			{
				mCurrentState->Update();
			}

			State::Update();
		}

	private:
		using StateUp = std::unique_ptr<State>;
		using StateContainer = std::vector<StateUp>;
		StateContainer mStateContainer;

		State* mCurrentState;
	};

	class Machine
	{
	private:
		using StateUp = std::unique_ptr<State>;

	public:
		Machine() : mState()
		{}

		void Start()
		{
			if( mState )
			{
				mState->Enter();
			}
		}
		void Stop()
		{
			if( mState )
			{
				mState->Exit();
			}
		}
		void Update()
		{
			if( mState )
			{
				mState->Update();
			}
		}

		void Add( StateUp&& state )
		{
			mState = std::move( state );
		}

		template<typename T>
		T* Add()
		{
			mState = std::make_unique<T>( 0 );

			return mState.get();
		}

	private:
		StateUp mState;
	};

	class LoggingState : public State
	{
	public:
		LoggingState( const StateIndexT state_index ) : State( state_index )
			, mStateName()
			, mI( 0 )
		{}

		void UserEnter() override
		{
			std::cout << mStateName << "::UserEnter" << r2cm::linefeed;
		}
		void UserUpdate() override
		{
			++mI;
			std::cout << mStateName << "::UserUpdate" " : " << mI << r2cm::linefeed;
		}
		void UserExit() override
		{
			std::cout << mStateName << "::UserExit" << r2cm::linefeed;
		}

		void SetName( const char* state_name )
		{
			mStateName = state_name;
		}

	private:
		std::string mStateName;
		int mI = 0;
	};
}