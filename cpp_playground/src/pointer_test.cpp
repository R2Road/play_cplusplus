#include "pch.h"
#include "pointer_test.h"

#include "r2_eTestResult.h"

namespace pointer_test
{
	const r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer";
		};
	}
	const r2::iTest::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "int i = 123;" << r2::linefeed;
				std::cout << "\t" << "int* ip= &i;" << r2::linefeed;
				int i = 123;
				int* ip = &i;

				std::cout << "\t + " << "adress of ip " << r2::linefeed;
				std::cout << "\t\t - " << ip << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "int ip[] = { 123, 234, 456 };" << r2::linefeed;
				int ip[] = { 123, 234, 456 };

				std::cout << "\t + " << "adress of ip " << r2::linefeed;
				std::cout << "\t\t - " << ip << r2::linefeed;

				std::cout << "\t + " << "ip + 1;" << r2::linefeed;
				std::cout << "\t\t - " << ip + 1 << r2::linefeed;

				std::cout << "\t + " << "offset : ( ( ip + 1 ) - ip )" << r2::linefeed;
				std::cout << "\t\t - " << ( ( ip + 1 ) - ip ) << r2::linefeed << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "int t1 = ( int )ip" << r2::linefeed;
				std::cout << "\t" << "int t2 = ( int )( ip + 1 );" << r2::linefeed;
				std::cout << "\t + " << "offset : ( t2 - t1 )" << r2::linefeed;
				auto t1 = reinterpret_cast<std::size_t>( ip );
				auto t2 = reinterpret_cast<std::size_t>( ip + 1 );
				std::cout << "\t\t - " << ( t2 - t1 ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}




namespace pointer_test
{
	const r2::iTest::TitleFunc ConstPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Const Pointer";
		};
	}
	const r2::iTest::DoFunc ConstPointer::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "int temp_int_1 = 0;" << r2::linefeed;
				std::cout << "\t" << "int temp_int_2 = 0;" << r2::linefeed;
				int temp_int_1 = 0;
				int temp_int_2 = 0;

				std::cout << r2::linefeed;

				std::cout << "\t" << "+ const int* temp_const_pointer = &temp_int_1;" << r2::linefeed << r2::linefeed;
				const int* temp_const_pointer = &temp_int_1;

				std::cout << "\t\t" << "OK : temp_const_pointer = &temp_int_2;" << r2::linefeed;
				temp_const_pointer = &temp_int_2;

				std::cout << "\t\t" << "Error : *temp_const_pointer = temp_int_2; " << r2::linefeed;
				//*temp_const_pointer = temp_int_2;


				std::cout << r2::linefeed << r2::linefeed;


				std::cout << "\t" << "+ int* const temp_pointer_const = &temp_int_1;" << r2::linefeed << r2::linefeed;
				int* const temp_pointer_const = &temp_int_1;

				std::cout << "\t\t" << "Error : temp_pointer_const = &temp_int_2;" << r2::linefeed;
				//temp_pointer_const = &temp_int_2;

				std::cout << "\t\t" << "OK : *temp_pointer_const = temp_int_2;" << r2::linefeed;
				*temp_pointer_const = temp_int_2;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "const int temp_const_int_1 = 0;" << r2::linefeed;
				const int temp_const_int_1 = 0;

				std::cout << r2::linefeed;

				std::cout << "\t" << "OK : const int* temp_pointer_const = &temp_const_int_1;" << r2::linefeed;
				const int* temp_pointer_const = &temp_const_int_1;

				std::cout << r2::linefeed;

				std::cout << "\t" << "Error : int* const temp_pointer_const = &temp_const_int_1;" << r2::linefeed;
				//int* const temp_pointer_const = &temp_const_int_1;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}