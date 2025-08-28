#include "menu_root.h"

#include <string>

#include "r2tm/r2tm_menu_processor.hpp"
#include "r2tm/r2tm_version_info.hpp"

#include "r2/r2_version_info.hpp"

#include "key_viewer.h"

#include "play_algorithm/menu_algorithm.hpp"
#include "play_cpu/menu_cpu.h"
#include "play_debug/menu_debug.h"
#include "play_hobby/menu_hobby.hpp"
#include "play_math/menu_play_math.h"
#include "play_rendering_pipeline/menu_play_rendering_pipeline.h"
#include "test_c/C_Menu.h"
#include "test_cpp/CPP_Menu.h"
#include "test_performance/PerformanceMenu.h"
#include "test_std/STDMenu.h"
#include "test_template/TemplateMenu.h"
#include "test_various/ETCMenu.h"
#include "test_various/RandomMenu.h"
#include "test_various/TimeMenu.h"
#include "test_windows/WindowsMenu.h"

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

			"\n"

			"\n"	"[o] " "Math"
			"\n"	"[o] " "Rendering Pipeline"
		;
	};
}
r2tm::WriteFunctionT Menu_Root::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "작업중", r2tm::eColor::FG_LightYellow );
		mp->AddMenu( '1', Menu_Hobby() );



		mp->AddLineFeed();



		mp->AddMessage( "완료", r2tm::eColor::FG_LightGreen );
		mp->AddMenu( 'q', WindowsMenu() );
		mp->AddMenu( 'w', C_Menu() );
		mp->AddMenu( 'e', CPP_Menu() );
		mp->AddMenu( 'r', STDMenu() );
		mp->AddMenu( 't', TemplateMenu() );
		mp->AddMenu( 'y', TimeMenu() );
		mp->AddMenu( 'u', RandomMenu() );
		mp->AddMenu( 'i', Menu_Debug() );



		mp->AddLineFeed();


		
		mp->AddMenu( 'a', Menu_Play_Math() );
		mp->AddMenu( 's', Menu_Play_Rendering_Pipeline() );
		mp->AddMenu( 'd', ETCMenu() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', Menu_Algorithm() );
		mp->AddMenu( 'x', PerformanceMenu() );
		mp->AddMenu( 'c', Menu_CPU() );



		mp->AddLineFeed();



		mp->AddItem( 32, key_viewer::View() );



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}