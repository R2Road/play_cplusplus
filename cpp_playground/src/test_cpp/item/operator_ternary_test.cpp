#include "operator_ternary_test.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace operator_ternary_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator_ternary_test : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ 삼항 연산자의 실행식은 쉼표로 구분해 여러개 넣을 수 있다." << r2cm::linefeed;
			std::cout << r2cm::tab << "+ 20년 만에 알았다 개 웃기네. 2022.05.18" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int j = 0 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( (
					false
					? ++i, ++j
					: ++i
				) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( i );
				OUTPUT_VALUE( j );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( (
					true
					? ++i, ++j
					: ++i
				) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( i );
				OUTPUT_VALUE( j );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}