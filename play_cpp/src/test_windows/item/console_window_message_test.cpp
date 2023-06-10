#include "console_window_message_test.h"

#include <assert.h>
#include <conio.h>
#define  STRICT
#define  WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "r2tm/r2tm_ostream.h"

namespace console_window_message_test
{
	BOOL WINAPI CtrlHandler( DWORD fdwCtrlType )
	{
		// return TRUE : Message Processed
		// return FALSE : Throw Next

		switch( fdwCtrlType )
		{
			// Handle the CTRL-C signal.
		case CTRL_C_EVENT:
			printf( "Ctrl-C event\n\n" );
			Beep( 750, 300 );
			return TRUE;

			// CTRL-CLOSE: confirm that the user wants to exit.
		case CTRL_CLOSE_EVENT:
			Beep( 600, 200 );
			printf( "Ctrl-Close event\n\n" );
			return TRUE;

			// Pass other signals to the next handler.
		case CTRL_BREAK_EVENT:
			Beep( 900, 200 );
			printf( "Ctrl-Break event\n\n" );
			return TRUE;

		case CTRL_LOGOFF_EVENT:
			Beep( 1000, 200 );
			printf( "Ctrl-Logoff event\n\n" );
			return FALSE;

		case CTRL_SHUTDOWN_EVENT:
			Beep( 750, 500 );
			printf( "Ctrl-Shutdown event\n\n" );
			return FALSE;

		default:
			return FALSE;
		}
	}
	r2tm::TitleFunctionT ConsoleControlHandler::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Message : Console Control Handler";
		};
	}
	r2tm::DoFunctionT ConsoleControlHandler::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			std::cout << "[ESC] End" << r2tm::linefeed2;
			std::cout << "[Ctrl + C] ..." << r2tm::linefeed;
			std::cout << "[Ctrl + Break] ..." << r2tm::linefeed;
			std::cout << "[Close Window] ..." << r2tm::linefeed;

			std::cout << r2tm::split;

			std::cout << r2tm::tab << "+ Ref" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "https://docs.microsoft.com/ko-kr/windows/console/registering-a-control-handler-function" << r2tm::linefeed;

			std::cout << r2tm::split;

			std::cout << r2tm::tab << "+ Message" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "Ctrl + C 를 누르면 디버거가 붙어있는 경우 PDB가 없다며 예외가 터진다." << r2tm::linefeed;
			std::cout << r2tm::tab2 << "F5 누르면 계속 실행 된다." << r2tm::linefeed;
			std::cout << r2tm::tab2 << "Ctrl + Break 는 메세지 받고 TRUE 를 반환하지 않으면 프로그램이 종료된다." << r2tm::linefeed;
			std::cout << r2tm::tab2 << "가급적 Ctrl + F5 로 실행할 것" << r2tm::linefeed;

			std::cout << r2tm::split;

			std::cout << "Press Key" << r2tm::linefeed2;

			if( SetConsoleCtrlHandler( CtrlHandler, TRUE ) )
			{
				do
				{
					if( _kbhit() )
					{
						//
						// ESC
						//
						if( 27 == _getch() )
						{
							break;
						}
					}
				}
				while( 1 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}

namespace console_window_message_test
{
	HHOOK g_hook_keyboard = NULL;
	HHOOK g_hook_mouse = NULL;

	LRESULT CALLBACK KeyboardProc( int code, WPARAM w, LPARAM l )
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)l;
		const char *info = NULL;
		if( w == WM_KEYDOWN )
			info = "key dn";
		else if( w == WM_KEYUP )
			info = "key up";
		else if( w == WM_SYSKEYDOWN )
			info = "sys key dn";
		else if( w == WM_SYSKEYUP )
			info = "sys key up";
		printf( "Keyboard : %s - vkCode [%04x], scanCode [%04x]\n", info, p->vkCode, p->scanCode );

		// always call next hook
		return CallNextHookEx( g_hook_keyboard, code, w, l );
	};
	LRESULT CALLBACK MouseProc( int code, WPARAM w, LPARAM l )
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)l;
		const char* info = " ";
		if( w == WM_RBUTTONDOWN )
			info = "mouse r dn";
		else if( w == WM_RBUTTONUP )
			info = "mouse r up";
		printf( "Mouse : %s - vkCode [%04x], scanCode [%04x]\n", info, p->vkCode, p->scanCode );

		// always call next hook
		return CallNextHookEx( g_hook_mouse, code, w, l );
	};

	r2tm::TitleFunctionT MessageHook::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Message : Hook";
		};
	}
	r2tm::DoFunctionT MessageHook::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			std::cout << r2tm::tab << "+ Message" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "GetMessage 함수를 쓰지 않으면 키 입력이 화면에 표시가 안된다." << r2tm::linefeed;
			std::cout << r2tm::tab2 << "GetMessage 는 프로그램을 멈춰놓는 역활을 할뿐 들어오는 Message 가 없어서 아무 일도 하지 않는다." << r2tm::linefeed;
			std::cout << r2tm::tab2 << "Test Loop 를 어떤식으로 끝내야 할지 모르겠다." << r2tm::linefeed;
			std::cout << r2tm::tab2 << "마우스 왼 클릭을 하면 엄청나게 느려진다." << r2tm::linefeed;
			std::cout << r2tm::tab2 << "CallNextHookEx 함수를 호출하지 않으면 느려지지 않는 대신 마우스가 움직이지 않는다." << r2tm::linefeed;

			std::cout << r2tm::split;

			{
				g_hook_keyboard = SetWindowsHookEx( WH_KEYBOARD_LL, &KeyboardProc, GetModuleHandle( NULL ), 0 );
				g_hook_mouse = SetWindowsHookEx( WH_MOUSE_LL, &MouseProc, GetModuleHandle( NULL ), 0 );
				if( NULL != g_hook_keyboard && NULL != g_hook_mouse )
				{
					MSG msg;
					while( GetMessage( &msg, NULL, 0, 0 ) )
					{
						//TranslateMessage( &msg );
						//DispatchMessage( &msg );
					}
				}

				UnhookWindowsHookEx( g_hook_keyboard );
				g_hook_keyboard = NULL;

				UnhookWindowsHookEx( g_hook_mouse );
				g_hook_mouse = NULL;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}