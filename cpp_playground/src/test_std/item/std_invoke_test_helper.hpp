#include <stdio.h>

namespace std_invoke_test
{
	void Do( int i )
	{
		printf( "\t" "> " "Do : " "%d" "\n", i );
	}

	auto do_lam = []( int i )
	{
		printf( "\t" "> " "do_lam : " "%d" "\n", i );
	};

	struct TestStruct_1
	{
		void Do( int i )
		{
			printf( "\t" "> " "TestStruct_1::Do : " "%d" "\n", i );
		}
	};

	struct TestStruct_2
	{
		int n = 777;
	};
}