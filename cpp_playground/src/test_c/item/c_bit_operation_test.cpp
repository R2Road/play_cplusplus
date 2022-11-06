#include "c_bit_operation_test.h"

#include <numeric>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
{
	void PrintBinary( const int value, const int limit = 32 )
	{
		printf( "\t> %8d : ", value );

		for( int position = limit - 1; 0 <= position; --position )
		{
			const int temp_1 = ( value >> position );
			const int temp_2 = temp_1 & 1;

			std::cout << temp_2;
		}

		std::cout << r2cm::linefeed;
	}
}

namespace c_bit_operation_test
{
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
			std::cout << r2cm::split;

			DECLARATION_MAIN( const int pivot = 0b1000000001 ); // binary
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
			std::cout << r2cm::split;

			{
				PrintBinary( 1 );
				PrintBinary( -1 );
				PrintBinary( 2 );
				PrintBinary( -2 );
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( const int pivot = 0b1000000001 ); // binary
			PrintBinary( pivot );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( int num = pivot );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 1의 보수 : 0 과 1을 뒤집어 음수를 만든다." << r2cm::linefeed2;

				PROCESS_MAIN( num = ~num );
				PrintBinary( num );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 2의 보수 : 0 과 1을 뒤집고 + 1 해서 음수를 만든다." << r2cm::linefeed2;

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



	r2cm::iItem::TitleFunctionT Operator_XOR::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Operator : XOR";
		};
	}
	r2cm::iItem::DoFunctionT Operator_XOR::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( char result = 0 );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char b_1 = 0b00000000 );
				DECLARATION_MAIN( const char b_2 = 0b00000000 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char b_1 = 0b00000011 );
				DECLARATION_MAIN( const char b_2 = 0b00000000 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char b_1 = 0b00000011 );
				DECLARATION_MAIN( const char b_2 = 0b00001100 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char b_1 = 0b00000111 );
				DECLARATION_MAIN( const char b_2 = 0b00001110 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( result = b_1 );
				OUTPUT_BINARY( result );
				PROCESS_MAIN( result ^= b_2 );
				OUTPUT_BINARY( result );
				PROCESS_MAIN( result ^= b_2 );
				OUTPUT_BINARY( result );
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
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char max_c = std::numeric_limits<char>::max() );
				PrintBinary( max_c, 8 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const int i_1 = max_c );
				PrintBinary( i_1, 32 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const int i_2 = max_c );
				PrintBinary( i_2, 32 );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const int i_3 = i_1 + i_2 );
				PrintBinary( i_3, 32 );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 최상위 1 bit 를 비워둘 수 있다면 최대 값 끼리 더해도 문제 없다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Plus_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Plus 1";
		};
	}
	r2cm::iItem::DoFunctionT Plus_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const short t_1 = 1 );
			DECLARATION_MAIN( const short t_2 = 2 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 1단계 : 겹치지 않는 bit 만 뽑아낸다." << r2cm::linefeed2;

				DECLARATION_MAIN( const short sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 2단계 : 겹치는 bit 만 뽑아서 shift 한다.( 실질적인 덧셈 처리 )" << r2cm::linefeed2;

				DECLARATION_MAIN( const short carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Plus_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Plus 2";
		};
	}
	r2cm::iItem::DoFunctionT Plus_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( short t_1 = 1 );
			DECLARATION_MAIN( short t_2 = 3 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			std::cout << r2cm::split;

			DECLARATION_MAIN( short sum = 0 );
			DECLARATION_MAIN( short carry = 0 );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( t_1 = sum );
				PROCESS_MAIN( t_2 = carry );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Minus_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Minus 1";
		};
	}
	r2cm::iItem::DoFunctionT Minus_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const short t_1 = 1 );
			DECLARATION_MAIN( const short t_2 = 1 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 1단계 : 겹치지 않는 bit 만 뽑아낸다." << r2cm::linefeed2;

				DECLARATION_MAIN( const short sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 2단계 : 앞의 수를 뒤집어 겹치는 bit 만 뽑아서 shift 한다.( 실질적인 뺄셈 처리 )" << r2cm::linefeed2;

				OUTPUT_BINARY( short( ~t_1 ) );
				OUTPUT_BINARY( t_2 );
				OUTPUT_BINARY( short( ( ~t_1 ) & t_2 ) );
				OUTPUT_BINARY( short( ( ( ~t_1 ) & t_2 ) <<1 ) );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const short borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Minus_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Minus 2";
		};
	}
	r2cm::iItem::DoFunctionT Minus_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( short t_1 = 2 );
			DECLARATION_MAIN( short t_2 = 1 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			std::cout << r2cm::split;

			DECLARATION_MAIN( short sub = 0 );
			DECLARATION_MAIN( short borrow = 0 );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( t_1 = sub );
				PROCESS_MAIN( t_2 = borrow );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}