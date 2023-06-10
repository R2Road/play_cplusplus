#include "template_specialization_test.h"
#include "template_specialization_test_helper_basic.hpp"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace template_specialization_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Specialization : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_template/item/template_specialization_test_helper_basic.hpp" );

			LS();

			{
				PROCESS_MAIN( TemplateFunc( int( 1 ) ) );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( TemplateFunc( uint8_t( 1 ) ) );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( TemplateFunc( int64_t( 1 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
