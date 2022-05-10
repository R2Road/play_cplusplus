#include "pch.h"
#include "bit_operation_test.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace
{
	void PrintBinary( const int value, const int limit = 31 )
	{
		for( int position = limit; 0 <= position; --position )
		{
			const int temp_1 = ( value >> position );
			const int temp_2 = temp_1 & 1;

			std::cout << temp_2;
		}

		std::cout << r2cm::linefeed;
	}
}

namespace bit_operation_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Bit Operation : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( int num = 0b1000000001 ); // binary
			PrintBinary( num, 16 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Test Flag" << r2cm::linefeed2;

				EXPECT_TRUE( num & ( 1 << 0 ) );
				EXPECT_FALSE( num & ( 1 << 2 ) );
				EXPECT_TRUE( num & ( 1 << 9 ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Add Flag" << r2cm::linefeed2;

				PROCESS_MAIN( num |= ( 1 << 2 ) );
				PrintBinary( num, 16 );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Remove Flag" << r2cm::linefeed2;

				PROCESS_MAIN( num &= ~( 1 << 2 ) );
				PrintBinary( num, 16 );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Toggle Flag" << r2cm::linefeed2;

				PROCESS_MAIN( num ^= ( 1 << 2 ) );
				PrintBinary( num, 16 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( num ^= ( 1 << 2 ) );
				PrintBinary( num, 16 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}