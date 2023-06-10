#include "number_test.h"

#include <iterator>
#include <numeric>
#include <string>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace number_test
{
	r2tm::TitleFunctionT Prefix::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number : Prefix";
		};
	}
	r2tm::DoFunctionT Prefix::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ Binary" << r2tm::linefeed2;

				DECLARATION_MAIN( const int num = 0b0011111 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( num );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Oct" << r2tm::linefeed2;

				DECLARATION_MAIN( const int num = 037 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( num );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Dec" << r2tm::linefeed2;

				DECLARATION_MAIN( const int num = 31 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( num );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Hex" << r2tm::linefeed2;

				DECLARATION_MAIN( const int num = 0x1f );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( num );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}