#include "play_c_sizeof.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

#pragma warning( disable : 4189 ) // 참조 되지 않은 변수 존재

namespace play_c_sizeof
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
				DECL_MAIN( const char buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			LS();

			{
				DECL_MAIN( const int buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			LS();

			{
				DECL_MAIN( const double buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			LS();

			{
				DECL_MAIN( const char buffer[10] = { 0 } );

				LF();

				DECL_MAIN( const char* cb = buffer );
				OUTPUT_VALUE( sizeof( cb ) );

				LF();

				OUTPUT_NOTE( "sizeof 에 pointer 를 넣으면 pointer 자체의 크기를 반환한다." );
			}

			LS();

			{
				DECL_MAIN( struct Dummy {} dummy; );
				OUTPUT_VALUE( sizeof( dummy ) );

				LF();

				OUTPUT_NOTE( "sizeof 의 반환값은 최소 1 이다.." );
			}

			LS();


			return r2tm::eDoLeaveAction::Pause;
		};
	}
}