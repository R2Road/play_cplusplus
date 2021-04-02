#include "string_view_test.h"

#include <iostream>
#include <string>
#include <string_view>

namespace stringview_test
{
	void Basic::Do()
	{
		std::cout << "== StringView ==" << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string_view sv = \"String View Test_1\";" << std::endl << std::endl;
			std::string_view sv = "String View Test_1";

			std::cout << "\t\t - Print" << std::endl;
			std::cout << "\t\t\t" << sv << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string s = \"String View Test_2\";" << std::endl;
			std::cout << "\t" << "+ std::string_view sv = s;" << std::endl << std::endl;
			std::string s = "String View Test_2";
			std::string_view sv = s;

			std::cout << "\t\t - Print" << std::endl;
			std::cout << "\t\t\t" << sv << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}