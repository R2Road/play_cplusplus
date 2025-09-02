#include "play_std_cin.hpp"

#include <iomanip> // Manipulator : 조작자, 조정자

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_std_cin
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

				OUT_VALUE( s );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}