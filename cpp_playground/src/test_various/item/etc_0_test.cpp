#include "etc_0_test.h"

#include <bitset>
#include <stdint.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace etc_test
{
	r2cm::iItem::TitleFunctionT ShowBinary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Show Binary";
		};
	}
	r2cm::iItem::DoFunctionT ShowBinary::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Use For" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 0b10110010101 ); // binary

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab;
				for( int i = 31; 0 <= i; --i )
				{
					const int temp_1 = ( num >> i );
					const int temp_2 = temp_1 & 1;

					std::cout << temp_2;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Use Bitset" << r2cm::linefeed2;

				DECLARATION_MAIN( const int num = 0b0011001 ); // binary
				DECLARATION_MAIN( std::bitset<16u> b( num ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( b );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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

	r2cm::iItem::TitleFunctionT LifeTimeTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Life Time";
		};
	}
	r2cm::iItem::DoFunctionT LifeTimeTest::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "1. Create a Tool That Helps You Understand Object LifeTime" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( LifeTime lt = f3() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "2. Study The Lambda!!" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( LifeTime lt = f3() );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto l = [ lt = std::move( lt ) ]() {} );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto l2 = l );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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
		function( Ret( *f )( Param... ) ) :
			mCallable( std::make_unique<callable_impl<Ret( *)( Param... ) >>( f ) )
		{}

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
				return callable( param... );
			}

			Callable callable;
		};

		std::unique_ptr<callable_interface> mCallable;
	};

	int f( int x, int y )
	{
		return x + y;
	}

	r2cm::iItem::TitleFunctionT STDFunctionImplement::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Function Implement";
		};
	}
	r2cm::iItem::DoFunctionT STDFunctionImplement::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				function<int( int, int)> func( f );
				PROCESS_MAIN( func( 1, 2 ) );
			}

			std::cout << r2cm::split;

			{
				function<int( int, int )> func( []( int x, int y ) { return x + y; } );
				PROCESS_MAIN( func( 1, 2 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}