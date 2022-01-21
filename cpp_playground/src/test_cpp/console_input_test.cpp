#include "pch.h"
#include "console_input_test.h"

#include <assert.h>
#include <conio.h> // _kbhit(), _getch()
#include <windows.h>

#include "base/r2_eTestResult.h"

namespace console_input_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

			bool process = true;
			int input = 0;
			while( process )
			{
				input = _getch();

				std::cout << "Key : " << input << r2::linefeed;

				if( 27 == input )
				{
					process = false;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}


	void ShowCurrentConsoleMode()
	{
		DWORD temp_console_mode;

		GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &temp_console_mode );
		std::cout << r2::tab << "Current Console Mode : " << temp_console_mode << r2::linefeed;
	}
	r2::iTest::TitleFunc EnableWindowInput::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Enable Window Input";
		};
	}
	r2::iTest::DoFunc EnableWindowInput::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			HANDLE hStdInputHandle = GetStdHandle( STD_INPUT_HANDLE );
			DWORD last_console_mode;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "HANDLE hStdInputHandle = GetStdHandle( STD_INPUT_HANDLE );" << r2::linefeed;
			std::cout << r2::tab2 << "DWORD last_console_mode;" << r2::linefeed;

			std::cout << r2::split;

			{
				if( !GetConsoleMode( hStdInputHandle, &last_console_mode ) )
				{
					assert( false && "GetConsoleMode( hStdInputHandle, &last_console_mode )" );
				}

				std::cout << r2::tab << "+ Backup Console Mode" << r2::linefeed2;
				std::cout << r2::tab2 << "GetConsoleMode( hStdInputHandle, &last_console_mode )" << r2::linefeed2;
				
				std::cout << r2::linefeed;
				ShowCurrentConsoleMode();
			}

			std::cout << r2::split;

			{
				const DWORD new_console_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
				if( !SetConsoleMode( hStdInputHandle, new_console_mode ) )
				{
					assert( false && "SetConsoleMode( hStdInputHandle, new_console_mode )" );
				}

				std::cout << r2::tab << "+ Change Console Mode" << r2::linefeed2;
				std::cout << r2::tab2 << "const DWORD new_console_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;" << r2::linefeed;
				std::cout << r2::tab2 << "SetConsoleMode( hStdInputHandle, new_console_mode )" << r2::linefeed;
				std::cout << r2::tab3 << "> " << new_console_mode << r2::linefeed;

				std::cout << r2::linefeed;
				ShowCurrentConsoleMode();
			}

			std::cout << r2::split;

			{
				//
				// # REF
				// https://docs.microsoft.com/en-us/windows/console/reading-input-buffer-events?redirectedfrom=MSDN
				//

				INPUT_RECORD input_records[128];
				DWORD current_record_count;
				bool process = true;

				do
				{
					if( !ReadConsoleInput(
						hStdInputHandle				// input buffer handle
						, input_records				// buffer to read into
						, 128						// size of read buffer
						, &current_record_count		// number of records read
					) )
					{
						assert( false && "ReadConsoleInput" );
					}

					for( DWORD i = 0; current_record_count > i; ++i )
					{
						switch( input_records[i].EventType )
						{
						case KEY_EVENT: // keyboard input
							std::cout << "================== KEY_EVENT ==================" << r2::linefeed;
							std::cout << "input_records[i].EventType : " << input_records[i].EventType << r2::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.uChar.AsciiChar : " << input_records[i].Event.KeyEvent.uChar.AsciiChar << r2::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.bKeyDown : " << input_records[i].Event.KeyEvent.bKeyDown << r2::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wVirtualKeyCode : " << input_records[i].Event.KeyEvent.wVirtualKeyCode << r2::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wVirtualScanCode : " << input_records[i].Event.KeyEvent.wVirtualScanCode << r2::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wRepeatCount : " << input_records[i].Event.KeyEvent.wRepeatCount << r2::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.dwControlKeyState : " << input_records[i].Event.KeyEvent.dwControlKeyState << r2::linefeed;
							std::cout << "===============================================" << r2::linefeed;

							if( 27 == input_records[i].Event.KeyEvent.wVirtualKeyCode )
							{
								process = false;
							}

							break;

						case MOUSE_EVENT: // mouse input
							std::cout << "MOUSE_EVENT" << r2::linefeed;
							break;

						case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
							std::cout << "WINDOW_BUFFER_SIZE_EVENT" << r2::linefeed;
							break;

						case FOCUS_EVENT:  // disregard focus events
							std::cout << "FOCUS_EVENT" << r2::linefeed;
							break;

						case MENU_EVENT:   // disregard menu events
							std::cout << "MENU_EVENT" << r2::linefeed;
							break;

						default:
							std::cout << "Unknown event type" << r2::linefeed;
							break;
						}
					}
				} while( process );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "Press Any Key : Rollback" << r2::linefeed;
				_getch();

				//
				// Rollback
				//
				SetConsoleMode( hStdInputHandle, last_console_mode );
				
				std::cout << r2::linefeed;
				ShowCurrentConsoleMode();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}