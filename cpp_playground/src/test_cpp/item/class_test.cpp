#include "class_test.h"

#include <iterator>
#include <numeric>
#include <string>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace class_test
{
	r2cm::iItem::TitleFunctionT Braces::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Braces";
		};
	}
	r2cm::iItem::DoFunctionT Braces::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				class TestClass1
				{
				public:
					int a;
					int b;
				};

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "class TestClass1" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "int a;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "int b;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed;


				TestClass1 t1{ 1, 2 };

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "TestClass1 t1{ 1, 2 }" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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
	r2cm::iItem::TitleFunctionT PrintName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Print Name";
		};
	}
	r2cm::iItem::DoFunctionT PrintName::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestClass1 {};" << r2cm::linefeed;


				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Print Name" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "typeid( TestClass1 ).name()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << typeid( TestClass1 ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				TestClass1 test_class;

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "TestClass1 test_class;" << r2cm::linefeed;


				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Print Name" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "typeid( test_class ).name()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << typeid( test_class ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "namespace" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "class TestClass2 {};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Print Name" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "typeid( TestClass2 ).name()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << typeid( TestClass2 ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;
			
			{
				class TestClass3 {};

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestClass3 {};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "...In this space" << r2cm::linefeed;


				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Print Name" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "typeid( TestClass3 ).name()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << typeid( TestClass3 ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace class_test
{
	r2cm::iItem::TitleFunctionT PrivateInheritance_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance 1";
		};
	}
	r2cm::iItem::DoFunctionT PrivateInheritance_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				class iPrivateInterface
				{
				protected:
					virtual void DoProcess() = 0;
				};
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class iPrivateInterface" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "protected:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "virtual void DoProcess() = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed2;


				class iPublicInterface
				{
				public:
					virtual void Do() = 0;
				};
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class iPublicInterface" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "virtual void Do() = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed2;


				class TestChild : private iPrivateInterface, public iPublicInterface
				{
				private:
					void DoProcess() override
					{
						std::cout << "Call : TestChild::DoProcess()" << r2cm::linefeed;
					}

				public:
					void Do() override
					{
						DoProcess();
					}
				};
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestChild : private iPrivateInterface, public iPublicInterface" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "private:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "void DoProcess() override" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab4 << "std::cout << \"Call : TestChild::DoProcess()\" << r2cm::linefeed;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "}" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "void Do() override" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab4 << "DoProcess();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "}" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed2;


				std::cout << r2cm::tab << "+ Call" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "TestChild().Do();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> ";
				TestChild().Do();
			}

			std::cout << r2cm::split;


			std::cout << r2cm::tab << "mmm.... not good ( '_')y-~" << r2cm::linefeed;


			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PrivateInheritance_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance 2";
		};
	}
	r2cm::iItem::DoFunctionT PrivateInheritance_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			class iPrivateInheritance
			{
			public:
				virtual void Do()
				{
					std::cout << "Call : TestChild::DoProcess()" << r2cm::linefeed;
				}
			};
			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "class iPrivateInheritance" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "virtual void Do() = 0;" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "{" << r2cm::linefeed;
			std::cout << r2cm::tab4 << "std::cout << \"Call : TestChild::DoProcess()\" << r2cm::linefeed;" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "}" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "}" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				class TestChild_1 : private iPrivateInheritance
				{
				};
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestChild_1 : private iPrivateInheritance" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed2;


				std::cout << r2cm::tab << "+ Call" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "TestChild_1().Do();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << " Not Working : Do is Private";
				//TestChild_1.Do();
			}

			std::cout << r2cm::split;

			{
				class TestChild_2 : private iPrivateInheritance
				{
				public:
					using iPrivateInheritance::Do;
				};
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestChild_2 : private iPrivateInheritance" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "using iPrivateInheritance::Do;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed2;


				std::cout << r2cm::tab << "+ Call" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "TestChild_2().Do();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> ";
				TestChild_2().Do();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ImplicitTypeConversion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Implicit Type Conversion";
		};
	}
	r2cm::iItem::DoFunctionT ImplicitTypeConversion::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				class TestClass1
				{
				public:
					operator int() const { return 100; }
				};

				{
					std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;

					std::cout << r2cm::tab2 << "class TestClass1" << r2cm::linefeed;
					std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
					std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
					std::cout << r2cm::tab3 << "operator int() const { return 100; }" << r2cm::linefeed;
					std::cout << r2cm::tab2 << "}" << r2cm::linefeed2;
				}

				std::cout << r2cm::split;

				{
					DECLARATION_MAIN( TestClass1 tc1 );
					DECLARATION_MAIN( int i = tc1 );

					std::cout << r2cm::linefeed;

					OUTPUT_VALUE( i );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MemberAdress::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Member Adress";
		};
	}
	r2cm::iItem::DoFunctionT MemberAdress::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

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

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestClass1" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "int a;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "int b;" << r2cm::linefeed2;
				std::cout << r2cm::tab3 << "void Func1() {}" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "void Func2() {}" << r2cm::linefeed2;
				std::cout << r2cm::tab3 << "int c;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "TestClass1 tc1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto pTc1 = &tc1;" << r2cm::linefeed;
				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Body Adress" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "&tc1 : " << &tc1 << r2cm::linefeed;
				std::cout << r2cm::tab2 << "pTc1 : " << pTc1 << r2cm::linefeed;
				std::cout << r2cm::tab2 << "&( *pTc1 ) : " << &( *pTc1 ) << r2cm::linefeed;
				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Member Adress" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "&tc1.a : " << &tc1.a << r2cm::linefeed;
				std::cout << r2cm::tab2 << "&tc1.b : " << &tc1.b << r2cm::linefeed;
				std::cout << r2cm::tab2 << "&tc1.c : " << &tc1.c << r2cm::linefeed;
				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Method Adress 1" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "&TestClass1::Func1 : " << &TestClass1::Func1 << r2cm::linefeed;
				std::cout << r2cm::tab2 << "&TestClass1::Func2 : " << &TestClass1::Func2 << r2cm::linefeed;

				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Method Adress 2" << r2cm::linefeed2;
				void ( TestClass1::*f1_ptr )( ) = &TestClass1::Func1;
				auto f1_void = (void*&)f1_ptr;
				std::cout << r2cm::tab2 << "void ( TestClass1::*f1_ptr )() = &TestClass1::Func1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto f1_void = (void*&)f1_ptr;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "f1_void : " << f1_void << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Offset_SingleInheritance::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Single Inheritance";
		};
	}
	r2cm::iItem::DoFunctionT Offset_SingleInheritance::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class A {}; );
				DECLARATION_MAIN( class B : public A {} );
				DECLARATION_MAIN( class C : public B {} );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)1 );
				OUTPUT_VALUE( pC );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class A {}; class B {}; );

				OUTPUT_CODE( ( class C : public A, public B {}; ) );
				class C : public A, public B {};

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)1 );
				OUTPUT_VALUE( pC );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class A {}; class B {}; class C {}; );

				OUTPUT_CODE( ( class D : public A, public B, public C {}; ) );
				class D : public A, public B, public C {};

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pD = (D*)1 );
				OUTPUT_VALUE( pD );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)pD );
				OUTPUT_VALUE( pC );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pD );
				OUTPUT_VALUE( pB );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pA = (A*)pD );
				OUTPUT_VALUE( pA );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
