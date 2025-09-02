#include "play_std_memory_unique_ptr_helper___forward_declaration.hpp"

namespace play_std_memory_unique_ptr_helper___forward_declaration
{
	struct ProcessorImpl
	{
	};

	void ProcessorImplDeleter::operator()( ProcessorImpl* p )
	{
		delete p;
	}
}