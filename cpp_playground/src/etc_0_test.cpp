#include "pch.h"
#include "etc_0_test.h"

#include "r2_eTestResult.h"

namespace etc_test
{
	r2::iTest::TitleFunc XOR_Swap::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XOR Swap";
		};
	}
	r2::iTest::DoFunc XOR_Swap::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int a = 123;
				int b = 456;

				std::cout << "\t" << "int a = 123;" << r2::linefeed;
				std::cout << "\t" << "int b = 456;" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				a = a ^ b;
				std::cout << "\t" << "a = a ^ b;" << r2::linefeed;
				std::cout << "\t\t" << "a : " << a << r2::linefeed;
				std::cout << r2::linefeed;

				b = b ^ a;
				std::cout << "\t" << "b = b ^ a;" << r2::linefeed;
				std::cout << "\t\t" << "b : " << b << r2::linefeed;
				std::cout << r2::linefeed;

				a = a ^ b;
				std::cout << "\t" << "a = a ^ b;" << r2::linefeed;
				std::cout << "\t\t" << "a : " << a << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}

namespace etc_test
{
	r2::iTest::TitleFunc InitArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Init Array";
		};
	}
	r2::iTest::DoFunc InitArray::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int array[10];
				std::cout << "\t\t" << "int array[10];" << r2::linefeed;

				std::cout << "\t\t" << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int array[10] = { 0, };
				std::cout << "\t\t" << "int array[10] = { 0, };" << r2::linefeed;

				std::cout << "\t\t" << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int array[10] = { '\0', };
				std::cout << "\t\t" << "int array[10] = { \'\\0\', };" << r2::linefeed;

				std::cout << "\t\t" << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int array[10] = {};
				std::cout << "\t\t" << "int array[10] = {};" << r2::linefeed;

				std::cout << "\t\t" << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}