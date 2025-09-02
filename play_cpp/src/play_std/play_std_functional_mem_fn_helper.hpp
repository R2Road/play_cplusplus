#include <stdio.h>

namespace play_std_functional_mem_fn
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