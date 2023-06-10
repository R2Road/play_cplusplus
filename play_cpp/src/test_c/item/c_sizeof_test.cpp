#include "c_sizeof_test.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_sizeof_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "sizeof : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_VALUE( sizeof( char ) );
				OUTPUT_VALUE( sizeof( int ) );
				OUTPUT_VALUE( sizeof( long long ) );
			}

			LS();

			{
				DECLARATION_MAIN( const char buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			LS();

			{
				DECLARATION_MAIN( const int buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			LS();

			{
				DECLARATION_MAIN( const double buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			LS();

			{
				DECLARATION_MAIN( const char buffer[10] = { 0 } );

				LF();

				DECLARATION_MAIN( const char* cb = buffer );
				OUTPUT_VALUE( sizeof( cb ) );

				LF();

				OUTPUT_NOTE( "sizeof 에 pointer 를 넣으면 pointer 자체의 크기를 반환한다." );
			}

			LS();

			{
				DECLARATION_MAIN( struct Dummy {} dummy; );
				OUTPUT_VALUE( sizeof( dummy ) );

				LF();

				OUTPUT_NOTE( "sizeof 의 반환값은 최소 1 이다.." );
			}

			LS();


			return r2tm::eDoLeaveAction::Pause;
		};
	}
}