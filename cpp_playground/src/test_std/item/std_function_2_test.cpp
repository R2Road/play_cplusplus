#include "std_function_2_test.h"

#include <functional>

#include "r2cm/r2cm_ostream.h"

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

	r2cm::iItem::TitleFunctionT Equality_STDBind_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : std::bind 1";
		};
	}
	r2cm::iItem::DoFunctionT Equality_STDBind_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;


			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "using FunctionPointerT = void(*)();" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "using STDFunctionT = std::function<void()>;" << r2cm::linefeed;


			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 음... 어떻게 해야 하지?" << r2cm::linefeed2;

				NamedTestClass test_class;

				STDFunctionT sf1 = std::bind( &NamedTestClass::TestFunction_1, &test_class );
				auto fn_1 = sf1.target<void(*)()>();
				auto fn_2 = sf1.target<void(std_function_2_test::NamedTestClass::*)()>();

				std::cout << r2cm::tab2 << "TestClass test_class;" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto fn_1 = sf1.target<void()>();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto fn_2 = sf1.target<void(*)()>();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto fn_3 = sf1.target<void(std_function_2_test::NamedTestClass::*)()>();" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "nullptr == fn_1" << r2cm::linefeed;
				if( nullptr == fn_1 )
				{
					std::cout << r2cm::tab3 << "- Is Null" << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- Convert Failed" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Null" << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "nullptr == fn_2" << r2cm::linefeed;
				if( nullptr == fn_2 )
				{
					std::cout << r2cm::tab3 << "- Is Null" << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- Convert Failed" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Null" << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}