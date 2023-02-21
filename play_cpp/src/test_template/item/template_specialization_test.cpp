#include "template_specialization_test.h"
#include "template_specialization_test_helper_basic.hpp"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace template_specialization_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Specialization : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_template/item/template_specialization_test_helper_basic.hpp" );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( TemplateFunc( int( 1 ) ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( TemplateFunc( uint8_t( 1 ) ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( TemplateFunc( int64_t( 1 ) ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
