#include "console_window_etc_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <Windows.h> // HDC

#include "r2cm/r2cm_ostream.h"

namespace console_window_etc_test
{
	r2cm::iItem::TitleFunctionT Pixel::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Set Pixel";
		};
	}
	r2cm::iItem::DoFunctionT Pixel::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << "[ESC] Exit" << r2cm::linefeed;

			{
				HWND console_window = GetConsoleWindow();
				HDC dc = GetDC( console_window );

				COORD pivot_pos{ 0, 100 };
				COLORREF pixel_color = RGB( 255, 100, 100 );
				int current_x = 0;
				int current_y = 0;
				while( true )
				{
					current_x = pivot_pos.X;

					for( double i = 0; i < 3.141592 * 4; i += 0.05 )
					{
						current_y = static_cast<int>( pivot_pos.Y + ( 35 * sin( i ) ) );

						SetPixel( dc, current_x, current_y, pixel_color );
						current_x += 1;
					}

					if( _kbhit() )
					{
						if( 27 == _getch() )
						{
							break;
						}
					}
				}

				ReleaseDC( console_window, dc );
			}

			return r2cm::eItemLeaveAction::None;
		};
	}
}