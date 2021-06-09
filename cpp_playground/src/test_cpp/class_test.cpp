#include "pch.h"
#include "class_test.h"

#include <iterator>
#include <numeric>
#include <string>

#include "base/r2_eTestResult.h"

namespace class_test
{
	r2::iTest::TitleFunc Braces::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Braces";
		};
	}
	r2::iTest::DoFunc Braces::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				class TestClass1
				{
					int a;
					int b;
				};

				std::cout << r2::tab << "+ Declaration" << r2::linefeed;

				std::cout << r2::tab2 << "class TestClass1" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "int a;" << r2::linefeed;
				std::cout << r2::tab3 << "int b;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed;


				//TestClass1 t1{ 1, 2 };

				std::cout << r2::tab << "+ Variable" << r2::linefeed;
				std::cout << r2::tab2 << "TestClass1 t1{ 1, 2 }; - Not Working" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}