#include "menu_root.hpp"

#include <string>

#include "r2tm/r2tm_menu_processor.hpp"
#include "r2tm/r2tm_version_info.hpp"

#include "r2/r2_version_info.hpp"

#include "play_algorithm/menu_algorithm.hpp"
#include "play_basic/menu_basic.hpp"
#include "play_c/menu_c.hpp"
#include "play_cpp/menu_cpp.hpp"
#include "play_cpu/menu_cpu.h"
#include "play_debug/menu_debug.h"
#include "play_hobby/menu_hobby.hpp"
#include "play_math/menu_play_math.hpp"
#include "play_performance/menu_performance.hpp"
#include "play_random/menu_random.hpp"
#include "play_rendering_pipeline/menu_play_rendering_pipeline.hpp"
#include "play_std/menu_std.hpp"
#include "play_time/menu_time.hpp"
#include "play_various/menu_various.hpp"
#include "play_template/menu_template.hpp"
#include "play_windows/menu_windows.hpp"

#include "viewer/key_viewer.hpp"

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
		mp->AddMenu( 'q', Menu_Windows() );
		mp->AddMenu( 'w', Menu_Basic() );
		mp->AddMenu( 'e', Menu_C() );
		mp->AddMenu( 'r', Menu_CPP() );
		mp->AddMenu( 't', Menu_STD() );
		mp->AddMenu( 'y', Menu_Template() );
		mp->AddMenu( 'u', Menu_Time() );
		mp->AddMenu( 'i', Menu_Random() );
		mp->AddMenu( 'o', Menu_Debug() );



		mp->AddLineFeed();


		
		mp->AddMenu( 'a', Menu_Play_Math() );
		mp->AddMenu( 's', Menu_Play_Rendering_Pipeline() );
		mp->AddMenu( 'd', Menu_Various() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', Menu_Algorithm() );
		mp->AddMenu( 'x', Menu_Performance() );
		mp->AddMenu( 'c', Menu_CPU() );



		mp->AddLineFeed();



		mp->AddItem( 32, key_viewer::View() );



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}