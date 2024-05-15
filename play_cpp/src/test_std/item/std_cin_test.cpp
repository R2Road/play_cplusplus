#include "std_cin_test.h"

#include <iomanip> // Manipulator : 조작자, 조정자

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace std_cin_test
{
	r2tm::TitleFunctionT InputLimit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Input Limit";
		};
	}
	r2tm::DoFunctionT InputLimit::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( std::string s );
				PROCESS_MAIN( std::cin >> std::setw( 10 ) >> s );

				LF();

				OUTPUT_VALUE( s );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}