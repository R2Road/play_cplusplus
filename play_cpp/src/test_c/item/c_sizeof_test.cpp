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
			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( sizeof( char ) );
				OUTPUT_VALUE( sizeof( int ) );
				OUTPUT_VALUE( sizeof( long long ) );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const char buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const int buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const double buffer[10] = { 0 } );
				OUTPUT_VALUE( sizeof( buffer ) );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const char buffer[10] = { 0 } );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const char* cb = buffer );
				OUTPUT_VALUE( sizeof( cb ) );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "sizeof �� pointer �� ������ pointer ��ü�� ũ�⸦ ��ȯ�Ѵ�." );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct Dummy {} dummy; );
				OUTPUT_VALUE( sizeof( dummy ) );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "sizeof �� ��ȯ���� �ּ� 1 �̴�.." );
			}

			std::cout << r2tm::split;


			return r2tm::eDoLeaveAction::Pause;
		};
	}
}