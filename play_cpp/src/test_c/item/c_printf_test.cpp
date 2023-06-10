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
			LS();

			{
				PROCESS_MAIN( printf( "\t" "1111111" "2222222" "3333333" "   %d" "\n", 456789 ) );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( const int num = 0xde81 );

			LS();

			{
				OUTPUT_NOTE( "8 : oct : %%o" );

				LF();

				PROCESS_MAIN( printf( "\t> " "%o" "\n", num ) );
			}

			LS();

			{
				OUTPUT_NOTE( "10 : dec : %%d" );

				LF();

				PROCESS_MAIN( printf( "\t> " "%d" "\n", num ) );
			}

			LS();

			{
				OUTPUT_NOTE( "16 : hex : %%x" );

				LF();

				PROCESS_MAIN( printf( "\t> " "%x" "\n", num ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}