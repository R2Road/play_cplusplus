#include <stdint.h>
#include "r2cm/r2cm_ostream.h"

#include <list>

namespace template_practice_test_02
{
	void TestFunction()
	{
		std::cout << "\t" "> " "TestFunction : " << r2cm::linefeed;
	}

	struct FuncContainer
	{
		std::list<void( *)( )> container;

		template<typename ReturnValueT>
		void push_functor( ReturnValueT(*func)() )
		{
			container.push_back( func );
		}

		template<typename T>
		void def( const char* name, T func )
		{
			std::cout << "def" << r2cm::linefeed;
			push_functor( func );
		}

		void CallAll()
		{
			for( auto& f : container )
			{
				f();
			}
		}
	};
}