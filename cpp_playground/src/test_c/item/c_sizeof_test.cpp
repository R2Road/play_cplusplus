#include "c_sizeof_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_sizeof_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "sizeof : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( sizeof( char ) );
				OUTPUT_VALUE( sizeof( int ) );
				OUTPUT_VALUE( sizeof( long long ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const double buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char buffer[10] = { 0 } );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const char* cb = buffer );
				OUTPUT_VALUE( sizeof( cb ) );

				std::cout << r2cm::linefeed << r2cm::tab << "+ sizeof 에 pointer 를 넣으면 pointer 자체의 크기를 반환한다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct Dummy {} dummy; );
				OUTPUT_VALUE( sizeof( dummy ) );

				std::cout << r2cm::linefeed << r2cm::tab << "+ sizeof 의 반환값은 최소 1 이다.." << r2cm::linefeed;
			}

			std::cout << r2cm::split;


			return r2cm::eItemLeaveAction::Pause;
		};
	}
}