#include "std_mem_fn_test.h"
#include "std_mem_fn_test_helper.hpp"

#include <functional>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_mem_fn_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::mem_fn : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			SHOW_FILE( "src/test_std/item/std_mem_fn_test_helper.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( TestStruct t );
				DECLARATION_MAIN( auto do_fn =  std::mem_fn( &TestStruct::Do ) );
				PROCESS_MAIN( do_fn( &t ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}