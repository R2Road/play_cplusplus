#include "cpp_structured_binding_test.h"

#include <array>
#include <tuple>
#include <utility> // pair

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
{
	std::pair<int, float> GetDummyPair()
	{
		return std::make_pair( 1, 3.14f );
	}

	std::tuple<int, float, char> GetDummyTuple()
	{
		return std::make_tuple( 2, 6.28f, 'b' );
	}
}
namespace cpp_structured_binding_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Structured Binding : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "array" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( int arr[3] );
				PROCESS_MAIN( arr[0] = 1; arr[1] = 2; arr[2] = 3; );
				auto[a, b, c] = arr;
				std::cout << "auto[a, b, c] = arr;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( a );
				OUTPUT_VALUE( b );
				OUTPUT_VALUE( c );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "std::array" );

				std::cout << r2cm::linefeed;

				std::array<int, 3> arr { 1, 2, 3};
				std::cout << "std::array<int, 3> arr( { 1, 2, 3} );" << r2cm::linefeed;
				auto[a, b, c] = arr;
				std::cout << "auto[a, b, c] = arr;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( a );
				OUTPUT_VALUE( b );
				OUTPUT_VALUE( c );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "struct" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( struct T
				{
					int i = 1;
					char c = 'a';
					float f = 3.14f;
				} );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( T t );

				auto[i, c, f] = t;
				std::cout << "auto[i, c, f] = t;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( i );
				OUTPUT_VALUE( c );
				OUTPUT_VALUE( f );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "with Pair" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto temp_pair = std::make_pair( 2, 'b' ) );

				auto[a, b] = temp_pair;
				std::cout << "auto[a, b] = temp_pair;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( a );
				OUTPUT_VALUE( b );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "with Tuple" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto temp_tuple = std::make_tuple( 3, 'c', 6.28f ) );

				auto[a, b, c] = temp_tuple;
				std::cout << "auto[a, b, c] = temp_tuple;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( a );
				OUTPUT_VALUE( b );
				OUTPUT_VALUE( c );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "with Function x 1" );

				std::cout << r2cm::linefeed;

				auto[a, b] = GetDummyPair();
				std::cout << "auto[a, b] = GetDummyPair();" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( a );
				OUTPUT_VALUE( b );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "with Function x 2" );

				std::cout << r2cm::linefeed;

				auto[a, b, c] = GetDummyTuple();
				std::cout << "auto[a, b, c] = GetDummyTuple();" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( a );
				OUTPUT_VALUE( b );
				OUTPUT_VALUE( c );
			}
			
			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}