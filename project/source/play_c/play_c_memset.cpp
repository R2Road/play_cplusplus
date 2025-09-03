#include "play_c_memset.hpp"

#include <cstring>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_c_memset
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

			DECL_MAIN( const uint32_t buffer_size = 6 );
			DECL_MAIN( char buffer[buffer_size] = { 0 } );
			OUT_BINARIES( buffer, buffer_size );

			LS();

			{
				PROC_MAIN( memset( buffer, 1, 1 ) );
				OUT_BINARIES( buffer, buffer_size );
			}

			LS();

			{
				PROC_MAIN( memset( buffer, 2, sizeof( buffer ) ) );
				OUT_BINARIES( buffer, buffer_size );
			}

			LS();

			{
				PROC_MAIN( memset( buffer, -1, sizeof( buffer ) / 2 ) );
				OUT_BINARIES( buffer, buffer_size );
			}

			LS();

			{
				PROC_MAIN( memset( buffer, 255, sizeof( buffer ) ) );
				OUT_BINARIES( buffer, buffer_size );

				LF();

				PROC_MAIN( memset( buffer, 258, sizeof( buffer ) ) );
				OUT_BINARIES( buffer, buffer_size );

				LF();

				OUT_NOTE( "값을 byte 단위로 쓴다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "memset : Size";
		};
	}
	r2tm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_NOTE( "값을 byte 단위로 쓴다." );
			OUT_NOTE( "4바이트 int의 경우 1을 할당하면" );
			OUT_NOTE( "00000001 00000001 00000001 00000001" );
			OUT_NOTE( "가 된다. 헷갈리지 마." );

			LS();

			DECL_MAIN( const uint32_t buffer_size = 6 );
			DECL_MAIN( int buffer[buffer_size] = { 0 } );
			OUT_BINARIES( buffer, buffer_size );

			LS();

			{
				PROC_MAIN( memset( buffer, 1, 1 ) );
				OUT_BINARIES( buffer, buffer_size );
			}

			LS();

			{
				PROC_MAIN( memset( buffer, 2, sizeof( buffer ) ) );
				OUT_BINARIES( buffer, buffer_size );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}