#include "etc_0_test.h"

#include <bitset>
#include <memory>
#include <stdint.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace etc_test
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
				std::cout << r2tm::tab << "+ Use For" << r2tm::linefeed2;

				DECLARATION_MAIN( const int num = 0b10110010101 ); // binary

				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab;
				for( int i = 31; 0 <= i; --i )
				{
					const int temp_1 = ( num >> i );
					const int temp_2 = temp_1 & 1;

					std::cout << temp_2;
				}
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Use Bitset" << r2tm::linefeed2;

				DECLARATION_MAIN( const int num = 0b0011001 ); // binary
				DECLARATION_MAIN( std::bitset<16u> b( num ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( b );
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
				OUTPUT_NOTE( "1. Create a Tool That Helps You Understand Object LifeTime" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( LifeTime lt = f3() );
			}

			LS();

			{
				OUTPUT_NOTE( "2. Study The Lambda!!" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( LifeTime lt = f3() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto l = [ lt = std::move( lt ) ]() {} );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto l2 = l );
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
				OUTPUT_VALUE( func( 1, 2 ) );
			}

			LS();

			{
				function<int( int, int )> func( [z = 42]( int x, int y ) { return x + y + z; } );
				OUTPUT_VALUE( func( 1, 2 ) );
			}

			LS();

			{
				//class T { public: int Do( int x, int y ) { return x + y; } } t;
				//function<int( int, int )> func( &T::Do );
				//OUTPUT_VALUE( func( &t, 1, 2 ) );
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
				DECLARATION_MAIN( int i{} );
				OUTPUT_VALUE( i );
			}

			LS();

			{
				DECLARATION_MAIN( int i = 123 );
				PROCESS_MAIN( i = {} );
				OUTPUT_VALUE( i );
			}

			LS();

			{
				DECLARATION_MAIN( std::shared_ptr<int> i = std::make_shared<int>( 123 ) );
				EXPECT_NE( nullptr, i );
				PROCESS_MAIN( i = {} );
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

			DECLARATION_MAIN( struct A
			{
				std::shared_ptr<A> self;
			} );

			LS();

			{
				OUTPUT_NOTE( "자기 참조" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto a = std::make_shared<A>() );
				PROCESS_MAIN( a->self = a );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "{} 를 벗어날 때 shared_ptr a 의 소멸자가 불린다." );
				OUTPUT_NOTE( "ref count 가 2 라서 보유한 메모리에 delete 를 호출하지 않고 ref count 만 감소 시켜 1로 만든다." );
				OUTPUT_NOTE( "A 의 소멸자가 불리지 않았기 때문에 self 는 그대로 남아있다." );
			}

			LS();

			{
				OUTPUT_NOTE( "상호 참조" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto a = std::make_shared<A>() );
				DECLARATION_MAIN( auto b = std::make_shared<A>() );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( a->self = b );
				PROCESS_MAIN( b->self = a );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "상호 참조가 되어 형태는 바뀌었지만 내용은 똑같다." );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "{} 를 벗어날 때 shared_ptr a 의 소멸자가 불린다." );
				OUTPUT_NOTE( "ref count 가 2 라서 보유한 메모리에 delete 를 호출하지 않고 ref count 만 감소 시켜 1로 만든다." );
				OUTPUT_NOTE( "A 의 소멸자가 불리지 않았기 때문에 self 는 그대로 남아있다." );
			}

			LS();

			{
				OUTPUT_NOTE( "순환 참조" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( auto a = std::make_shared<A>() );
				DECLARATION_MAIN( auto b = std::make_shared<A>() );
				DECLARATION_MAIN( auto c = std::make_shared<A>() );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( a->self = b );
				PROCESS_MAIN( b->self = c );
				PROCESS_MAIN( c->self = a );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "순환 참조가 되어 형태는 바뀌었지만 내용은 똑같다." );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "{} 를 벗어날 때 shared_ptr a 의 소멸자가 불린다." );
				OUTPUT_NOTE( "ref count 가 2 라서 보유한 메모리에 delete 를 호출하지 않고 ref count 만 감소 시켜 1로 만든다." );
				OUTPUT_NOTE( "A 의 소멸자가 불리지 않았기 때문에 self 는 그대로 남아있다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}