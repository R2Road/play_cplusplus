#include "pch.h"
#include "console_buffer_test.h"

#include <bitset>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

#include "base/r2_eTestResult.h"

namespace console_buffer_test
{
	r2::iTest::TitleFunc DoubleBuffering::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Double Buffering";
		};
	}
	r2::iTest::DoFunc DoubleBuffering::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << "[ESC] Exit" << r2::linefeed;

			{
				HWND console_window = GetConsoleWindow();
				HDC dc = GetDC( console_window );

				COLORREF COLOR = RGB( 255, 100, 100 );
				while( true )
				{
					int pixel = 0;

					for( double i = 0; i < 3.141592 * 4; i += 0.05 )
					{
						SetPixel( dc, pixel, (int)( 70 + 25 * sin( i ) ), COLOR );
						pixel += 1;
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

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}