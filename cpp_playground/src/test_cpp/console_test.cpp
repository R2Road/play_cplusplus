#include "pch.h"
#include "console_test.h"

#include <bitset>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

#include "base/r2_eTestResult.h"

namespace console_test
{
	r2::iTest::TitleFunc GetWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Get Window Size";
		};
	}
	r2::iTest::DoFunc GetWindowSize::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( hStdout, &csbi );
				std::cout << r2::tab << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
				std::cout << r2::tab << "CONSOLE_SCREEN_BUFFER_INFO csbi;" << r2::linefeed;
				std::cout << r2::tab << "GetConsoleScreenBufferInfo( hStdout, &csbi );" << r2::linefeed;

				std::cout << r2::linefeed;

				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );
				std::cout << r2::tab2 << " - Width : " << width << r2::linefeed;
				std::cout << r2::tab2 << " - Height : " << width << r2::linefeed;

				std::cout << r2::linefeed;
				std::cout << r2::tab2 << " - Left : " << csbi.srWindow.Left << r2::linefeed;
				std::cout << r2::tab2 << " - Top : " << csbi.srWindow.Top << r2::linefeed;
				std::cout << r2::tab2 << " - Right : " << csbi.srWindow.Right << r2::linefeed;
				std::cout << r2::tab2 << " - Bottom : " << csbi.srWindow.Bottom << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc ChangeWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Size";
		};
	}
	r2::iTest::DoFunc ChangeWindowSize::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			{
				system( "mode con lines=30 cols=120" );
			}

			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );

				std::cout << r2::tab << "Current Window Size" << r2::linefeed;
				std::cout << r2::tab << " - Width : " << width << r2::linefeed;
				std::cout << r2::tab << " - Height : " << width << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Size" << r2::linefeed;
			_getch();

			{
				system( "mode con lines=60 cols=120" );
			}

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc WindowPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Position";
		};
	}
	r2::iTest::DoFunc WindowPosition::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			RECT last_window_rect;

			{
				HWND hWnd = GetConsoleWindow();
				GetWindowRect( hWnd, &last_window_rect );
				std::cout << r2::tab << "HWND hWnd = GetConsoleWindow();" << r2::linefeed;
				std::cout << r2::tab << "RECT last_window_rect;" << r2::linefeed;
				std::cout << r2::tab << "GetWindowRect( hWnd, &last_window_rect );" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Current Window Position" << r2::linefeed;
				std::cout << r2::tab2 << " - X : " << last_window_rect.left << r2::linefeed;
				std::cout << r2::tab2 << " - Y : " << last_window_rect.top << r2::linefeed;
			}

			std::cout << r2::split;

			{
				RECT rectClient, rectWindow;
				HWND hWnd = GetConsoleWindow();
				GetClientRect( hWnd, &rectClient );
				GetWindowRect( hWnd, &rectWindow );
				
				int posx = GetSystemMetrics( SM_CXSCREEN ) / 2 - ( rectWindow.right - rectWindow.left ) / 2;
				int posy = GetSystemMetrics( SM_CYSCREEN ) / 2 - ( rectWindow.bottom - rectWindow.top ) / 2;

				MoveWindow( hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );

				std::cout << r2::tab << "Move To Center" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				RECT rectWindow;
				HWND hWnd = GetConsoleWindow();
				GetWindowRect( hWnd, &rectWindow );

				std::cout << r2::linefeed;

				std::cout << r2::tab << "Current Window Position" << r2::linefeed;
				std::cout << r2::tab2 << " - X : " << rectWindow.left << r2::linefeed;
				std::cout << r2::tab2 << " - Y : " << rectWindow.top << r2::linefeed;
			}

			std::cout << r2::split;
			system( "pause" );

			{
				//
				// Rollback
				//

				HWND hWnd = GetConsoleWindow();

				MoveWindow(
					hWnd
					, last_window_rect.left, last_window_rect.top
					, last_window_rect.right - last_window_rect.left, last_window_rect.bottom - last_window_rect.top
					, TRUE
				);
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc ChangeWindowName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Change Window Name";
		};
	}
	r2::iTest::DoFunc ChangeWindowName::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				TCHAR window_name_string[MAX_PATH];
				GetConsoleTitle( window_name_string, MAX_PATH );

				std::cout << r2::tab << " + " << "Current Window Name" << r2::linefeed;
				std::wcout << r2::tab2 << " - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto* window_name_string = TEXT( "console_test : ChangeWindowName" );

				SetConsoleTitle( window_name_string );

				std::cout << r2::tab << " + " << "New Window Name" << r2::linefeed;
				std::wcout << r2::tab2 << " - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Name" << r2::linefeed;
			_getch();

			{
				SetConsoleTitle( TEXT( "cpp_playground" ) );
			}
			_getch();

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc HideTitleBar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Hide Title Bar";
		};
	}
	r2::iTest::DoFunc HideTitleBar::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			LONG last_window_style = 0;

			{
				HWND hwnd = GetConsoleWindow();
				last_window_style = GetWindowLong( hwnd, GWL_STYLE );

				std::cout << r2::tab << "Last Window Stype : " << r2::tab << std::bitset<32>( last_window_style ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				HWND hwnd = GetConsoleWindow();
				LONG style = last_window_style;
				style &= ~( WS_BORDER | WS_CAPTION | WS_THICKFRAME );
				SetWindowLong( hwnd, GWL_STYLE, style );

				std::cout << r2::tab << "New Window Stype : " << r2::tab << std::bitset<32>( style ) << r2::linefeed;
			}

			std::cout << r2::split;

			system( "pause" );
			{
				HWND hwnd = GetConsoleWindow();
				SetWindowLong( hwnd, GWL_STYLE, last_window_style );
			}

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc CursorMove::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Move";
		};
	}
	r2::iTest::DoFunc CursorMove::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
			std::cout << r2::tab << " + [W, A, S, D] : Move" << r2::linefeed;
			std::cout << r2::tab << " + [SPACE BAR] Foot Print" << r2::linefeed;
			std::cout << r2::tab << " + [ESC] Exit" << r2::linefeed;

			{
				HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
				COORD pos = { 0, 3 };

				bool process = true;
				while( process )
				{
					SetConsoleCursorPosition( stdHandle, pos );

					switch( _getch() )
					{
					case 'w': // up
						pos.Y -= 1;
						break;
					case 's': // down
						pos.Y += 1;
						break;
					case 'a': // left
						pos.X -= 1;
						break;
					case 'd': // right
						pos.X += 1;
						break;

					case 27: // ESC
						process = false;
						break;

					case 32: // space
						std::cout << "test string";
						break;
					}
				}
			}

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}

	r2::iTest::TitleFunc CursorVisibility::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cursor Visibility";
		};
	}
	r2::iTest::DoFunc CursorVisibility::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				CONSOLE_CURSOR_INFO     cursorInfo;

				GetConsoleCursorInfo( stdHandle, &cursorInfo );
				cursorInfo.bVisible = false;
				SetConsoleCursorInfo( stdHandle, &cursorInfo );
			}

			system( "pause" );

			{
				CONSOLE_CURSOR_INFO     cursorInfo;

				GetConsoleCursorInfo( stdHandle, &cursorInfo );
				cursorInfo.bVisible = true;
				SetConsoleCursorInfo( stdHandle, &cursorInfo );
			}

			system( "pause" );

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc ColorTable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Table";
		};
	}
	r2::iTest::DoFunc ColorTable::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Color Table" << r2::linefeed;
				std::cout << r2::tab2 << "Black" << r2::tab3 << "0" << r2::linefeed;
				std::cout << r2::tab2 << "Blue" << r2::tab3 << "1" << r2::linefeed;
				std::cout << r2::tab2 << "Green" << r2::tab3 << "2" << r2::linefeed;
				std::cout << r2::tab2 << "Aqua" << r2::tab3 << "3" << r2::linefeed;
				std::cout << r2::tab2 << "Red" << r2::tab3 << "4" << r2::linefeed;
				std::cout << r2::tab2 << "Purple" << r2::tab3 << "5" << r2::linefeed;
				std::cout << r2::tab2 << "Yellow" << r2::tab3 << "6" << r2::linefeed;
				std::cout << r2::tab2 << "White" << r2::tab3 << "7" << r2::linefeed;
				std::cout << r2::tab2 << "Gray" << r2::tab3 << "8" << r2::linefeed;
				std::cout << r2::tab2 << "Light Blue" << r2::tab2 << "9" << r2::linefeed;
				std::cout << r2::tab2 << "Light Green" << r2::tab2 << "A" << r2::linefeed;
				std::cout << r2::tab2 << "Light Aqua" << r2::tab2 << "B" << r2::linefeed;
				std::cout << r2::tab2 << "Light Led" << r2::tab2 << "C" << r2::linefeed;
				std::cout << r2::tab2 << "Light Purple" << r2::tab2 << "D" << r2::linefeed;
				std::cout << r2::tab2 << "Light Yellow" << r2::tab2 << "E" << r2::linefeed;
				std::cout << r2::tab2 << "Bright White" << r2::tab2 << "F" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc TextColor1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Text Color 1";
		};
	}
	r2::iTest::DoFunc TextColor1::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				//
				// 0 for background Color(Black)
				// A for text color(Green)
				//
				system( "Color 0A" );
				std::cout << r2::tab << "system( \"Color 0A\" );" << r2::linefeed;
				std::cout << r2::tab2 << "- 0 : background Color( Black )" << r2::linefeed;
				std::cout << r2::tab2 << "- A : text color( Green )" << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Text Color" << r2::linefeed;
			system( "pause" );

			{
				system( "Color 07" );
			}
			system( "pause" );
			

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}



	r2::iTest::TitleFunc TextColor2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Text Color 2";
		};
	}
	r2::iTest::DoFunc TextColor2::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				char background_color = 8;
				char text_color = 6;

				WORD current_color = 0;
				current_color = background_color << 4;
				current_color |= text_color;

				std::cout << r2::tab << " SetConsoleTextAttribute( stdHandle, current_color );" << r2::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << r2::tab2 << "- " << std::hex << "hex : " << (int)background_color << " : background Color" << r2::linefeed;
				std::cout << r2::tab2 << "- " << std::hex << "hex : " << (int)text_color << " : text Color" << r2::linefeed;
				std::cout << r2::tab2 << "- " << std::hex << "hex : " << (int)current_color << " : current Color" << r2::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			std::cout << r2::split;

			{
				const WORD current_color = BACKGROUND_BLUE | FOREGROUND_GREEN | COMMON_LVB_GRID_HORIZONTAL;

				std::cout << r2::tab << " SetConsoleTextAttribute( stdHandle, current_color );" << r2::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << r2::tab2 << "- " << std::hex << "hex : " << (int)BACKGROUND_BLUE << " : BACKGROUND_BLUE" << r2::linefeed;
				std::cout << r2::tab2 << "- " << std::hex << "hex : " << (int)FOREGROUND_GREEN << " : FOREGROUND_GREEN" << r2::linefeed;
				std::cout << r2::tab2 << "- " << std::hex << "hex : " << (int)COMMON_LVB_GRID_HORIZONTAL << " : COMMON_LVB_GRID_HORIZONTAL" << r2::linefeed;
				std::cout << r2::tab2 << "- " << std::hex << "hex : " << (int)current_color << " : curren Color" << r2::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			std::cout << r2::split;

			{
				const char background_color = BACKGROUND_RED;
				const char text_color = FOREGROUND_GREEN;

				const WORD current_color = background_color | text_color | COMMON_LVB_GRID_HORIZONTAL;

				std::cout << r2::tab;
				SetConsoleTextAttribute( stdHandle, FOREGROUND_GREEN );
				std::cout << "SetConsoleTextAttribute( ";
				SetConsoleTextAttribute( stdHandle, FOREGROUND_RED );
				std::cout << "stdHandle";
				std::cout << ", current_color";
				SetConsoleTextAttribute( stdHandle, FOREGROUND_GREEN );
				std::cout << " );" << r2::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc AdjustColorTable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Adjust Color Table";
		};
	}
	r2::iTest::DoFunc AdjustColorTable::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				CONSOLE_SCREEN_BUFFER_INFOEX info;
				info.cbSize = sizeof( CONSOLE_SCREEN_BUFFER_INFOEX );
				std::cout << r2::tab << "CONSOLE_SCREEN_BUFFER_INFOEX info;" << r2::linefeed;
				std::cout << r2::tab << "info.cbSize = sizeof( CONSOLE_SCREEN_BUFFER_INFOEX );" << r2::linefeed;
				std::cout << r2::linefeed;

				GetConsoleScreenBufferInfoEx( stdHandle, &info );
				std::cout << r2::tab << "GetConsoleScreenBufferInfoEx( stdHandle, &info );" << r2::linefeed;
				std::cout << r2::linefeed;

				info.ColorTable[1] = RGB( 255, 100, 100 );
				std::cout << r2::tab << "info.ColorTable[1] = RGB( 255, 100, 100 );" << r2::linefeed;
				std::cout << r2::linefeed;

				SetConsoleScreenBufferInfoEx( stdHandle, &info );
				std::cout << r2::tab << "SetConsoleScreenBufferInfoEx( stdHandle, &info );" << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				char background_color = 8;
				char text_color = 1;

				WORD current_color = 0;
				current_color = background_color << 4;
				current_color |= text_color;

				std::cout << r2::tab << "SetConsoleTextAttribute( stdHandle, current_color );" << r2::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << r2::tab2 << "- " << std::hex << (int)background_color << " : background Color" << r2::linefeed;
				std::cout << r2::tab2 << "- " << std::hex << (int)text_color << " : text Color" << r2::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc ColorTable2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Table 2";
		};
	}
	r2::iTest::DoFunc ColorTable2::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			//
			// Link : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
			// > \033 : reset the console
			//

			{
				int n = 0;

				for( int i = 0; i < 11; i++ )
				{
					for( int j = 0; j < 10; j++ )
					{
						n = 10 * i + j;
						if( n > 108 )
						{
							break;
						}

						printf( " " "\033[%dm" "%3d" "\033[m", n, n );
					}

					printf( "\n" );
				}
			}

			std::cout << r2::split;

			{
				for( int i = 30; 37 >= i; ++i )
				{
					std::cout << r2::tab2;
					printf( "\x1B[%dm" "Foreground Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}

				std::cout << r2::linefeed;

				for( int i = 90; 97 >= i; ++i )
				{
					std::cout << r2::tab2;
					printf( "\x1B[%dm" "Foreground Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::linefeed;

			{
				for( int i = 40; 47 >= i; ++i )
				{
					std::cout << r2::tab2;
					printf( "\x1B[%dm" "Background Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}

				std::cout << r2::linefeed;

				for( int i = 100; 107 >= i; ++i )
				{
					std::cout << r2::tab2;
					printf( "\x1B[%dm" "Background Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc TextColor3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Text Color 3";
		};
	}
	r2::iTest::DoFunc TextColor3::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			//
			// Link : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
			// > \033 : reset the console
			//

			{
				std::cout << r2::tab << "+ Sequence Not Required" << r2::linefeed << r2::linefeed;

				const int background_color = 31;
				const int foreground_color = 44;

				std::cout << r2::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", foreground_color, background_color );
				printf( ": First - %d, Second - %d", foreground_color, background_color );
				std::cout << r2::linefeed;

				std::cout << r2::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color, foreground_color );
				printf( ": First - %d, Second - %d", background_color, foreground_color );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;


			{
				std::cout << r2::tab << "+ 같은 속성의 값이 입력되면 뒤의 값이 적용된다." << r2::linefeed << r2::linefeed;

				const int background_color_1 = 41;
				const int background_color_2 = 44;

				std::cout << r2::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color_2, background_color_1 );
				printf( ": First - %d, Second - %d", background_color_2, background_color_1 );
				std::cout << r2::linefeed;

				std::cout << r2::tab2;
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color_1, background_color_2 );
				printf( ": First - %d, Second - %d", background_color_1, background_color_2 );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				const int background_color = 47;
				const int foreground_color = 31;

				for( int i = 0; 9 >= i; ++i )
				{
					std::cout << r2::tab2;
					printf( "\033[%d;%d;%dm" "Text" "\033[0m", i, background_color, foreground_color );
					printf( ": 1st - %d, 2nd - %d, 3rd - %d ", i, background_color, foreground_color );
					std::cout << r2::linefeed << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				const char* target_color = "\033[31;44m";
				const char* reset_color = "\033[0m";

				std::cout << r2::tab2 << target_color << "Change Color with std::cout" << reset_color << r2::linefeed;
			}

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
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

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