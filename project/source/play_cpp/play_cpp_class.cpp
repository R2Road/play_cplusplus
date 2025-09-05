#include "play_cpp_class.hpp"
#include "play_cpp_class_helper___member_adress.hpp"
#include "play_cpp_class_helper___offset_singleton.hpp"
#include "play_cpp_class_helper___size_with_enum.hpp"

#include <iterator>
#include <numeric>
#include <string>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_cpp_class
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

			OUT_NOTE( "Class Method 를 호출하는법." );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			struct S
			{
				void Func() { printf( "\t" "> " "[Call] Func" "\n" ); }
			};
			OUT_SOURCE_END;

			LS();

			DECL_MAIN( S s );

			LS();

			{
				OUT_SUBJECT( "일반적인 호출 1" );

				LF();

				PROC_MAIN( s.Func() );
			}

			LS();

			{
				OUT_SUBJECT( "일반적인 호출 2" );

				LF();

				PROC_MAIN( s.S::Func() );
			}

			LS();

			{
				OUT_SUBJECT( "함수 포인터를 이용" );

				LF();

				DECL_MAIN( auto m = &S::Func );
				PROC_MAIN( ( s.*m )( ) );
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

			OUT_NOTE( "Class Member에 접근하는 방법" );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			struct S
			{
				int a = 123;
				int b = 234;
			};
			OUT_SOURCE_END;

			LS();

			DECL_MAIN( S s );

			LS();

			{
				OUT_SUBJECT( "일반적인 접근 1" );

				LF();

				OUT_VALUE( s.b );
			}

			LS();

			{
				OUT_SUBJECT( "일반적인 접근 2" );

				LF();

				OUT_VALUE( s.S::b );
			}

			LS();

			{
				OUT_SUBJECT( "멤버 포인터를 이용" );

				LF();

				DECL_MAIN( auto p = &S::b );
				OUT_VALUE( ( s.*p ) );
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
				OUT_SUBJECT( "public member를 가진 class : 가능" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					int a;
					int b;
				};

				S s{ 1, 2 };
				OUT_SOURCE_END;
			}

			LS();

			{
				OUT_SUBJECT( "사용자 정의 생성자를 가진 class : 가능" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					S( int _a, int _b ) : a( _a ), b( _b ) {}

					int a;
					int b;
				};

				S s{ 1, 2 };
				OUT_SOURCE_END;
			}

			LS();

			{
				OUT_SUBJECT( "사용자 정의 explicit 생성자를 가진 class : 가능" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					explicit S( int _a, int _b ) : a( _a ), b( _b ) {}

					int a;
					int b;
				};

				S s{ 1, 2 };
				OUT_SOURCE_END;
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
				OUT_SUBJECT( "가능 : 인자 없는 생성자" );
				OUT_SUBJECT( "가능 : 사용자 정의 explicit 생성자를 가진 class" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				struct S
				{
					S() : a( 0 ), b( 0 ) {}
					explicit S( int _a, int _b ) : a( _a ), b( _b ) {}

					int a;
					int b;
				};

				S s1{};
				S s2{ 1, 2 };
				OUT_SOURCE_END;
			}

			LS();

			{
				OUT_NOTE( "멤버가 explicit 생성자를 가지고 있으면 문제가 생긴다.	" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
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
				OUT_SOURCE_END;
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

			OUT_NOTE( "멤버가 explicit 생성자를 가지고 있으면 문제가 생긴다." );
			OUT_NOTE( "그러면 멤버에" );
			OUT_NOTE( "std::initialize_list 를 인자로 받는 생성자를 추가하면 되는게 아닐까." );

			LS();

			{
				OUT_SOURCE_READY;
				OUT_SOURCE_BEGIN;
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
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( ss.s.a );
				OUT_VALUE( ss.s.b );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



#include "play_cpp_class_helper___print_name.hpp"

namespace play_cpp_class
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

			OUT_FILE( "source/play_cpp/play_cpp_class_helper___print_name.hpp" );

			LS();

			{
				OUT_SUBJECT( "Class" );

				LF();

				OUT_VALUE( typeid( PrintNameTest_Class1 ).name() );
			}

			LS();

			{
				OUT_SUBJECT( "Object" );

				LF();

				DECL_MAIN( PrintNameTest_Class1 c );

				LF();

				OUT_VALUE( typeid( c ).name() );
			}

			LS();

			{
				OUT_SUBJECT( "Unnamed Namespace" );

				LF();

				OUT_VALUE( typeid( PrintNameTest_TestClass2 ).name() );
			}

			LS();
			
			{
				OUT_SUBJECT( "This Place" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				class PrintNameTest_TestClass3 {};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( typeid( PrintNameTest_TestClass2 ).name() );
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

			OUT_SUBJECT( "암시적 타입 변환" );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			class TestClass1
			{
			public:
				operator int() const { return 100; }
			};
			OUT_SOURCE_END;

			LS();

			{
				DECL_MAIN( TestClass1 tc1 );
				DECL_MAIN( int i = tc1 );

				LF();

				OUT_VALUE( i );
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

			OUT_FILE( "source/play_cpp/play_cpp_class_helper___member_adress.hpp" );

			LF();

			DECL_MAIN( using C = play_cpp_class_helper___member_adress::TestClass );
			DECL_MAIN( C c );

			LS();

			{
				OUT_VALUE( &c );
			}

			LS();

			{
				OUT_SUBJECT( "Member Adress" );

				LF();

				OUT_VALUE( &c.a );
				OUT_VALUE( &c.b );
				OUT_VALUE( &c.c );
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

			OUT_FILE( "source/play_cpp/play_cpp_class_helper___member_adress.hpp" );

			LF();

			DECL_MAIN( using C = play_cpp_class_helper___member_adress::TestClass );
			DECL_MAIN( C c );

			LS();

			{
				OUT_VALUE( &c );
			}

			LS();

			{
				OUT_SUBJECT( "Method Adress 1" );

				LF();

				OUT_VALUE( &C::Func1 );
				OUT_VALUE( &C::Func2 );
			}

			LS();

			{
				OUT_SUBJECT( "Method Adress 2" );

				LF();

				DECL_MAIN( void ( C::*f1_ptr )( ) = &C::Func1 );
				DECL_MAIN( auto f1_void = (void*&)f1_ptr );
				OUT_VALUE( f1_void );

				LF();

				DECL_MAIN( void ( C::*f2_ptr )( ) = &C::Func2 );
				DECL_MAIN( auto f2_void = (void*&)f2_ptr );
				OUT_VALUE( f2_void );
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

			OUT_SOURCE_READY_N_BEGIN;
			class A
			{};

			class B : public A
			{};

			class C : public B
			{};
			OUT_SOURCE_END;

			LS();

			{
				DECL_MAIN( const auto pC = (C*)1 );
				OUT_VALUE( pC );

				LF();

				DECL_MAIN( const auto pA = (A*)pC );
				OUT_VALUE( pA );

				LF();

				DECL_MAIN( const auto pB = (B*)pC );
				OUT_VALUE( pB );
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

			OUT_SOURCE_READY_N_BEGIN;
			class A
			{};

			class B
			{};

			class C : public A, public B
			{};
			OUT_SOURCE_END;

			LS();

			{
				DECL_MAIN( const auto pC = (C*)1 );
				OUT_VALUE( pC );

				LF();

				DECL_MAIN( const auto pA = (A*)pC );
				OUT_VALUE( pA );

				LF();

				DECL_MAIN( const auto pB = (B*)pC );
				OUT_VALUE( pB );
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

			OUT_SOURCE_READY_N_BEGIN;
			class A
			{};

			class B
			{};

			class C
			{};

			class D : public A, public B, public C
			{};
			OUT_SOURCE_END;

			LS();

			{
				DECL_MAIN( const auto pD = (D*)1 );
				OUT_VALUE( pD );

				LF();

				DECL_MAIN( const auto pA = (A*)pD );
				OUT_VALUE( pA );

				LF();

				DECL_MAIN( const auto pB = (B*)pD );
				OUT_VALUE( pB );

				LF();

				DECL_MAIN( const auto pC = (C*)pD );
				OUT_VALUE( pC );

				LF();

				OUT_VALUE( dynamic_cast<C*>( pD ) );

				LF();

				DECL_MAIN( const auto offset =
						reinterpret_cast<int64_t>( pD )
					-	reinterpret_cast<int64_t>( pC )
				);
				OUT_VALUE( offset );

				LF();

				DECL_MAIN( const auto pCastWithOffset = reinterpret_cast<D*>( pC + offset ) );
				OUT_VALUE( pCastWithOffset );
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

			OUT_FILE( "source/play_cpp/play_cpp_class_helper___offset_singleton.hpp" );

			LS();

			DECL_MAIN( A_B_ST abst );

			LS();

			OUT_VALUE( &abst );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_And_Byte_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Size And Byte 1";
		};
	}
	r2tm::DoFunctionT Size_And_Byte_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_NOTE( "type 의 최소 크기 : 1 byte" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				class C1
				{};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( C1 ) );
				OUT_BINARY( C1() );
			}

			LS();

			{
				OUT_NOTE( "member 변수의 크기" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				class C1
				{
					int a;
				};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( C1 ) );
				OUT_BINARY( C1() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_And_Byte_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Size And Byte 2";
		};
	}
	r2tm::DoFunctionT Size_And_Byte_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_NOTE( "공백 class 최적화" );

				LF();

				DECL_MAIN( class C1 {} );
				DECL_MAIN( class C2 : public C1 { int i; } );
				OUT_VALUE( sizeof( C2 ) );
				OUT_BINARY( C2() );

				LF();

				OUT_COMMENT( "기본 클래스가 메모리를 차지하지 않는다." );
			}

			LS();

			{
				OUT_NOTE( "각 member 변수의 크기의 총합" );

				LF();

				DECL_MAIN( class C1 { int i; } );
				DECL_MAIN( class C2 : public C1 { int i; } );
				OUT_VALUE( sizeof( C2 ) );
				OUT_BINARY( C2() );
			}

			LS();

			{
				OUT_NOTE( "virtual table의 크기" );

				LF();

				DECL_MAIN( class C1 { public: virtual ~C1() {} } );
				DECL_MAIN( class C2 : public C1 {} );
				OUT_VALUE( sizeof( C2 ) );
				OUT_BINARY( C2() );
			}

			LS();

			{
				OUT_NOTE( "virtual table 의 영향으로 결정된 byte 정렬" );

				LF();

				DECL_MAIN( class C1 { public: virtual ~C1(){} } );
				DECL_MAIN( class C2 : public C1 { int a = -1; } );
				OUT_VALUE( sizeof( C2 ) );
				OUT_BINARY( C2() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_And_Byte_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Size And Byte 3";
		};
	}
	r2tm::DoFunctionT Size_And_Byte_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( class C1 { public: virtual ~C1() {} int i = -1; int j = -2; } );
				DECL_MAIN( class C2 : public C1 { int a = -3; } );
				OUT_VALUE( sizeof( C2 ) );
				OUT_VALUE( sizeof( C1 ) );
				OUT_BINARY( C2() );

				LF();

				DECL_MAIN( C1 c1 );
				OUT_VALUE( &c1 );
				OUT_VALUE( &c1.i );
				OUT_VALUE( &c1.j );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



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

			OUT_NOTE( "enum 과 static constexpr 은 비슷한 의도로 사용 가능하다." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				class C
				{
					enum { etest = 1 };
				};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( C ) );
			}

			LS();

			{
				OUT_FILE( "source/play_cpp/play_cpp_class_helper___size_with_enum.hpp" );

				LF();

				OUT_VALUE( sizeof( C_has_StaticConstexprInt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
