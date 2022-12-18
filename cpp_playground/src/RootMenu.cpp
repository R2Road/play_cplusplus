#include "RootMenu.h"

#include <string>

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_VersionInfo.h"

#include "test_various/item/various_console_input_test.h"

#include "test_algorithm/AlgorithmMenu.h"
#include "test_c/C_Menu.h"
#include "test_cpp/CPP_Menu.h"
#include "test_hobby/HobbyMenu.h"
#include "test_performance/PerformanceMenu.h"
#include "test_std/STDMenu.h"
#include "test_template/TemplateMenu.h"
#include "test_various/DebugMenu.h"
#include "test_various/ETCMenu.h"
#include "test_various/FileMenu.h"
#include "test_various/MathMenu.h"
#include "test_various/RandomMenu.h"
#include "test_various/TimeMenu.h"
#include "test_windows/WindowsMenu.h"

const char* RootMenu::GetTitle()
{
	static const std::string ret =
		std::string( "Root Menu" )
		+ " : " + "<" + "C++17" + ">"
		+ ", " + "<" + "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
		+ ", " + "<" + r2cm::VersionInfo.String4Version + ">";
	return ret.c_str();
}

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle(),
				"> In Progress : ..."

		"\n"

		"\n"	"> To do : Regex"
		"\n"	"> To do : Encoding"
		"\n"	"> To do : Infinite Number"
		"\n"	"> To do : Thread"
		"\n"	"> To do : Memory Pool"
		"\n"	"> To do : FSM v1"
	) );

	{
		ret->AddItem( '1', various_console_input_test::Basic::GetInstance() );
		ret->AddMenu<WindowsMenu>( '2' );		



		ret->AddLineFeed();



		ret->AddMenu<C_Menu>( 'q' );
		ret->AddMenu<CPP_Menu>( 'w' );
		ret->AddMenu<STDMenu>( 'e' );
		ret->AddMenu<TemplateMenu>( 'r' );
		ret->AddMenu<FileMenu>( 't' );
		ret->AddMenu<TimeMenu>( 'y' );
		ret->AddMenu<RandomMenu>( 'u' );
		ret->AddMenu<DebugMenu>( 'i' );



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