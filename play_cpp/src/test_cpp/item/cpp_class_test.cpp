#include "cpp_class_test.h"
#include "cpp_class_test_helper_member_adress.hpp"
#include "cpp_class_test_helper_offset_singleton.hpp"

#include <iterator>
#include <numeric>
#include <string>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace cpp_class_test
{
	r2tm::TitleFunctionT Method::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Method";
		};
	}
	r2tm::DoFunctionT Method::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_NOTE( "Class Method 를 호출하는법." );

			std::cout << r2tm::split;

			DECLARATION_MAIN( struct S
			{
				void Func() { printf( "\t" "> " "[Call] Func" "\n" ); }
			} );

			std::cout << r2tm::split;

			DECLARATION_MAIN( S s );

			std::cout << r2tm::split;
			{
				PROCESS_MAIN( s.Func() );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( s.S::Func() );
				
				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto f = &S::Func );
				PROCESS_MAIN( ( s.*f )( ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MemberValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : MemberValue";
		};
	}
	r2tm::DoFunctionT MemberValue::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( DECLARATION_MAIN( struct TC
			{
				int a = 123; int b = 234;
			} ); );
			DECLARATION_MAIN( TC tc );

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( tc.b );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( tc.TC::b );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Braces::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Braces";
		};
	}
	r2tm::DoFunctionT Braces::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				class TestClass1
				{
				public:
					int a;
					int b;
				};

				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed;

				std::cout << r2tm::tab2 << "class TestClass1" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "public:" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "int a;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "int b;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "}" << r2tm::linefeed;


				std::cout << r2tm::linefeed;


				TestClass1 t1{ 1, 2 };

				std::cout << r2tm::tab << "+ Variable" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "TestClass1 t1{ 1, 2 }" << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



class TestClass1 {};

namespace
{
	class TestClass2 {};
}

