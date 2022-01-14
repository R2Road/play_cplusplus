#include "pch.h"
#include "console_buffer_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <Windows.h>

#include "base/r2_eTestResult.h"

namespace console_buffer_test
{
	r2::iTest::TitleFunc BufferInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Buffer Info";
		};
	}
	r2::iTest::DoFunc BufferInfo::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
			std::cout << r2::tab2 << "CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info;" << r2::linefeed;

			std::cout << r2::split;

			const auto result = GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info );

			std::cout << r2::tab << "+ Process" << r2::linefeed2;
			std::cout << r2::tab2 << "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2::linefeed;

			std::cout << r2::split;

			if( result )
			{
				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.dwCursorPosition" << r2::linefeed;
				std::cout << r2::tab2 << "X : " << cs_buffer_info.dwCursorPosition.X << r2::linefeed;
				std::cout << r2::tab2 << "Y : " << cs_buffer_info.dwCursorPosition.Y << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.dwMaximumWindowSize" << r2::linefeed;
				std::cout << r2::tab2 << "X : " << cs_buffer_info.dwMaximumWindowSize.X << r2::linefeed;
				std::cout << r2::tab2 << "Y : " << cs_buffer_info.dwMaximumWindowSize.Y << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.dwSize" << r2::linefeed;
				std::cout << r2::tab2 << "X : " << cs_buffer_info.dwSize.X << r2::linefeed;
				std::cout << r2::tab2 << "Y : " << cs_buffer_info.dwSize.Y << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.srWindow" << r2::linefeed;
				std::cout << r2::tab2 << "T : " << cs_buffer_info.srWindow.Top << r2::linefeed;
				std::cout << r2::tab2 << "B : " << cs_buffer_info.srWindow.Bottom << r2::linefeed;
				std::cout << r2::tab2 << "L : " << cs_buffer_info.srWindow.Left << r2::linefeed;
				std::cout << r2::tab2 << "R : " << cs_buffer_info.srWindow.Right << r2::linefeed2;

				std::cout << r2::tab << "+ CONSOLE_SCREEN_BUFFER_INFO.wAttributes" << r2::linefeed;
				std::cout << r2::tab2 << cs_buffer_info.wAttributes << r2::linefeed;

				//const DWORD length = cs_buffer_info.dwSize.X * cs_buffer_info.dwSize.Y;

				//DWORD out_result;

				//// Flood-fill the console with spaces to clear it
				//FillConsoleOutputCharacter( hStdout, TEXT( ' ' ), length, topLeft, &out_result );

				//// Reset the attributes of every character to the default.
				//// This clears all background colour formatting, if any.
				//FillConsoleOutputAttribute( hStdout, cs_buffer_info.wAttributes, length, topLeft, &out_result );
			}
			else
			{
				std::cout << r2::tab << "Failed : " "GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info )" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



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