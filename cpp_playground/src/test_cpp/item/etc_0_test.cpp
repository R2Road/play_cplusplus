#include "etc_0_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2cm/r2cm_constant.h"

namespace etc_test
{
#define MACRO2STRING( x ) #x

	r2cm::iItem::TitleFunctionT Macro2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Macro 2 String";
		};
	}
	r2cm::iItem::DoFunctionT Macro2String::GetDoFunction()
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
}