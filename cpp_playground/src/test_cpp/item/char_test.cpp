#include "char_test.h"

#include <conio.h>

#include <locale>
#include <string>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace char_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Print Chars" << r2cm::linefeed << r2cm::linefeed;

				for( char c = 0; 126 >= c; ++c )
				{
					std::cout << c;
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Sound" << r2cm::linefeed;

				std::cout << (char)7;
				std::cout << r2cm::tab2 << "- std::cout << (char)7;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



//
// https://en.cppreference.com/w/cpp/language/string_literal
// https://en.cppreference.com/w/cpp/locale/codecvt/out
//
namespace char_test
{
	r2cm::iItem::TitleFunctionT Encoding::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Encoding";
		};
	}
	r2cm::iItem::DoFunctionT Encoding::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ char 2 wchar_t" << r2cm::linefeed << r2cm::linefeed;

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

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace char_test
{
	r2cm::iItem::TitleFunctionT RawStringLiteral::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Raw-String-Literal";
		};
	}
	r2cm::iItem::DoFunctionT RawStringLiteral::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const char* str = R"(Test)" );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << str << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "escape ���ڵ��� ���õǰ� �Էµ� �״�� ��µȴ�." );

				std::cout << r2cm::linefeed;

				const char* str = R"(Test
Test \n
Test \t )";

				std::cout << str << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Delimeter�� ����ǥ ����� ������ �Ǵ� ���( www �ּҸ� �ٷ�ٰų� )��..." );
				OUTPUT_NOTE( "��Ȯ�ϰ� �������� �ֱ� ���� ����Ѵ�." );
				OUTPUT_NOTE( "�� �� ���� ���ڿ��� �����ָ� �ȴ�." );
				OUTPUT_NOTE( "�ִ� 16��." );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const char* str = R"delimeter(Embedded)" pre)delimeter" );

				PROCESS_MAIN( std::cout << str << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}