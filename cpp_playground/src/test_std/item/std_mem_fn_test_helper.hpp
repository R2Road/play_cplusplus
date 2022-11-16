#include <stdio.h>

namespace std_mem_fn_test
{
	struct TestStruct
	{
		void Do()
		{
			printf( "\t" "> " "TestStruct::Do" "\n" );
		}
	};
}