#include "std_function_2_test.h"

#include <functional>

#include "r2tm/r2tm_ostream.h"

namespace std_function_2_test
{
	class NamedTestClass
	{
	public:
		void TestFunction_1()
		{
			std::cout << "TestFunction_1";
		}

		void TestFunction_2()
		{
			std::cout << "TestFunction_2";
		}
	};

	r2tm::TitleFunctionT Equality_STDBind_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : std::bind 1";
		};
	}
	r2tm::DoFunctionT Equality_STDBind_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();


			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "using FunctionPointerT = void(*)();" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "using STDFunctionT = std::function<void()>;" << r2tm::linefeed;


			LS();

			{
				std::cout << r2tm::tab << "+ 음... 어떻게 해야 하지?" << r2tm::linefeed2;

				NamedTestClass test_class;

				STDFunctionT sf1 = std::bind( &NamedTestClass::TestFunction_1, &test_class );
				auto fn_1 = sf1.target<void(*)()>();
				auto fn_2 = sf1.target<void(std_function_2_test::NamedTestClass::*)()>();

				std::cout << r2tm::tab2 << "TestClass test_class;" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "auto fn_1 = sf1.target<void()>();" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "auto fn_2 = sf1.target<void(*)()>();" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "auto fn_3 = sf1.target<void(std_function_2_test::NamedTestClass::*)()>();" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "nullptr == fn_1" << r2tm::linefeed;
				if( nullptr == fn_1 )
				{
					std::cout << r2tm::tab3 << "- Is Null" << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- Convert Failed" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Null" << r2tm::linefeed;
				}

				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab2 << "nullptr == fn_2" << r2tm::linefeed;
				if( nullptr == fn_2 )
				{
					std::cout << r2tm::tab3 << "- Is Null" << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- Convert Failed" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Null" << r2tm::linefeed;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}