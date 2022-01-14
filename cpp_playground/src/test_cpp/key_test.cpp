#include "pch.h"
#include "key_test.h"

#include <conio.h>

#include "base/r2_eTestResult.h"

namespace key_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

			bool process = true;
			int input = 0;
			while( process )
			{
				input = _getch();

				std::cout << "Key : " << input << r2::linefeed;

				if( 27 == input )
				{
					process = false;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}