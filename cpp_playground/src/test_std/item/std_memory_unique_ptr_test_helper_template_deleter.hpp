#include <stdio.h>

namespace std_memory_unique_ptr_test_helper_template_deleter
{
	template<typename T>
	struct TDeleter
	{
		void operator()( T* p )
		{
			delete p;
			puts( "TDeleter::operator()" );
		}
	};
}