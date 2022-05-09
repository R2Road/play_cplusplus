#include "pch.h"
#include "console_input_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2cm/r2cm_constant.h"

namespace console_input_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed2;
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