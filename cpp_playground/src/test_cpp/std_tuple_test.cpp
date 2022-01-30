#include "pch.h"
#include "std_tuple_test.h"

#include <string>
#include <tuple>

#include "base/r2_eTestResult.h"

namespace std_tuple_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Tuple : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;


			std::cout << r2::split;


			{
				std::cout << r2::tab << "+ std::tuple<int, std::string, char> v;" << r2::linefeed;
				std::tuple<int, std::string, char> v;

				std::cout << r2::tab2 << "- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<0>( v ) << r2::linefeed;

				std::cout << r2::tab2 << "- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<1>( v ) << r2::linefeed;

				std::cout << r2::tab2 << "- Call : std::get<2>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<2>( v ) << r2::linefeed;
			}


			std::cout << r2::split;


			{
				std::cout << r2::tab << "+ std::tuple<int, std::string, bool> v{ 2, \"park\", 'b' };" << r2::linefeed;
				std::tuple<int, std::string, char> v{ 2, "park", 'b' };

				std::cout << r2::tab2  << "- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<0>( v ) << r2::linefeed;

				std::cout << r2::tab2 << "- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<1>( v ) << r2::linefeed;

				std::cout << r2::tab2 << "- Call : std::get<2>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<2>( v ) << r2::linefeed;
			}


			std::cout << r2::split;


			{
				std::cout << r2::tab << "+ auto v = std::make_tuple( 10, \"Kim\", 'c' );" << r2::linefeed;
				auto v = std::make_tuple( 10, "Kim", 'c' );

				std::cout << r2::tab2 << "- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<0>( v ) << r2::linefeed;

				std::cout << r2::tab2 << "- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<1>( v ) << r2::linefeed;

				std::cout << r2::tab2 << "- Call : std::get<2>( v );" << r2::linefeed;
				std::cout << r2::tab3 << std::get<2>( v ) << r2::linefeed;
			}


			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}