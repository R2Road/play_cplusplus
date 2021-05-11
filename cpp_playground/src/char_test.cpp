#include "pch.h"
#include "char_test.h"

#include <conio.h>
#include <iostream>

#include "r2_eTestResult.h"

namespace char_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Print Chars" << r2::linefeed << r2::linefeed;

				for( char c = 0; 126 >= c; ++c )
				{
					std::cout << c;
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Sound" << r2::linefeed;

				std::cout << (char)7;
				std::cout << "\t\t" << "- std::cout << (char)7;" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}