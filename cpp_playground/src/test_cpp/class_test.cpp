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
				public:
					int a;
					int b;
				};

				std::cout << r2::tab << "+ Declaration" << r2::linefeed;

				std::cout << r2::tab2 << "class TestClass1" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "int a;" << r2::linefeed;
				std::cout << r2::tab3 << "int b;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed;


				TestClass1 t1{ 1, 2 };

				std::cout << r2::tab << "+ Variable" << r2::linefeed;
				std::cout << r2::tab2 << "TestClass1 t1{ 1, 2 }" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



class TestClass1 {};

namespace
{
	class TestClass2 {};
}

namespace class_test
{
	r2::iTest::TitleFunc PrintName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Print Name";
		};
	}
	r2::iTest::DoFunc PrintName::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class TestClass1 {};" << r2::linefeed;


				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Print Name" << r2::linefeed2;
				std::cout << r2::tab2 << "- " << "typeid( TestClass1 ).name()" << r2::linefeed;
				std::cout << r2::tab3 << "> " << typeid( TestClass1 ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				TestClass1 test_class;

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "TestClass1 test_class;" << r2::linefeed;


				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Print Name" << r2::linefeed2;
				std::cout << r2::tab2 << "- " << "typeid( test_class ).name()" << r2::linefeed;
				std::cout << r2::tab3 << "> " << typeid( test_class ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "namespace" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "class TestClass2 {};" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Print Name" << r2::linefeed2;
				std::cout << r2::tab2 << "- " << "typeid( TestClass2 ).name()" << r2::linefeed;
				std::cout << r2::tab3 << "> " << typeid( TestClass2 ).name() << r2::linefeed;
			}

			std::cout << r2::split;
			
			{
				class TestClass3 {};

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class TestClass3 {};" << r2::linefeed;
				std::cout << r2::tab2 << "...In this space" << r2::linefeed;


				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Print Name" << r2::linefeed2;
				std::cout << r2::tab2 << "- " << "typeid( TestClass3 ).name()" << r2::linefeed;
				std::cout << r2::tab3 << "> " << typeid( TestClass3 ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}



namespace class_test
{
	r2::iTest::TitleFunc PrivateInheritance_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance";
		};
	}
	r2::iTest::DoFunc PrivateInheritance_1::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				class iPrivateInterface
				{
				protected:
					virtual void DoProcess() = 0;
				};
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class iPrivateInterface" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "protected:" << r2::linefeed;
				std::cout << r2::tab3 << "virtual void DoProcess() = 0;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed2;


				class iPublicInterface
				{
				public:
					virtual void Do() = 0;
				};
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class iPublicInterface" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "virtual void Do() = 0;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed2;


				class TestChild : private iPrivateInterface, public iPublicInterface
				{
				private:
					void DoProcess() override
					{
						std::cout << "Call : TestChild::DoProcess()" << r2::linefeed;
					}

				public:
					void Do() override
					{
						DoProcess();
					}
				};
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class TestChild : private iPrivateInterface, public iPublicInterface" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "private:" << r2::linefeed;
				std::cout << r2::tab3 << "void DoProcess() override" << r2::linefeed;
				std::cout << r2::tab3 << "{" << r2::linefeed;
				std::cout << r2::tab4 << "std::cout << \"Call : TestChild::DoProcess()\" << r2::linefeed;" << r2::linefeed;
				std::cout << r2::tab3 << "}" << r2::linefeed2;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "void Do() override" << r2::linefeed;
				std::cout << r2::tab3 << "{" << r2::linefeed;
				std::cout << r2::tab4 << "DoProcess();" << r2::linefeed;
				std::cout << r2::tab3 << "}" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed2;


				std::cout << r2::tab << "+ Call" << r2::linefeed2;
				std::cout << r2::tab2 << "- " << "TestChild().Do();" << r2::linefeed;
				std::cout << r2::tab3 << "> ";
				TestChild().Do();
			}

			std::cout << r2::split;


			std::cout << r2::tab << "mmm.... not good ( '_')y-~" << r2::linefeed;


			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}