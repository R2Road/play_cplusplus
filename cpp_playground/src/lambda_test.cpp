#include "pch.h"
#include "lambda_test.h"

#include <cassert>
#include <functional>

#include "r2_eTestResult.h"

namespace lambda_test
{
	const r2::iNode::TitleFunc Capture::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lamabda : Basic";
		};
	}

	const r2::iNode::DoFunc Capture::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "REF Capture" << r2::linefeed << r2::linefeed;

				int i = 0;
				std::cout << "\t\t" << "int i = 0;" << r2::linefeed << r2::linefeed;

				const std::function<void()> test_func = [ &temp_int = i]()
				{
					++temp_int;
				};
				std::cout << "\t\t" << "const std::function<void()> test_func = [&temp_int = i]()" << r2::linefeed;
				std::cout << "\t\t\t" << "++temp_int;" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				std::cout << "\t\t" << "- Call Lambda" << r2::linefeed;
				test_func();
				std::cout << r2::linefeed;

				std::cout << "\t\t" << "- Print : i" << r2::linefeed;
				std::cout << "\t\t\t" << i << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}