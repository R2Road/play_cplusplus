#include "class_test.h"
#include "class_test_helper_nvi.hpp"
#include "class_test_helper_member_adress.hpp"
#include "class_test_helper_offset_singleton.hpp"

#include <iterator>
#include <numeric>
#include <string>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace class_test
{
	r2cm::iItem::TitleFunctionT Method::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Method";
		};
	}
	r2cm::iItem::DoFunctionT Method::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "Class Method 를 호출하는법." );

			std::cout << r2cm::split;

			DECLARATION_MAIN( struct MethodTestStruct
			{
				void Func() { printf( "\t" "> " "[Call] Func" "\n" ); }
			} );

			std::cout << r2cm::split;

			DECLARATION_MAIN( MethodTestStruct mts );

			std::cout << r2cm::split;
			{
				PROCESS_MAIN( mts.Func() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( mts.MethodTestStruct::Func() );
				
				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto f = &MethodTestStruct::Func );
				PROCESS_MAIN( ( mts.*f )( ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MemberValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : MemberValue";
		};
	}
	r2cm::iItem::DoFunctionT MemberValue::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( DECLARATION_MAIN( struct TC
			{
				int a = 123; int b = 234;
			} ); );
			DECLARATION_MAIN( TC tc );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( tc.b );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( tc.TC::b );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



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

				OUTPUT_VALUE( typeid( TestClass1 ).name() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( TestClass1 test_class );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( typeid( test_class ).name() );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "namespace" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "class TestClass2 {};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( typeid( TestClass2 ).name() );
			}

			std::cout << r2cm::split;
			
			{
				class TestClass3 {};

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestClass3 {};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "...In this space" << r2cm::linefeed;


				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( typeid( TestClass3 ).name() );
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



	r2cm::iItem::TitleFunctionT NoneVirtualInterface::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : NVI( None Virtual Interface )";
		};
	}
	r2cm::iItem::DoFunctionT NoneVirtualInterface::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/class_test_helper_nvi.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class_test_helper_nvi::D1 d1 );
				OUTPUT_VALUE( d1.Do() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class_test_helper_nvi::D2 d2 );
				OUTPUT_VALUE( d2.Do() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}






	r2cm::iItem::TitleFunctionT MemberAdress_Value::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Member Adress : Value";
		};
	}
	r2cm::iItem::DoFunctionT MemberAdress_Value::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/class_test_helper_member_adress.hpp" );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( using TC = class_test_helper_member_adress::TestClass );
			DECLARATION_MAIN( TC tc );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( &tc );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Member Adress" << r2cm::linefeed2;
				OUTPUT_VALUE( &tc.a );
				OUTPUT_VALUE( &tc.b );
				OUTPUT_VALUE( &tc.c );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MemberAdress_Method::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Member Adress : Method";
		};
	}
	r2cm::iItem::DoFunctionT MemberAdress_Method::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/class_test_helper_member_adress.hpp" );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( using TC = class_test_helper_member_adress::TestClass );
			DECLARATION_MAIN( TC tc );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( &tc );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Method Adress 1" << r2cm::linefeed2;
				OUTPUT_VALUE( &TC::Func1 );
				OUTPUT_VALUE( &TC::Func2 );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Method Adress 2" << r2cm::linefeed2;
				DECLARATION_MAIN( void ( TC::*f1_ptr )( ) = &TC::Func1 );
				DECLARATION_MAIN( auto f1_void = (void*&)f1_ptr );
				OUTPUT_VALUE( f1_void );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( void ( TC::*f2_ptr )( ) = &TC::Func2 );
				DECLARATION_MAIN( auto f2_void = (void*&)f2_ptr );
				OUTPUT_VALUE( f2_void );
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

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Offset_MultipleInheritance::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Multiple Inheritance";
		};
	}
	r2cm::iItem::DoFunctionT Offset_MultipleInheritance::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class A {}; class B {}; );

				OUTPUT_CODE( ( class C : public A, public B {}; ) );
				class C : public A, public B {};

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)1 );
				OUTPUT_VALUE( pC );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );
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

				DECLARATION_MAIN( const auto pA = (A*)pD );
				OUTPUT_VALUE( pA );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pD );
				OUTPUT_VALUE( pB );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)pD );
				OUTPUT_VALUE( pC );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( dynamic_cast<C*>( pD ) );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto offset = reinterpret_cast<int64_t>( pD ) - reinterpret_cast<int64_t>( pC ) );
				OUTPUT_VALUE( offset );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto pCastWithOffset = reinterpret_cast<D*>( pC + offset ) );
				OUTPUT_VALUE( pCastWithOffset );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Offset_Singleton::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Singleton";
		};
	}
	r2cm::iItem::DoFunctionT Offset_Singleton::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/class_test_helper_offset_singleton.hpp" );

			std::cout << r2cm::split;

			DECLARATION_MAIN( A_B_ST abst );

			std::cout << r2cm::split;

			OUTPUT_VALUE( &abst );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Size";
		};
	}
	r2cm::iItem::DoFunctionT Size::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class C1 { int a; } );
				OUTPUT_VALUE( sizeof( C1 ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class C1 {} );
				DECLARATION_MAIN( class C2 : public C1 { int a; } );
				OUTPUT_VALUE( sizeof( C2 ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class C1 { int i; } );
				DECLARATION_MAIN( class C2 : public C1 { int a; } );
				OUTPUT_VALUE( sizeof( C2 ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class C1 { public: virtual ~C1(){} } );
				DECLARATION_MAIN( class C2 : public C1 { int a = -1; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( class C1 { public: virtual ~C1() {} int i = -1; int j = -2; } );
				DECLARATION_MAIN( class C2 : public C1 { int a = -3; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_VALUE( sizeof( C1 ) );
				OUTPUT_BINARY( C2() );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( C1 c1 );
				OUTPUT_VALUE( &c1 );
				OUTPUT_VALUE( &c1.i );
				OUTPUT_VALUE( &c1.j );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
