#include "pch.h"
#include "korean_test.h"

#include <locale>

#include "r2_eTestResult.h"

namespace korean_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Korean : Basic";
		};
	}

	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# Korean #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ const char* korean = \"한글 출력\";" << r2::linefeed;
				const char* korean = "한글 출력";

				std::cout << "\t\t" << "- " << korean << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ use std::cout" << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ const wchar_t* korean = L\"한글 출력\";" << r2::linefeed;
				const wchar_t* korean = L"한글 출력";

				std::cout << "\t" << "+ std::wcout.imbue( std::locale( \"kor\" ) );" << r2::linefeed;
				std::wcout.imbue( std::locale( "kor" ) );

				std::wcout << "\t\t" << "- " << korean << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ use std::wcout" << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}