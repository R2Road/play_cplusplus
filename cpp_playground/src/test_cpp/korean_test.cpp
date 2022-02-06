#include "pch.h"
#include "korean_test.h"

#include <locale>

#include "base/r2_eTestResult.h"

namespace korean_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Korean : Basic";
		};
	}

	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ use std::cout" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ const char* korean = \"한글 출력\";" << r2::linefeed;
				const char* korean = "한글 출력";

				std::cout << r2::tab2 << "- " << korean << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ use std::wcout" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ const wchar_t* korean = L\"한글 출력\";" << r2::linefeed;
				const wchar_t* korean = L"한글 출력";

				std::cout << r2::tab << "+ std::wcout.imbue( std::locale( \"kor\" ) );" << r2::linefeed;
				std::wcout.imbue( std::locale( "kor" ) );

				std::wcout << r2::tab2 << "- " << korean << r2::linefeed2;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}