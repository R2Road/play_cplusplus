#include "play_template_specialization.hpp"
#include "play_template_specialization_helper___basic.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_template_specialization
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

			OUT_FILE( "src/play_template/play_template_specialization_helper___basic.hpp" );

			LS();

			{
				PROC_MAIN( TemplateFunc( int( 1 ) ) );

				LF();

				PROC_MAIN( TemplateFunc( uint8_t( 1 ) ) );

				LF();

				PROC_MAIN( TemplateFunc( int64_t( 1 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
