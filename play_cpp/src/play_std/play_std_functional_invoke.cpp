#include "play_std_functional_invoke.hpp"
#include "play_std_functional_invoke_helper.hpp"

#include <functional>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_std_functional_invoke
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::invoke : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_FILE( "src/play_std/play_std_functional_invoke_helper.hpp" );

			LS();

			{
				PROC_MAIN( std::invoke( Do, 2 ) );

				LF();

				PROC_MAIN( std::invoke( do_lam, 3 ) );

				LF();

				DECL_MAIN( S1 s_1 );
				PROC_MAIN( std::invoke( &S1::Do, s_1, 123 ) );
				PROC_MAIN( std::invoke( &S1::Do, &s_1, 234 ) );

				LF();

				DECL_MAIN( S2 s_2 );
				OUT_VALUE( std::invoke( &S2::n, &s_2 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}