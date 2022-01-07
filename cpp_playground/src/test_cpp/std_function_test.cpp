#include "pch.h"
#include "std_function_test.h"

#include <functional>

#include "base/r2_eTestResult.h"

namespace
{
	void TestFunction_1()
	{
		std::cout << "TestFunction_1";
	}
	void TestFunction_2()
	{
		std::cout << "TestFunction_2";
	}
}

namespace std_function_test
{
	r2::iTest::TitleFunc Equality::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality";
		};
	}
	r2::iTest::DoFunc Equality::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;


			using FunctionT = void(*)();
			using TestFunctionT = std::function<void()>;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "using FunctionT = void(*)();" << r2::linefeed;
			std::cout << r2::tab2 << "using TestFunctionT = std::function<void()>;" << r2::linefeed;


			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::function::target<T>()" << r2::linefeed2;

				TestFunctionT tf1 = TestFunction_1;
				auto fn_1 = tf1.target<void()>();
				auto fn_2 = tf1.target<void( *)( )>();

				std::cout << r2::tab2 << "TestFunctionT tf1 = TestFunction_1;" << r2::linefeed;
				std::cout << r2::tab2 << "auto fn_1 = tf1.target<void()>();" << r2::linefeed;
				std::cout << r2::tab2 << "auto fn_2 = tf1.target<void(*)()>();" << r2::linefeed2;

				std::cout << r2::tab2 << "nullptr == fn_1" << r2::linefeed;
				if( nullptr == fn_1 )
				{
					std::cout << r2::tab3 << "- Is Null" << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab3 << "- Is Not Null" << r2::linefeed;
				}

				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "nullptr == fn_2" << r2::linefeed;
				if( nullptr == fn_2 )
				{
					std::cout << r2::tab3 << "- Is Null" << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab3 << "- Is Not Null" << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Empty" << r2::linefeed2;

				TestFunctionT tf1;
				TestFunctionT tf2;

				std::cout << r2::tab2 << "TestFunctionT tf1;" << r2::linefeed;
				std::cout << r2::tab2 << "TestFunctionT tf2;" << r2::linefeed2;

				std::cout << r2::tab2 << "tf1.target<FunctionT>() == tf2.target<FunctionT>()" << r2::linefeed;
				if( tf1.target<TestFunctionT::result_type()>() == tf2.target<TestFunctionT::result_type()>() )
				{
					std::cout << r2::tab3 << "- Is Equal" << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab3 << "- Is Not Equal" << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Not Empty" << r2::linefeed2;

				TestFunctionT tf1 = TestFunction_1;
				TestFunctionT tf2 = TestFunction_1;
				TestFunctionT tf3 = TestFunction_2;

				std::cout << r2::tab2 << "TestFunctionT tf1 = TestFunction_1;" << r2::linefeed;
				std::cout << r2::tab2 << "TestFunctionT tf2 = TestFunction_1;" << r2::linefeed;
				std::cout << r2::tab2 << "TestFunctionT tf3 = TestFunction_2;" << r2::linefeed2;

				std::cout << r2::tab2 << "tf1.target<FunctionT>() == tf1.target<FunctionT>()" << r2::linefeed;
				if( tf1.target<FunctionT>() == tf1.target<FunctionT>() )
				{
					std::cout << r2::tab3 << "- Is Equal" << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab3 << "- Is Not Equal" << r2::linefeed;
				}

				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "tf1.target<FunctionT>() == tf2.target<FunctionT>()" << r2::linefeed;
				if( tf1.target<FunctionT>() == tf2.target<FunctionT>() )
				{
					std::cout << r2::tab3 << "- Is Equal" << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab3 << "- Is Not Equal" << r2::linefeed;
				}

				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "tf1.target<FunctionT>() == tf3.target<FunctionT>()" << r2::linefeed;
				if( tf1.target<FunctionT>() == tf3.target<FunctionT>() )
				{
					std::cout << r2::tab3 << "- Is Equal" << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab3 << "- Is Not Equal" << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}