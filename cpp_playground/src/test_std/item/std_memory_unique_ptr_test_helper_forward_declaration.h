#include <memory>

//
// # REF
// https://stackoverflow.com/questions/9954518/stdunique-ptr-with-an-incomplete-type-wont-compile/17950450#17950450
//

namespace std_memory_unique_ptr_test_helper_forward_declaration
{
	struct ProcessorImpl;
	struct ProcessorImplDeleter
	{
		void operator()( ProcessorImpl* p );
	};

	struct Processor
	{	
		std::unique_ptr<ProcessorImpl, ProcessorImplDeleter> mImpl;
	};
}