#include "std_mem_fn_test.h"

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

			DECLARATION_MAIN( struct TestStruct { void Do() { printf( "TestStruct::Do" "\n" ); } } );

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