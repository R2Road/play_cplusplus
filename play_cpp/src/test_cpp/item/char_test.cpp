#include "char_test.h"

#include <conio.h>

#include <locale>
#include <string>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace char_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Print Chars" << r2tm::linefeed << r2tm::linefeed;

				for( char c = 0; 126 >= c; ++c )
				{
					std::cout << c;
				}

				std::cout << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Sound" << r2tm::linefeed;

				std::cout << (char)7;
				std::cout << r2tm::tab2 << "- std::cout << (char)7;" << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



//
// https://en.cppreference.com/w/cpp/language/string_literal
// https://en.cppreference.com/w/cpp/locale/codecvt/out
//
namespace char_test
{
	r2tm::TitleFunctionT Encoding::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Encoding";
		};
	}
	r2tm::DoFunctionT Encoding::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ char 2 wchar_t" << r2tm::linefeed << r2tm::linefeed;

				const std::wstring internal = L"z\u00df\u6c34\U0001f34c";

				std::locale::global( std::locale( "en_US.utf8" ) );
				auto& f = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>( std::locale() );

				// note that the following can be done with wstring_convert
				std::mbstate_t mb{}; // initial shift state
				std::string external( internal.size() * f.max_length(), '\0' );
				const wchar_t* from_next;
				char* to_next;
				f.out(
					mb
					, &internal[0], &internal[internal.size()], from_next,
					&external[0], &external[external.size()], to_next
				);

				// error checking skipped for brevity
				external.resize( to_next - &external[0] );

				std::cout << "The string in narrow multibyte encoding: " << external << '\n';
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace char_test
{
	r2tm::TitleFunctionT RawStringLiteral::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Raw-String-Literal";
		};
	}
	r2tm::DoFunctionT RawStringLiteral::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const char* str = R"(Test)" );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( std::cout << str << r2tm::linefeed );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "escape 문자들이 무시되고 입력된 그대로 출력된다." );

				std::cout << r2tm::linefeed;

				const char* str = R"(Test
Test \n
Test \t )";

				std::cout << str << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "Delimeter는 따옴표 사용이 문제가 되는 경우( www 주소를 다룬다거나 )에..." );
				OUTPUT_NOTE( "명확하게 구분지어 주기 위해 사용한다." );
				OUTPUT_NOTE( "앞 뒤 같은 문자열로 맞춰주면 된다." );
				OUTPUT_NOTE( "최대 16자." );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const char* str = R"delimeter(Embedded)" pre)delimeter" );

				PROCESS_MAIN( std::cout << str << r2tm::linefeed );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}