#include "play_cpp_structured_binding.hpp"

#include <array>
#include <tuple>
#include <utility> // pair

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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
namespace play_cpp_structured_binding
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Structured Binding : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_NOTE( "array" );

				LF();

				DECL_MAIN( int arr[3] );
				PROC_MAIN( arr[0] = 1; arr[1] = 2; arr[2] = 3; );
				auto[a, b, c] = arr;
				std::cout << "auto[a, b, c] = arr;" << r2tm::linefeed;

				LF();

				OUT_VALUE( a );
				OUT_VALUE( b );
				OUT_VALUE( c );
			}

			LS();

			{
				OUT_NOTE( "std::array" );

				LF();

				std::array<int, 3> arr { 1, 2, 3};
				std::cout << "std::array<int, 3> arr( { 1, 2, 3} );" << r2tm::linefeed;
				auto[a, b, c] = arr;
				std::cout << "auto[a, b, c] = arr;" << r2tm::linefeed;

				LF();

				OUT_VALUE( a );
				OUT_VALUE( b );
				OUT_VALUE( c );
			}

			LS();

			{
				OUT_NOTE( "struct" );

				LF();

				DECL_MAIN( struct T
				{
					int i = 1;
					char c = 'a';
					float f = 3.14f;
				} );

				LF();

				DECL_MAIN( T t );

				auto[i, c, f] = t;
				std::cout << "auto[i, c, f] = t;" << r2tm::linefeed;

				LF();

				OUT_VALUE( i );
				OUT_VALUE( c );
				OUT_VALUE( f );
			}

			LS();

			{
				OUT_NOTE( "with Pair" );

				LF();

				DECL_MAIN( auto temp_pair = std::make_pair( 2, 'b' ) );

				auto[a, b] = temp_pair;
				std::cout << "auto[a, b] = temp_pair;" << r2tm::linefeed;

				LF();

				OUT_VALUE( a );
				OUT_VALUE( b );
			}

			LS();

			{
				OUT_NOTE( "with Tuple" );

				LF();

				DECL_MAIN( auto temp_tuple = std::make_tuple( 3, 'c', 6.28f ) );

				auto[a, b, c] = temp_tuple;
				std::cout << "auto[a, b, c] = temp_tuple;" << r2tm::linefeed;

				LF();

				OUT_VALUE( a );
				OUT_VALUE( b );
				OUT_VALUE( c );
			}

			LS();

			{
				OUT_NOTE( "with Function x 1" );

				LF();

				auto[a, b] = GetDummyPair();
				std::cout << "auto[a, b] = GetDummyPair();" << r2tm::linefeed;

				LF();

				OUT_VALUE( a );
				OUT_VALUE( b );
			}

			LS();

			{
				OUT_NOTE( "with Function x 2" );

				LF();

				auto[a, b, c] = GetDummyTuple();
				std::cout << "auto[a, b, c] = GetDummyTuple();" << r2tm::linefeed;

				LF();

				OUT_VALUE( a );
				OUT_VALUE( b );
				OUT_VALUE( c );
			}
			
			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}