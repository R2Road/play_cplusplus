#include "pch.h"
#include "korean_test.h"

#include <locale>

#include "r2cm/r2cm_eTestEndAction.h"

namespace korean_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Korean : Basic";
		};
	}

	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}
}