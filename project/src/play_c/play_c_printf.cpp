#include "play_c_printf.hpp"

#include <stdio.h>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_c_printf
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
				PROC_MAIN( printf( "\t" "1111111" "2222222" "3333333" "   %d" "\n", 456789 ) );
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

			DECL_MAIN( const int num = 0xde81 );

			LS();

			{
				OUT_NOTE( "8 : oct : %%o" );

				LF();

				PROC_MAIN( printf( "\t> " "%o" "\n", num ) );
			}

			LS();

			{
				OUT_NOTE( "10 : dec : %%d" );

				LF();

				PROC_MAIN( printf( "\t> " "%d" "\n", num ) );
			}

			LS();

			{
				OUT_NOTE( "16 : hex : %%x" );

				LF();

				PROC_MAIN( printf( "\t> " "%x" "\n", num ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}