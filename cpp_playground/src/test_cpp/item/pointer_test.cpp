#include "pch.h"
#include "pointer_test.h"

#include "r2cm/r2cm_constant.h"

namespace pointer_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "int i = 123;" << r2cm::linefeed;
				std::cout << r2cm::tab << "int* ip= &i;" << r2cm::linefeed;
				int i = 123;
				int* ip = &i;

				std::cout << r2cm::tab << "+ adress of ip " << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << ip << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "int ip[] = { 123, 234, 456 };" << r2cm::linefeed;
				int ip[] = { 123, 234, 456 };

				std::cout << r2cm::tab << "+ adress of ip " << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << ip << r2cm::linefeed;

				std::cout << r2cm::tab << "+ ip + 1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << ip + 1 << r2cm::linefeed;

				std::cout << r2cm::tab << "+ offset : ( ( ip + 1 ) - ip )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << ( ( ip + 1 ) - ip ) << r2cm::linefeed << r2cm::linefeed << r2cm::linefeed;

				

				std::cout << r2cm::tab << "auto t1 = reinterpret_cast<std::size_t>( ip );" << r2cm::linefeed;
				std::cout << r2cm::tab << "auto t2 = reinterpret_cast<std::size_t>( ip + 1 );;" << r2cm::linefeed;
				auto t1 = reinterpret_cast<std::size_t>( ip );
				auto t2 = reinterpret_cast<std::size_t>( ip + 1 );

				std::cout << r2cm::tab2 << " - t1 : " << t1 << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- t2 : " << t2 << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- offset ( t2 - t1 ) : " << ( t2 - t1 ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}




namespace pointer_test
{
	r2cm::iItem::TitleFuncT ConstPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Const Pointer";
		};
	}
	r2cm::iItem::DoFuncT ConstPointer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "int temp_int_1 = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab << "int temp_int_2 = 0;" << r2cm::linefeed;
				int temp_int_1 = 0;
				int temp_int_2 = 0;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ const int* temp_const_pointer = &temp_int_1;" << r2cm::linefeed << r2cm::linefeed;
				const int* temp_const_pointer = &temp_int_1;

				std::cout << r2cm::tab2 << "OK : temp_const_pointer = &temp_int_2;" << r2cm::linefeed;
				temp_const_pointer = &temp_int_2;

				std::cout << r2cm::tab2 << "Error : *temp_const_pointer = temp_int_2; " << r2cm::linefeed;
				//*temp_const_pointer = temp_int_2;


				std::cout << r2cm::linefeed << r2cm::linefeed;


				std::cout << r2cm::tab << "+ int* const temp_pointer_const = &temp_int_1;" << r2cm::linefeed << r2cm::linefeed;
				int* const temp_pointer_const = &temp_int_1;

				std::cout << r2cm::tab2 << "Error : temp_pointer_const = &temp_int_2;" << r2cm::linefeed;
				//temp_pointer_const = &temp_int_2;

				std::cout << r2cm::tab2 << "OK : *temp_pointer_const = temp_int_2;" << r2cm::linefeed;
				*temp_pointer_const = temp_int_2;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "const int temp_const_int_1 = 0;" << r2cm::linefeed;
				//const int temp_const_int_1 = 0;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "OK : const int* temp_pointer_const = &temp_const_int_1;" << r2cm::linefeed;
				//const int* temp_pointer_const = &temp_const_int_1;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "Error : int* const temp_pointer_const = &temp_const_int_1;" << r2cm::linefeed;
				//int* const temp_pointer_const = &temp_const_int_1;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}