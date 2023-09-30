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
			LS();

			OUTPUT_NOTE( "Class Method 를 호출하는법." );

			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			struct S
			{
				void Func() { printf( "\t" "> " "[Call] Func" "\n" ); }
			};
			OUTPUT_SOURCE_END;

			LS();

			DECLARATION_MAIN( S s );

			LS();

			{
				OUTPUT_SUBJECT( "일반적인 호출 1" );

				LF();

				PROCESS_MAIN( s.Func() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "일반적인 호출 2" );

				LF();

				PROCESS_MAIN( s.S::Func() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "함수 포인터를 이용" );

				LF();

				DECLARATION_MAIN( auto m = &S::Func );
				PROCESS_MAIN( ( s.*m )( ) );
			}

			LS();

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
			LS();

			OUTPUT_NOTE( "Class Member에 접근하는 방법" );

			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			struct S
			{
				int a = 123;
				int b = 234;
			};
			OUTPUT_SOURCE_END;

			LS();

			DECLARATION_MAIN( S s );

			LS();

			{
				OUTPUT_SUBJECT( "일반적인 접근 1" );

				LF();

				OUTPUT_VALUE( s.b );
			}

			LS();

			{
				OUTPUT_SUBJECT( "일반적인 접근 2" );

				LF();

				OUTPUT_VALUE( s.S::b );
			}

			LS();

			{
				OUTPUT_SUBJECT( "멤버 포인터를 이용" );

				LF();

				DECLARATION_MAIN( auto p = &S::b );
				OUTPUT_VALUE( ( s.*p ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Braces_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Braces 1";
		};
	}
	r2tm::DoFunctionT Braces_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "public member를 가진 class : 가능" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					int a;
					int b;
				};

				S s{ 1, 2 };
				OUTPUT_SOURCE_END;
			}

			LS();

			{
				OUTPUT_SUBJECT( "사용자 정의 생성자를 가진 class : 가능" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					S( int _a, int _b ) : a( _a ), b( _b ) {}

					int a;
					int b;
				};

				S s{ 1, 2 };
				OUTPUT_SOURCE_END;
			}

			LS();

			{
				OUTPUT_SUBJECT( "사용자 정의 explicit 생성자를 가진 class : 가능" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					explicit S( int _a, int _b ) : a( _a ), b( _b ) {}

					int a;
					int b;
				};

				S s{ 1, 2 };
				OUTPUT_SOURCE_END;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Braces_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Braces 2";
		};
	}
	r2tm::DoFunctionT Braces_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();


			{
				OUTPUT_SUBJECT( "인자 없는 생성자 + 사용자 정의 explicit 생성자를 가진 class : 가능" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					S() : a( 0 ), b( 0 ) {}
					explicit S( int _a, int _b ) : a( _a ), b( _b ) {}

					int a;
					int b;
				};

				S s1{};
				S s2{ 1, 2 };
				OUTPUT_SOURCE_END;
			}

			LS();

			{
				OUTPUT_NOTE( "멤버가 explicit 생성자를 가지고 있으면 문제가 생긴다.	" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					S() : a( 0 ), b( 0 ) {}
					explicit S( int _a, int _b ) : a( _a ), b( _b ) {}
					// 이 위의 explicit 가 붙으면 initialize-list 적용 안됨

					int a;
					int b;
				};

				struct SS
				{
					//SS() : a( 0,  0 ) {}
					//explicit SS( S _a ) : a( _a ) {}

					S a;
				};

				SS s1{};
				//SS s2{ { 1, 2 } }; // <= Error
				OUTPUT_SOURCE_END;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Braces_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Braces 3";
		};
	}
	r2tm::DoFunctionT Braces_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "멤버가 explicit 생성자를 가지고 있으면 문제가 생긴다." );
			OUTPUT_NOTE( "그러면 멤버에" );
			OUTPUT_NOTE( "std::initialize_list 를 인자로 받는 생성자를 추가하면 되는게 아닐까." );

			LS();

			{
				OUTPUT_SOURCE_READY;
				OUTPUT_SOURCE_BEGIN;
				struct S
				{
					S() : a( 0 ), b( 0 ) {}
					S( const std::initializer_list<int>& l ) :
						  a( *( l.begin() ) )
						, b( *( l.begin() + 1 ) )
					{}
					explicit S( int _a, int _b ) : a( _a ), b( _b ) {}

					int a;
					int b;
				};

				struct SS
				{
					S s;
				};

				SS ss{ { 1, 2 } }; // <= Working
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( ss.s.a );
				OUTPUT_VALUE( ss.s.b );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



#include "cpp_class_test_print_name.hpp"

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
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_print_name.hpp" );

			LS();

			{
				OUTPUT_SUBJECT( "Class" );

				LF();

				OUTPUT_VALUE( typeid( PrintNameTest_Class1 ).name() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Object" );

				LF();

				DECLARATION_MAIN( PrintNameTest_Class1 c );

				LF();

				OUTPUT_VALUE( typeid( c ).name() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Unnamed Namespace" );

				LF();

				OUTPUT_VALUE( typeid( PrintNameTest_TestClass2 ).name() );
			}

			LS();
			
			{
				OUTPUT_SUBJECT( "This Place" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				class PrintNameTest_TestClass3 {};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( typeid( PrintNameTest_TestClass2 ).name() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}






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
			LS();

			OUTPUT_SUBJECT( "암시적 타입 변환" );

			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			class TestClass1
			{
			public:
				operator int() const { return 100; }
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				DECLARATION_MAIN( TestClass1 tc1 );
				DECLARATION_MAIN( int i = tc1 );

				LF();

				OUTPUT_VALUE( i );
			}

			LS();

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
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_member_adress.hpp" );

			LF();

			DECLARATION_MAIN( using C = cpp_class_test_helper_member_adress::TestClass );
			DECLARATION_MAIN( C c );

			LS();

			{
				OUTPUT_VALUE( &c );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Member Adress" );

				LF();

				OUTPUT_VALUE( &c.a );
				OUTPUT_VALUE( &c.b );
				OUTPUT_VALUE( &c.c );
			}

			LS();

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
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_member_adress.hpp" );

			LF();

			DECLARATION_MAIN( using C = cpp_class_test_helper_member_adress::TestClass );
			DECLARATION_MAIN( C c );

			LS();

			{
				OUTPUT_VALUE( &c );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Method Adress 1" );

				LF();

				OUTPUT_VALUE( &C::Func1 );
				OUTPUT_VALUE( &C::Func2 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Method Adress 2" );

				LF();

				DECLARATION_MAIN( void ( C::*f1_ptr )( ) = &C::Func1 );
				DECLARATION_MAIN( auto f1_void = (void*&)f1_ptr );
				OUTPUT_VALUE( f1_void );

				LF();

				DECLARATION_MAIN( void ( C::*f2_ptr )( ) = &C::Func2 );
				DECLARATION_MAIN( auto f2_void = (void*&)f2_ptr );
				OUTPUT_VALUE( f2_void );
			}

			LS();

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
			LS();

			DECLARATION_MAIN( class A {}; );
			DECLARATION_MAIN( class B : public A {} );
			DECLARATION_MAIN( class C : public B {} );

			LS();

			{
				DECLARATION_MAIN( const auto pC = (C*)1 );
				OUTPUT_VALUE( pC );

				LF();

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );

				LF();

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Offset_MultipleInheritance_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Multiple Inheritance 1";
		};
	}
	r2tm::DoFunctionT Offset_MultipleInheritance_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			class A {}; class B {};
			class C : public A, public B {};
			OUTPUT_SOURCE_END;

			LS();

			{
				DECLARATION_MAIN( const auto pC = (C*)1 );
				OUTPUT_VALUE( pC );

				LF();

				DECLARATION_MAIN( const auto pA = (A*)pC );
				OUTPUT_VALUE( pA );

				LF();

				DECLARATION_MAIN( const auto pB = (B*)pC );
				OUTPUT_VALUE( pB );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Offset_MultipleInheritance_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Offset : Multiple Inheritance 2";
		};
	}
	r2tm::DoFunctionT Offset_MultipleInheritance_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				class A {}; class B {}; class C {};
				class D : public A, public B, public C {};
				OUTPUT_SOURCE_END;

				LF();

				DECLARATION_MAIN( const auto pD = (D*)1 );
				OUTPUT_VALUE( pD );

				LF();

				DECLARATION_MAIN( const auto pA = (A*)pD );
				OUTPUT_VALUE( pA );

				LF();

				DECLARATION_MAIN( const auto pB = (B*)pD );
				OUTPUT_VALUE( pB );

				LF();

				DECLARATION_MAIN( const auto pC = (C*)pD );
				OUTPUT_VALUE( pC );

				LF();

				OUTPUT_VALUE( dynamic_cast<C*>( pD ) );

				LF();

				DECLARATION_MAIN( const auto offset = reinterpret_cast<int64_t>( pD ) - reinterpret_cast<int64_t>( pC ) );
				OUTPUT_VALUE( offset );

				LF();

				DECLARATION_MAIN( const auto pCastWithOffset = reinterpret_cast<D*>( pC + offset ) );
				OUTPUT_VALUE( pCastWithOffset );
			}

			LS();

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
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_offset_singleton.hpp" );

			LS();

			DECLARATION_MAIN( A_B_ST abst );

			LS();

			OUTPUT_VALUE( &abst );

			LS();

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
			LS();

			{
				OUTPUT_NOTE( "type 의 최소 크기 : 1 byte" );

				LF();

				DECLARATION_MAIN( class C1 {} );
				OUTPUT_VALUE( sizeof( C1 ) );
				OUTPUT_BINARY( C1() );
			}

			LS();

			{
				OUTPUT_NOTE( "member 변수의 크기" );

				LF();

				DECLARATION_MAIN( class C1 { int a; } );
				OUTPUT_VALUE( sizeof( C1 ) );
				OUTPUT_BINARY( C1() );
			}

			LS();

			{
				OUTPUT_NOTE( "공백 class 최적화" );

				LF();

				DECLARATION_MAIN( class C1 {} );
				DECLARATION_MAIN( class C2 : public C1 { int a; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			LS();

			{
				OUTPUT_NOTE( "각 member 변수의 크기의 총합" );

				LF();

				DECLARATION_MAIN( class C1 { int i; } );
				DECLARATION_MAIN( class C2 : public C1 { int a; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			LS();

			{
				OUTPUT_NOTE( "virtual table의 크기" );

				LF();

				DECLARATION_MAIN( class C1 { public: virtual ~C1() {} } );
				DECLARATION_MAIN( class C2 : public C1 {} );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			LS();

			{
				OUTPUT_NOTE( "virtual table 의 영향으로 결정된 byte 정렬" );

				LF();

				DECLARATION_MAIN( class C1 { public: virtual ~C1(){} } );
				DECLARATION_MAIN( class C2 : public C1 { int a = -1; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_BINARY( C2() );
			}

			LS();

			{
				DECLARATION_MAIN( class C1 { public: virtual ~C1() {} int i = -1; int j = -2; } );
				DECLARATION_MAIN( class C2 : public C1 { int a = -3; } );
				OUTPUT_VALUE( sizeof( C2 ) );
				OUTPUT_VALUE( sizeof( C1 ) );
				OUTPUT_BINARY( C2() );

				LF();

				DECLARATION_MAIN( C1 c1 );
				OUTPUT_VALUE( &c1 );
				OUTPUT_VALUE( &c1.i );
				OUTPUT_VALUE( &c1.j );
			}

			LS();

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
			LS();

			OUTPUT_NOTE( "enum 과 static constexpr 은 비슷한 의도로 사용 가능하다." );

			LS();

			{
				DECLARATION_MAIN( class C { enum { etest = 1 }; } );
				OUTPUT_VALUE( sizeof( C ) );
			}

			LS();

			{
				OUTPUT_VALUE( sizeof( C_has_StaticConstexprInt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
