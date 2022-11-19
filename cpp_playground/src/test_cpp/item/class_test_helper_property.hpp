#include <stdio.h>

namespace class_test_helper_property
{
	class TestClass
	{
	public:
		int a;
		int b;

		void Func1()
		{
			printf( "\t" "> " "[Call] TestClass::Func1" "\n" );
		}
		void Func2()
		{
			printf( "\t" "> " "[Call] TestClass::Func2" "\n" );
		}

		int c;
	};
}