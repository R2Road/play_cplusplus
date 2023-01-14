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
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const uint32_t buffer_size = 6 );
			DECLARATION_MAIN( char buffer[buffer_size] = { 0 } );
			OUTPUT_BINARIES( buffer, buffer_size );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( memset( buffer, 1, sizeof( buffer ) ) );
				OUTPUT_BINARIES( buffer, buffer_size );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( memset( buffer, -1, sizeof( buffer ) / 2 ) );
				OUTPUT_BINARIES( buffer, buffer_size );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}