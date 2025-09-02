#include "play_cpp_number.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_cpp_number
{
	r2tm::TitleFunctionT Prefix::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number : Prefix";
		};
	}
	r2tm::DoFunctionT Prefix::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "Binary" );

				LF();

				DECL_MAIN( const int num = 0b0011111 );

				LF();

				OUT_VALUE( num );
			}

			LS();

			{
				OUT_SUBJECT( "Oct" );

				LF();

				DECL_MAIN( const int num = 037 );

				LF();

				OUT_VALUE( num );
			}

			LS();

			{
				OUT_SUBJECT( "Dec" );

				LF();

				DECL_MAIN( const int num = 31 );

				LF();

				OUT_VALUE( num );
			}

			LS();

			{
				OUT_SUBJECT( "Hex" );

				LF();

				DECL_MAIN( const int num = 0x1f );

				LF();

				OUT_VALUE( num );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}