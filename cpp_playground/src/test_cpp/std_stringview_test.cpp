#include "pch.h"
#include "std_stringview_test.h"

#include <string>
#include <string_view>

#include "base/r2_eTestEndAction.h"

using namespace std::string_view_literals; // for sv

namespace std_stringview_test
{
	r2::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Basic";
		};
	}
	r2::iItem::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::string_view view = \"String View Test_1\";" << r2::linefeed2;
				std::string_view view = "String View Test_1";

				std::cout << r2::tab2 << "- Print : " << view << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::string str = \"String View Test_2\";" << r2::linefeed;
				std::cout << r2::tab << "+ std::string_view view = str;" << r2::linefeed2;
				std::string str = "String View Test_2";
				std::string_view view = str;

				std::cout << r2::tab2 << "- Print : " << view << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::string_view view = \"test 3\";" << r2::linefeed;
				std::string_view view = "test 3";

				std::cout << r2::tab2 << "- Enable Ranged For" << r2::linefeed;
				std::cout << r2::tab3 << "- for( const auto c : view )" << r2::linefeed;
				for( const auto c : view )
				{
					std::cout << r2::tab4 << c << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ auto view = \"String View Test_4\"sv;" << r2::linefeed2;
				auto view = "String View Test_4"sv;

				std::cout << r2::tab2 << "- Has Literal \"sv\"" << r2::linefeed;
				std::cout << r2::tab2 << "- \"sv\" make constexpr string_view" << r2::linefeed;
				std::cout << r2::tab3 << "- Print : " << view << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ auto view = \"String View Test_5\"sv;" << r2::linefeed2;
				auto view = "String View Test_5"sv;

				std::cout << r2::tab2 << "- view.remove_prefix( 3u );" << r2::linefeed;
				view.remove_prefix( 3u );

				std::cout << r2::tab3 << "- Print : " << view << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ auto view = \"String View Test_6\"sv;" << r2::linefeed2;
				auto view = "String View Test_6"sv;

				std::cout << r2::tab2 << "- view.remove_suffix( 4u );" << r2::linefeed;
				view.remove_suffix( 4u );

				std::cout << r2::tab3 << "- Print : " << view << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ auto view = \"String View Test_7\"sv;" << r2::linefeed;
				auto view = "String View Test_7"sv;

				std::cout << r2::tab << "+ auto view2 = view.substr( 7u, 4u );" << r2::linefeed;
				auto view_2 = view.substr( 12u, 6u );

				std::cout << r2::tab2 << "- Print : " << view_2 << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}