#include <stdio.h>

namespace std_functional_invoke_test
{
	void Do( int i )
	{
		printf( "\t" "> " "Do : " "%d" "\n", i );
	}

	auto do_lam = []( int i )
	{
		printf( "\t" "> " "do_lam : " "%d" "\n", i );
	};

	struct S1
	{
		void Do( int i )
		{
			printf( "\t" "> " "S1::Do : " "%d" "\n", i );
		}
	};

	struct S2
	{
		int n = 777;
	};
}