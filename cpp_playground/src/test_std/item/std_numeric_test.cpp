#include "std_numeric_test.h"

#include <iterator>
#include <numeric>
#include <string>

#include "r2cm/r2cm_ostream.h"

namespace std_numeric_test
{
	r2cm::iItem::TitleFunctionT Accumulate_Number::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::accumulate : Number";
		};
	}
	r2cm::iItem::DoFunctionT Accumulate_Number::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << "# Sum" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

				const int sum = std::accumulate( v.begin(), v.end(), 0 );

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const int sum = std::accumulate( v.begin(), v.end(), 0 );" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2 << sum << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "# Minus" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::vector<int> v{ 5, 10, 25 };

				const int result = std::accumulate( v.begin(), v.end(), 100, std::minus<int>() );

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::vector<int> v{ 5, 10, 25 };" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const int product = std::accumulate( v.begin(), v.end(), 100, std::minus<int>() );" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2 << result << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "# Multiply" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::vector<int> v{ 2, 10, 4 };

				const int result = std::accumulate( v.begin(), v.end(), 2, std::multiplies<int>() );

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::vector<int> v{ 2, 10, 4 };" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const int product = std::accumulate( v.begin(), v.end(), 2, std::multiplies<int>() );" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2 << result << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Accumulate_String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::accumulate : String";
		};
	}
	r2cm::iItem::DoFunctionT Accumulate_String::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			// Copy from https://en.cppreference.com/w/cpp/algorithm/accumulate

			std::vector<int> v{ 1, 2, 3, 4, 5 };

			auto modifier = []( std::string a, int b )
			{
				return std::move( a ) + '-' + std::to_string( b );
			};

			std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5 };" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "auto modifier = []( std::string a, int b )" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "return std::move( a ) + '-' + std::to_string( b );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
			std::cout << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				const std::string s = std::accumulate(
					std::next( v.begin() ), v.end()
					, std::to_string( v[0] ) // start with first element
					, modifier
				);

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const std::string s = std::accumulate(" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "std::next( v.begin() ), v.end()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << ", std::to_string( v[0] )" << r2cm::linefeed;
				std::cout << r2cm::tab3 << ", modifier" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ");" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2 << s << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const std::string rs = std::accumulate(
					std::next( v.rbegin() ), v.rend()
					, std::to_string( v.back() )
					, modifier
				);

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "const std::string rs = std::accumulate(" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "std::next( v.rbegin() ), v.rend()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << ", , std::to_string( v.back() )" << r2cm::linefeed;
				std::cout << r2cm::tab3 << ", modifier" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ");" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2 << rs << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Partial_Sum::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Partial_Sum";
		};
	}
	r2cm::iItem::DoFunctionT Partial_Sum::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				// Copy from https://en.cppreference.com/w/cpp/algorithm/partial_sum

				std::vector<int> v{ 1, 2, 3, 4, 5 };

				std::partial_sum( v.begin(), v.end(), v.begin(), std::plus<int>() );

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5 };" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::partial_sum( v.begin(), v.end(), v.begin(), std::plus<int>() );" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2;
				for( const auto& i : v )
				{
					std::cout << i << r2cm::tab;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				// Copy from https://en.cppreference.com/w/cpp/algorithm/partial_sum

				std::vector<int> v{ 1, 2, 3, 4, 5 };

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::vector<int> v{ 1, 2, 3, 4, 5 };" << r2cm::linefeed;
				std::cout << r2cm::linefeed;


				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::partial_sum(" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "v.begin(), v.end()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << ", std::ostream_iterator<int>( std::cout, \"-\" )" << r2cm::linefeed;
				std::cout << r2cm::tab3 << ", std::multiplies<int>()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ");" << r2cm::linefeed;
				std::cout << r2cm::linefeed;


				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2;

				std::partial_sum(
					v.begin(), v.end()
					, std::ostream_iterator<int>( std::cout, "-" )
					, std::multiplies<int>()
				);

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT FillSequenceNumber::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Fill Sequence Number In Container";
		};
	}
	r2cm::iItem::DoFunctionT FillSequenceNumber::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::list<int> temp_list( 10, 0 );

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::list<int> temp_list( 10, 0 );" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::iota( temp_list.begin(), temp_list.end(), 11 ); // fill : 0, 1, 2, 3, 4 ......

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::iota( temp_list.begin(), temp_list.end(), 11 )" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				std::cout << r2cm::tab2;
				for( auto i : temp_list )
				{
					std::cout << i << r2cm::tab;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}