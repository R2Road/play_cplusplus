#include "pch.h"
#include "locale_test.h"

#include <conio.h>
#include <locale>

#include "r2_eTestResult.h"

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
				setlocale( LC_ALL, "" );
				std::cout << "LC_ALL: " << setlocale( LC_ALL, NULL ) << r2::linefeed;
				std::cout << "LC_CTYPE: " << setlocale( LC_CTYPE, NULL ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::locale l( "" );
				std::wcout << "Locale Name : " << l.name().c_str() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}