#include "c_memset_test.h"

#include <cstring>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_memset_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "memset : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const uint32_t buffer_size = 6 );
			DECLARATION_MAIN( char buffer[buffer_size] = { 0 } );
			OUTPUT_BINARIES( buffer, buffer_size );

			LS();

			{
				PROCESS_MAIN( memset( buffer, 1, sizeof( buffer ) ) );
				OUTPUT_BINARIES( buffer, buffer_size );
			}

			LS();

			{
				PROCESS_MAIN( memset( buffer, -1, sizeof( buffer ) / 2 ) );
				OUTPUT_BINARIES( buffer, buffer_size );
			}

			LS();

			{
				PROCESS_MAIN( memset( buffer, 255, sizeof( buffer ) ) );
				OUTPUT_BINARIES( buffer, buffer_size );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( memset( buffer, 258, sizeof( buffer ) ) );
				OUTPUT_BINARIES( buffer, buffer_size );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "값을 byte 단위로 쓴다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}