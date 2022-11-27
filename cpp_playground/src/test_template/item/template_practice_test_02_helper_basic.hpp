#include <stdint.h>
#include "r2cm/r2cm_ostream.h"

#include <map>

namespace template_practice_test_02
{
	void FN_V_A0()
	{
		printf( "\t" "> " "FN_V_A0()" "\n" );
	}
	void FN_V_A1( int i )
	{
		printf( "\t" "> " "FN_V_A1() : %d" "\n", i );
	}
	void FN_V_A3( int i, int j, int k )
	{
		printf( "\t" "> " "FN_V_A3() : %d, %d, %d" "\n", i, j, k );
	}

	struct FuncContainer
	{
		std::map<const char*, void*> container;

		template<typename ReturnValueT>
		void push_functor( const char* name, ReturnValueT(*func)() )
		{
			container.emplace( name, func );
		}

		template<typename ReturnValueT, typename ArgumentT>
		void push_functor( const char* name, ReturnValueT( *func )( ArgumentT ) )
		{
			container.emplace( name, func );
		}

		template<typename ReturnValueT, typename T1, typename T2, typename T3>
		void push_functor( const char* name, ReturnValueT( *func )( T1, T2, T3 ) )
		{
			container.emplace( name, func );
		}

		template<typename T>
		void def( const char* name, T func )
		{
			std::cout << "def" << r2cm::linefeed;
			push_functor( name, func );
		}

		template<typename ReturnValueT, typename T1 = void, typename T2 = void, typename T3 = void, typename T4 = void>
		ReturnValueT Call( const char* name, T1 t1, T2 t2, T3 t3, T4 t4 )
		{
			std::cout << "Call : R, A4" "\n";

			const auto f = container.find( name );
			auto rf = ( ReturnValueT( *)( T1, T2, T3, T4 ) )( f->second );
			return rf( t1, t2, t3, t4 );
		}

		template<typename ReturnValueT, typename T1 = void, typename T2 = void, typename T3 = void>
		ReturnValueT Call( const char* name, T1 t1, T2 t2, T3 t3 )
		{
			std::cout << "Call : R, A3" "\n";

			const auto f = container.find( name );
			auto rf = ( ReturnValueT( *)( T1, T2, T3 ) )( f->second );
			return rf( t1, t2, t3 );
		}

		template<typename ReturnValueT, typename T1>
		ReturnValueT Call( const char* name, T1 t1 )
		{
			std::cout << "Call : R, A1" "\n";

			const auto f = container.find( name );
			auto rf = ( ReturnValueT( *)( T1 ) )( f->second );
			return rf( t1 );
		}

		template<typename ReturnValueT>
		ReturnValueT Call( const char* name )
		{
			std::cout << "Call : V, A0" "\n";

			const auto f = container.find( name );
			auto rf = ( void( *)( ) )( f->second );
			return rf();
		}
	};
}