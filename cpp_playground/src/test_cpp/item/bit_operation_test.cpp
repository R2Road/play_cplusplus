#include "pch.h"
#include "bit_operation_test.h"

#include <numeric>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace
{
	void PrintBinary( const int value, const int limit = 31 )
	{
		std::cout << r2cm::tab << "> ";

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



	r2cm::iItem::TitleFuncT Mask::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Bit Operation : Mask";
		};
	}
	r2cm::iItem::DoFuncT Mask::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( const int num = 0b0011011000 );
			PrintBinary( num, 31 );
			DECLARATION_MAIN( unsigned int mask = 0 );
			PrintBinary( mask, 31 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Make Mask" << r2cm::linefeed2;

				PROCESS_MAIN( mask = std::numeric_limits<unsigned int>::max() );
				PrintBinary( mask, 31 );
				PROCESS_MAIN( mask >>= ( 31 - 5 ) );
				PrintBinary( mask, 31 );
				PROCESS_MAIN( mask <<= 3 );
				PrintBinary( mask, 31 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const unsigned int result = num & mask );
				PrintBinary( result, 31 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT XOR_Swap::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Bit Operation : XOR Swap";
		};
	}
	r2cm::iItem::DoFuncT XOR_Swap::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int a = 123;
				int b = 456;

				std::cout << r2cm::tab << "int a = 123;" << r2cm::linefeed;
				std::cout << r2cm::tab << "int b = 456;" << r2cm::linefeed;
				std::cout << r2cm::linefeed2;

				a = a ^ b;
				std::cout << r2cm::tab << "a = a ^ b;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "a : " << a << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				b = b ^ a;
				std::cout << r2cm::tab << "b = b ^ a;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "b : " << b << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				a = a ^ b;
				std::cout << r2cm::tab << "a = a ^ b;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "a : " << a << r2cm::linefeed;
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}