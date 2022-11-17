#include "template_practice_test_02.h"
#include "template_practice_test_02_helper_basic.hpp"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace template_practice_test_02
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Practice : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			SHOW_FILE( "src/test_template/item/template_practice_test_02_helper_basic.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FuncContainer f );
				PROCESS_MAIN( f.def( "TestFunc", TestFunction ) );
				PROCESS_MAIN( f.def( "TestFunc", TestFunction ) );
				PROCESS_MAIN( f.def( "TestFunc", TestFunction ) );
				PROCESS_MAIN( f.def( "TestFunc", TestFunction ) );
				PROCESS_MAIN( f.CallAll() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
