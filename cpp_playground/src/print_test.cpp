#include "pch.h"
#include "print_test.h"

#include <iostream>

#include "r2_eTestResult.h"

namespace print_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print : Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int i = 0xde81;

				std::cout << "\t" << "int i = 0xde81;" << r2::linefeed;

				std::cout << "\t\t" << "Print( 8 : oct ) : " << std::oct << i << r2::linefeed;
				std::cout << "\t\t" << "Print( 10 : dec ) : " << std::dec << i << r2::linefeed;
				std::cout << "\t\t" << "Print( 16 : hex ) : " << std::hex << i << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}