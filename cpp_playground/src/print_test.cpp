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
				std::cout << "\t" << "+ Show Number : Use std::cout" << r2::linefeed << r2::linefeed;

				int i = 0xde81;

				std::cout << "\t" << "int i = 0xde81;" << r2::linefeed;

				std::cout << "\t\t" << "Print( 8 : oct ) : " << std::oct << i << r2::linefeed;
				std::cout << "\t\t" << "Print( 10 : dec ) : " << std::dec << i << r2::linefeed;
				std::cout << "\t\t" << "Print( 16 : hex ) : " << std::hex << i << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Show Number : Use printf" << r2::linefeed << r2::linefeed;

				int i = 0xde81;

				std::cout << "\t" << "int i = 0xde81;" << r2::linefeed;

				printf( "\t\tPrint( 8 : oct ) : %o\n", i );
				printf( "\t\tPrint( 10 : dec ) : %d\n", i );
				printf( "\t\tPrint( 16 : hex ) : %x\n", i );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}