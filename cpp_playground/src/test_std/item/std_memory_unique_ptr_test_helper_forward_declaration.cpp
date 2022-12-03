#include "std_memory_unique_ptr_test_helper_forward_declaration.h"

namespace std_memory_test_helper_up_and_forward_declaration
{
	struct ProcessorImpl
	{
	};

	void ProcessorImplDeleter::operator()( ProcessorImpl* p )
	{
		delete p;
	}
}