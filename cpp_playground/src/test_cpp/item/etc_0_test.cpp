#include "pch.h"
#include "etc_0_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2cm/r2cm_constant.h"

namespace etc_test
{
	r2cm::iItem::TitleFuncT XOR_Swap::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XOR Swap";
		};
	}
	r2cm::iItem::DoFuncT XOR_Swap::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int a = 123;
				int b = 456;

				std::cout << r2cm::tab << "int a = 123;" << r2cm::linefeed;
				std::cout << r2cm::tab << "int b = 456;" << r2cm::linefeed;
				std::cout << r2cm::linefeed2;

				a = a ^ b;
				std::cout << r2cm::tab << "a = a ^ b;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "a : " << a << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				b = b ^ a;
				std::cout << r2cm::tab << "b = b ^ a;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "b : " << b << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				a = a ^ b;
				std::cout << r2cm::tab << "a = a ^ b;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "a : " << a << r2cm::linefeed;
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}

namespace etc_test
{
	r2cm::iItem::TitleFuncT InitArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Init Array";
		};
	}
	r2cm::iItem::DoFuncT InitArray::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int array[10];
				std::cout << r2cm::tab2 << "int array[10];" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int array[10] = { 0, };
				std::cout << r2cm::tab2 << "int array[10] = { 0, };" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int array[10] = { '\0', };
				std::cout << r2cm::tab2 << "int array[10] = { \'\\0\', };" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int array[10] = {};
				std::cout << r2cm::tab2 << "int array[10] = {};" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}

namespace etc_test
{
#define MACRO2STRING( x ) #x

	r2cm::iItem::TitleFuncT Macro2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Macro 2 String";
		};
	}
	r2cm::iItem::DoFuncT Macro2String::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int test_int = 3456;

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "#define MACRO2STRING( x ) #x" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "int test_int = " << test_int << ";" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << MACRO2STRING( test_int ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



#pragma warning( disable : 4311 )
#pragma warning( disable : 4302 )

	r2cm::iItem::TitleFuncT Pointer2Index::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer 2 Index";
		};
	}
	r2cm::iItem::DoFuncT Pointer2Index::GetDoFunction()
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
}