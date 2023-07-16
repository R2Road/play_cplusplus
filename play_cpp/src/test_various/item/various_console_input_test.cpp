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
			std::cout << "[ESC] End" << r2tm::linefeed;

			LS();

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

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}