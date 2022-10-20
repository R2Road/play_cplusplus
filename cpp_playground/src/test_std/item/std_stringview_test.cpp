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

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Literal_Operator_sv::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Literal Operator \"\"sv";
		};
	}
	r2cm::iItem::DoFunctionT Literal_Operator_sv::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::string_view 는 특별한 literal operator 를 가지고 있다." << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- constexpr string_view operator \"\" sv(const char *_Str, size_t _Len) noexcept" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- \"\" sv 는 constexpr string_view 를 만들어준다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto view = "String View Test_4"sv );
				OUTPUT_VALUE( view );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Utility::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Utility";
		};
	}
	r2cm::iItem::DoFunctionT Utility::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto view = "String View Test_5"sv );
				PROCESS_MAIN( view.remove_prefix( 3u ) );
				OUTPUT_VALUE( view );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto view = "String View Test_6"sv );
				PROCESS_MAIN( view.remove_suffix( 4u ) );
				OUTPUT_VALUE( view );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto view_1 = "String View Test_7"sv );

				std::cout << r2cm::linefeed2;

				DECLARATION_MAIN( auto view_2 = view_1.substr( 12u, 16u ) );
				OUTPUT_VALUE( view_2 );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ 복사를 요청한 구간의 끝이 원본 문자열의 최대 길이를 넘어서도 문제 없다." << r2cm::linefeed;
				DECLARATION_MAIN( auto view_22 = view_1.substr( 12u, 20u ) );
				OUTPUT_VALUE( view_22 );

				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ string_view 의 size 를 offset 으로 지정해도 문제가 없다. 왜???" << r2cm::linefeed;
				std::cout << r2cm::tab << "- offset 검사 코드를 보면 if (_Mysize < _Off) 조건으로 되어있다. 왜???" << r2cm::linefeed;
				DECLARATION_MAIN( auto view_3 = view_2.substr( view_2.size(), 6u ) );
				OUTPUT_VALUE( view_3 );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ string_view 에 할당된 범위를 넘어선 지역에 sub_str 을 시도하면 문제가 생긴다." << r2cm::linefeed;
				OUTPUT_CODE( auto view_33 = view_2.substr( view_2.size() + 1, 6u ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ 복사를 요청한 구간의 시작점이 원본 문자열의 범위를 넘어서면 문제가 생긴다." << r2cm::linefeed;
				OUTPUT_CODE( auto view_4 = view_1.substr( view_1.size() + 1, 6u ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}