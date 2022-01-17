#include "pch.h"
#include "console_test.h"

#include <conio.h> // _kbhit(), _getch()
#include <cwchar>
#include <Windows.h> // HDC

#include "base/r2_eTestResult.h"

void ShowFontInfo( const CONSOLE_FONT_INFOEX & cfie )
{
	std::cout << r2::tab2 << "dwFontSize.X : " << cfie.dwFontSize.X << r2::linefeed;
	std::cout << r2::tab2 << "dwFontSize.Y : " << cfie.dwFontSize.Y << r2::linefeed;
	std::cout << r2::tab2 << "FontFamily : " << cfie.FontFamily << r2::linefeed;
	std::cout << r2::tab2 << "FontWeight : " << cfie.FontWeight << r2::linefeed;
	std::cout << r2::tab2 << "nFont : " << cfie.nFont << r2::linefeed; // 시스템의 콘솔 글꼴 테이블에 있는 글꼴의 인덱스입니다.

	std::wcout.imbue( std::locale( "kor" ) );
	std::wcout << r2::tab2 << "FaceName : " << cfie.FaceName << r2::linefeed;
}

namespace console_test
{
	r2::iTest::TitleFunc FontInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Info";
		};
	}
	r2::iTest::DoFunc FontInfo::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			CONSOLE_FONT_INFOEX cfie;
			cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );

			std::cout << r2::tab << "+ Declartion" << r2::linefeed2;
			std::cout << r2::tab2 << "CONSOLE_FONT_INFOEX cfie;" << r2::linefeed;

			std::cout << r2::split;

			// https://docs.microsoft.com/ko-kr/windows/console/console-font-infoex
			std::cout << r2::tab << "+ Process" << r2::linefeed2;
			std::cout << r2::tab2 << "cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2::tab << "<===== Need This" << r2::linefeed;
			std::cout << r2::tab2 << "GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &cfie );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Font Info" << r2::linefeed2;
				ShowFontInfo( cfie );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc FontChange::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Font Change";
		};
	}
	r2::iTest::DoFunc FontChange::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			CONSOLE_FONT_INFOEX backup_cfie;
			backup_cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
			GetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), 0, &backup_cfie );

			{
				std::cout << r2::tab << "+ Backup : Font Info" << r2::linefeed2;
				ShowFontInfo( backup_cfie );
			}

			std::cout << r2::split;

			{
				CONSOLE_FONT_INFOEX cfie;
				cfie.cbSize = sizeof( CONSOLE_FONT_INFOEX );
				cfie.nFont = 0;
				cfie.dwFontSize.X = backup_cfie.dwFontSize.X;
				cfie.dwFontSize.Y = backup_cfie.dwFontSize.Y;
				cfie.FontFamily = FF_DONTCARE;
				cfie.FontWeight = FW_NORMAL;
				wcscpy_s( cfie.FaceName, L"NSimSun" );

				std::cout << r2::tab << "+ Declartion" << r2::linefeed2;
				std::cout << r2::tab2 << "CONSOLE_FONT_INFOEX cfi;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.cbSize = sizeof( CONSOLE_FONT_INFOEX );" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.dwFontSize.X = backup_cfie.dwFontSize.X;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.dwFontSize.Y = backup_cfie.dwFontSize.Y;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.FontFamily = FF_DONTCARE;" << r2::linefeed;
				std::cout << r2::tab2 << "cfi.FontWeight = FW_NORMAL;" << r2::linefeed;
				std::cout << r2::tab2 << "wcscpy_s( cfi.FaceName, L\"NSimSun\" );" << r2::linefeed;

				std::cout << r2::split;

				std::cout << r2::tab << "Press Key : Change Font" << r2::linefeed;
				_getch();

				std::cout << r2::split;
				
				SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &cfie );

				{
					std::cout << r2::tab << "+ Current : Font Info" << r2::linefeed2;
					ShowFontInfo( cfie );
				}
			}

			std::cout << r2::split;

			std::cout << r2::tab << "Press Key : Rollback" << r2::linefeed;
			_getch();

			SetCurrentConsoleFontEx( GetStdHandle( STD_OUTPUT_HANDLE ), FALSE, &backup_cfie );

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Pixel::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Set Pixel";
		};
	}
	r2::iTest::DoFunc Pixel::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;

			std::cout << "[ESC] Exit" << r2::linefeed;

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

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}