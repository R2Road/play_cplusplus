#include "std_functional_invoke_test.h"
#include "std_functional_invoke_test_helper.hpp"

#include <functional>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_functional_invoke_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::invoke : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_std/item/std_functional_invoke_test_helper.hpp" );

			LS();

			{
				PROCESS_MAIN( std::invoke( Do, 2 ) );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( std::invoke( do_lam, 3 ) );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( S1 s_1 );
				PROCESS_MAIN( std::invoke( &S1::Do, s_1, 123 ) );
				PROCESS_MAIN( std::invoke( &S1::Do, &s_1, 234 ) );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( S2 s_2 );
				OUTPUT_VALUE( std::invoke( &S2::n, &s_2 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}