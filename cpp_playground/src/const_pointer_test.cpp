#include "const_pointer_test.h"

#include <iostream>

namespace const_pointer_test
{
	void Basic::Do()
	{
		std::cout << "== Const Pointer ==" << std::endl << std::endl;

		std::cout << "\t" << "int temp_int_1 = 0;" << std::endl;
		std::cout << "\t" << "int temp_int_2 = 0;" << std::endl;
		int temp_int_1 = 0;
		int temp_int_2 = 0;

		std::cout << std::endl;

		{
			std::cout << "\t" << "+ const int* temp_const_pointer = &temp_int_1;" << std::endl;
			const int* temp_const_pointer = &temp_int_1;

			std::cout << "\t\t" << "OK : temp_const_pointer = &temp_int_2;" << std::endl;
			temp_const_pointer = &temp_int_2;

			std::cout << "\t\t" << "Error : *temp_const_pointer = temp_int_2; " << std::endl;
			//*temp_const_pointer = temp_int_2;
		}

		std::cout << std::endl;

		{
			std::cout << "\t" << "+ int* const temp_pointer_const = &temp_int_1;" << std::endl;
			int* const temp_pointer_const = &temp_int_1;

			std::cout << "\t\t" << "Error : temp_pointer_const = &temp_int_2;" << std::endl;
			//temp_pointer_const = &temp_int_2;

			std::cout << "\t\t" << "OK : *temp_pointer_const = temp_int_2;" << std::endl;
			*temp_pointer_const = temp_int_2;
		}



		std::cout << std::endl << std::endl;



		std::cout << "\t" << "const int temp_const_int_1 = 0;" << std::endl;
		const int temp_const_int_1 = 0;

		std::cout << std::endl;

		{
			std::cout << "\t" << "OK : const int* temp_pointer_const = &temp_const_int_1;" << std::endl;
			const int* temp_pointer_const = &temp_const_int_1;
		}

		std::cout << std::endl;

		{
			std::cout << "\t" << "Error : int* const temp_pointer_const = &temp_const_int_1;" << std::endl;
			//int* const temp_pointer_const = &temp_const_int_1;
		}
	}
}