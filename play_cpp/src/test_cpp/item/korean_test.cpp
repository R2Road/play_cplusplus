#include "korean_test.h"

#include <locale>

#include "r2tm/r2tm_ostream.h"

namespace korean_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Korean : Basic";
		};
	}

	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ use std::cout" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ const char* korean = \"한글 출력\";" << r2tm::linefeed;
				const char* korean = "한글 출력";

				std::cout << r2tm::tab2 << "- " << korean << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ use std::wcout" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ const wchar_t* korean = L\"한글 출력\";" << r2tm::linefeed;
				const wchar_t* korean = L"한글 출력";

				std::cout << r2tm::tab << "+ std::wcout.imbue( std::locale( \"kor\" ) );" << r2tm::linefeed;
				std::wcout.imbue( std::locale( "kor" ) );

				std::wcout << r2tm::tab2 << "- " << korean << r2tm::linefeed2;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}