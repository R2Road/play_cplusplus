#include <memory>
#include <stdio.h>

namespace play_std_memory_unique_ptr_helper_template_deleter
{
	template<typename T>
	struct Deleter
	{
		void operator()( T* p )
		{
			delete p;
			puts( "TDeleter::operator()" );
		}
	};

	template<typename T>
	using U = std::unique_ptr<int, Deleter<T>>;
}