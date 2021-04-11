#include "korean_test.h"

#include <iostream>
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
			std::cout << "== Korean ==" << std::endl << std::endl;

			{
				std::cout << "\t" << "+ const char* korean = \"한글 출력\";" << std::endl;
				const char* korean = "한글 출력";

				std::cout << "\t\t" << "- " << korean << std::endl << std::endl;

				std::cout << "\t" << "+ use std::cout" << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl;

			{
				std::cout << "\t" << "+ const wchar_t* korean = L\"한글 출력\";" << std::endl;
				const wchar_t* korean = L"한글 출력";

				std::cout << "\t" << "+ std::wcout.imbue( std::locale( \"kor\" ) );" << std::endl;
				std::wcout.imbue( std::locale( "kor" ) );

				std::wcout << "\t\t" << "- " << korean << std::endl << std::endl;

				std::cout << "\t" << "+ use std::wcout" << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}
}