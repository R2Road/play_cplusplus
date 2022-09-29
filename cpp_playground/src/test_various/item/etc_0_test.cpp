#include "etc_0_test.h"

#include <bitset>
#include <stdint.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace etc_test
{
	r2cm::iItem::TitleFunctionT ShowBinary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Show Binary";
		};
	}
	r2cm::iItem::DoFunctionT ShowBinary::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Use For" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 0b10110010101 ); // binary

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab;
				for( int i = 31; 0 <= i; --i )
				{
					const int temp_1 = ( num >> i );
					const int temp_2 = temp_1 & 1;

					std::cout << temp_2;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Use Bitset" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 0b0011001 ); // binary
				DECLARATION_MAIN( std::bitset<16u> b( num ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( b );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}