#include "play_c_macro.hpp"
#include "play_c_macro_helper___to_string.hpp"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

#pragma warning( disable : 4189 ) // 참조 되지 않은 변수 존재

namespace play_c_macro
{
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

			OUT_FILE( "source/play_c/play_c_macro_helper___to_string.hpp" );

			LS();

			{
				DECL_MAIN( const int test_int = 3456 );

				LF();

				OUT_VALUE( MACRO2STRING( test_int ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}