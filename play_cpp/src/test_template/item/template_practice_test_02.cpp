#include "template_practice_test_02.h"
#include "template_practice_test_02_helper_basic.hpp"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace template_practice_test_02
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
			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_template/item/template_practice_test_02_helper_basic.hpp" );

			std::cout << r2tm::split;

			DECLARATION_MAIN( FuncContainer f );
			PROCESS_MAIN( f.def( "F1_A0", FN_V_A0 ) );
			PROCESS_MAIN( f.def( "F2_A0", FN_V_A0 ) );
			PROCESS_MAIN( f.def( "F3_A1", FN_V_A1 ) );
			PROCESS_MAIN( f.def( "F4_A1", FN_V_A1 ) );
			PROCESS_MAIN( f.def( "F5_A3", FN_V_A3 ) );

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "정상적인 인자 설정으로 함수 호출 시도" );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( f.Call<void>( "F1_A0" ) );
				PROCESS_MAIN( f.Call<void>( "F5_A3", 100, 200, 300 ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "잘못된 인자 설정으로 함수 호출 시도" );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( f.Call<void>( "F5_A3", 100, 200, 300, 400 ) );
				PROCESS_MAIN( f.Call<void>( "F5_A3" ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
