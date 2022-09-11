#include "c_memset_test.h"

#include <cstring>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_memset_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "memset : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( char buffer[10] = { 0 } );
			OUTPUT_BINARIES( buffer, 10 );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( memset( buffer, 1, sizeof( buffer ) ) );
				OUTPUT_BINARIES( buffer, 10 );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( memset( buffer, 7, sizeof( buffer ) / 2 ) );
				OUTPUT_BINARIES( buffer, 10 );
			}

			std::cout << r2cm::split;


			return r2cm::eItemLeaveAction::Pause;
		};
	}
}