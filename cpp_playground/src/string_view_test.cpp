#include "pch.h"
#include "string_view_test.h"

#include <string>
#include <string_view>

#include "r2_eTestResult.h"

using namespace std::string_view_literals; // for sv

namespace stringview_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== StringView ==" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ std::string_view view = \"String View Test_1\";" << r2::linefeed << r2::linefeed;
				std::string_view view = "String View Test_1";

				std::cout << "\t\t - Print : " << view << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ std::string str = \"String View Test_2\";" << r2::linefeed;
				std::cout << "\t" << "+ std::string_view view = str;" << r2::linefeed << r2::linefeed;
				std::string str = "String View Test_2";
				std::string_view view = str;

				std::cout << "\t\t - Print : " << view << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ std::string_view view = \"test 3\";" << r2::linefeed;
				std::string_view view = "test 3";

				std::cout << "\t\t - Enable Ranged For" << r2::linefeed;
				std::cout << "\t\t\t - for( const auto c : view )" << r2::linefeed;
				for( const auto c : view )
				{
					std::cout << "\t\t\t\t" << c << r2::linefeed;
				}
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ auto view = \"String View Test_4\"sv;" << r2::linefeed << r2::linefeed;
				auto view = "String View Test_4"sv;

				std::cout << "\t\t - Has Literal \"sv\"" << r2::linefeed;
				std::cout << "\t\t - \"sv\" make constexpr string_view" << r2::linefeed;
				std::cout << "\t\t\t - Print : " << view << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ auto view = \"String View Test_5\"sv;" << r2::linefeed << r2::linefeed;
				auto view = "String View Test_5"sv;

				std::cout << "\t\t - view.remove_prefix( 3u );" << r2::linefeed;
				view.remove_prefix( 3u );

				std::cout << "\t\t\t - Print : " << view << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ auto view = \"String View Test_6\"sv;" << r2::linefeed << r2::linefeed;
				auto view = "String View Test_6"sv;

				std::cout << "\t\t - view.remove_suffix( 4u );" << r2::linefeed;
				view.remove_suffix( 4u );

				std::cout << "\t\t\t - Print : " << view << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ auto view = \"String View Test_7\"sv;" << r2::linefeed;
				auto view = "String View Test_7"sv;

				std::cout << "\t+ auto view2 = view.substr( 7u, 4u );" << r2::linefeed;
				auto view_2 = view.substr( 12u, 6u );

				std::cout << "\t\t - Print : " << view_2 << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}