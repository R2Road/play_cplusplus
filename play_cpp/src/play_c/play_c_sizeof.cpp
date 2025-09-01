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
				OUT_VALUE( sizeof( char ) );
				OUT_VALUE( sizeof( int ) );
				OUT_VALUE( sizeof( long long ) );
			}

			LS();

			{
				OUT_SUBJECT( "sizeof 에 배열을 넣으면 배열의 전체 메모리 크기를 반환." );

				LF();

				{
					DECL_MAIN( const char buffer[10] = { 0 } );
					OUT_VALUE( sizeof( buffer ) );
				}

				SS();

				{
					DECL_MAIN( const int buffer[10] = { 0 } );
					OUT_VALUE( sizeof( buffer ) );
				}

				SS();

				{
					DECL_MAIN( const double buffer[10] = { 0 } );
					OUT_VALUE( sizeof( buffer ) );
				}
			}

			LS();

			{
				OUT_SUBJECT( "sizeof 에 pointer 를 넣으면 pointer 자체의 크기를 반환한다." );

				LF();

				DECL_MAIN( const char buffer[10] = { 0 } );

				LF();

				DECL_MAIN( const char* cb = buffer );
				OUT_VALUE( sizeof( cb ) );
			}

			LS();

			{
				OUT_SUBJECT( "sizeof 의 최소 반환값은 1 " );

				LF();

				DECL_MAIN( struct Dummy {} dummy; );
				OUT_VALUE( sizeof( dummy ) );
			}

			LS();


			return r2tm::eDoLeaveAction::Pause;
		};
	}
}