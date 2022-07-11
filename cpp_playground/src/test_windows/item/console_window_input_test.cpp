#include "console_window_input_test.h"

#include <assert.h>
#include <conio.h> // _kbhit(), _getch()
#include <stdio.h>
#include <windows.h>

#include "r2cm/r2cm_ostream.h"

namespace console_window_input_test
{
	void ShowCurrentConsoleMode()
	{
		DWORD temp_console_mode;

		GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &temp_console_mode );
		std::cout << r2cm::tab << "Current Console Mode : " << temp_console_mode << r2cm::linefeed;
	}
	r2cm::iItem::TitleFunctionT WindowInput_ReadConsoleInput::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : ReadConsoleInput";
		};
	}
	r2cm::iItem::DoFunctionT WindowInput_ReadConsoleInput::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			HANDLE hStdInputHandle = GetStdHandle( STD_INPUT_HANDLE );
			DWORD last_console_mode;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "HANDLE hStdInputHandle = GetStdHandle( STD_INPUT_HANDLE );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "DWORD last_console_mode;" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				if( !GetConsoleMode( hStdInputHandle, &last_console_mode ) )
				{
					assert( false && "GetConsoleMode( hStdInputHandle, &last_console_mode )" );
				}

				std::cout << r2cm::tab << "+ Backup Console Mode" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "GetConsoleMode( hStdInputHandle, &last_console_mode )" << r2cm::linefeed2;
				
				std::cout << r2cm::linefeed;
				ShowCurrentConsoleMode();
			}

			std::cout << r2cm::split;

			{
				const DWORD new_console_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
				if( !SetConsoleMode( hStdInputHandle, new_console_mode ) )
				{
					assert( false && "SetConsoleMode( hStdInputHandle, new_console_mode )" );
				}

				std::cout << r2cm::tab << "+ Change Console Mode" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "const DWORD new_console_mode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "SetConsoleMode( hStdInputHandle, new_console_mode )" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << new_console_mode << r2cm::linefeed;

				std::cout << r2cm::linefeed;
				ShowCurrentConsoleMode();
			}

			std::cout << r2cm::split;

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
							std::cout << "================== KEY_EVENT ==================" << r2cm::linefeed;
							std::cout << "input_records[i].EventType : " << input_records[i].EventType << r2cm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.uChar.AsciiChar : " << input_records[i].Event.KeyEvent.uChar.AsciiChar << r2cm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.bKeyDown : " << input_records[i].Event.KeyEvent.bKeyDown << r2cm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wVirtualKeyCode : " << input_records[i].Event.KeyEvent.wVirtualKeyCode << r2cm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wVirtualScanCode : " << input_records[i].Event.KeyEvent.wVirtualScanCode << r2cm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.wRepeatCount : " << input_records[i].Event.KeyEvent.wRepeatCount << r2cm::linefeed;
							std::cout << "input_records[i].Event.KeyEvent.dwControlKeyState : " << input_records[i].Event.KeyEvent.dwControlKeyState << r2cm::linefeed;
							std::cout << "===============================================" << r2cm::linefeed;

							if( 27 == input_records[i].Event.KeyEvent.wVirtualKeyCode )
							{
								process = false;
							}

							break;

						case MOUSE_EVENT: // mouse input
							std::cout << "MOUSE_EVENT" << r2cm::linefeed;
							break;

						case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing
							std::cout << "WINDOW_BUFFER_SIZE_EVENT" << r2cm::linefeed;
							break;

						case FOCUS_EVENT:  // disregard focus events
							std::cout << "FOCUS_EVENT" << r2cm::linefeed;
							break;

						case MENU_EVENT:   // disregard menu events
							std::cout << "MENU_EVENT" << r2cm::linefeed;
							break;

						default:
							std::cout << "Unknown event type" << r2cm::linefeed;
							break;
						}
					}
				} while( process );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "Press Any Key : Rollback" << r2cm::linefeed;
				_getch();

				//
				// Rollback
				//
				SetConsoleMode( hStdInputHandle, last_console_mode );
				
				std::cout << r2cm::linefeed;
				ShowCurrentConsoleMode();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT WindowInput_GetKeyState::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetKeyState";
		};
	}
	r2cm::iItem::DoFunctionT WindowInput_GetKeyState::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << "[ESC] Exit" << r2cm::linefeed;
			std::cout << "[SPACE] Do" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "+ Message" << r2cm::linefeed2;
			std::cout << "pause ���� �޴��� ��ȯ�ϴ� ��� �޼��� ť�� �����ִ� ������ �ٸ� Test �� ���� ��ų �� �ִ�." << r2cm::linefeed;
			std::cout << "Ű �������� �߿��� ���α׷��� ����ٸ� �� �༮�� ���� �ʴ°� ���ڴ�." << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Key Info : VK_SPACE" << r2cm::linefeed3;

			std::cout << r2cm::split;

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

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT WindowInput_GetKeyboardState::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetKeyboardState";
		};
	}
	r2cm::iItem::DoFunctionT WindowInput_GetKeyboardState::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << "[ESC] Exit" << r2cm::linefeed;
			std::cout << "[SPACE] Do" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "+ Message" << r2cm::linefeed2;
			std::cout << "�� �༮ ���� pause ���� �޴��� ��ȯ�ϴ� ��� �޼��� ť�� �����ִ� ������ �ٸ� Test �� ���� ��ų �� �ִ�." << r2cm::linefeed;
			std::cout << "Ű �������� �߿��� ���α׷��� ����ٸ� �� �༮�� ���� �ʴ°� ���ڴ�." << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::linefeed3 << r2cm::linefeed2;

			std::cout << r2cm::split;

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
				// 1st 4bit : Toggle Info : Ű ���� ������ ��ȭ 0001 > 0000 > 0001 > 0000 ....
				// 2nd 4bit : Current Key State : ������ 1000
				//
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT WindowInput_GetAsyncKeyStates::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Input : GetAsyncKeyStates";
		};
	}
	r2cm::iItem::DoFunctionT WindowInput_GetAsyncKeyStates::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << "[ESC] Exit" << r2cm::linefeed;
			std::cout << "[SPACE] Do" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Key Info : VK_SPACE" << r2cm::linefeed << r2cm::linefeed3;

			std::cout << r2cm::split;

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

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}