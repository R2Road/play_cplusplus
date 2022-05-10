#include "pch.h"
#include "r2utility_WindowUtil.h"

#include <Windows.h>

namespace r2utility
{
	void ChangeWindowTitle( const wchar_t* title_string )
	{
		SetConsoleTitle( title_string );
	}

	void ResizeWindow( const int w, const int h )
	{
		HWND hWnd = GetConsoleWindow();
		RECT window_rect;
		GetClientRect( hWnd, &window_rect );
		MoveWindow( hWnd, window_rect.left, window_rect.top, w, h, TRUE );
	}

	void MoveWindow( const int x, const int y )
	{
		//
		// # MoveWindow( hWnd, 0, 0... ); �����δ� Window �� �������� 0, 0 ��ǥ�� ��ġ���� �ʴ´�.
		// # �Ʒ��� �ڵ带 �̿��ؼ� Ÿ��Ʋ �ٿ� ���� �������� ���� �ؾ߸� �� �ڵ�� 0, 0 ��ġ�� ��������.
		//		LONG lStyle = GetWindowLong( GetConsoleWindow(), GWL_STYLE );
		//		lStyle &= ~( WS_CAPTION | WS_THICKFRAME );
		//		SetWindowLong( GetConsoleWindow(), GWL_STYLE, lStyle );
		//
		// # �� ��ǥ�� Ÿ��Ʋ �ٴ� ���� ������ Window �� 0, 0 �� �ڸ��ϴ� ���̴�.
		// # ���� Frame ũ�⸦ ����ؼ� ������ 0, 0 ��ġ�� ���̰� �ϰ��� �Ѵ�.
		//
		int offset_x = 0;
		offset_x -= GetSystemMetrics( SM_CXBORDER );
		offset_x -= GetSystemMetrics( SM_CXFRAME );
		offset_x -= GetSystemMetrics( SM_CXFIXEDFRAME );

		HWND hWnd = GetConsoleWindow();
		RECT rectClient;
		GetClientRect( hWnd, &rectClient );
		MoveWindow( hWnd, x + offset_x, y, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );
	}

	CursorPoint GetCursorPoint()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi{};
		GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );

		return CursorPoint{ csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
	}
	void SetCursorPoint( const CursorPoint new_cursor_point )
	{
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), COORD{ static_cast<SHORT>( new_cursor_point.x ), static_cast<SHORT>( new_cursor_point.y ) } );
	}

	void RequestSleep( const uint32_t m )
	{
		Sleep( m );
	}
}
