#include "number_test.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace number_test
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

				DECLARATION_MAIN( const int num = 0b0011111 );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Oct" );

				LF();

				DECLARATION_MAIN( const int num = 037 );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Dec" );

				LF();

				DECLARATION_MAIN( const int num = 31 );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Hex" );

				LF();

				DECLARATION_MAIN( const int num = 0x1f );

				LF();

				OUTPUT_VALUE( num );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}