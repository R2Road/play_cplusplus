#include "number_test.h"

#include <iterator>
#include <numeric>
#include <string>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace number_test
{
	r2cm::iItem::TitleFunctionT Prefix::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number : Prefix";
		};
	}
	r2cm::iItem::DoFunctionT Prefix::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Binary" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 0b0011111 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( num );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Oct" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 037 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( num );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Dec" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 31 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( num );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Hex" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 0x1f );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( num );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}