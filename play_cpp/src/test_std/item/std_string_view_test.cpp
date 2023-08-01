#include "std_string_view_test.h"

#include <string>
#include <string_view>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

using namespace std::string_view_literals; // for sv

namespace std_string_view_test
{
	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "인자 없는 생성자" );

				LF();

				DECLARATION_MAIN( const std::string_view view );
				EXPECT_TRUE( view.empty() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "인자 있는 생성자 : 공백 문자열" );

				LF();

				DECLARATION_MAIN( const std::string_view view = "" );
				EXPECT_TRUE( view.empty() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "인자 있는 생성자" );
				
				LF();

				DECLARATION_MAIN( const std::string_view view = "String View Test_1" );
				OUTPUT_VALUE( view );
			}

			LS();

			{
				OUTPUT_SUBJECT( "std::string을 인자로 받는 생성자" );

				LF();

				DECLARATION_MAIN( const std::string str = "String View Test_2" );
				DECLARATION_MAIN( const std::string_view view = str );
				OUTPUT_VALUE( view );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Iteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Iteration";
		};
	}
	r2tm::DoFunctionT Iteration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const std::string_view view = "test 3" );

			LS();

			{
				PROCESS_MAIN( for( const auto& c : view ) { OUTPUT_VALUE( c ); } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Literal_Operator_sv::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Literal Operator \"\"sv";
		};
	}
	r2tm::DoFunctionT Literal_Operator_sv::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ std::string_view 는 특별한 literal operator 를 가지고 있다." << r2tm::linefeed2;
				std::cout << r2tm::tab << "> constexpr string_view operator \"\" sv(const char *_Str, size_t _Len) noexcept" << r2tm::linefeed;
				std::cout << r2tm::tab << "> \"\" sv 는 constexpr string_view 를 만들어준다." << r2tm::linefeed;
			}

			LS();

			{
				DECLARATION_MAIN( auto view = "String View Test_4"sv );
				OUTPUT_VALUE( view );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Remove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : Remove";
		};
	}
	r2tm::DoFunctionT Remove::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( auto view = "String View Test_12345"sv );
			OUTPUT_VALUE( view );

			LS();

			{
				PROCESS_MAIN( view.remove_prefix( 3u ) );
				OUTPUT_VALUE( view );
			}

			LS();

			{
				PROCESS_MAIN( view.remove_suffix( 4u ) );
				OUTPUT_VALUE( view );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT SubStr::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "StringView : SubStr";
		};
	}
	r2tm::DoFunctionT SubStr::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( auto view = "String View Test_7"sv );

			LS();

			{
				DECLARATION_MAIN( const auto other_view = view.substr( 12u, 16u ) );
				OUTPUT_VALUE( other_view );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ 복사를 요청한 구간의 끝이 원본 문자열의 최대 길이를 넘어서도 문제 없다." << r2tm::linefeed2;
				DECLARATION_MAIN( const auto other_view = view.substr( 12u, 20u ) );
				OUTPUT_VALUE( other_view );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ string_view 의 size 를 offset 으로 지정해도 문제가 없다. 왜???" << r2tm::linefeed;
				std::cout << r2tm::tab << "- offset 검사 코드를 보면 if (_Mysize < _Off) 조건으로 되어있다. 왜???" << r2tm::linefeed2;
				DECLARATION_MAIN( const auto other_view = view.substr( view.size(), 6u ) );
				OUTPUT_VALUE( other_view );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ string_view 에 할당된 범위를 넘어선 지역에 sub_str 을 시도하면 문제가 생긴다." << r2tm::linefeed2;
				OUTPUT_CODE( const auto other_view = view.substr( view + 1, 6u ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ 복사를 요청한 구간의 시작점이 원본 문자열의 범위를 넘어서면 문제가 생긴다." << r2tm::linefeed2;
				OUTPUT_CODE( const auto other_view = view.substr( view.size() + 1, 6u ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}