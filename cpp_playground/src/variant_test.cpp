#include "variant_test.h"

#include <iostream>
#include <variant>


namespace variant_test
{
	void Basic::Do()
	{
		std::cout << "== Variant : Basic ==" << std::endl;


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::variant<int, float, bool> v;" << std::endl;
			std::variant<int, float, bool> v;

			std::cout << "\t\t- Default Type is First T : int : index 0" << std::endl;

			std::cout << "\t\t- Check T Index" << std::endl;
			std::cout << "\t\t\t- Call : v.index();" << std::endl;
			std::cout << "\t\t\t\t" << v.index() << std::endl;

			std::cout << "\t\t- Get Value" << std::endl;
			std::cout << "\t\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t\t" << std::get<0>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::variant<int, int> v;" << std::endl;

			std::variant<int, int> v;
			std::cout << "\t\t- Has Problem Using Same Type" << std::endl << std::endl;
			std::cout << "\t\t- Not Working : v = 1;" << std::endl << std::endl;
			//
			//v = 1;
			//
		}


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::variant<int, float> v;" << std::endl;

			std::variant<int, float> v;


			v = 1;
			std::cout << "\t\t- v = 1;" << std::endl;
			std::cout << "\t\t\t- Call : v.index();" << std::endl;
			std::cout << "\t\t\t\t" << v.index() << std::endl;
			
			
			v = 2.f;
			std::cout << "\t\t- v = 2.f;" << std::endl;
			std::cout << "\t\t\t- Call : v.index();" << std::endl;
			std::cout << "\t\t\t\t" << v.index() << std::endl;
		}
	}
}