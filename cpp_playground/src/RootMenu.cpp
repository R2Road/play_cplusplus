#include "RootMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_cpp/item/console_input_test.h"

#include "test_algorithm/AlgorithmMenu.h"
#include "test_cpp/C_CPP_Menu.h"
#include "test_cpp/DebugMenu.h"
#include "test_cpp/RandomMenu.h"
#include "test_hobby/HobbyMenu.h"
#include "test_performance/PerformanceMenu.h"
#include "test_std/STDMenu.h"
#include "test_various/ETCMenu.h"
#include "test_various/FileMenu.h"
#include "test_various/MathMenu.h"
#include "test_various/TimeMenu.h"
#include "test_windows/WindowsMenu.h"

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle(),
				"> In Progress : ..."

		"\n"

		"\n"	"> To do : Regex"
		"\n"	"> To do : Vector3"
		"\n"	"> To do : Encoding"
		"\n"	"> To do : Infinite Number"
		"\n"	"> To do : Thread"
		"\n"	"> To do : Memory Pool"
		"\n"	"> To do : FSM v1"
	) );

	{
		ret->AddItem( '1', console_input_test::Basic::GetInstance() );
		ret->AddMenu<WindowsMenu>( '2' );		



		ret->AddLineFeed();



		ret->AddMenu<C_CPP_Menu>( 'q' );
		ret->AddMenu<STDMenu>( 'w' );
		ret->AddMenu<FileMenu>( 'e' );
		ret->AddMenu<TimeMenu>( 'r' );
		ret->AddMenu<RandomMenu>( 't' );
		ret->AddMenu<DebugMenu>( 'y' );



		ret->AddLineFeed();



		ret->AddMenu<ETCMenu>( 'a' );
		ret->AddMenu<MathMenu>( 's' );



		ret->AddLineFeed();



		ret->AddMenu<AlgorithmMenu>( 'z' );
		ret->AddMenu<HobbyMenu>( 'x' );
		ret->AddMenu<PerformanceMenu>( 'c' );



		ret->AddSplit();



		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eItemLeaveAction { return r2cm::eItemLeaveAction::Exit; }
		);
	}

	return ret;
}