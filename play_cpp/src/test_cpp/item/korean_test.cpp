#include "korean_test.h"

#include <locale>

#include "r2cm/r2cm_ostream.h"

namespace korean_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Korean : Basic";
		};
	}

	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ use std::cout" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ const char* korean = \"한글 출력\";" << r2cm::linefeed;
				const char* korean = "한글 출력";

				std::cout << r2cm::tab2 << "- " << korean << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ use std::wcout" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ const wchar_t* korean = L\"한글 출력\";" << r2cm::linefeed;
				const wchar_t* korean = L"한글 출력";

				std::cout << r2cm::tab << "+ std::wcout.imbue( std::locale( \"kor\" ) );" << r2cm::linefeed;
				std::wcout.imbue( std::locale( "kor" ) );

				std::wcout << r2cm::tab2 << "- " << korean << r2cm::linefeed2;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}