#include "pch.h"
#include "console_window_message_test.h"

#include <assert.h>
#include <conio.h>
#define  STRICT
#define  WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "base/r2_eTestEndAction.h"

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
	r2::iItem::TitleFuncT ConsoleControlHandler::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Message : Console Control Handler";
		};
	}
	r2::iItem::DoFunc ConsoleControlHandler::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed2;
			std::cout << "[Ctrl + C] ..." << r2::linefeed;
			std::cout << "[Ctrl + Break] ..." << r2::linefeed;
			std::cout << "[Close Window] ..." << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Ref" << r2::linefeed2;
			std::cout << r2::tab2 << "https://docs.microsoft.com/ko-kr/windows/console/registering-a-control-handler-function" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Message" << r2::linefeed2;
			std::cout << r2::tab2 << "Ctrl + C �� ������ ����Ű� �پ��ִ� ��� PDB�� ���ٸ� ���ܰ� ������." << r2::linefeed;
			std::cout << r2::tab2 << "F5 ������ ��� ���� �ȴ�." << r2::linefeed;
			std::cout << r2::tab2 << "Ctrl + Break �� �޼��� �ް� TRUE �� ��ȯ���� ������ ���α׷��� ����ȴ�." << r2::linefeed;
			std::cout << r2::tab2 << "������ Ctrl + F5 �� ������ ��" << r2::linefeed;

			std::cout << r2::split;

			std::cout << "Press Key" << r2::linefeed2;

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

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
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

	r2::iItem::TitleFuncT MessageHook::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Window Message : Hook";
		};
	}
	r2::iItem::DoFunc MessageHook::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Message" << r2::linefeed2;
			std::cout << r2::tab2 << "GetMessage �Լ��� ���� ������ Ű �Է��� ȭ�鿡 ǥ�ð� �ȵȴ�." << r2::linefeed;
			std::cout << r2::tab2 << "GetMessage �� ���α׷��� ������� ��Ȱ�� �һ� ������ Message �� ��� �ƹ� �ϵ� ���� �ʴ´�." << r2::linefeed;
			std::cout << r2::tab2 << "Test Loop �� ������� ������ ���� �𸣰ڴ�." << r2::linefeed;
			std::cout << r2::tab2 << "���콺 �� Ŭ���� �ϸ� ��û���� ��������." << r2::linefeed;
			std::cout << r2::tab2 << "CallNextHookEx �Լ��� ȣ������ ������ �������� �ʴ� ��� ���콺�� �������� �ʴ´�." << r2::linefeed;

			std::cout << r2::split;

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

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}