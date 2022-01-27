#include "pch.h"
#include "c_random_test.h"

#include <cstdlib>

#include "base/r2_eTestResult.h"


namespace c_random_test
{
	r2::iTest::TitleFunc Rand::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Rand : Basic";
		};
	}
	r2::iTest::DoFunc Rand::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2::tab2 << "rand() : " << rand() << r2::linefeed;
				}

				std::cout << r2::linefeed;
				std::cout << r2::tab << "# Message : Same Value Printed When Every Single Execute" << r2::linefeed;
				std::cout << r2::tab << "# Message : ���α׷� ���� �⵿�ص� rand() �� ��ȯ�ϴ� ���� ������ ����." << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}