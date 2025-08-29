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
				OUTPUT_SUBJECT( "Binary" );

				LF();

				DECL_MAIN( const int num = 0b0011111 );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Oct" );

				LF();

				DECL_MAIN( const int num = 037 );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Dec" );

				LF();

				DECL_MAIN( const int num = 31 );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Hex" );

				LF();

				DECL_MAIN( const int num = 0x1f );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}