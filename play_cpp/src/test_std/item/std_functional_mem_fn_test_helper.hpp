#include <stdio.h>

namespace std_functional_mem_fn_test
{
	struct TestStruct
	{
		int a = 0;

		void Do()
		{
			printf( "\t" "> " "TestStruct::Do" "\n" );
		}
	};
}