#include "various_console_input_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2cm/r2cm_ostream.h"

namespace various_console_input_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "[ESC] End" << r2cm::linefeed;

			std::cout << r2cm::split;

			int input = 0;
			while( true )
			{
				input = _getch();

				std::cout << "Key : " << input << r2cm::linefeed;

				if( 27 == input )
				{
					break;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}