#include "template_practice_test_02.h"
#include "template_practice_test_02_helper_basic.hpp"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace template_practice_test_02
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Practice : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_template/item/template_practice_test_02_helper_basic.hpp" );

			std::cout << r2cm::split;

			DECLARATION_MAIN( FuncContainer f );
			PROCESS_MAIN( f.def( "F1_A0", FN_V_A0 ) );
			PROCESS_MAIN( f.def( "F2_A0", FN_V_A0 ) );
			PROCESS_MAIN( f.def( "F3_A1", FN_V_A1 ) );
			PROCESS_MAIN( f.def( "F4_A1", FN_V_A1 ) );
			PROCESS_MAIN( f.def( "F5_A3", FN_V_A3 ) );

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "정상적인 인자 설정으로 함수 호출 시도" );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( f.Call<void>( "F1_A0" ) );
				PROCESS_MAIN( f.Call<void>( "F5_A3", 100, 200, 300 ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "잘못된 인자 설정으로 함수 호출 시도" );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( f.Call<void>( "F5_A3", 100, 200, 300, 400 ) );
				PROCESS_MAIN( f.Call<void>( "F5_A3" ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
