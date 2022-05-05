#include "pch.h"
#include "class_test.h"

#include <iterator>
#include <numeric>
#include <string>

#include "r2cm/r2cm_eTestEndAction.h"

namespace class_test
{
	r2cm::iItem::TitleFuncT Braces::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Braces";
		};
	}
	r2cm::iItem::DoFuncT Braces::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
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
	r2cm::iItem::TitleFuncT PrintName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Print Name";
		};
	}
	r2cm::iItem::DoFuncT PrintName::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}
}



namespace class_test
{
	r2cm::iItem::TitleFuncT PrivateInheritance_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance 1";
		};
	}
	r2cm::iItem::DoFuncT PrivateInheritance_1::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PrivateInheritance_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance 2";
		};
	}
	r2cm::iItem::DoFuncT PrivateInheritance_2::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			class iPrivateInheritance
			{
			public:
				virtual void Do()
				{
					std::cout << "Call : TestChild::DoProcess()" << r2::linefeed;
				}
			};
			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "class iPrivateInheritance" << r2::linefeed;
			std::cout << r2::tab2 << "{" << r2::linefeed;
			std::cout << r2::tab2 << "public:" << r2::linefeed;
			std::cout << r2::tab3 << "virtual void Do() = 0;" << r2::linefeed;
			std::cout << r2::tab3 << "{" << r2::linefeed;
			std::cout << r2::tab4 << "std::cout << \"Call : TestChild::DoProcess()\" << r2::linefeed;" << r2::linefeed;
			std::cout << r2::tab3 << "}" << r2::linefeed;
			std::cout << r2::tab2 << "}" << r2::linefeed;

			std::cout << r2::split;

			{
				class TestChild_1 : private iPrivateInheritance
				{
				};
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class TestChild_1 : private iPrivateInheritance" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed2;


				std::cout << r2::tab << "+ Call" << r2::linefeed2;
				std::cout << r2::tab2 << "- " << "TestChild_1().Do();" << r2::linefeed;
				std::cout << r2::tab3 << "> " << " Not Working : Do is Private";
				//TestChild_1.Do();
			}

			std::cout << r2::split;

			{
				class TestChild_2 : private iPrivateInheritance
				{
				public:
					using iPrivateInheritance::Do;
				};
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class TestChild_2 : private iPrivateInheritance" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "using iPrivateInheritance::Do;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed;


				std::cout << r2::linefeed2;


				std::cout << r2::tab << "+ Call" << r2::linefeed2;
				std::cout << r2::tab2 << "- " << "TestChild_2().Do();" << r2::linefeed;
				std::cout << r2::tab3 << "> ";
				TestChild_2().Do();
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}


	r2cm::iItem::TitleFuncT MemberAdress::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Member Adress";
		};
	}
	r2cm::iItem::DoFuncT MemberAdress::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				class TestClass1
				{
				public:
					int a;
					int b;

					void Func1() {}
					void Func2() {}

					int c;
				};

				TestClass1 tc1;
				auto pTc1 = &tc1;

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class TestClass1" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "int a;" << r2::linefeed;
				std::cout << r2::tab3 << "int b;" << r2::linefeed2;
				std::cout << r2::tab3 << "void Func1() {}" << r2::linefeed;
				std::cout << r2::tab3 << "void Func2() {}" << r2::linefeed2;
				std::cout << r2::tab3 << "int c;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed2;
				std::cout << r2::tab2 << "TestClass1 tc1;" << r2::linefeed;
				std::cout << r2::tab2 << "auto pTc1 = &tc1;" << r2::linefeed;
				std::cout << r2::linefeed2;

				std::cout << r2::tab << "+ Body Adress" << r2::linefeed2;
				std::cout << r2::tab2 << "&tc1 : " << &tc1 << r2::linefeed;
				std::cout << r2::tab2 << "pTc1 : " << pTc1 << r2::linefeed;
				std::cout << r2::tab2 << "&( *pTc1 ) : " << &( *pTc1 ) << r2::linefeed;
				std::cout << r2::linefeed2;

				std::cout << r2::tab << "+ Member Adress" << r2::linefeed2;
				std::cout << r2::tab2 << "&tc1.a : " << &tc1.a << r2::linefeed;
				std::cout << r2::tab2 << "&tc1.b : " << &tc1.b << r2::linefeed;
				std::cout << r2::tab2 << "&tc1.c : " << &tc1.c << r2::linefeed;
				std::cout << r2::linefeed2;

				std::cout << r2::tab << "+ Method Adress 1" << r2::linefeed2;
				std::cout << r2::tab2 << "&TestClass1::Func1 : " << &TestClass1::Func1 << r2::linefeed;
				std::cout << r2::tab2 << "&TestClass1::Func2 : " << &TestClass1::Func2 << r2::linefeed;

				std::cout << r2::linefeed2;

				std::cout << r2::tab << "+ Method Adress 2" << r2::linefeed2;
				void ( TestClass1::*f1_ptr )( ) = &TestClass1::Func1;
				auto f1_void = (void*&)f1_ptr;
				std::cout << r2::tab2 << "void ( TestClass1::*f1_ptr )() = &TestClass1::Func1;" << r2::linefeed;
				std::cout << r2::tab2 << "auto f1_void = (void*&)f1_ptr;" << r2::linefeed;
				std::cout << r2::tab2 << "f1_void : " << f1_void << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}
