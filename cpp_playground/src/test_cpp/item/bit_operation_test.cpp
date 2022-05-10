#include "pch.h"
#include "bit_operation_test.h"

#include <numeric>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace
{
	void PrintBinary( const int value, const int limit = 32 )
	{
		std::cout << r2cm::tab << "> ";

		for( int position = limit - 1; 0 <= position; --position )
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
			PrintBinary( num );
			DECLARATION_MAIN( unsigned int mask = 0 );
			PrintBinary( mask );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( const unsigned int target_pos = 3 );
			DECLARATION_MAIN( const unsigned int target_range = 5 );
			DECLARATION_MAIN( const unsigned int bit_length = 32 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 1로 채운다" << r2cm::linefeed2;

				PROCESS_MAIN( mask = std::numeric_limits<unsigned int>::max() );
				PrintBinary( mask );

				std::cout << r2cm::linefeed2;
				std::cout << r2cm::tab << "+ 꺼내올 데이터 크기 만큼 남긴다." << r2cm::linefeed2;

				PROCESS_MAIN( mask >>= ( bit_length - target_range ) );
				PrintBinary( mask );

				std::cout << r2cm::linefeed2;
				std::cout << r2cm::tab << "+ 꺼내올 데이터 위치로 이동한다." << r2cm::linefeed2;

				PROCESS_MAIN( mask <<= target_pos );
				PrintBinary( mask );

				std::cout << r2cm::linefeed2;
				std::cout << r2cm::tab << "+ 꺼낸다." << r2cm::linefeed2;

				DECLARATION_MAIN( unsigned int result = num & mask );
				PrintBinary( result );

				std::cout << r2cm::linefeed2;
				std::cout << r2cm::tab << "+ 0번 bit 까지 이동시킨다." << r2cm::linefeed2;

				PROCESS_MAIN( result >>= target_pos );
				PrintBinary( result );
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
				DECLARATION_MAIN( int a = 123 );
				PrintBinary( a, 31 );
				DECLARATION_MAIN( int b = 456 );
				PrintBinary( b, 31 );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( a = a ^ b );
				OUTPUT_VALUE( a );
				PrintBinary( a, 31 );
				OUTPUT_VALUE( b );
				PrintBinary( b, 31 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( b = b ^ a );
				OUTPUT_VALUE( a );
				PrintBinary( a, 31 );
				OUTPUT_VALUE( b );
				PrintBinary( b, 31 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( a = a ^ b );
				OUTPUT_VALUE( a );
				PrintBinary( a, 31 );
				OUTPUT_VALUE( b );
				PrintBinary( b, 31 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}