#include "play_various_0.hpp"

#include <array>
#include <bitset>
#include <iomanip>
#include <memory>
#include <stdint.h>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_various_0
{
	r2tm::TitleFunctionT ShowBinary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Show Binary";
		};
	}
	r2tm::DoFunctionT ShowBinary::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "Use For" );

				LF();

				DECL_MAIN( const int num = 0b10110010101 ); // binary

				LF();

				std::cout << r2tm::tab;
				for( int i = 31; 0 <= i; --i )
				{
					const int temp_1 = ( num >> i );
					const int temp_2 = temp_1 & 1;

					std::cout << temp_2;
				}
				LF();
			}

			LS();

			{
				OUT_SUBJECT( "Use Bitset" );

				LF();

				DECL_MAIN( const int num = 0b0011001 ); // binary
				DECL_MAIN( std::bitset<16u> b( num ) );

				LF();

				OUT_VALUE( b );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	// C++ Weekley with Jason Turners
	// https://www.youtube.com/watch?v=287_oG4CNMc
	class LifeTime
	{
	public:
		LifeTime() noexcept
		{
			puts( "\t> LifeTime()" );
		}
		LifeTime( const LifeTime& ) noexcept
		{
			puts( "\t> LifeTime( const LifeTime& ) noexcept" );
		}
		LifeTime( LifeTime&& ) noexcept
		{
			puts( "\t> LifeTime( LifeTime&& ) noexcept" );
		}
		~LifeTime() noexcept
		{
			puts( "\t> ~LifeTime()\n" );
		}

		LifeTime& operator=( const LifeTime& ) noexcept
		{
			puts( "\t> operator=( const LifeTime& ) noexcept" );
			return *this;
		}
		LifeTime& operator=( LifeTime&& ) noexcept
		{
			puts( "\t> operator=( LifeTime&& ) noexcept" );
			return *this;
		}
	};
	LifeTime f1()
	{
		return LifeTime{};
	}
	LifeTime f2()
	{
		return f1();
	}
	LifeTime f3()
	{
		return f2();
	}

	r2tm::TitleFunctionT LifeTimeTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Life Time";
		};
	}
	r2tm::DoFunctionT LifeTimeTest::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_NOTE( "1. Create a Tool That Helps You Understand Object LifeTime" );

				LF();

				DECL_MAIN( LifeTime lt = f3() );
			}

			LS();

			{
				OUT_NOTE( "2. Study The Lambda!!" );

				LF();

				DECL_MAIN( LifeTime lt = f3() );

				LF();

				DECL_MAIN( auto l = [ lt = std::move( lt ) ]() {} );

				LF();

				DECL_MAIN( auto l2 = l );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	// C++ Weekley with Jason Turners : Ep 333
	// https://www.youtube.com/watch?v=xJSKk_q25oQ
	template<typename T>
	class function;

	template<typename Ret, typename ... Param>
	class function<Ret (Param...)>
	{
	public:
		template<typename FunctionObject>
		function( FunctionObject fo )
			: mCallable( std::make_unique<callable_impl<FunctionObject>>( std::move( fo ) ) )
		{}

		Ret operator()( Param... param ) { return mCallable->call( param... ); }

	private:
		struct callable_interface
		{
			virtual Ret call( Param... ) = 0;
			virtual ~callable_interface() = default;
		};

		template<typename Callable>
		struct callable_impl : callable_interface
		{
			callable_impl( Callable callable_ ) : callable( std::move( callable_ ) )
			{}

			Ret call( Param... param )
			{
				//return callable( param... );
				return std::invoke( callable, param... );
			}

			Callable callable;
		};

		std::unique_ptr<callable_interface> mCallable;
	};

	int f( int x, int y )
	{
		return x + y;
	}

	r2tm::TitleFunctionT STDFunctionImplement::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Function Implement";
		};
	}
	r2tm::DoFunctionT STDFunctionImplement::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				function<int( int, int)> func( f );
				OUT_VALUE( func( 1, 2 ) );
			}

			LS();

			{
				function<int( int, int )> func( [z = 42]( int x, int y ) { return x + y + z; } );
				OUT_VALUE( func( 1, 2 ) );
			}

			LS();

			{
				//class T { public: int Do( int x, int y ) { return x + y; } } t;
				//function<int( int, int )> func( &T::Do );
				//OUT_VALUE( func( &t, 1, 2 ) );
			}

			LS();


			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Braces_PrimitiveType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "{}";
		};
	}
	r2tm::DoFunctionT Braces_PrimitiveType::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( int i{} );
				OUT_VALUE( i );
			}

			LS();

			{
				DECL_MAIN( int i = 123 );
				PROC_MAIN( i = {} );
				OUT_VALUE( i );
			}

			LS();

			{
				DECL_MAIN( std::shared_ptr<int> i = std::make_shared<int>( 123 ) );
				EXPECT_NE( nullptr, i );
				PROC_MAIN( i = {} );
				EXPECT_EQ( nullptr, i );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CircularReference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Circular Reference";
		};
	}
	r2tm::DoFunctionT CircularReference::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( struct A
			{
				std::shared_ptr<A> self;
			} );

			LS();

			{
				OUT_NOTE( "자기 참조" );

				LF();

				DECL_MAIN( auto a = std::make_shared<A>() );
				PROC_MAIN( a->self = a );

				LF();

				OUT_NOTE( "{} 를 벗어날 때 shared_ptr a 의 소멸자가 불린다." );
				OUT_NOTE( "ref count 가 2 라서 보유한 메모리에 delete 를 호출하지 않고 ref count 만 감소 시켜 1로 만든다." );
				OUT_NOTE( "A 의 소멸자가 불리지 않았기 때문에 self 는 그대로 남아있다." );
			}

			LS();

			{
				OUT_NOTE( "상호 참조" );

				LF();

				DECL_MAIN( auto a = std::make_shared<A>() );
				DECL_MAIN( auto b = std::make_shared<A>() );

				LF();

				PROC_MAIN( a->self = b );
				PROC_MAIN( b->self = a );

				LF();

				OUT_NOTE( "상호 참조가 되어 형태는 바뀌었지만 내용은 똑같다." );

				LF();

				OUT_NOTE( "{} 를 벗어날 때 shared_ptr a 의 소멸자가 불린다." );
				OUT_NOTE( "ref count 가 2 라서 보유한 메모리에 delete 를 호출하지 않고 ref count 만 감소 시켜 1로 만든다." );
				OUT_NOTE( "A 의 소멸자가 불리지 않았기 때문에 self 는 그대로 남아있다." );
			}

			LS();

			{
				OUT_NOTE( "순환 참조" );

				LF();

				DECL_MAIN( auto a = std::make_shared<A>() );
				DECL_MAIN( auto b = std::make_shared<A>() );
				DECL_MAIN( auto c = std::make_shared<A>() );

				LF();

				PROC_MAIN( a->self = b );
				PROC_MAIN( b->self = c );
				PROC_MAIN( c->self = a );

				LF();

				OUT_NOTE( "순환 참조가 되어 형태는 바뀌었지만 내용은 똑같다." );

				LF();

				OUT_NOTE( "{} 를 벗어날 때 shared_ptr a 의 소멸자가 불린다." );
				OUT_NOTE( "ref count 가 2 라서 보유한 메모리에 delete 를 호출하지 않고 ref count 만 감소 시켜 1로 만든다." );
				OUT_NOTE( "A 의 소멸자가 불리지 않았기 때문에 self 는 그대로 남아있다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT E::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "E";
		};
	}
	r2tm::DoFunctionT E::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_NOTE( "1e+4 = 1 * 10 * 10 * 10 * 10" );

				LF();

				DECL_MAIN( const double e = 1e+4 );
				OUT_VALUE( e );
			}

			LS();

			{
				OUT_NOTE( "1e-4 = 1 * ( 1/10 ) * ( 1/10 ) * ( 1/10 ) * ( 1/10 )" );

				LF();

				DECL_MAIN( const double e = 1e-4 );
				OUT_VALUE( e );
			}

			LS();

			{
				OUT_NOTE( "-1e+4 = -1 * 10 * 10 * 10 * 10" );

				LF();

				DECL_MAIN( const double e = -1e+4 );
				OUT_VALUE( e );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Init_Class_Array::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Init Class Array";
		};
	}
	r2tm::DoFunctionT Init_Class_Array::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "class 멤버인 배열은 {} 로 초기화 한다." );
			OUT_SUBJECT( "신기한데... o_o" );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			class C
			{
			public:
				using FunctionT = std::function<int( int* const properties )>;

				static int Function1( int* const ) { return 11; }
				static int Function2( int* const ) { return 22; }
				static int Function3( int* const ) { return 33; }

				C() : mA{ 1, 2, 3 }, mF{ Function1, Function2, Function3 }
				{}

				std::array<int, 3> mA;
				FunctionT mF[3];
			};


			OUT_SOURCE_END;

			LS();

			{
				DECL_MAIN( C c );

				LF();

				EXPECT_EQ( 1, c.mA[0] );
				EXPECT_EQ( 2, c.mA[1] );
				EXPECT_EQ( 3, c.mA[2] );

				LF();

				EXPECT_EQ( 11, c.mF[0]( nullptr ) );
				EXPECT_EQ( 22, c.mF[1]( nullptr ) );
				EXPECT_EQ( 33, c.mF[2]( nullptr ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Float_Binary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Float Binary";
		};
	}
	r2tm::DoFunctionT Float_Binary::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
			{
				LS();

				OUT_SOURCE_READY_N_BEGIN;
				const auto F = []( const float f )->void
				{
					static const int w = 8;

					const unsigned int mask = (unsigned int)-1;
					const unsigned int* up = reinterpret_cast<const unsigned int*>( &f );
					std::cout << r2tm::tab << std::left

						<< "값 : " << f << r2tm::linefeed
						<< "부호 : " << std::setw( w ) << ( ( *up >> 31 ) & 1 )
						<< "     "
						<< "지수 : " << std::setw( w ) << ( ( ( *up << 1 ) >> 24 ) & ( mask >> 24 ) )
						<< "     "
						<< "가수 : " << std::setw( w ) << ( ( ( *up << 9 ) >> 9 ) & ( mask >> 9 ) )

						<< std::right;

					r2tm::PrintBinary( f );
					r2tm::PrintBinary( ( *up >> 31 ) & 1 );
					r2tm::PrintBinary( ( ( *up << 1 ) >> 24 ) & ( mask >> 24 ) );
					r2tm::PrintBinary( ( ( *up << 9 ) >> 9 ) & ( mask >> 9 ) );
					LF();
				};
				OUT_SOURCE_END;

				LS();

				{
					OUT_BINARY( 0.f );
				}

				LS();

				{
					F( 1.f );

					LF();

					F( 2.f );

					LF();

					F( 3.f );

					LF();

					F( -1.f );
				}

				LS();

				{
					F( 0.1f );

					LF();

					F( 0.01f );

					LF();

					F( 0.00001f );
				}

				LS();

				return r2tm::eDoLeaveAction::Pause;
			};
	}



	class MyClass {
	public:
		int value = 99;

		// 비가상 멤버 함수
		void print_status() {
			// 이 함수 내에서 ECX 레지스터의 값이 'this' 포인터로 사용됨
			std::cout << "Value via assembly call: " << this->value << std::endl;
		}
	};

	// 멤버 함수 포인터 타입 정의
	using MemberFuncPtr = void ( MyClass::* )( );

	void ForceMemberCall_x86( MyClass* obj, MemberFuncPtr func_ptr ) {

		// 멤버 함수 포인터에서 실제 함수 주소 추출 (비가상 함수의 경우 단순 주소)
		// MSVC의 멤버 함수 포인터는 일반적으로 8바이트 (함수 주소 + delta/vtable index)
		// 비가상 함수의 경우 첫 4바이트(32bit)가 실제 함수 주소입니다.

		unsigned int func_addr;
		// memcpy 대신 union을 사용하는 것이 안전하고 명확합니다.
		union {
			MemberFuncPtr ptr;
			unsigned int parts[2]; // x86에서 주소 4바이트 + delta 4바이트 가정
		} u;
		u.ptr = func_ptr;
		func_addr = u.parts[0]; // 함수 주소 (첫 4바이트) 추출

		std::cout << "Attempting to call address: 0x" << std::hex << func_addr << std::dec << std::endl;

		__asm {
			// 1. ECX에 'this' 포인터 (obj) 로드 (__thiscall 규약)
			//    'obj' 변수의 값을 ECX 레지스터로 옮깁니다.
			mov ecx, obj

			// 2. 함수 주소(func_addr)를 EAX에 로드
			mov eax, func_addr

			// 3. EAX 레지스터가 가진 주소로 CALL (함수 호출)
			//    CALL 명령어는 반환 주소를 스택에 PUSH하고 EIP를 함수 주소로 변경
			call eax

			// __thiscall은 Callee가 스택을 정리하므로, 여기서는 스택 정리 코드가 필요 없음
		}
	}
	r2tm::TitleFunctionT Forced_Call::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Forced Call";
		};
	}
	r2tm::DoFunctionT Forced_Call::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "비가상 멤버 함수를 어셈블리로 강제 호출" );

			LS();

			{
				DECL_MAIN( MyClass s );
				DECL_MAIN( MemberFuncPtr ptr = &MyClass::print_status );

				SS();

				{
					OUT_NOTE( "정상 호출" );
					PROC_MAIN( ( s.*ptr )( ) );
				}

				SS();

				{
					OUT_NOTE( "강제 호출" );
					PROC_MAIN( ForceMemberCall_x86( &s, ptr ) );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}