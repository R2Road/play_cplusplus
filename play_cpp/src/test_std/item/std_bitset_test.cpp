#include "std_bitset_test.h"

#include <bitset>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_bitset_test
{
	r2tm::TitleFunctionT All_Any_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::bitset : All_Any_None";
		};
	}
	r2tm::DoFunctionT All_Any_None::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::bitset<3u> b = 0b000 );
				EXPECT_FALSE( b.all() );
				EXPECT_FALSE( b.any() );
				EXPECT_TRUE( b.none() );
				OUTPUT_VALUE( b.size() );
			}

			LS();

			{
				DECLARATION_MAIN( std::bitset<3u> b = 0b001 );
				EXPECT_FALSE( b.all() );
				EXPECT_TRUE( b.any() );
				EXPECT_FALSE( b.none() );
				OUTPUT_VALUE( b.size() );
			}

			LS();

			{
				DECLARATION_MAIN( std::bitset<3u> b = 0b011 );
				EXPECT_FALSE( b.all() );
				EXPECT_TRUE( b.any() );
				EXPECT_FALSE( b.none() );
				OUTPUT_VALUE( b.size() );
			}

			LS();

			{
				DECLARATION_MAIN( std::bitset<3u> b = 0b111 );
				EXPECT_TRUE( b.all() );
				EXPECT_TRUE( b.any() );
				EXPECT_FALSE( b.none() );
				OUTPUT_VALUE( b.size() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Set_And_Test::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::bitset : Set And Test";
		};
	}
	r2tm::DoFunctionT Set_And_Test::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::bitset<3u> b );

			LS();

			{
				EXPECT_FALSE( b.test( 0 ) );
				OUTPUT_VALUE( b.to_string() );
			}

			LS();

			{
				PROCESS_MAIN( b.set( 0, true ) );
				EXPECT_TRUE( b.test( 0 ) );
				OUTPUT_VALUE( b.to_string() );
			}

			LS();

			{
				PROCESS_MAIN( b.set( 0, false ) );
				EXPECT_FALSE( b.test( 0 ) );
				OUTPUT_VALUE( b.to_string() );
			}

			LS();

			{
				PROCESS_MAIN( b.set( 0, true ) );
				PROCESS_MAIN( b.set( 2, true ) );
				OUTPUT_VALUE( b.to_string() );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( b = 0 );
				OUTPUT_VALUE( b.to_string() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::bitset : Size";
		};
	}
	r2tm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "크기는 4byte 단위로 증가." );

			LS();

			{
				DECLARATION_MAIN( std::bitset<1> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			LS();

			{
				DECLARATION_MAIN( std::bitset<8> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			LS();

			{
				DECLARATION_MAIN( std::bitset<16> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			LS();

			{
				DECLARATION_MAIN( std::bitset<32> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			LS();

			{
				DECLARATION_MAIN( std::bitset<48> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Operator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::bitset : Operator";
		};
	}
	r2tm::DoFunctionT Operator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::bitset<10> b = 0b10101 );
			OUTPUT_VALUE( b.to_string() );

			LS();

			{
				OUTPUT_NOTE( "bit 연산이 안되는 큰 단점." );

				std::cout << r2tm::linefeed;

				EXPECT_TRUE( 0b10101 & b.to_ulong() );
				EXPECT_FALSE( 0b01010 & b.to_ulong() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}