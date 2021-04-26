#include "pch.h"
#include "console_test.h"

#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <wincon.h> // BACKGROUND_RED

#include "r2_eTestResult.h"

namespace console_test
{
	const r2::iNode::TitleFunc GetWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Get Window Size";
		};
	}
	const r2::iNode::DoFunc GetWindowSize::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
				std::cout << "\t" << "CONSOLE_SCREEN_BUFFER_INFO csbi;" << r2::linefeed;
				std::cout << "\t" << "GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );" << r2::linefeed;

				std::cout << r2::linefeed;

				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );
				std::cout << "\t\t - Width : " << width << r2::linefeed;
				std::cout << "\t\t - Height : " << width << r2::linefeed;

				std::cout << r2::linefeed;
				std::cout << "\t\t - Left : " << csbi.srWindow.Left << r2::linefeed;
				std::cout << "\t\t - Top : " << csbi.srWindow.Top << r2::linefeed;
				std::cout << "\t\t - Right : " << csbi.srWindow.Right << r2::linefeed;
				std::cout << "\t\t - Bottom : " << csbi.srWindow.Bottom << r2::linefeed;
			}

			std::cout << r2::split;

			{
				HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( hStdout, &csbi );
				std::cout << "\t" << "HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );" << r2::linefeed;
				std::cout << "\t" << "CONSOLE_SCREEN_BUFFER_INFO csbi;" << r2::linefeed;
				std::cout << "\t" << "GetConsoleScreenBufferInfo( hStdout, &csbi );" << r2::linefeed;

				std::cout << r2::linefeed;

				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );
				std::cout << "\t\t - Width : " << width << r2::linefeed;
				std::cout << "\t\t - Height : " << width << r2::linefeed;

				std::cout << r2::linefeed;
				std::cout << "\t\t - Left : " << csbi.srWindow.Left << r2::linefeed;
				std::cout << "\t\t - Top : " << csbi.srWindow.Top << r2::linefeed;
				std::cout << "\t\t - Right : " << csbi.srWindow.Right << r2::linefeed;
				std::cout << "\t\t - Bottom : " << csbi.srWindow.Bottom << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc ChangeWindowSize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Change Window Size";
		};
	}
	const r2::iNode::DoFunc ChangeWindowSize::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			{
				system( "mode con lines=30 cols=120" );
			}

			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
				const auto width = static_cast<int>( csbi.srWindow.Right - csbi.srWindow.Left + 1 );
				const auto height = static_cast<int>( csbi.srWindow.Bottom - csbi.srWindow.Top + 1 );

				std::cout << "\t" << "Current Window Size" << r2::linefeed;
				std::cout << "\t\t - Width : " << width << r2::linefeed;
				std::cout << "\t\t - Height : " << width << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Size" << r2::linefeed;
			_getch();

			{
				system( "mode con lines=60 cols=120" );
			}

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc ChangeWindowPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Change Window Position";
		};
	}
	const r2::iNode::DoFunc ChangeWindowPosition::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				RECT rectClient, rectWindow;
				HWND hWnd = GetConsoleWindow();
				GetClientRect( hWnd, &rectClient );
				GetWindowRect( hWnd, &rectWindow );
				
				int posx = GetSystemMetrics( SM_CXSCREEN ) / 2 - ( rectWindow.right - rectWindow.left ) / 2;
				int posy = GetSystemMetrics( SM_CYSCREEN ) / 2 - ( rectWindow.bottom - rectWindow.top ) / 2;

				MoveWindow( hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );

				std::cout << "\t" << "Move To Center" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc ChangeWindowName::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Change Window Name";
		};
	}
	const r2::iNode::DoFunc ChangeWindowName::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				TCHAR window_name_string[MAX_PATH];
				GetConsoleTitle( window_name_string, MAX_PATH );

				std::cout << "\t + " << "Current Window Name" << r2::linefeed;
				std::wcout << "\t\t - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto* window_name_string = TEXT( "console_test : ChangeWindowName" );

				SetConsoleTitle( window_name_string );

				std::cout << "\t + " << "New Window Name" << r2::linefeed;
				std::wcout << "\t\t - " << window_name_string << r2::linefeed;
			}

			std::cout << r2::split;

			std::cout << "Press Any Key : Roll Back Window Name" << r2::linefeed;
			_getch();

			{
				SetConsoleTitle( TEXT( "cpp_playground" ) );
			}

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc MoveCursor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Move Cursor";
		};
	}
	const r2::iNode::DoFunc MoveCursor::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			{
				HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
				COORD pos = { 0, 0 };

				bool process = true;
				while( process )
				{
					system( "cls" );

					std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;
					std::cout << "\t" << " + Key : W, A, S, D" << r2::linefeed;


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
					}
				}
			}

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc ColorTable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Color Table";
		};
	}
	const r2::iNode::DoFunc ColorTable::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Color Table" << r2::linefeed;
				std::cout << "\t\t" << "Black" << "\t\t\t" << "0" << r2::linefeed;
				std::cout << "\t\t" << "Blue" << "\t\t\t" << "1" << r2::linefeed;
				std::cout << "\t\t" << "Green" << "\t\t\t" << "2" << r2::linefeed;
				std::cout << "\t\t" << "Aqua" << "\t\t\t" << "3" << r2::linefeed;
				std::cout << "\t\t" << "Red" << "\t\t\t" << "4" << r2::linefeed;
				std::cout << "\t\t" << "Purple" << "\t\t\t" << "5" << r2::linefeed;
				std::cout << "\t\t" << "Yellow" << "\t\t\t" << "6" << r2::linefeed;
				std::cout << "\t\t" << "White" << "\t\t\t" << "7" << r2::linefeed;
				std::cout << "\t\t" << "Gray" << "\t\t\t" << "8" << r2::linefeed;
				std::cout << "\t\t" << "Light Blue" << "\t\t" << "9" << r2::linefeed;
				std::cout << "\t\t" << "Light Green" << "\t\t" << "A" << r2::linefeed;
				std::cout << "\t\t" << "Light Aqua" << "\t\t" << "B" << r2::linefeed;
				std::cout << "\t\t" << "Light Led" << "\t\t" << "C" << r2::linefeed;
				std::cout << "\t\t" << "Light Purple" << "\t\t" << "D" << r2::linefeed;
				std::cout << "\t\t" << "Light Yellow" << "\t\t" << "E" << r2::linefeed;
				std::cout << "\t\t" << "Bright White" << "\t\t" << "F" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc TextColor1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Text Color 1";
		};
	}
	const r2::iNode::DoFunc TextColor1::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				//
				// 0 for background Color(Black)
				// A for text color(Green)
				//
				system( "Color 0A" );
				std::cout << "\t" << "system( \"Color 0A\" );" << r2::linefeed;
				std::cout << "\t\t" << "- 0 : background Color( Black )" << r2::linefeed;
				std::cout << "\t\t" << "- A : text color( Green )" << r2::linefeed;
			}

			std::cout << r2::split;

			system( "pause" );
			system( "Color 07" );

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc TextColor2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Text Color 2";
		};
	}
	const r2::iNode::DoFunc TextColor2::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				char background_color = 8;
				char text_color = 6;

				WORD current_color = 0;
				current_color = background_color << 4;
				current_color |= text_color;

				std::cout << "\t" << " SetConsoleTextAttribute( stdHandle, current_color );" << r2::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << "\t\t" << "- " << std::hex << (int)background_color << " : background Color" << r2::linefeed;
				std::cout << "\t\t" << "- " << std::hex << (int)text_color << " : text Color" << r2::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			std::cout << r2::split;

			{
				const char background_color = BACKGROUND_RED;
				const char text_color = FOREGROUND_GREEN;

				const WORD current_color = background_color | text_color | COMMON_LVB_GRID_HORIZONTAL;

				std::cout << "\t" << " SetConsoleTextAttribute( stdHandle, current_color );" << r2::linefeed;
				SetConsoleTextAttribute( stdHandle, current_color );

				std::cout << "\t\t" << "- " << std::hex << (int)background_color << " : background Color" << r2::linefeed;
				std::cout << "\t\t" << "- " << std::hex << (int)text_color << " : text Color" << r2::linefeed;
			}

			SetConsoleTextAttribute( stdHandle, 7 ); // bg - black( 0 ), text - white( 7 )

			std::cout << r2::split;

			{
				const char background_color = BACKGROUND_RED;
				const char text_color = FOREGROUND_GREEN;

				const WORD current_color = background_color | text_color | COMMON_LVB_GRID_HORIZONTAL;

				std::cout << "\t";
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



	const r2::iNode::TitleFunc ColorTable2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Color Table 2";
		};
	}
	const r2::iNode::DoFunc ColorTable2::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

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

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc TextColor3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Text Color 3";
		};
	}
	const r2::iNode::DoFunc TextColor3::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			//
			// Link : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
			// > \033 : reset the console
			//

			{
				for( int i = 30; 37 >= i; ++i )
				{
					std::cout << "\t\t";
					printf( "\x1B[%dm" "Foreground Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}

				std::cout << r2::linefeed;

				for( int i = 90; 97 >= i; ++i )
				{
					std::cout << "\t\t";
					printf( "\x1B[%dm" "Foreground Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				for( int i = 40; 47 >= i; ++i )
				{
					std::cout << "\t\t";
					printf( "\x1B[%dm" "Background Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}

				std::cout << r2::linefeed;

				for( int i = 100; 107 >= i; ++i )
				{
					std::cout << "\t\t";
					printf( "\x1B[%dm" "Background Color" "\033[0m : %d", i, i );
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				const int background_color = 31;
				const int foreground_color = 44;

				std::cout << "\t\t";
				printf( "\x1B[%d;%dm" "Color" "\033[0m", foreground_color, background_color );
				printf( ": First - %d, Second - %d", foreground_color, background_color );
				std::cout << r2::linefeed;

				std::cout << "\t\t";
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color, foreground_color );
				printf( ": First - %d, Second - %d", background_color, foreground_color );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;


			{
				const int background_color = 41;
				const int foreground_color = 44;

				std::cout << "\t\t";
				printf( "\x1B[%d;%dm" "Color" "\033[0m", foreground_color, background_color );
				printf( ": First - %d, Second - %d", foreground_color, background_color );
				std::cout << r2::linefeed;

				std::cout << "\t\t";
				printf( "\x1B[%d;%dm" "Color" "\033[0m", background_color, foreground_color );
				printf( ": First - %d, Second - %d", background_color, foreground_color );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc TextColor4::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Console : Text Color 4";
		};
	}
	const r2::iNode::DoFunc TextColor4::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			//
			// Link : https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
			// > \033 : reset the console
			//

			{
				for( int i = 0; 9 >= i; ++i )
				{
					std::cout << "\t\t";
					printf( "\033[%d;47;31m" "Text" "\033[0m" " : %d", i, i );
					std::cout << r2::linefeed << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}