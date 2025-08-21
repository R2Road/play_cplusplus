#include "c_bit_operation_test.h"

#include <numeric>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace
{
	template<typename T>
	void PrintBinary( const T value )
	{
		const int limit = sizeof( value ) * 8;

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

			DECL_MAIN( const int pivot = 0b100000001 ); // binary
			PrintBinary( pivot );

			LS();

			{
				OUTPUT_SUBJECT( "Flip : ~" );

				LF();

				PrintBinary( pivot );
				OUTPUT_CODE( ~pivot );
				PrintBinary( ~pivot );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Shift : Left : <<" );

				LF();

				PrintBinary( pivot );
				OUTPUT_CODE( pivot << 1 );
				PrintBinary( pivot << 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Shift : Right : >>" );

				LF();

				PrintBinary( pivot );
				OUTPUT_CODE( pivot >> 1 );
				PrintBinary( pivot >> 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Operator_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Operator_2";
		};
	}
	r2tm::DoFunctionT Operator_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( const int pivot = 0b100000001 ); // binary
			PrintBinary( pivot );

			LS();

			{
				OUTPUT_SUBJECT( "OR : | : 합치기" );

				LF();

				PrintBinary( pivot );
				OUTPUT_CODE( pivot | 0b000111000 );
				PrintBinary( pivot | 0b000111000 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "AND : & : 중복 추출" );

				LF();

				PrintBinary( pivot );
				OUTPUT_CODE( pivot & 0b100000000 );
				PrintBinary( pivot & 0b100000000 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "XOR : ^ : 같은 자리에 1 과 0 이 배치되면 1 그 외 0" );

				LF();

				PrintBinary( pivot );

				LF();

				OUTPUT_CODE( pivot ^ 0b000000000 );
				PrintBinary( pivot ^ 0b000000000 );

				LF();

				OUTPUT_CODE( pivot ^ 0b111111111 );
				PrintBinary( pivot ^ 0b111111111 );
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

			DECL_MAIN( const int pivot = 0b1000000001 ); // binary
			PrintBinary( pivot );

			LF();

			DECL_MAIN( int num = pivot );

			LS();

			{
				OUTPUT_SUBJECT( "1의 보수 : 0 과 1을 뒤집어 음수를 만든다" );

				LF();

				PROC_MAIN( num = ~num );
				PrintBinary( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "2의 보수 : 0 과 1을 뒤집고 + 1 해서 음수를 만든다" );

				LF();

				PROC_MAIN( num += 1 );
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

			DECL_MAIN( unsigned int num = 0b1000000001 ); // binary
			PrintBinary( num );

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

				PROC_MAIN( num |= ( 1 << 2 ) );
				PrintBinary( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Remove Flag" );

				LF();

				PROC_MAIN( num &= ~( 1 << 2 ) );
				PrintBinary( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Toggle Flag" );

				LF();

				PROC_MAIN( num ^= ( 1 << 2 ) );
				PrintBinary( num );

				LF();

				PROC_MAIN( num ^= ( 1 << 2 ) );
				PrintBinary( num );
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

			DECL_MAIN( const unsigned int num = 0b0011011000 );
			PrintBinary( num );
			DECL_MAIN( unsigned int mask = 0 );
			PrintBinary( mask );

			LF();

			DECL_MAIN( const unsigned int target_pos = 3 );
			DECL_MAIN( const unsigned int target_range = 5 );
			DECL_MAIN( const unsigned int bit_length = sizeof( num ) * 8 );

			LS();

			{
				OUTPUT_SUBJECT( "1로 채운다" );

				LF();

				PROC_MAIN( mask = std::numeric_limits<unsigned int>::max() );
				PrintBinary( mask );
				
				LF2();

				OUTPUT_SUBJECT( "꺼내올 데이터 크기 만큼 남긴다" );

				LF();

				PROC_MAIN( mask >>= ( bit_length - target_range ) );
				PrintBinary( mask );
				
				LF2();

				OUTPUT_SUBJECT( "꺼내올 데이터 위치로 이동한다" );

				LF();

				PROC_MAIN( mask <<= target_pos );
				PrintBinary( mask );
				
				LF2();

				OUTPUT_SUBJECT( "꺼낸다" );

				LF();

				DECL_MAIN( unsigned int result = num & mask );
				PrintBinary( result );
				
				LF2();

				OUTPUT_SUBJECT( "0번 bit 까지 이동시킨다" );

				LF();

				PROC_MAIN( result >>= target_pos );
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

			DECL_MAIN( char result = 0 );

			LS();

			{
				DECL_MAIN( const char b_1 = 0b00000000 );
				DECL_MAIN( const char b_2 = 0b00000000 );
				PROC_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			LS();

			{
				DECL_MAIN( const char b_1 = 0b00000011 );
				DECL_MAIN( const char b_2 = 0b00000000 );
				PROC_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			LS();

			{
				DECL_MAIN( const char b_1 = 0b00000011 );
				DECL_MAIN( const char b_2 = 0b00001100 );
				PROC_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );
			}

			LS();

			{
				DECL_MAIN( const char b_1 = 0b00000111 );
				DECL_MAIN( const char b_2 = 0b00001110 );
				PROC_MAIN( result = b_1 ^ b_2 );
				OUTPUT_BINARY( result );

				LF();

				PROC_MAIN( result = b_1 );
				OUTPUT_BINARY( result );
				PROC_MAIN( result ^= b_2 );
				OUTPUT_BINARY( result );
				PROC_MAIN( result ^= b_2 );
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
				DECL_MAIN( int a = 123 );
				PrintBinary( a );
				DECL_MAIN( int b = 456 );
				PrintBinary( b );

				std::cout << r2tm::linefeed2;

				PROC_MAIN( a = a ^ b );
				OUTPUT_VALUE( a );
				PrintBinary( a );
				OUTPUT_VALUE( b );
				PrintBinary( b );

				LF();

				PROC_MAIN( b = b ^ a );
				OUTPUT_VALUE( a );
				PrintBinary( a );
				OUTPUT_VALUE( b );
				PrintBinary( b );

				LF();

				PROC_MAIN( a = a ^ b );
				OUTPUT_VALUE( a );
				PrintBinary( a );
				OUTPUT_VALUE( b );
				PrintBinary( b );
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

			DECL_MAIN( const short t_1 = 1 );
			DECL_MAIN( const short t_2 = 5 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LS();

			{
				OUTPUT_NOTE( "1단계 : 겹치지 않는 bit 만 뽑아낸다." );

				LF();

				DECL_MAIN( const short sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );
			}

			LS();

			{
				OUTPUT_NOTE( "2단계 : 겹치는 bit 만 뽑아서 shift 한다.( 실질적인 덧셈 처리 )" );

				LF();

				DECL_MAIN( const short temp = ( t_1 & t_2 ) );
				OUTPUT_VALUE( temp );
				OUTPUT_BINARY( temp );

				LF();

				DECL_MAIN( const short carry = ( temp << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			LS();

			{
				OUTPUT_NOTE( "3	단계 : 완료" );

				LF();

				DECL_MAIN( const short result = ( ( t_1 ^ t_2 ) + ( ( t_1 & t_2 ) << 1 ) ) );
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

			DECL_MAIN( short t_1 = 1 );
			DECL_MAIN( short t_2 = 3 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LF();

			DECL_MAIN( short sum = 0 );
			DECL_MAIN( short carry = 0 );

			LS();

			{
				OUTPUT_NOTE( "cycle 1" );

				LF();

				PROC_MAIN( sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				LF();

				PROC_MAIN( carry = ( ( t_1 & t_2 ) << 1 ) );
				OUTPUT_VALUE( carry );
				OUTPUT_BINARY( carry );
			}

			LS();

			{
				PROC_MAIN( t_1 = sum );
				PROC_MAIN( t_2 = carry );
			}

			LS();

			{
				OUTPUT_NOTE( "cycle 2" );

				LF();

				PROC_MAIN( sum = t_1 ^ t_2 );
				OUTPUT_VALUE( sum );
				OUTPUT_BINARY( sum );

				LF();

				PROC_MAIN( carry = ( ( t_1 & t_2 ) << 1 ) );
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

			DECL_MAIN( const short t_1 = 4 );
			DECL_MAIN( const short t_2 = 1 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LS();

			{
				OUTPUT_NOTE( "1단계 : 겹치지 않는 bit 만 뽑아낸다." );

				LF();

				DECL_MAIN( const short sub = t_1 ^ t_2 );
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

				DECL_MAIN( const short borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			LS();

			{
				OUTPUT_NOTE( "3완료" );

				LF();

				DECL_MAIN( const short result = ( ( t_1 ^ t_2 ) - ( ( ( ~t_1 ) & t_2 ) << 1 ) ) );
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

			DECL_MAIN( short t_1 = 2 );
			DECL_MAIN( short t_2 = 1 );
			OUTPUT_BINARY( t_1 );
			OUTPUT_BINARY( t_2 );

			LS();

			DECL_MAIN( short sub = 0 );
			DECL_MAIN( short borrow = 0 );

			LS();

			{
				OUTPUT_NOTE( "cycle 1" );

				LF();

				PROC_MAIN( sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );

				LF();

				PROC_MAIN( borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
			}

			LS();

			{
				PROC_MAIN( t_1 = sub );
				PROC_MAIN( t_2 = borrow );
			}

			LS();

			{
				OUTPUT_NOTE( "cycle 2" );

				LF();

				PROC_MAIN( sub = t_1 ^ t_2 );
				OUTPUT_VALUE( sub );
				OUTPUT_BINARY( sub );

				LF();

				PROC_MAIN( borrow = ( ( ( ~t_1 ) & t_2 ) << 1 ) );
				OUTPUT_VALUE( borrow );
				OUTPUT_BINARY( borrow );
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
				DECL_MAIN( const char max_c = std::numeric_limits<char>::max() );
				PrintBinary( max_c );

				LF();

				DECL_MAIN( const int i_1 = max_c );
				PrintBinary( i_1 );

				LF();

				DECL_MAIN( const int i_2 = max_c );
				PrintBinary( i_2 );

				LF();

				DECL_MAIN( const int i_3 = i_1 + i_2 );
				PrintBinary( i_3 );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ 최상위 1 bit 를 비워둘 수 있다면 최대 값 끼리 더해도 문제 없다." << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ETC_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "ETC 2";
		};
	}
	r2tm::DoFunctionT ETC_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( const int i = -1 );
				OUTPUT_BINARY( i );
			}

			LS();

			{
				DECL_MAIN( const int i = 1 );
				OUTPUT_BINARY( i << 4 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "부호가 있는 type의 최상위 비트가 1 일 때 >> 연산을 수행하면 이전 비트가 유지된다." );

				LF();

				DECL_MAIN( const int i = -1 );
				OUTPUT_BINARY( i >> 4 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "부호가 없는 type의 최상위 비트가 1 일 때 >> 연산을 수행하면 이전 비트는 초기화 된다." );

				LF();

				DECL_MAIN( const unsigned int i = -1 );
				OUTPUT_BINARY( i >> 4 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}