#include "pch.h"
#include "console_input_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "base/r2_eTestEndAction.h"

namespace console_input_test
{
	r2::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

			int input = 0;
			while( true )
			{
				input = _getch();

				std::cout << "Key : " << input << r2::linefeed;

				if( 27 == input )
				{
					break;
				}
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}