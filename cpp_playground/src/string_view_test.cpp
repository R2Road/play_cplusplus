#include "string_view_test.h"

#include <iostream>
#include <string>
#include <string_view>

using namespace std::string_view_literals; // for sv

namespace stringview_test
{
	void Basic::Do()
	{
		std::cout << "== StringView ==" << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string_view view = \"String View Test_1\";" << std::endl << std::endl;
			std::string_view view = "String View Test_1";

			std::cout << "\t\t - Print : " << view << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string str = \"String View Test_2\";" << std::endl;
			std::cout << "\t" << "+ std::string_view view = str;" << std::endl << std::endl;
			std::string str = "String View Test_2";
			std::string_view view = str;

			std::cout << "\t\t - Print : " << view << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ std::string_view view = \"test 3\";" << std::endl;
			std::string_view view = "test 3";

			std::cout << "\t\t - Enable Ranged For" << std::endl;
			std::cout << "\t\t\t - for( const auto c : view )" << std::endl;
			for( const auto c : view )
			{
				std::cout << "\t\t\t\t" << c << std::endl;
			}
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ auto view = \"String View Test_4\"sv;" << std::endl << std::endl;
			auto view = "String View Test_4"sv;

			std::cout << "\t\t - Has Literal \"sv\"" << std::endl;
			std::cout << "\t\t - \"sv\" make constexpr string_view" << std::endl;
			std::cout << "\t\t\t - Print : " << view << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ auto view = \"String View Test_5\"sv;" << std::endl << std::endl;
			auto view = "String View Test_5"sv;

			std::cout << "\t\t - view.remove_prefix( 3u );" << std::endl;
			view.remove_prefix( 3u );

			std::cout << "\t\t\t - Print : " << view << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ auto view = \"String View Test_6\"sv;" << std::endl << std::endl;
			auto view = "String View Test_6"sv;

			std::cout << "\t\t - view.remove_suffix( 4u );" << std::endl;
			view.remove_suffix( 4u );

			std::cout << "\t\t\t - Print : " << view << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ auto view = \"String View Test_7\"sv;" << std::endl;
			auto view = "String View Test_7"sv;

			std::cout << "\t+ auto view2 = view.substr( 7u, 4u );" << std::endl;
			auto view_2 = view.substr( 12u, 6u );

			std::cout << "\t\t - Print : " << view_2 << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}