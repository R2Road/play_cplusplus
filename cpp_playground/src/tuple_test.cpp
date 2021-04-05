#include "tuple_test.h"

#include <iostream>
#include <string>
#include <tuple>

namespace tuple_test
{
	r2::eTestResult Basic::Do()
	{
		std::cout << "== Tuple : Basic ==" << std::endl;


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::tuple<int, std::string, char> v;" << std::endl;
			std::tuple<int, std::string, char> v;

			std::cout << "\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<0>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<1>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<1>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<2>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<2>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::tuple<int, std::string, bool> v{ 2, \"park\", 'b' };" << std::endl;
			std::tuple<int, std::string, char> v{ 2, "park", 'b' };

			std::cout << "\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<0>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<1>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<1>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<2>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<2>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ auto v = std::make_tuple( 10, \"Kim\", 'c' );" << std::endl;
			auto v = std::make_tuple( 10, "Kim", 'c' );

			std::cout << "\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<0>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<1>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<1>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<2>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<2>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;

		return r2::eTestResult::RunTest;
	}
}