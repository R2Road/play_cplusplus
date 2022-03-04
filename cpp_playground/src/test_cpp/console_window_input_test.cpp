#include "pch.h"
#include "console_window_input_test.h"

#include <assert.h>
#include <conio.h> // _kbhit(), _getch()
#include <stdio.h>
#include <windows.h>

#include "base/r2cm_eTestEndAction.h"

namespace console_window_input_test
{
	void ShowCurrentConsoleMode()
	{
		DWORD temp_console_mode;

		GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &temp_console_mode );
		std::cout << r2::tab << "Current Console Mode : " << temp_console_mode << r2::linefeed;
	}
	r2cm::iItem::TitleFuncT WindowInput_ReadConsoleInput::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : ReadConsoleInput";
		};
	}
	r2cm::iItem::DoFuncT WindowInput_ReadConsoleInput::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT WindowInput_GetKeyState::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetKeyState";
		};
	}
	r2cm::iItem::DoFuncT WindowInput_GetKeyState::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] Exit" << r2::linefeed;
			std::cout << "[SPACE] Do" << r2::linefeed;

			std::cout << r2::split;

			std::cout << "+ Message" << r2::linefeed2;
			std::cout << "pause 없이 메뉴를 전환하는 경우 메세지 큐에 남아있던 값들이 다른 Test 를 실행 시킬 수 있다." << r2::linefeed;
			std::cout << "키 반응성이 중요한 프로그램을 만든다면 이 녀석은 쓰지 않는게 좋겠다." << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Key Info : VK_SPACE" << r2::linefeed3;

			std::cout << r2::split;

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
					SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 15 } );
					printf_s(
						"\t\t" "Key State : %c \n"
						"\t\t" "Key Value : hex : %8x \n"
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT WindowInput_GetKeyboardState::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetKeyboardState";
		};
	}
	r2cm::iItem::DoFuncT WindowInput_GetKeyboardState::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] Exit" << r2::linefeed;
			std::cout << "[SPACE] Do" << r2::linefeed;

			std::cout << r2::split;

			std::cout << "+ Message" << r2::linefeed2;
			std::cout << "이 녀석 역시 pause 없이 메뉴를 전환하는 경우 메세지 큐에 남아있던 값들이 다른 Test 를 실행 시킬 수 있다." << r2::linefeed;
			std::cout << "키 반응성이 중요한 프로그램을 만든다면 이 녀석은 쓰지 않는게 좋겠다." << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::linefeed3 << r2::linefeed2;

			std::cout << r2::split;

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
						
						SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), { 0, 14 } );
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

				//
				// 1st 4bit : Toggle Info : 키 누를 때마다 변화 0001 > 0000 > 0001 > 0000 ....
				// 2nd 4bit : Current Key State : 눌리면 1000
				//
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT WindowInput_GetAsyncKeyStates::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetAsyncKeyStates";
		};
	}
	r2cm::iItem::DoFuncT WindowInput_GetAsyncKeyStates::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] Exit" << r2::linefeed;
			std::cout << "[SPACE] Do" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Key Info : VK_SPACE" << r2::linefeed << r2::linefeed3;

			std::cout << r2::split;

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
						"\t\t" "Key State : %c \n"
						"\t\t" "Key Value : hex : %8x \n"
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

			return r2cm::eTestEndAction::Pause;
		};
	}
}