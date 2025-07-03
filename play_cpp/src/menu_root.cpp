#include "menu_root.h"

#include <string>

#include "r2/r2_VersionInfo.h"

#include "r2tm/r2tm_MenuProcessor.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test_various/item/various_console_input_test.h"

#include "play_hobby/HobbyMenu.h"
#include "play_math/menu_play_math.h"
#include "play_rendering_pipeline/menu_play_rendering_pipeline.h"
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

r2tm::TitleFunctionT Menu_Root::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string( "Root" )
			+ " : " + "<" + "C++17" + ">"
			+ ", " + "<" + "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			+ ", " + "<" + r2tm::VersionInfo.String4Version + ">"
			+ ", " + "<" + r2::VersionInfo.String4Version + ">";
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT Menu_Root::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return
			"> o : complete             ~ : in-progress"

		"\n"

		"\n"	"[ ] " "My Int"
		"\n"	"[ ] " "Regex"
		"\n"	"[ ] " "Encoding"
		"\n"	"[ ] " "Infinite Number"
		"\n"	"[ ] " "Thread"
		"\n"	"[ ] " "Memory Pool"
		"\n"	"[ ] " "Spin-Lock"
		"\n"	"[~] " "Math";
	};
}
r2tm::WriteFunctionT Menu_Root::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( '1', Menu_Play_Math() );
		mp->AddMenu( '2', Menu_Play_Rendering_Pipeline() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', WindowsMenu() );
		mp->AddMenu( 'w', C_Menu() );
		mp->AddMenu( 'e', CPP_Menu() );
		mp->AddMenu( 'r', STDMenu() );
		mp->AddMenu( 't', TemplateMenu() );
		mp->AddMenu( 'y', TimeMenu() );
		mp->AddMenu( 'u', RandomMenu() );
		mp->AddMenu( 'i', DebugMenu() );



		mp->AddLineFeed();


		
		mp->AddMenu( 'd', ETCMenu() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', AlgorithmMenu() );
		mp->AddMenu( 'x', HobbyMenu() );
		mp->AddMenu( 'c', PerformanceMenu() );
		mp->AddMenu( 'v', Menu_CPU() );



		mp->AddLineFeed();



		mp->AddItem( 32, various_console_input_test::KeyCodeView() );



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}