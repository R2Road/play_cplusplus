#include "pointer_test.h"

#include "r2cm/r2cm_ostream.h"

namespace pointer_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
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



#pragma warning( disable : 4311 )
#pragma warning( disable : 4302 )

	r2cm::iItem::TitleFunctionT Pointer2Index::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer 2 Index";
		};
	}
	r2cm::iItem::DoFunctionT Pointer2Index::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int i = 0;
				int* pi = &i;
				int32_t i32 = (int32_t)( &i );
				int64_t i64_1 = (int64_t)( &i );
				int64_t i64_2 = reinterpret_cast<int64_t>( &i );

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "int i = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "int* pi = &i;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "int32_t i32 = (int32_t)( &i );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "int64_t i64_1 = (int64_t)( &i );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "int64_t i64_2 = reinterpret_cast<int64_t>( &i );" << r2cm::linefeed;
				std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ ...." << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "pi : " << pi << r2cm::linefeed;
				std::cout << r2cm::tab2 << "i32 : " << i32 << r2cm::tab2 << " ...64bit 에서 잘림 Platform 신경써." << r2cm::linefeed;
				std::cout << r2cm::tab2 << "i64_1 dec : " << std::dec << i64_1 << r2cm::linefeed;
				std::cout << r2cm::tab2 << "i64_1 hex : " << std::hex << i64_1 << r2cm::linefeed;
				std::cout << r2cm::tab2 << "i64_2 hex : " << i64_2 << r2cm::linefeed;

				// rollback
				std::cout << std::dec;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ConstPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Const Pointer";
		};
	}
	r2cm::iItem::DoFunctionT ConstPointer::GetDoFunction()
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