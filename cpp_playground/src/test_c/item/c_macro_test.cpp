#include "c_macro_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_macro_test
{
#define MACRO2STRING( x ) #x

	r2cm::iItem::TitleFunctionT ToString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "macro : to string";
		};
	}
	r2cm::iItem::DoFunctionT ToString::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "#define MACRO2STRING( x ) #x" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int test_int = 3456 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( MACRO2STRING( test_int ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}