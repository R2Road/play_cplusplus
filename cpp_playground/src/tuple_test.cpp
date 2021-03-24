#include "tuple_test.h"

#include <iostream>
#include <string>
#include <tuple>


namespace tuple_test
{
	void Basic::Do()
	{
		std::cout << "== Tuple : Basic ==" << std::endl;


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::variant<int, std::string, bool> v;" << std::endl;
			std::tuple<int, std::string, bool> v;

			std::cout << "\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<0>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<1>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<1>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<2>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<2>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ auto v = std::make_tuple( 10, ""Kim"", true );" << std::endl;
			auto v = std::make_tuple( 10, "Kim", true );

			std::cout << "\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<0>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<1>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<1>( v ) << std::endl;

			std::cout << "\t\t- Call : std::get<2>( v );" << std::endl;
			std::cout << "\t\t\t" << std::get<2>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;
	}
}