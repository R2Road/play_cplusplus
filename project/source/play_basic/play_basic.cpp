#include "play_basic.hpp"

#include "r2tm/r2tm_color_modifier.hpp"
#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_basic
{
	r2tm::TitleFunctionT Primitive_Type_Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Primitive Type Size";
		};
	}
	r2tm::DoFunctionT Primitive_Type_Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "기본 제공 타입들의 크기" );

			LS();

			{
				OUT_SIZE( bool );
			}

			SS();

			{
				OUT_SIZE( char );
			}
			
			SS();

			{
				OUT_SIZE( short );

				LF();

				OUT_SIZE( int );

				LF();

				OUT_SIZE( long long );
			}

			SS();

			{
				OUT_SIZE( float );

				LF();

				OUT_SIZE( double );

				LF();

				OUT_SIZE( long double );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}