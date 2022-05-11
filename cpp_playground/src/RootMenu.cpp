#include "pch.h"
#include "RootMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"


#include "test_cpp/r2_TimeMenu.h"

#include "test_cpp/item/console_input_test.h"
#include "test_cpp/r2_ETCMenu.h"
#include "test_cpp/r2_MathMenu.h"
#include "test_performance/r2_PerformanceMenu.h"

#include "test_algorithm/TestAlgorithmMenu.h"
#include "test_cpp/C_CPP_Menu.h"
#include "test_cpp/DebugMenu.h"
#include "test_cpp/RandomMenu.h"
#include "test_cpp/STDMenu.h"
#include "test_hobby/HobbyMenu.h"
#include "test_windows/TestWindowsMenu.h"

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle(),
				"> To do : Regex"
		"\n"	"> To do : Vector3"
		"\n"	"> To do : Encoding"
		"\n"	"> To do : Infinite Number"
		"\n"	"> To do : Thread"
		"\n"	"> To do : Memory Pool"
	) );

	{
		ret->AddItem( '1', console_input_test::Basic::GetInstance() );
		ret->AddItem(
			'2'
			, []()->const char* { return TestWindowsMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TestWindowsMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'3'
			, []()->const char* { return C_CPP_Menu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( C_CPP_Menu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'4'
			, []()->const char* { return STDMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'5'
			, []()->const char* { return r2::TimeMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::TimeMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'6'
			, []()->const char* { return r2::RandomMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::RandomMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'7'
			, []()->const char* { return DebugMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( DebugMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'a'
			, []()->const char* { return r2::ETCMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::ETCMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			's'
			, []()->const char* { return r2::MathMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::MathMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'd'
			, []()->const char* { return r2::PerformanceMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( r2::PerformanceMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddSplit();


		ret->AddItem(
			'z'
			, []()->const char* { return TestAlgorithmMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TestAlgorithmMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'x'
			, []()->const char* { return HobbyMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( HobbyMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eItemLeaveAction { return r2cm::eItemLeaveAction::Exit; }
		);
	}

	return ret;
}