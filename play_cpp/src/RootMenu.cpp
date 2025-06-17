#include "RootMenu.h"

#include <string>

#include "r2tm/r2tm_MenuProcessor.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test_various/item/various_console_input_test.h"

#include "play_hobby/HobbyMenu.h"
#include "play_math/menu_math.h"
#include "test_algorithm/AlgorithmMenu.h"
#include "test_c/C_Menu.h"
#include "test_cpp/CPP_Menu.h"
#include "test_performance/PerformanceMenu.h"
#include "test_std/STDMenu.h"
#include "test_template/TemplateMenu.h"
#include "test_various/DebugMenu.h"
#include "test_various/ETCMenu.h"
#include "test_various/RandomMenu.h"
#include "test_various/TimeMenu.h"
#include "test_windows/WindowsMenu.h"
#include "test_cpu/Menu_CPU.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', various_console_input_test::KeyCodeView() );
		mp->AddMenu( '2', WindowsMenu() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', C_Menu() );
		mp->AddMenu( 'w', CPP_Menu() );
		mp->AddMenu( 'e', STDMenu() );
		mp->AddMenu( 'r', TemplateMenu() );
		mp->AddMenu( 't', TimeMenu() );
		mp->AddMenu( 'y', RandomMenu() );
		mp->AddMenu( 'u', DebugMenu() );



		mp->AddLineFeed();



		mp->AddMenu( 'a', Menu_Math() );
		mp->AddMenu( 's', ETCMenu() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', AlgorithmMenu() );
		mp->AddMenu( 'x', HobbyMenu() );
		mp->AddMenu( 'c', PerformanceMenu() );
		mp->AddMenu( 'v', Menu_CPU() );



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}