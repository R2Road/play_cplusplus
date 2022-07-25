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
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Show String : Use printf" << r2cm::linefeed2;

				PROCESS_MAIN( printf( "1111111" "2222222" "3333333" "   %d" "\n", 456789 ) );
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
	r2cm::iItem::DoFunctionT ShowNumbers::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( int num = 0xde81 );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( printf( "\t( 8 : oct : %%o ) : %o\n", num ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( printf( "\t( 10 : dec : %%d ) : %d\n", num ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( printf( "\t( 16 : hex : %%x ) : %x\n", num ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}