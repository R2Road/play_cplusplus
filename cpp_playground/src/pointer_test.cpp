#include "pointer_test.h"

#include <iostream>

#include "r2_eTestResult.h"

namespace pointer_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Basic ==" << std::endl << std::endl;

			std::cout << "\t" << "int i = 123;" << std::endl;
			std::cout << "\t" << "int* ip= &i;" << std::endl;
			int i = 123;
			int* ip= &i;

			std::cout << std::endl;

			{
				std::cout << "\t\t" << "adress : " << ip << std::endl;
			}

			std::cout << std::endl;

			return r2::eTestResult::RunTest;
		};
	}
}




namespace pointer_test
{
	const r2::iNode::TitleFunc ConstPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Const Pointer";
		};
	}
	const r2::iNode::DoFunc ConstPointer::GetDoFunction() const
	{
		return []()->r2::eTestResult
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

			return r2::eTestResult::RunTest;
		};
	}
}