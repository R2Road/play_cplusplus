#include "RootMenu.h"

#include <string>

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test_various/item/various_console_input_test.h"

#include "play_hobby/HobbyMenu.h"
#include "test_algorithm/AlgorithmMenu.h"
#include "test_c/C_Menu.h"
#include "test_cpp/CPP_Menu.h"
#include "test_performance/PerformanceMenu.h"
#include "test_std/STDMenu.h"
#include "test_template/TemplateMenu.h"
#include "test_various/DebugMenu.h"
#include "test_various/ETCMenu.h"
#include "test_various/MathMenu.h"
#include "test_various/RandomMenu.h"
#include "test_various/TimeMenu.h"
#include "test_windows/WindowsMenu.h"

r2tm::TitleFunctionT RootMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string( "Root" )
			+ " : " + "<" + "C++17" + ">"
			+ ", " + "<" + "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			+ ", " + "<" + r2tm::VersionInfo.String4Version + ">";
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT RootMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return
			"> In Progress : ..."

		"\n"

		"\n"	"> To do : My Int"
		"\n"	"> To do : Regex"
		"\n"	"> To do : Encoding"
		"\n"	"> To do : Infinite Number"
		"\n"	"> To do : Thread"
		"\n"	"> To do : Memory Pool"
		"\n"	"> To do : Spin-Lock";
	};
}
r2tm::WriteFunctionT RootMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', various_console_input_test::KeyCodeView() );
		ret->AddMenu( '2', WindowsMenu() );



		ret->AddLineFeed();



		ret->AddMenu( 'q', C_Menu() );
		ret->AddMenu( 'w', CPP_Menu() );
		ret->AddMenu( 'e', STDMenu() );
		ret->AddMenu( 'r', TemplateMenu() );
		ret->AddMenu( 't', TimeMenu() );
		ret->AddMenu( 'y', RandomMenu() );
		ret->AddMenu( 'u', DebugMenu() );



		ret->AddLineFeed();



		ret->AddMenu( 'a', ETCMenu() );
		ret->AddMenu( 's', MathMenu() );



		ret->AddLineFeed();



		ret->AddMenu( 'z', AlgorithmMenu() );
		ret->AddMenu( 'x', HobbyMenu() );
		ret->AddMenu( 'c', PerformanceMenu() );



		ret->AddSplit();



		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2tm::eDoLeaveAction { return r2tm::eDoLeaveAction::Exit; }
		);
	};
}