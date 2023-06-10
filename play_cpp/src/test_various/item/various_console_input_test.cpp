#include "various_console_input_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2tm/r2tm_ostream.h"

namespace various_console_input_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << "[ESC] End" << r2tm::linefeed;

			std::cout << r2tm::split;

			int input = 0;
			while( true )
			{
				input = _getch();

				std::cout << "Key : " << input << r2tm::linefeed;

				if( 27 == input )
				{
					break;
				}
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}