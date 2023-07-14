#include "c_bit_operation_test.h"

#include <numeric>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

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

		LF();
	}
}

namespace c_bit_operation_test
{
	r2tm::TitleFunctionT Operator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Operator";
		};
	}
	r2tm::DoFunctionT Operator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const int pivot = 0b1000000001 ); // binary
			PrintBinary( pivot );

			LS();

			{
				OUTPUT_SUBJECT( "Flip" );

				LF();

				OUTPUT_CODE( ~pivot );
				PrintBinary( ~pivot );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Shift : Left" );

				LF();

				OUTPUT_CODE( pivot << 1 );
				PrintBinary( pivot << 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Shift : Right" );

				LF();

				OUTPUT_CODE( pivot >> 1 );
				PrintBinary( pivot >> 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Complement::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Complement";
		};
	}
	r2tm::DoFunctionT Complement::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				PrintBinary( 1 );
				PrintBinary( -1 );
				PrintBinary( 2 );
				PrintBinary( -2 );
			}

			LS();

			DECLARATION_MAIN( const int pivot = 0b1000000001 ); // binary
			PrintBinary( pivot );

			LF();

			DECLARATION_MAIN( int num = pivot );

			LS();

			{
				std::cout << r2tm::tab << "+ 1의 보수 : 0 과 1을 뒤집어 음수를 만든다." << r2tm::linefeed2;

				PROCESS_MAIN( num = ~num );
				PrintBinary( num );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ 2의 보수 : 0 과 1을 뒤집고 + 1 해서 음수를 만든다." << r2tm::linefeed2;

				PROCESS_MAIN( num += 1 );
				PrintBinary( num );
			}

			LS();

			{
				EXPECT_EQ( num, -pivot );
				OUTPUT_VALUE( num );
				OUTPUT_VALUE( -pivot );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Add_Remove_Toggle::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Add, Remove, Toggle";
		};
	}
	r2tm::DoFunctionT Add_Remove_Toggle::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( unsigned int num = 0b1000000001 ); // binary
			PrintBinary( num, 16 );

			LS();

			{
				OUTPUT_SUBJECT( "Test Flag" );

				LF();

				EXPECT_TRUE( num & ( 1 << 0 ) );
				EXPECT_FALSE( num & ( 1 << 2 ) );
				EXPECT_TRUE( num & ( 1 << 9 ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Add Flag" );

				LF();

				PROCESS_MAIN( num |= ( 1 << 2 ) );
				PrintBinary( num, 16 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Remove Flag" );

				LF();

				PROCESS_MAIN( num &= ~( 1 << 2 ) );
				PrintBinary( num, 16 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Toggle Flag" );

				LF();

				PROCESS_MAIN( num ^= ( 1 << 2 ) );
				PrintBinary( num, 16 );

				LF();

				PROCESS_MAIN( num ^= ( 1 << 2 ) );
				PrintBinary( num, 16 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Mask::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Mask";
		};
	}
	r2tm::DoFunctionT Mask::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const unsigned int num = 0b0011011000 );
			PrintBinary( num );
			DECLARATION_MAIN( unsigned int mask = 0 );
			PrintBinary( mask );

			LF();

			DECLARATION_MAIN( const unsigned int target_pos = 3 );
			DECLARATION_MAIN( const unsigned int target_range = 5 );
			DECLARATION_MAIN( const unsigned int bit_length = sizeof( num ) * 8 );

			LS();

			{
				OUTPUT_SUBJECT( "1로 채운다" );

				LF();

				PROCESS_MAIN( mask = std::numeric_limits<unsigned int>::max() );
				PrintBinary( mask );
				
				LF2();

				OUTPUT_SUBJECT( "꺼내올 데이터 크기 만큼 남긴다" );

				LF();

				PROCESS_MAIN( mask >>= ( bit_length - target_range ) );
				PrintBinary( mask );
				
				LF2();

				OUTPUT_SUBJECT( "꺼내올 데이터 위치로 이동한다" );

				LF();

				PROCESS_MAIN( mask <<= target_pos );
				PrintBinary( mask );
				
				LF2();

				OUTPUT_SUBJECT( "꺼낸다" );

				LF();

				DECLARATION_MAIN( unsigned int result = num & mask );
				PrintBinary( result );
				
				LF2();

				OUTPUT_SUBJECT( "0번 bit 까지 이동시킨다" );

				LF();

				PROCESS_MAIN( result >>= target_pos );
				PrintBinary( result );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Operator_XOR::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Operator : XOR";
		};
	}
	r2tm::DoFunctionT Operator_XOR::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( char result = 0 );

			LS();

			{
				DECLARATION_MAIN( const char b_1 = 0b00000000 );
				DECLARATION_MAIN( const char b_2 = 0b00000000 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			LS();

			{
				DECLARATION_MAIN( const char b_1 = 0b00000011 );
				DECLARATION_MAIN( const char b_2 = 0b00000000 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			LS();

			{
				DECLARATION_MAIN( const char b_1 = 0b00000011 );
				DECLARATION_MAIN( const char b_2 = 0b00001100 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			LS();

			{
				DECLARATION_MAIN( const char b_1 = 0b00000111 );
				DECLARATION_MAIN( const char b_2 = 0b00001110 );
				PROCESS_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );

				LF();

				PROCESS_MAIN( result = b_1 );
				OUTPUT_BINARY( result );
				PROCESS_MAIN( result ^= b_2 );
				OUTPUT_BINARY( result );
				PROCESS_MAIN( result ^= b_2 );
				OUTPUT_BINARY( result );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT XOR_Swap::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XOR Swap";
		};
	}
	r2tm::DoFunctionT XOR_Swap::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int a = 123 );
				PrintBinary( a, 31 );
				DECLARATION_MAIN( int b = 456 );
				PrintBinary( b, 31 );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( a = a ^ b );
				OUTPUT_VALUE( a );
				PrintBinary( a, 31 );
				OUTPUT_VALUE( b );
				PrintBinary( b, 31 );

				LF();

				PROCESS_MAIN( b = b ^ a );
				OUTPUT_VALUE( a );
				PrintBinary( a, 31 );
				OUTPUT_VALUE( b );
				PrintBinary( b, 31 );

				LF();

				PROCESS_MAIN( a = a ^ b );
				OUTPUT_VALUE( a );
				PrintBinary( a, 31 );
				OUTPUT_VALUE( b );
				PrintBinary( b, 31 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ETC_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "ETC_1";
		};
	}
	r2tm::DoFunctionT ETC_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( const char max_c = std::numeric_limits<char>::max() );
				PrintBinary( max_c, 8 );

				LF();

				DECLARATION_MAIN( const int i_1 = max_c );
				PrintBinary( i_1, 32 );

				LF();

				DECLARATION_MAIN( const int i_2 = max_c );
				PrintBinary( i_2, 32 );

				LF();

				DECLARATION_MAIN( const int i_3 = i_1 + i_2 );
				PrintBinary( i_3, 32 );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ 최상위 1 bit 를 비워둘 수 있다면 최대 값 끼리 더해도 문제 없다." << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Plus_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Plus 1";
		};
	}
	r2tm::DoFunctionT Plus_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "개념 잡기" );

			LS();

			DECLARATION_MAIN( const short t_1 = 1 );
			DECLARATION_MAIN( const short t_2 = 5 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LS();

			{
				OUTPUT_NOTE( "1단계 : 겹치지 않는 bit 만 뽑아낸다." );

				LF();

				DECLARATION_MAIN( const short sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );
			}

			LS();

			{
				OUTPUT_NOTE( "2단계 : 겹치는 bit 만 뽑아서 shift 한다.( 실질적인 덧셈 처리 )" );

				LF();

				DECLARATION_MAIN( const short temp = ( t_1 & t_2 ) );
				OUTPUT_VALUE( temp );
				OUTPUT_BINARY( temp );

				LF();

				DECLARATION_MAIN( const short carry = ( temp << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			LS();

			{
				OUTPUT_NOTE( "3	단계 : 완료" );

				LF();

				DECLARATION_MAIN( const short result = ( ( t_1 ^ t_2 ) + ( ( t_1 & t_2 ) << 1 ) ) );
				OUTPUT_VALUE( result );
				OUTPUT_BINARY( result );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Plus_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Plus 2";
		};
	}
	r2tm::DoFunctionT Plus_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "bit 연산 만으로 덧셈 처리 해보자." );

			LS();

			DECLARATION_MAIN( short t_1 = 1 );
			DECLARATION_MAIN( short t_2 = 3 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LF();

			DECLARATION_MAIN( short sum = 0 );
			DECLARATION_MAIN( short carry = 0 );

			LS();

			{
				OUTPUT_NOTE( "cycle 1" );

				LF();

				PROCESS_MAIN( sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				LF();

				PROCESS_MAIN( carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			LS();

			{
				PROCESS_MAIN( t_1 = sum );
				PROCESS_MAIN( t_2 = carry );
			}

			LS();

			{
				OUTPUT_NOTE( "cycle 2" );

				LF();

				PROCESS_MAIN( sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				LF();

				PROCESS_MAIN( carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Minus_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Minus 1";
		};
	}
	r2tm::DoFunctionT Minus_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "개념 잡기" );

			LS();

			DECLARATION_MAIN( const short t_1 = 4 );
			DECLARATION_MAIN( const short t_2 = 1 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LS();

			{
				OUTPUT_NOTE( "1단계 : 겹치지 않는 bit 만 뽑아낸다." );

				LF();

				DECLARATION_MAIN( const short sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );
			}

			LS();

			{
				OUTPUT_NOTE( "2단계 : 앞의 수를 뒤집어 겹치는 bit 만 뽑아서 shift 한다.( 실질적인 뺄셈 처리 )" );

				LF();

				OUTPUT_BINARY( short( ~t_1 ) );
				OUTPUT_BINARY( t_2 );
				OUTPUT_BINARY( short( ( ~t_1 ) & t_2 ) );
				OUTPUT_BINARY( short( ( ( ~t_1 ) & t_2 ) <<1 ) );

				LF();

				DECLARATION_MAIN( const short borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			LS();

			{
				OUTPUT_NOTE( "3완료" );

				LF();

				DECLARATION_MAIN( const short result = ( ( t_1 ^ t_2 ) - ( ( ( ~t_1 ) & t_2 ) << 1 ) ) );
				OUTPUT_VALUE( result );
				OUTPUT_BINARY( result );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Minus_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Minus 2";
		};
	}
	r2tm::DoFunctionT Minus_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "bit 연산 만으로 뺄셈 처리 해보자." );

			LS();

			DECLARATION_MAIN( short t_1 = 2 );
			DECLARATION_MAIN( short t_2 = 1 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LS();

			DECLARATION_MAIN( short sub = 0 );
			DECLARATION_MAIN( short borrow = 0 );

			LS();

			{
				OUTPUT_NOTE( "cycle 1" );

				LF();

				PROCESS_MAIN( sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );

				LF();

				PROCESS_MAIN( borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			LS();

			{
				PROCESS_MAIN( t_1 = sub );
				PROCESS_MAIN( t_2 = borrow );
			}

			LS();

			{
				OUTPUT_NOTE( "cycle 2" );

				LF();

				PROCESS_MAIN( sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );

				LF();

				PROCESS_MAIN( borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}