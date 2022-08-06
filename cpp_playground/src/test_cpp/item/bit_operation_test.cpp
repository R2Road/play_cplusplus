#include "bit_operation_test.h"

#include <numeric>

#include "r2cm/r2cm_ostream.h"
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
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ 2의 보수 : 0 과 1을 뒤집고 + 1 해서 음수를 만든다." << r2cm::linefeed;
			
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int num = 1 ); // binary
				PrintBinary( num );
			}

			std::cout << r2cm::split;


			{
				DECLARATION_MAIN( const int num = -1 ); // binary
				PrintBinary( num );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int num = 2 ); // binary
				PrintBinary( num );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int num = -2 ); // binary
				PrintBinary( num );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Operator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Operator";
		};
	}
	r2cm::iItem::DoFunctionT Operator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( const int pivot = 0b1000000001 ); // binary
			std::cout << r2cm::tab << "> " << pivot << r2cm::linefeed;
			PrintBinary( pivot );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Flip" << r2cm::linefeed2;

				OUTPUT_CODE( ~pivot );
				PrintBinary( ~pivot );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Shift : Left" << r2cm::linefeed2;

				OUTPUT_CODE( pivot << 1 );
				PrintBinary( pivot << 1 );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Shift : Right" << r2cm::linefeed2;

				OUTPUT_CODE( pivot >> 1 );
				PrintBinary( pivot >> 1 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Complement::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Complement";
		};
	}
	r2cm::iItem::DoFunctionT Complement::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( const int pivot = 0b1000000001 ); // binary
			std::cout << r2cm::tab << "> " << pivot << r2cm::linefeed;
			PrintBinary( pivot );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( int num = pivot );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 1의 보수 만들기." << r2cm::linefeed2;

				PROCESS_MAIN( num = ~num );
				PrintBinary( num );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 2의 보수 만들기." << r2cm::linefeed2;

				PROCESS_MAIN( num += 1 );
				PrintBinary( num );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( num, -pivot );
				OUTPUT_VALUE( num );
				OUTPUT_VALUE( -pivot );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Add_Remove_Toggle::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Add, Remove, Toggle";
		};
	}
	r2cm::iItem::DoFunctionT Add_Remove_Toggle::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( unsigned int num = 0b1000000001 ); // binary
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



	r2cm::iItem::TitleFunctionT Mask::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mask";
		};
	}
	r2cm::iItem::DoFunctionT Mask::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( const unsigned int num = 0b0011011000 );
			PrintBinary( num );
			DECLARATION_MAIN( unsigned int mask = 0 );
			PrintBinary( mask );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( const unsigned int target_pos = 3 );
			DECLARATION_MAIN( const unsigned int target_range = 5 );
			DECLARATION_MAIN( const unsigned int bit_length = sizeof( num ) * 8 );

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



	r2cm::iItem::TitleFunctionT XOR_Swap::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XOR Swap";
		};
	}
	r2cm::iItem::DoFunctionT XOR_Swap::GetDoFunction()
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



	r2cm::iItem::TitleFunctionT ETC_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "ETC_1";
		};
	}
	r2cm::iItem::DoFunctionT ETC_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char c_1 = std::numeric_limits<char>::max() );
				PrintBinary( c_1, 8 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( int i_1 = c_1 );
				PrintBinary( i_1, 32 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( i_1 += c_1 );
				PrintBinary( i_1, 32 );
			}

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Plus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Plus";
		};
	}
	r2cm::iItem::DoFunctionT Plus::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const short t_1 = 1 );
				OUTPUT_BINARY( t_1 );
				DECLARATION_MAIN( const short t_2 = 2 );
				OUTPUT_BINARY( t_2 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const short sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const short carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const short t_1 = 1 );
				OUTPUT_BINARY( t_1 );
				DECLARATION_MAIN( const short t_2 = 3 );
				OUTPUT_BINARY( t_2 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const short sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const short carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}