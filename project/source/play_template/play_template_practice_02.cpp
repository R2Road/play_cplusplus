#include "play_template_practice_02.hpp"
#include "play_template_practice_02_helper___basic.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_template_practice_02
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Practice : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_FILE( "source/play_template/play_template_practice_02_helper___basic.hpp" );

			LS();

			DECL_MAIN( FuncContainer f );
			PROC_MAIN( f.def( "F1_A0", FN_V_A0 ) );
			PROC_MAIN( f.def( "F2_A0", FN_V_A0 ) );
			PROC_MAIN( f.def( "F3_A1", FN_V_A1 ) );
			PROC_MAIN( f.def( "F4_A1", FN_V_A1 ) );
			PROC_MAIN( f.def( "F5_A3", FN_V_A3 ) );

			LS();

			{
				OUT_NOTE( "정상적인 인자 설정으로 함수 호출 시도" );

				LF();

				PROC_MAIN( f.Call<void>( "F1_A0" ) );
				PROC_MAIN( f.Call<void>( "F5_A3", 100, 200, 300 ) );
			}

			LS();

			{
				OUT_NOTE( "잘못된 인자 설정으로 함수 호출 시도" );

				LF();

				PROC_MAIN( f.Call<void>( "F5_A3", 100, 200, 300, 400 ) );
				PROC_MAIN( f.Call<void>( "F5_A3" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
