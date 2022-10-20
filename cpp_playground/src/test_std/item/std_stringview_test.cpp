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
				std::cout << r2cm::tab << "+ std::string_view �� Ư���� literal operator �� ������ �ִ�." << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- constexpr string_view operator \"\" sv(const char *_Str, size_t _Len) noexcept" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- \"\" sv �� constexpr string_view �� ������ش�." << r2cm::linefeed;
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

				std::cout << r2cm::tab << "+ ���縦 ��û�� ������ ���� ���� ���ڿ��� �ִ� ���̸� �Ѿ�� ���� ����." << r2cm::linefeed;
				DECLARATION_MAIN( auto view_22 = view_1.substr( 12u, 20u ) );
				OUTPUT_VALUE( view_22 );

				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ string_view �� size �� offset ���� �����ص� ������ ����. ��???" << r2cm::linefeed;
				std::cout << r2cm::tab << "- offset �˻� �ڵ带 ���� if (_Mysize < _Off) �������� �Ǿ��ִ�. ��???" << r2cm::linefeed;
				DECLARATION_MAIN( auto view_3 = view_2.substr( view_2.size(), 6u ) );
				OUTPUT_VALUE( view_3 );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ string_view �� �Ҵ�� ������ �Ѿ ������ sub_str �� �õ��ϸ� ������ �����." << r2cm::linefeed;
				OUTPUT_CODE( auto view_33 = view_2.substr( view_2.size() + 1, 6u ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ ���縦 ��û�� ������ �������� ���� ���ڿ��� ������ �Ѿ�� ������ �����." << r2cm::linefeed;
				OUTPUT_CODE( auto view_4 = view_1.substr( view_1.size() + 1, 6u ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}