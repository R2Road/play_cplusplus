#include "template_practice_test_02.h"
#include "template_practice_test_02_helper_basic.hpp"
#include "template_practice_test_02_helper_return_value.hpp"

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

			SHOW_FILE( "src/test_template/item/template_practice_test_02_helper_basic.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FuncContainer f );
				PROCESS_MAIN( f.def( "F1_A0", TestFunction_A0 ) );
				PROCESS_MAIN( f.def( "F2_A0", TestFunction_A0 ) );
				PROCESS_MAIN( f.def( "F3_A1", TestFunction_A1 ) );
				PROCESS_MAIN( f.def( "F4_A1", TestFunction_A1 ) );
				PROCESS_MAIN( f.def( "F5_A3", TestFunction_A3 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( f.Call<void>( "F1_A0" ) );
				PROCESS_MAIN( f.Call<void>( "F5_A3", 100, 200, 300 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ReturnValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Practice : Return Value";
		};
	}
	r2cm::iItem::DoFunctionT ReturnValue::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			SHOW_FILE( "src/test_template/item/template_practice_test_02_helper_return_value.hpp" );

			std::cout << r2cm::split;

			{
				OUTPUT_CODE( int i = template_practice_test_02_return_value::ReturnValueTestFunction() );
				std::cout << "\t" "> " "변수에 할당하는 행위로는 Templae 의 타입 추론에 영향을 주지 못한다." << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( int i = template_practice_test_02_return_value::ReturnValueTestFunction<int>() );
				OUTPUT_VALUE( i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = template_practice_test_02_return_value::ReturnValueTestFunction_With_Argument1( 123 ) );
				OUTPUT_VALUE( i );
				std::cout << "\t" "> " "함수 인자 타입과 반환값이 같다면 인자에서 타입이 정해지므로 타입 추론에 성공한다." << r2cm::linefeed;

			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
