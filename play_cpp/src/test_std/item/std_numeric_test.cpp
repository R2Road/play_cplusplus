#include "std_numeric_test.h"

#include <iterator>
#include <numeric>
#include <string>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_numeric_test
{
	r2tm::TitleFunctionT Accumulate_Number::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::accumulate : Number";
		};
	}
	r2tm::DoFunctionT Accumulate_Number::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "# Sum" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

				const int sum = std::accumulate( v.begin(), v.end(), 0 );

				std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "const int sum = std::accumulate( v.begin(), v.end(), 0 );" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Result" << r2tm::linefeed;
				std::cout << r2tm::tab2 << sum << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "# Minus" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::vector<int> v{ 5, 10, 25 };

				const int result = std::accumulate( v.begin(), v.end(), 100, std::minus<int>() );

				std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::vector<int> v{ 5, 10, 25 };" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "const int product = std::accumulate( v.begin(), v.end(), 100, std::minus<int>() );" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Result" << r2tm::linefeed;
				std::cout << r2tm::tab2 << result << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "# Multiply" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::vector<int> v{ 2, 10, 4 };

				const int result = std::accumulate( v.begin(), v.end(), 2, std::multiplies<int>() );

				std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::vector<int> v{ 2, 10, 4 };" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "const int product = std::accumulate( v.begin(), v.end(), 2, std::multiplies<int>() );" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Result" << r2tm::linefeed;
				std::cout << r2tm::tab2 << result << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Accumulate_String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::accumulate : String";
		};
	}
	r2tm::DoFunctionT Accumulate_String::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			// Copy from https://en.cppreference.com/w/cpp/algorithm/accumulate

			std::vector<int> v{ 1, 2, 3, 4, 5 };

			auto modifier = []( std::string a, int b )
			{
				return std::move( a ) + '-' + std::to_string( b );
			};

			std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5 };" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "auto modifier = []( std::string a, int b )" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
			std::cout << r2tm::tab3 << "return std::move( a ) + '-' + std::to_string( b );" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
			std::cout << r2tm::linefeed;

			LS();

			{
				const std::string s = std::accumulate(
					std::next( v.begin() ), v.end()
					, std::to_string( v[0] ) // start with first element
					, modifier
				);

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "const std::string s = std::accumulate(" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "std::next( v.begin() ), v.end()" << r2tm::linefeed;
				std::cout << r2tm::tab3 << ", std::to_string( v[0] )" << r2tm::linefeed;
				std::cout << r2tm::tab3 << ", modifier" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ");" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Result" << r2tm::linefeed;
				std::cout << r2tm::tab2 << s << r2tm::linefeed;
			}

			LS();

			{
				const std::string rs = std::accumulate(
					std::next( v.rbegin() ), v.rend()
					, std::to_string( v.back() )
					, modifier
				);

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "const std::string rs = std::accumulate(" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "std::next( v.rbegin() ), v.rend()" << r2tm::linefeed;
				std::cout << r2tm::tab3 << ", , std::to_string( v.back() )" << r2tm::linefeed;
				std::cout << r2tm::tab3 << ", modifier" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ");" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Result" << r2tm::linefeed;
				std::cout << r2tm::tab2 << rs << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Partial_Sum::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::partial_sum";
		};
	}
	r2tm::DoFunctionT Partial_Sum::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				// Copy from https://en.cppreference.com/w/cpp/algorithm/partial_sum

				std::vector<int> v{ 1, 2, 3, 4, 5 };

				std::partial_sum( v.begin(), v.end(), v.begin(), std::plus<int>() );

				std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5 };" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::partial_sum( v.begin(), v.end(), v.begin(), std::plus<int>() );" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Result" << r2tm::linefeed;
				std::cout << r2tm::tab2;
				for( const auto& i : v )
				{
					std::cout << i << r2tm::tab;
				}
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				// Copy from https://en.cppreference.com/w/cpp/algorithm/partial_sum

				std::vector<int> v{ 1, 2, 3, 4, 5 };

				std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5 };" << r2tm::linefeed;
				std::cout << r2tm::linefeed;


				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::partial_sum(" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "v.begin(), v.end()" << r2tm::linefeed;
				std::cout << r2tm::tab3 << ", std::ostream_iterator<int>( std::cout, \"-\" )" << r2tm::linefeed;
				std::cout << r2tm::tab3 << ", std::multiplies<int>()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ");" << r2tm::linefeed;
				std::cout << r2tm::linefeed;


				std::cout << r2tm::tab << "+ Result" << r2tm::linefeed;
				std::cout << r2tm::tab2;

				std::partial_sum(
					v.begin(), v.end()
					, std::ostream_iterator<int>( std::cout, "-" )
					, std::multiplies<int>()
				);

				std::cout << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillSequenceNumber::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::iota : Fill Sequence Number In Container";
		};
	}
	r2tm::DoFunctionT FillSequenceNumber::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::list<int> temp_list( 10, 0 ) );

			LS();

			{
				PROCESS_MAIN( std::iota( temp_list.begin(), temp_list.end(), 11 ) ); // fill : 0, 1, 2, 3, 4 ......
			}

			LS();

			{
				std::cout << r2tm::tab << "+ View" << r2tm::linefeed2;
				for( auto i : temp_list )
				{
					OUTPUT_VALUE( i );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}