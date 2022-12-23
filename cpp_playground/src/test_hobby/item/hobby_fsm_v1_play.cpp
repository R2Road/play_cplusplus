#include "hobby_fsm_v1_play.h"

#include <memory>
#include <string>
#include <vector>

#include "r2/r2_Assert.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
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

		//
		// Override 4 User
		//
	private:
		virtual void UserEnter() {}
		virtual void UserExit() {}

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
			State::Enter();

			if( mCurrentState )
			{
				mCurrentState->Enter();
			}
		}
		void Exit() override
		{
			if( mCurrentState )
			{
				mCurrentState->Exit();
			}

			State::Exit();
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
}

namespace hobby_fsm_v1_play
{
	r2cm::iItem::TitleFunctionT State_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : State - Declaration";
		};
	}
	r2cm::iItem::DoFunctionT State_Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( State s( 0 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT State_Enter_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : State - Enter, Exit";
		};
	}
	r2cm::iItem::DoFunctionT State_Enter_Exit::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			class S : public State
			{
			public:
				S( const StateIndexT state_index ) : State( state_index )
				{}

				void Enter() override
				{
					std::cout << "[START] S::Enter" << r2cm::linefeed;
					State::Enter();
					std::cout << "[ END ] S::Enter" << r2cm::linefeed;
				}
				void Exit() override
				{
					std::cout << "[START] S::UserExit" << r2cm::linefeed;
					State::Exit();
					std::cout << "[ END ] S::UserExit" << r2cm::linefeed;
				}

				void UserEnter() override
				{
					std::cout << "S::UserEnter" << r2cm::linefeed;
				}
				void UserExit() override
				{
					std::cout << "S::UserExit" << r2cm::linefeed;
				}
			};

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( S s( 0 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( s.Enter() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( s.Exit() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Package_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Package - Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Package_Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Package p( 0 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Package_AddState::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Package - AddState";
		};
	}
	r2cm::iItem::DoFunctionT Package_AddState::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			class S : public State
			{
			public:
				S( const StateIndexT state_index ) : State( state_index )
				{}

				int i = 10;
			};

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Package p( 0 ) );
				DECLARATION_MAIN( S* s = p.AddState<S>() );
				OUTPUT_VALUE( s->i );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Package_AddTransition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Package - AddTransition";
		};
	}
	r2cm::iItem::DoFunctionT Package_AddTransition::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( Package p( 0 ) );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto s_1 = p.AddState<State>() );
			DECLARATION_MAIN( auto s_2 = p.AddState<State>() );
			DECLARATION_MAIN( auto s_3 = p.AddState<State>() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( p.AddTransition( s_1->GetIndex(), s_2->GetIndex() ) );
				EXPECT_EQ( 1, s_1->GetTransitionContainer().size() );
				EXPECT_EQ( 0, s_2->GetTransitionContainer().size() );
				EXPECT_EQ( 0, s_3->GetTransitionContainer().size() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( p.AddTransition( s_2->GetIndex(), s_3->GetIndex() ) );
				EXPECT_EQ( 1, s_1->GetTransitionContainer().size() );
				EXPECT_EQ( 1, s_2->GetTransitionContainer().size() );
				EXPECT_EQ( 0, s_3->GetTransitionContainer().size() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( s_1->GetTransitionContainer()[0].Do() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Machine_Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Machine - Basic";
		};
	}
	r2cm::iItem::DoFunctionT Machine_Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Machine m );
				PROCESS_MAIN( m.Add( std::move( std::make_unique<State>( 0 ) ) ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Machine m );
				PROCESS_MAIN( m.Add<State>() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Machine_Start_Stop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Machine - Start and Stop";
		};
	}
	r2cm::iItem::DoFunctionT Machine_Start_Stop::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			class P : public Package
			{
			public:
				P( const StateIndexT state_index ) : Package( state_index )
				{}

				void UserEnter() override
				{
					std::cout << "P::UserEnter" << r2cm::linefeed;
				}
				void UserExit() override
				{
					std::cout << "P::UserExit" << r2cm::linefeed;
				}
			};

			class S : public State
			{
			public:
				S( const StateIndexT state_index ) : State( state_index )
				{}

				void UserEnter() override
				{
					std::cout << "S::UserEnter" << r2cm::linefeed;
				}
				void UserExit() override
				{
					std::cout << "S::UserExit" << r2cm::linefeed;
				}
			};

			std::cout << r2cm::split;

			DECLARATION_MAIN( Machine m );

			std::cout << r2cm::split;

			DECLARATION_MAIN( auto p = std::make_unique<P>( 0 ) );
			DECLARATION_MAIN( auto s = p->AddState<S>() );
			PROCESS_MAIN( p->SetEntryState( s->GetIndex() ) );
			PROCESS_MAIN( m.Add( std::move( p ) ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( m.Start() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( m.Stop() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Demo";
		};
	}
	r2cm::iItem::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( Machine m );
			DECLARATION_MAIN( auto p = std::make_unique<Package>( 0 ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto s_1 = p->AddState<State>() );
				DECLARATION_MAIN( auto s_2 = p->AddState<State>() );
				DECLARATION_MAIN( auto s_3 = p->AddState<State>() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( p->AddTransition( s_1->GetIndex(), s_2->GetIndex() ) );
				PROCESS_MAIN( p->AddTransition( s_2->GetIndex(), s_3->GetIndex() ) );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( m.Add( std::move( p ) ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}