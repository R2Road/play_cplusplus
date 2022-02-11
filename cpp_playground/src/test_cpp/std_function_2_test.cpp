#include "pch.h"
#include "std_function_2_test.h"

#include <functional>

#include "base/r2_eTestResult.h"

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

	r2::iTest::TitleFunc Equality_STDBind_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : std::bind 1";
		};
	}
	r2::iTest::DoFunc Equality_STDBind_1::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;


			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "using FunctionPointerT = void(*)();" << r2::linefeed;
			std::cout << r2::tab2 << "using STDFunctionT = std::function<void()>;" << r2::linefeed;


			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ 음... 어떻게 해야 하지?" << r2::linefeed2;

				NamedTestClass test_class;

				STDFunctionT sf1 = std::bind( &NamedTestClass::TestFunction_1, &test_class );
				auto fn_1 = sf1.target<void(*)()>();
				auto fn_2 = sf1.target<void(std_function_2_test::NamedTestClass::*)()>();

				std::cout << r2::tab2 << "TestClass test_class;" << r2::linefeed2;
				std::cout << r2::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2::linefeed2;
				std::cout << r2::tab2 << "auto fn_1 = sf1.target<void()>();" << r2::linefeed;
				std::cout << r2::tab2 << "auto fn_2 = sf1.target<void(*)()>();" << r2::linefeed;
				std::cout << r2::tab2 << "auto fn_3 = sf1.target<void(std_function_2_test::NamedTestClass::*)()>();" << r2::linefeed2;

				std::cout << r2::tab2 << "nullptr == fn_1" << r2::linefeed;
				if( nullptr == fn_1 )
				{
					std::cout << r2::tab3 << "- Is Null" << r2::linefeed;
					std::cout << r2::tab3 << "- Convert Failed" << r2::linefeed;
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
					std::cout << r2::tab3 << "- Convert Failed" << r2::linefeed;
				}
				else
				{
					std::cout << r2::tab3 << "- Is Not Null" << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}