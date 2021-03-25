#include "structured_binding_test.h"

#include <iostream>
#include <utility>

namespace structured_binding_test
{
	void Basic::Do()
	{
		std::cout << "== Structured Binding : Basic ==" << std::endl;


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ Basic" << std::endl;

			std::cout << "\t\t" << "struct TestStruct" << std::endl;
			std::cout << "\t\t" << "{" << std::endl;
			std::cout << "\t\t\t" << "int i = 1;" << std::endl;
			std::cout << "\t\t\t" << "char c = 'a';" << std::endl;
			std::cout << "\t\t\t" << "bool b = true;" << std::endl;
			std::cout << "\t\t" << "};" << std::endl << std::endl;

			struct TestStruct
			{
				int i = 1;
				char c = 'a';
				float f = 3.14f;
			};

			std::cout << "\t\t" << "TestStruct t;" << std::endl << std::endl;
			TestStruct t;

			std::cout << "\t\t" << "auto[i, c, b] = t;" << std::endl;
			auto[i, c, f] = t;

			std::cout << "\t\t\t" << " - i : " << i << std::endl;
			std::cout << "\t\t\t" << " - c : " << c << std::endl;
			std::cout << "\t\t\t" << " - f : " << f << std::endl;
		}


		std::cout << std::endl << std::endl;
	}
}