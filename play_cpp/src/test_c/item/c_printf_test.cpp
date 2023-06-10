#include "c_printf_test.h"

#include <stdio.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_printf_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "printf : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				PROCESS_MAIN( printf( "\t" "1111111" "2222222" "3333333" "   %d" "\n", 456789 ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ShowNumbers::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "printf : Number";
		};
	}
	r2tm::DoFunctionT ShowNumbers::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( const int num = 0xde81 );

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "8 : oct : %%o" );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( printf( "\t> " "%o" "\n", num ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "10 : dec : %%d" );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( printf( "\t> " "%d" "\n", num ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "16 : hex : %%x" );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( printf( "\t> " "%x" "\n", num ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}