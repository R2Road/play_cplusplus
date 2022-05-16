#include "RootMenu.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Director.h"

#include "test_cpp/item/console_input_test.h"

#include "test_algorithm/AlgorithmMenu.h"
#include "test_cpp/C_CPP_Menu.h"
#include "test_cpp/ETCMenu.h"
#include "test_cpp/DebugMenu.h"
#include "test_cpp/MathMenu.h"
#include "test_cpp/RandomMenu.h"
#include "test_cpp/TimeMenu.h"
#include "test_hobby/HobbyMenu.h"
#include "test_performance/PerformanceMenu.h"
#include "test_std/STDMenu.h"
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


		ret->AddLineFeed();


		ret->AddItem(
			'q'
			, []()->const char* { return C_CPP_Menu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( C_CPP_Menu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'w'
			, []()->const char* { return STDMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( STDMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'e'
			, []()->const char* { return TimeMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( TimeMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			'r'
			, []()->const char* { return RandomMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( RandomMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			't'
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
			, []()->const char* { return ETCMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( ETCMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
		ret->AddItem(
			's'
			, []()->const char* { return MathMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( MathMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);


		ret->AddLineFeed();


		ret->AddItem(
			'z'
			, []()->const char* { return AlgorithmMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( AlgorithmMenu::Create( director ) );
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
		ret->AddItem(
			'c'
			, []()->const char* { return PerformanceMenu::GetTitle(); }
			, [&director]()->r2cm::eItemLeaveAction
				{
					director.Setup( PerformanceMenu::Create( director ) );
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