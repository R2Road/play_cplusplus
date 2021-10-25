#include "pch.h"
#include "locale_test.h"

#include <conio.h>
#include <locale>

#include "base/r2_eTestResult.h"

namespace locale_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Locale";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::locale l( \"\" );" << r2::linefeed2;

				std::locale l( "" );
				std::wcout << r2::tab2 << "Locale Name : " << l.name().c_str() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::locale l( \"en_US.utf8\" );" << r2::linefeed2;

				std::locale l( "en_US.utf8" );
				std::wcout << r2::tab2 << "Locale Name : " << l.name().c_str() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				const std::string old_locale = setlocale( LC_ALL, nullptr );

				std::cout << r2::tab << "+ Current Locale" << r2::linefeed2;
				std::cout << r2::tab2 << "const std::string old_locale = setlocale( LC_ALL, nullptr );" << r2::linefeed;
				std::cout << r2::tab2 << "- " << old_locale << r2::linefeed;
			}

			std::cout << r2::split;

			{
				setlocale( LC_ALL, "" );
				std::cout << "LC_ALL: " << setlocale( LC_ALL, NULL ) << r2::linefeed;
				std::cout << "LC_CTYPE: " << setlocale( LC_CTYPE, NULL ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}