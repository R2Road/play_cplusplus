#include "std_functional_invoke_test.h"
#include "std_functional_invoke_test_helper.hpp"

#include <functional>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_functional_invoke_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::invoke : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_std/item/std_functional_invoke_test_helper.hpp" );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( std::invoke( Do, 2 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::invoke( do_lam, 3 ) );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( S1 s_1 );
				PROCESS_MAIN( std::invoke( &S1::Do, s_1, 123 ) );
				PROCESS_MAIN( std::invoke( &S1::Do, &s_1, 234 ) );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( S2 s_2 );
				OUTPUT_VALUE( std::invoke( &S2::n, &s_2 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}