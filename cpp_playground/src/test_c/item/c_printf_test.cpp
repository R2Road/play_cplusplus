#include "c_printf_test.h"

#include <stdio.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_printf_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "printf : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				PROCESS_MAIN( printf( "\t" "1111111" "2222222" "3333333" "   %d" "\n", 456789 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ShowNumbers::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "printf : Number";
		};
	}
	r2cm::iItem::DoFunctionT ShowNumbers::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const int num = 0xde81 );

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "8 : oct : %%o" );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( printf( "\t> " "%o" "\n", num ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "10 : dec : %%d" );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( printf( "\t> " "%d" "\n", num ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "16 : hex : %%x" );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( printf( "\t> " "%x" "\n", num ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}