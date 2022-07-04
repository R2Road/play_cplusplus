#include "char_test.h"

#include <conio.h>

#include <locale>
#include <string>

#include "r2cm/r2cm_constant.h"

namespace char_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

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
	r2cm::iItem::DoFunctionT Encoding::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

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