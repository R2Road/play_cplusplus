#include "hobby_fsm_v1_play.h"
#include "hobby_fsm_v1_play_helper.hpp"

#include <memory>
#include <string>
#include <vector>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

using namespace hobby_fsm_v1_play_helper;

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

			DECLARATION_MAIN( Package p( 0 ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto s_1 = p.AddState<State>() );
				DECLARATION_MAIN( auto s_2 = p.AddState<State>() );
				DECLARATION_MAIN( auto s_3 = p.AddState<State>() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, s_1->GetIndex() );
				EXPECT_EQ( 1, s_2->GetIndex() );
				EXPECT_EQ( 2, s_3->GetIndex() );
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

			DECLARATION_MAIN( auto s_1 = p->AddState<LoggingState>(); s_1->SetName( "S1" ) );
			DECLARATION_MAIN( auto s_2 = p->AddState<LoggingState>(); s_2->SetName( "S2" ) );
			DECLARATION_MAIN( auto s_3 = p->AddState<LoggingState>(); s_3->SetName( "S3" ) );
			PROCESS_MAIN( p->SetEntryState( s_1->GetIndex() ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( p->AddTransition( s_1->GetIndex(), s_2->GetIndex() ) );
				PROCESS_MAIN( p->AddTransition( s_2->GetIndex(), s_3->GetIndex() ) );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( m.Add( std::move( p ) ) );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( m.Start() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}