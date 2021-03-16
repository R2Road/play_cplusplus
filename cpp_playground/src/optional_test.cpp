#include "optional_test.h"

#include <iostream>
#include <optional>

namespace optional_test
{
	void Basic::Do()
	{
		struct TestStruct
		{
			TestStruct() { std::cout << "- Call : TestStruct::TestStruct()"; }
			TestStruct( const TestStruct& ) { std::cout << "- Call : TestStruct::TestStruct( const TestStruct& )"; }

			int i = 0;
		};		

		std::cout << "== Optional : Basic ==" << std::endl;


		std::cout << "\t+ Make Test Struct" << std::endl;
		std::cout << "\t\t- TestStruct ts;" << std::endl;
		std::cout << "\t\t\t";
		TestStruct ts;
		std::cout << std::endl;


		std::cout << std::endl << std::endl;


		std::cout << "\t+ Make Optional" << std::endl;
		std::cout << "\t\t- std::optional<TestStruct> op_ts;" << std::endl;
		std::optional<TestStruct> op_ts;
		std::cout << "\t\t- Call : has_value()" << std::endl;
		std::cout << "\t\t\t" << op_ts.has_value() << std::endl;
		//std::cout << "\t\t\t" << op_ts.value().i << std::endl; // throw exception : op_ts is nullopt


		std::cout << std::endl << std::endl;


		std::cout << "\t+ Assign 2 Optional " << std::endl;
		std::cout << "\t\t- op_ts = ts" << std::endl;
		std::cout << "\t\t\t";
		op_ts = ts;
		std::cout << std::endl;
		std::cout << "\t\t- Call : has_value()" << std::endl;
		std::cout << "\t\t\t" << op_ts.has_value() << std::endl;


		std::cout << std::endl << std::endl;
	}
}