#include "std_string_view_test.h"

#include <string>
#include <string_view>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

using namespace std::string_view_literals; // for sv

namespace std_string_view_test
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
				std::cout << r2cm::tab << "+ std::string_view �� Ư���� literal operator �� ������ �ִ�." << r2cm::linefeed2;
				std::cout << r2cm::tab << "> constexpr string_view operator \"\" sv(const char *_Str, size_t _Len) noexcept" << r2cm::linefeed;
				std::cout << r2cm::tab << "> \"\" sv �� constexpr string_view �� ������ش�." << r2cm::linefeed;
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



	r2cm::iItem::TitleFunctionT Remove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Remove";
		};
	}
	r2cm::iItem::DoFunctionT Remove::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( auto view = "String View Test_12345"sv );
			OUTPUT_VALUE( view );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( view.remove_prefix( 3u ) );
				OUTPUT_VALUE( view );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( view.remove_suffix( 4u ) );
				OUTPUT_VALUE( view );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT SubStr::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : SubStr";
		};
	}
	r2cm::iItem::DoFunctionT SubStr::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( auto view = "String View Test_7"sv );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto other_view = view.substr( 12u, 16u ) );
				OUTPUT_VALUE( other_view );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ ���縦 ��û�� ������ ���� ���� ���ڿ��� �ִ� ���̸� �Ѿ�� ���� ����." << r2cm::linefeed2;
				DECLARATION_MAIN( const auto other_view = view.substr( 12u, 20u ) );
				OUTPUT_VALUE( other_view );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ string_view �� size �� offset ���� �����ص� ������ ����. ��???" << r2cm::linefeed;
				std::cout << r2cm::tab << "- offset �˻� �ڵ带 ���� if (_Mysize < _Off) �������� �Ǿ��ִ�. ��???" << r2cm::linefeed2;
				DECLARATION_MAIN( const auto other_view = view.substr( view.size(), 6u ) );
				OUTPUT_VALUE( other_view );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ string_view �� �Ҵ�� ������ �Ѿ ������ sub_str �� �õ��ϸ� ������ �����." << r2cm::linefeed2;
				OUTPUT_CODE( const auto other_view = view.substr( view + 1, 6u ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ ���縦 ��û�� ������ �������� ���� ���ڿ��� ������ �Ѿ�� ������ �����." << r2cm::linefeed2;
				OUTPUT_CODE( const auto other_view = view.substr( view.size() + 1, 6u ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}