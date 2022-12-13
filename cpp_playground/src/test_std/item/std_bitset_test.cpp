#include "std_bitset_test.h"

#include <bitset>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_bitset_test
{
	r2cm::iItem::TitleFunctionT Set_And_Test::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::bitset : Set And Test";
		};
	}
	r2cm::iItem::DoFunctionT Set_And_Test::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::bitset<3u> b );

			std::cout << r2cm::split;

			{
				EXPECT_FALSE( b.test( 0 ) );
				OUTPUT_VALUE( b.to_string() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( b.set( 0, true ) );
				EXPECT_TRUE( b.test( 0 ) );
				OUTPUT_VALUE( b.to_string() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( b.set( 0, false ) );
				EXPECT_FALSE( b.test( 0 ) );
				OUTPUT_VALUE( b.to_string() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( b.set( 0, true ) );
				PROCESS_MAIN( b.set( 2, true ) );
				OUTPUT_VALUE( b.to_string() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( b = 0 );
				OUTPUT_VALUE( b.to_string() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::bitset : Size";
		};
	}
	r2cm::iItem::DoFunctionT Size::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "크기는 4byte 단위로 증가." );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::bitset<1> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::bitset<8> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::bitset<16> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::bitset<32> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::bitset<48> container );
				OUTPUT_VALUE( sizeof( container ) );
				OUTPUT_VALUE( container.size() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}