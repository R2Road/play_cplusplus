#include "string_view_test.h"

#include <iostream>
#include <string_view>

namespace stringview_test
{
	void Basic::Do()
	{
		std::cout << "== StringView ==" << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string_view sv = ""String View Test"";" << std::endl << std::endl;
			std::string_view sv = "String View Test";

			std::cout << "\t\t - Print : " << sv << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}