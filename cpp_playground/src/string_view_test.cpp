#include "string_view_test.h"

#include <iostream>
#include <string>
#include <string_view>

using namespace std::string_view_literals;

namespace stringview_test
{
	void Basic::Do()
	{
		std::cout << "== StringView ==" << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string_view view = \"String View Test_1\";" << std::endl << std::endl;
			std::string_view view = "String View Test_1";

			std::cout << "\t\t - Print" << std::endl;
			std::cout << "\t\t\t" << view << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string str = \"String View Test_2\";" << std::endl;
			std::cout << "\t" << "+ std::string_view view = str;" << std::endl << std::endl;
			std::string str = "String View Test_2";
			std::string_view view = str;

			std::cout << "\t\t - Print" << std::endl;
			std::cout << "\t\t\t" << view << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string_view view = \"String View Test_3\";" << std::endl;
			std::string_view view = "String View Test_3";

			std::cout << "\t\t - Enable Ranged For" << std::endl;
			std::cout << "\t\t\t - for( const auto c : view )" << std::endl;
			for( const auto c : view )
			{
				std::cout << "\t\t\t\t" << c << std::endl;
			}
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string_view view = \"String View Test_4\"sv;" << std::endl << std::endl;
			auto view = "String View Test_4"sv;

			std::cout << "\t\t - Has Literal \"sv\"" << std::endl;
			std::cout << "\t\t - \"sv\" make constexpr string_view" << std::endl;
			std::cout << "\t\t - Print" << std::endl;
			std::cout << "\t\t\t" << view << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}