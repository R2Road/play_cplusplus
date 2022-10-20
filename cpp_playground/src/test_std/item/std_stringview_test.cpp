#include "std_stringview_test.h"

#include <string>
#include <string_view>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

using namespace std::string_view_literals; // for sv

namespace std_stringview_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string_view view );
				EXPECT_TRUE( view.empty() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string_view view = "" );
				EXPECT_TRUE( view.empty() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string_view view = "String View Test_1" );
				OUTPUT_VALUE( view );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string str = "String View Test_2" );
				DECLARATION_MAIN( const std::string_view view = str );
				OUTPUT_VALUE( view );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string_view view = "test 3" );

				std::cout << r2cm::tab << "- Enable Ranged For" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- for( const auto c : view )" << r2cm::linefeed;
				for( const auto c : view )
				{
					std::cout << r2cm::tab3 << c << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ auto view = \"String View Test_4\"sv;" << r2cm::linefeed2;
				auto view = "String View Test_4"sv;

				std::cout << r2cm::tab2 << "- Has Literal \"sv\"" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- \"sv\" make constexpr string_view" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Print : " << view << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ auto view = \"String View Test_5\"sv;" << r2cm::linefeed2;
				auto view = "String View Test_5"sv;

				std::cout << r2cm::tab2 << "- view.remove_prefix( 3u );" << r2cm::linefeed;
				view.remove_prefix( 3u );

				std::cout << r2cm::tab3 << "- Print : " << view << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ auto view = \"String View Test_6\"sv;" << r2cm::linefeed2;
				auto view = "String View Test_6"sv;

				std::cout << r2cm::tab2 << "- view.remove_suffix( 4u );" << r2cm::linefeed;
				view.remove_suffix( 4u );

				std::cout << r2cm::tab3 << "- Print : " << view << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ auto view = \"String View Test_7\"sv;" << r2cm::linefeed;
				auto view = "String View Test_7"sv;

				std::cout << r2cm::tab << "+ auto view2 = view.substr( 7u, 4u );" << r2cm::linefeed;
				auto view_2 = view.substr( 12u, 6u );

				std::cout << r2cm::tab2 << "- Print : " << view_2 << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}