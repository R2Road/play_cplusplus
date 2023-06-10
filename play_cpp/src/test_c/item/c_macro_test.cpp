#include "c_macro_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_macro_test
{
#define MACRO2STRING( x ) #x

	r2tm::TitleFunctionT ToString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "macro : to string";
		};
	}
	r2tm::DoFunctionT ToString::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "#define MACRO2STRING( x ) #x" << r2tm::linefeed;

			LS();

			{
				DECLARATION_MAIN( const int test_int = 3456 );

				LF();

				OUTPUT_VALUE( MACRO2STRING( test_int ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}