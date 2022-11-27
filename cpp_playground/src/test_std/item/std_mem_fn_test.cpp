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

			OUTPUT_FILE( "src/test_std/item/std_mem_fn_test_helper.hpp" );

			std::cout << r2cm::split;

			DECLARATION_MAIN( TestStruct t );
			PROCESS_MAIN( t.a = 123 );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto do_fn =  std::mem_fn( &TestStruct::Do ) );
				PROCESS_MAIN( do_fn( &t ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto do_mv = std::mem_fn( &TestStruct::a ) );
				OUTPUT_VALUE( do_mv( &t ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}