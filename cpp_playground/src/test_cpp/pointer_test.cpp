#include "pch.h"
#include "pointer_test.h"

#include "base/r2_eTestEndAction.h"

namespace pointer_test
{
	r2::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer";
		};
	}
	r2::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "int i = 123;" << r2::linefeed;
				std::cout << r2::tab << "int* ip= &i;" << r2::linefeed;
				int i = 123;
				int* ip = &i;

				std::cout << r2::tab << "+ adress of ip " << r2::linefeed;
				std::cout << r2::tab2 << "- " << ip << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "int ip[] = { 123, 234, 456 };" << r2::linefeed;
				int ip[] = { 123, 234, 456 };

				std::cout << r2::tab << "+ adress of ip " << r2::linefeed;
				std::cout << r2::tab2 << "- " << ip << r2::linefeed;

				std::cout << r2::tab << "+ ip + 1;" << r2::linefeed;
				std::cout << r2::tab2 << "- " << ip + 1 << r2::linefeed;

				std::cout << r2::tab << "+ offset : ( ( ip + 1 ) - ip )" << r2::linefeed;
				std::cout << r2::tab2 << "- " << ( ( ip + 1 ) - ip ) << r2::linefeed << r2::linefeed << r2::linefeed;

				

				std::cout << r2::tab << "auto t1 = reinterpret_cast<std::size_t>( ip );" << r2::linefeed;
				std::cout << r2::tab << "auto t2 = reinterpret_cast<std::size_t>( ip + 1 );;" << r2::linefeed;
				auto t1 = reinterpret_cast<std::size_t>( ip );
				auto t2 = reinterpret_cast<std::size_t>( ip + 1 );

				std::cout << r2::tab2 << " - t1 : " << t1 << r2::linefeed;
				std::cout << r2::tab2 << "- t2 : " << t2 << r2::linefeed;
				std::cout << r2::tab2 << "- offset ( t2 - t1 ) : " << ( t2 - t1 ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}




namespace pointer_test
{
	r2::iItem::TitleFuncT ConstPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Const Pointer";
		};
	}
	r2::iItem::DoFuncT ConstPointer::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "int temp_int_1 = 0;" << r2::linefeed;
				std::cout << r2::tab << "int temp_int_2 = 0;" << r2::linefeed;
				int temp_int_1 = 0;
				int temp_int_2 = 0;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ const int* temp_const_pointer = &temp_int_1;" << r2::linefeed << r2::linefeed;
				const int* temp_const_pointer = &temp_int_1;

				std::cout << r2::tab2 << "OK : temp_const_pointer = &temp_int_2;" << r2::linefeed;
				temp_const_pointer = &temp_int_2;

				std::cout << r2::tab2 << "Error : *temp_const_pointer = temp_int_2; " << r2::linefeed;
				//*temp_const_pointer = temp_int_2;


				std::cout << r2::linefeed << r2::linefeed;


				std::cout << r2::tab << "+ int* const temp_pointer_const = &temp_int_1;" << r2::linefeed << r2::linefeed;
				int* const temp_pointer_const = &temp_int_1;

				std::cout << r2::tab2 << "Error : temp_pointer_const = &temp_int_2;" << r2::linefeed;
				//temp_pointer_const = &temp_int_2;

				std::cout << r2::tab2 << "OK : *temp_pointer_const = temp_int_2;" << r2::linefeed;
				*temp_pointer_const = temp_int_2;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "const int temp_const_int_1 = 0;" << r2::linefeed;
				//const int temp_const_int_1 = 0;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "OK : const int* temp_pointer_const = &temp_const_int_1;" << r2::linefeed;
				//const int* temp_pointer_const = &temp_const_int_1;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Error : int* const temp_pointer_const = &temp_const_int_1;" << r2::linefeed;
				//int* const temp_pointer_const = &temp_const_int_1;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}