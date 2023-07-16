#include "various_console_input_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2tm/r2tm_ostream.h"

namespace various_console_input_test
{
	r2tm::TitleFunctionT KeyCodeView::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key Code View";
		};
	}
	r2tm::DoFunctionT KeyCodeView::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << "[ESC] End" << r2tm::linefeed;

			LS();

			int input = 0;
			do
			{
				input = _getch();

				std::cout << "Key : " << input << r2tm::linefeed;

			} while( 27 != input );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}