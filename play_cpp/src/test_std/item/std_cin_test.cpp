#include "std_cin_test.h"

#include <iomanip> // Manipulator : 조작자, 조정자

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

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
				DECL_MAIN( std::string s );
				PROC_MAIN( std::cin >> std::setw( 10 ) >> s );

				LF();

				OUTPUT_VALUE( s );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}