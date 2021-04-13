#include "pch.h"
#include "tuple_test.h"

#include <string>
#include <tuple>

#include "r2_eTestResult.h"

namespace tuple_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Tuple : Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# Tuple : Basic #" << r2::linefeed;


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ std::tuple<int, std::string, char> v;" << r2::linefeed;
				std::tuple<int, std::string, char> v;

				std::cout << "\t\t- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<0>( v ) << r2::linefeed;

				std::cout << "\t\t- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<1>( v ) << r2::linefeed;

				std::cout << "\t\t- Call : std::get<2>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<2>( v ) << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ std::tuple<int, std::string, bool> v{ 2, \"park\", 'b' };" << r2::linefeed;
				std::tuple<int, std::string, char> v{ 2, "park", 'b' };

				std::cout << "\t\t- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<0>( v ) << r2::linefeed;

				std::cout << "\t\t- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<1>( v ) << r2::linefeed;

				std::cout << "\t\t- Call : std::get<2>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<2>( v ) << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ auto v = std::make_tuple( 10, \"Kim\", 'c' );" << r2::linefeed;
				auto v = std::make_tuple( 10, "Kim", 'c' );

				std::cout << "\t\t- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<0>( v ) << r2::linefeed;

				std::cout << "\t\t- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<1>( v ) << r2::linefeed;

				std::cout << "\t\t- Call : std::get<2>( v );" << r2::linefeed;
				std::cout << "\t\t\t" << std::get<2>( v ) << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}