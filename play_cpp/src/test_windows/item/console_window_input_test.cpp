#include "console_window_input_test.h"

#include <assert.h>
#include <conio.h> // _kbhit(), _getch()
#include <stdio.h>
#include <windows.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

namespace console_window_input_test
{
	void ShowCurrentConsoleMode()
	{
		DWORD temp_console_mode;

		GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &temp_console_mode );
		std::cout << r2tm::tab << "Current Console Mode : " << temp_console_mode << r2tm::linefeed;
	}
	r2tm::TitleFunctionT WindowInput_ReadConsoleInput::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : ReadConsoleInput";
		};
	}
	r2tm::DoFunctionT WindowInput_ReadConsoleInput::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			//
			// Mouse Input을 받아 오려면 Quick Edit를 꺼야한다.
			//
			PROCESS_MAIN( r2tm::WindowUtility::QuickEditEnable( false ) );

			DECLARATION_MAIN( HANDLE hStdInputHandle = GetStdHandle( STD_INPUT_HANDLE ) );
			DECLARATION_MAIN( DWORD last_console_mode );

			LS();

			{
				OUTPUT_SUBJECT( "Backup Console Mode" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				if( !GetConsoleMode( hStdInputHandle, &last_console_mode ) )
				{
					assert( false );
				}
				OUTPUT_SOURCE_END;
				
				LF();

				ShowCurrentConsoleMode();
			}

			LS();

			{
				OUTPUT_SUBJECT( "Change Console Mode" );

				LF();

				DECLARATION_MAIN( const DWORD new_console_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				if( !SetConsoleMode( hStdInputHandle, new_console_mode ) )
				{
					assert( false );
				}
				OUTPUT_SOURCE_END;

				LF();

				ShowCurrentConsoleMode();
			}

			LS();

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
							std::cout << "================== KEY_EVENT ==================" << r2tm::linefeed;
							std::cout << "input_records[i].EventType : " << input_records[i].EventType << r2tm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.uChar.AsciiChar : " << input_records[i].Event.KeyEvent.uChar.AsciiChar << r2tm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.bKeyDown : " << input_records[i].Event.KeyEvent.bKeyDown << r2tm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wVirtualKeyCode : " << input_records[i].Event.KeyEvent.wVirtualKeyCode << r2tm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wVirtualScanCode : " << input_records[i].Event.KeyEvent.wVirtualScanCode << r2tm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wRepeatCount : " << input_records[i].Event.KeyEvent.wRepeatCount << r2tm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.dwControlKeyState : " << input_records[i].Event.KeyEvent.dwControlKeyState << r2tm::linefeed;
							std::cout << "===============================================" << r2tm::linefeed;

							if( 27 == input_records[i].Event.KeyEvent.wVirtualKeyCode )
							{
								process = false;
							}

							break;

						case MOUSE_EVENT: // mouse input
							std::cout << "================== MOUSE_EVENT ==================" << r2tm::linefeed;
							OUTPUT_VALUE( input_records[i].Event.MouseEvent.dwMousePosition.X );
							OUTPUT_VALUE( input_records[i].Event.MouseEvent.dwMousePosition.Y );
							OUTPUT_VALUE( input_records[i].Event.MouseEvent.dwButtonState );
							OUTPUT_VALUE( input_records[i].Event.MouseEvent.dwControlKeyState );
							OUTPUT_VALUE( input_records[i].Event.MouseEvent.dwEventFlags );
							std::cout << "===============================================" << r2tm::linefeed;
							break;

						case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
							std::cout << "WINDOW_BUFFER_SIZE_EVENT" << r2tm::linefeed;
							break;

						case FOCUS_EVENT:  // disregard focus events
							std::cout << "FOCUS_EVENT" << r2tm::linefeed;
							break;

						case MENU_EVENT:   // disregard menu events
							std::cout << "MENU_EVENT" << r2tm::linefeed;
							break;

						default:
							std::cout << "Unknown event type" << r2tm::linefeed;
							break;
						}
					}
				} while( process );
			}

			LS();

			{
				OUTPUT_NOTE( "Press Any Key : Rollback" );
				_getch();

				//
				// Rollback
				//
				SetConsoleMode( hStdInputHandle, last_console_mode );
				
				LF();

				ShowCurrentConsoleMode();
			}

			LS();

			PROCESS_MAIN( r2tm::WindowUtility::QuickEditEnable( true ) );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT WindowInput_GetKeyState::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetKeyState";
		};
	}
	r2tm::DoFunctionT WindowInput_GetKeyState::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "pause 없이 메뉴를 전환하는 경우..." );
			OUTPUT_NOTE( "메세지 큐에 남아있던 값들이 다른 Test 를 실행 시킬 수 있다." );

			LS();

			OUTPUT_NOTE( "1st 4bit : Toggle Info : 키 누를 때마다 변화 0001 > 0000 > 0001 > 0000 ...." );
			OUTPUT_NOTE( "2nd 4bit : Current Key State : 눌리면 1000" );

			LS();

			OUTPUT_STRING( "[ ESC ] Exit" );
			OUTPUT_STRING( "[SPACE] Do" );

			LS();

			{
				int key_value = 0;

				while( 1 )
				{
					//
					// Process
					//
					key_value = GetKeyState( VK_SPACE );

					//
					// View
					//
					SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 19 } );
					printf_s(
						"\t\t" "Key State : %c \n"
						"\t\t" "Key Value : hex : %8x \n\n"
						, ( key_value & 0x8000 ? 'O' : 'X' )
						, key_value
					);

					//
					// ESC
					//
					if( GetKeyState( VK_ESCAPE ) & 0x8000 )
					{
						break;
					}
				}
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT WindowInput_GetKeyboardState::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetKeyboardState";
		};
	}
	r2tm::DoFunctionT WindowInput_GetKeyboardState::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_STRING( "[ ESC ] Exit" );
			OUTPUT_STRING( "[SPACE] Do" );

			LS();

			OUTPUT_NOTE( "1st 4bit : Toggle Info : 키 누를 때마다 변화 0001 > 0000 > 0001 > 0000 ...." );
			OUTPUT_NOTE( "2nd 4bit : Current Key State : 눌리면 1000" );

			LS();

			std::cout << r2tm::linefeed3 << r2tm::linefeed2;

			LS();

			{
				int key_value;
				BYTE states[256];
				char str_flags[257] = { '\0', };

				while( 1 )
				{
					memset( states, 0, sizeof( states ) );

					GetKeyState( 0 );
					if( GetKeyboardState( states ) )
					{
						//
						// View
						//
						for( int i = 0; i < 256; i++ )
						{
							key_value = (int)states[i];
							key_value >>= 7; // get 8th bit

							str_flags[i] = key_value > 0 ? 'O' : 'X';
						}
						
						SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 19 } );
						printf_s(
							"%s"
							"\n\n"
							"Key Value[VK_SPACE] : hex : %-4x \n"
							, str_flags
							, (int)states[VK_SPACE]
						);

						//
						// ESC
						//
						if( 0 < ( states[27] >> 7 ) )
						{
							break;
						}
					}
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT WindowInput_GetAsyncKeyStates::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetAsyncKeyStates";
		};
	}
	r2tm::DoFunctionT WindowInput_GetAsyncKeyStates::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_STRING( "[ ESC ] Exit" );
			OUTPUT_STRING( "[SPACE] Do" );

			LS();

			//
			// Key Info 출력용 공간
			//
			std::cout << r2tm::linefeed2;

			LS();

			{
				int key_value = 0;

				while( 1 )
				{
					//
					// Process
					//
					key_value = GetAsyncKeyState( VK_SPACE );

					//
					// View
					//
					SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 9 } );
					printf_s(
						"\t" "[Space] Key State : %c \n"
						"\t" "[Space] Key Value : hex : %8x \n"
						, ( key_value & 0x8000 ? 'O' : 'X' )
						, key_value
					);

					//
					// ESC
					//
					if( GetKeyState( VK_ESCAPE ) & 0x8000 )
					{
						SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 14 } );
						break;
					}
				}
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}