namespace cpp_class_test
{
	r2tm::TitleFunctionT PrintName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Print Name";
		};
	}
	r2tm::DoFunctionT PrintName::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "class TestClass1 {};" << r2tm::linefeed;


				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( typeid( TestClass1 ).name() );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( TestClass1 test_class );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( typeid( test_class ).name() );
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "namespace" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "class TestClass2 {};" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "}" << r2tm::linefeed;


				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( typeid( TestClass2 ).name() );
			}

			std::cout << r2tm::split;
			
			{
				class TestClass3 {};

				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "class TestClass3 {};" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "...In this space" << r2tm::linefeed;


				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( typeid( TestClass3 ).name() );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace cpp_class_test
{
	r2tm::TitleFunctionT ImplicitTypeConversion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Implicit Type Conversion";
		};
	}
	r2tm::DoFunctionT ImplicitTypeConversion::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				class TestClass1
				{
				public:
					operator int() const { return 100; }
				};

				{
					std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;

					std::cout << r2tm::tab2 << "class TestClass1" << r2tm::linefeed;
					std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
					std::cout << r2tm::tab2 << "public:" << r2tm::linefeed;
					std::cout << r2tm::tab3 << "operator int() const { return 100; }" << r2tm::linefeed;
					std::cout << r2tm::tab2 << "}" << r2tm::linefeed2;
				}

				std::cout << r2tm::split;

				{
					DECLARATION_MAIN( TestClass1 tc1 );
					DECLARATION_MAIN( int i = tc1 );

					std::cout << r2tm::linefeed;

					OUTPUT_VALUE( i );
				}
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}






	r2tm::TitleFunctionT MemberAdress_Value::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Member Adress : Value";
		};
	}
	r2tm::DoFunctionT MemberAdress_Value::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_member_adress.hpp" );

			std::cout << r2tm::linefeed;

			DECLARATION_MAIN( using TC = cpp_class_test_helper_member_adress::TestClass );
			DECLARATION_MAIN( TC tc );

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( &tc );
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Member Adress" << r2tm::linefeed2;
				OUTPUT_VALUE( &tc.a );
				OUTPUT_VALUE( &tc.b );
				OUTPUT_VALUE( &tc.c );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MemberAdress_Method::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Member Adress : Method";
		};
	}
	r2tm::DoFunctionT MemberAdress_Method::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_member_adress.hpp" );

			std::cout << r2tm::linefeed;

			DECLARATION_MAIN( using TC = cpp_class_test_helper_member_adress::TestClass );
			DECLARATION_MAIN( TC tc );

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( &tc );
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Method Adress 1" << r2tm::linefeed2;
				OUTPUT_VALUE( &TC::Func1 );
				OUTPUT_VALUE( &TC::Func2 );
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Method Adress 2" << r2tm::linefeed2;
				DECLARATION_MAIN( void ( TC::*f1_ptr )( ) = &TC::Func1 );
				DECLARATION_MAIN( auto f1_void = (void*&)f1_ptr );
				OUTPUT_VALUE( f1_void );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( void ( TC::*f2_ptr )( ) = &TC::Func2 );
				DECLARATION_MAIN( auto f2_void = (void*&)f2_ptr );
				OUTPUT_VALUE( f2_void );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Offset_SingleInheritance::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Single Inheritance";
		};
	}
	r2tm::DoFunctionT Offset_SingleInheritance::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( class A {}; );
				DECLARATION_MAIN( class B : public A {} );
				DECLARATION_MAIN( class C : public B {} );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)1 );
				OUTPUT_VALUE( pC );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Offset_MultipleInheritance::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Multiple Inheritance";
		};
	}
	r2tm::DoFunctionT Offset_MultipleInheritance::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( class A {}; class B {}; );

				OUTPUT_CODE( ( class C : public A, public B {}; ) );
				class C : public A, public B {};

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)1 );
				OUTPUT_VALUE( pC );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( class A {}; class B {}; class C {}; );

				OUTPUT_CODE( ( class D : public A, public B, public C {}; ) );
				class D : public A, public B, public C {};

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pD = (D*)1 );
				OUTPUT_VALUE( pD );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pA = (A*)pD );
				OUTPUT_VALUE( pA );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pB = (B*)pD );
				OUTPUT_VALUE( pB );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pC = (C*)pD );
				OUTPUT_VALUE( pC );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( dynamic_cast<C*>( pD ) );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto offset = reinterpret_cast<int64_t>( pD ) - reinterpret_cast<int64_t>( pC ) );
				OUTPUT_VALUE( offset );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( const auto pCastWithOffset = reinterpret_cast<D*>( pC + offset ) );
				OUTPUT_VALUE( pCastWithOffset );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Offset_Singleton::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Singleton";
		};
	}
	r2tm::DoFunctionT Offset_Singleton::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_offset_singleton.hpp" );

			std::cout << r2tm::split;

			DECLARATION_MAIN( A_B_ST abst );

			std::cout << r2tm::split;

			OUTPUT_VALUE( &abst );

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_And_Byte::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Size And Byte";
		};
	}
	r2tm::DoFunctionT Size_And_Byte::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "type 의 최소 크기 : 1 byte" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( class C1 {} );
				OUTPUT_VALUE( sizeof( C1 ) );
				OUTPUT_BINARY( C1() );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "member 변수의 크기" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( class C1 { int a; } );
				OUTPUT_VALUE( sizeof( C1 ) );
				OUTPUT_BINARY( C1() );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "공백 class 최적화" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( class C1 {} );
				DECLARATION_MAIN( class C2 : public C1 { int a; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "각 member 변수의 크기의 총합" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( class C1 { int i; } );
				DECLARATION_MAIN( class C2 : public C1 { int a; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "virtual table의 크기" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( class C1 { public: virtual ~C1() {} } );
				DECLARATION_MAIN( class C2 : public C1 {} );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "virtual table 의 영향으로 결정된 byte 정렬" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( class C1 { public: virtual ~C1(){} } );
				DECLARATION_MAIN( class C2 : public C1 { int a = -1; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( class C1 { public: virtual ~C1() {} int i = -1; int j = -2; } );
				DECLARATION_MAIN( class C2 : public C1 { int a = -3; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_VALUE( sizeof( C1 ) );
				OUTPUT_BINARY( C2() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( C1 c1 );
				OUTPUT_VALUE( &c1 );
				OUTPUT_VALUE( &c1.i );
				OUTPUT_VALUE( &c1.j );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	class C_has_StaticConstexprInt { static constexpr int etest = 1; };

	r2tm::TitleFunctionT Size_With_Enum::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Size With Enum";
		};
	}
	r2tm::DoFunctionT Size_With_Enum::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_NOTE( "enum 과 static constexpr 은 비슷한 의도로 사용 가능하다." );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( class C { enum { etest = 1 }; } );
				OUTPUT_VALUE( sizeof( C ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( sizeof( C_has_StaticConstexprInt ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
