#include "shared_pointer_test.h"

#include <iostream>
#include <memory>

namespace shared_pointer_test
{
	void SharedPtr::Do()
	{
		std::cout << "== Shared Pointer ==" << std::endl;

		std::shared_ptr<int> test_sp( new int( 10 ) );
		std::cout << "\t" << "+ Make Sp" << std::endl;
		std::cout << "\t\t" << *test_sp << std::endl;

		const auto test_sp_2 = test_sp;
		std::cout << "\t" << "+ Copy To Const Sp" << std::endl;

		*test_sp_2 = 11;
		std::cout << "\t" << "+ Change Value with Const Sp" << std::endl;
		std::cout << "\t\t" << *test_sp_2 << std::endl;


		std::shared_ptr<const int> const_test_sp( new int( 10 ) );
		std::cout << "\t" << "+ Make Sp Has Const Value" << std::endl;
		std::cout << "\t\t" << *const_test_sp << std::endl;

		//*const_test_sp = 11;
		//std::cout << "\t" << "+ Change Value with Sp Has Const Value" << std::endl;
		//std::cout << "\t\t" << *const_test_sp << std::endl;
	}
}