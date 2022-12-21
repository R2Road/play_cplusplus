#include "hobby_fsm_v1_play.h"

#include <memory>
#include <string>
#include <vector>

#include "r2/r2_Assert.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
{
	class Transition
	{
	private:
		using IndexT = int;

	public:
		Transition( const IndexT to_state_index ) : mToStateIndex( to_state_index )
		{}

		bool Do() const
		{
			return true;
		}

	private:
		const IndexT mToStateIndex;
	};

	class State
	{
	public:
		using IndexT = int;

		State( const IndexT index ) : mIndex( index ), mTransitionContainer()
		{}

		const IndexT GetIndex() const
		{
			return mIndex;
		}

		const std::vector<Transition>& GetTransitionContainer() const
		{
			return mTransitionContainer;
		}
		void AddTransition( State::IndexT to_state_index )
		{
			mTransitionContainer.emplace_back( to_state_index );
		}

	private:
		const IndexT mIndex;
		std::vector<Transition> mTransitionContainer;
	};

	class Package : public State
	{
	public:
		Package( const IndexT index ) : State( index ), mStateContainer()
		{}

		template<typename T>
		T* Add()
		{
			std::unique_ptr<T> up = std::make_unique<T>( mStateContainer.size() );
			T* ret = up.get();

			mStateContainer.emplace_back( std::move( up ) );

			return ret;
		}

		// from ~ to
		void AddTransition( State::IndexT from_state_index, State::IndexT to_state_index )
		{
			//
			// 문제 생겼을 때 편하게 확인 되게 따로 assert 로 확인한다.
			//
			R2ASSERT( mStateContainer.size() > from_state_index, "" );
			R2ASSERT( mStateContainer.size() > to_state_index, "" );

			mStateContainer[from_state_index]->AddTransition( to_state_index );
		}

	private:
		using StateUp = std::unique_ptr<State>;
		using StateContainer = std::vector<StateUp>;
		StateContainer mStateContainer;
	};

	class Machine
	{
	private:
		using StateUp = std::unique_ptr<State>;

	public:
		Machine() : mState()
		{}

		void Add( StateUp&& state )
		{
			mState = std::move( state );
		}

	private:
		StateUp mState;
	};
}

namespace
{
	class TestState : public State
	{
	public:
		TestState( const IndexT state_index ) : State( state_index )
		{}

		int i = 10;
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



	r2cm::iItem::TitleFunctionT Package_Add::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Package - Add";
		};
	}
	r2cm::iItem::DoFunctionT Package_Add::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Package p( 0 ) );
				DECLARATION_MAIN( TestState* s = p.Add<TestState>() );
				OUTPUT_VALUE( s->i );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Package_Transition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Package - Transition";
		};
	}
	r2cm::iItem::DoFunctionT Package_Transition::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( Package p( 0 ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto s_1 = p.Add<TestState>() );
				DECLARATION_MAIN( auto s_2 = p.Add<TestState>() );
				DECLARATION_MAIN( auto s_3 = p.Add<TestState>() );

				std::cout << r2cm::linefeed;

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



	r2cm::iItem::TitleFunctionT Machine_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Machine - Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Machine_Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Machine m );
				PROCESS_MAIN( m.Add( std::move( std::make_unique<TestState>( 0 ) ) ) );
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

			{
				DECLARATION_MAIN( Machine m );
				PROCESS_MAIN( m.Add( std::move( std::make_unique<TestState>( 0 ) ) ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}