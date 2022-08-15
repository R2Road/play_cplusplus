#include "r2cm_WindowUtility.h"

#include <Windows.h>

namespace r2cm
{
	void WindowUtility::ChangeTitle( const char* title_string )
	{
		SetConsoleTitleA( title_string );
	}

	void WindowUtility::Resize( const int w, const int h )
	{
		HWND hWnd = GetConsoleWindow();
		RECT window_rect;
		GetClientRect( hWnd, &window_rect );
		MoveWindow( hWnd, window_rect.left, window_rect.top, w, h, TRUE );
	}

	void WindowUtility::Move( const int x, const int y )
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

	WindowUtility::CursorPoint WindowUtility::GetCursorPoint()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi{};
		GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );

		return CursorPoint{ csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
	}
	void WindowUtility::MoveCursorPoint( const CursorPoint new_cursor_point )
	{
		const CursorPoint fixed_new_cursor_point{ ( 0 > new_cursor_point.x ? 0 : new_cursor_point.x ), ( 0 > new_cursor_point.y ? 0 : new_cursor_point.y ) };
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), COORD{ fixed_new_cursor_point.x, fixed_new_cursor_point.y } );
	}
	void WindowUtility::MoveCursorPointWithClearBuffer( const CursorPoint new_cursor_point )
	{
		const auto last_cursor_point = GetCursorPoint();

		const CursorPoint fixed_new_cursor_point{ ( 0 > new_cursor_point.x ? 0 : new_cursor_point.x ), ( 0 > new_cursor_point.y ? 0 : new_cursor_point.y ) };
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), COORD{ fixed_new_cursor_point.x, fixed_new_cursor_point.y } );


		if( last_cursor_point.y >= fixed_new_cursor_point.y )
		{
			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info{};
			GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info );

			DWORD out_result;
			for( short i = 0, end = last_cursor_point.y - fixed_new_cursor_point.y; end > i; ++i )
			{
				FillConsoleOutputCharacterA( hStdout, ' ', cs_buffer_info.dwSize.X, COORD{ 0, fixed_new_cursor_point.y + i }, &out_result );
				FillConsoleOutputAttribute( hStdout, eColor::BG_Black | eColor::FG_White, cs_buffer_info.dwSize.X, COORD{ 0, fixed_new_cursor_point.y + i }, &out_result );
			}
		}
	}

	void WindowUtility::FillCharacter( const CursorPoint point, const char c )
	{
		DWORD out_result;
		FillConsoleOutputCharacterA( GetStdHandle( STD_OUTPUT_HANDLE ), c, 1, { point.x, point.y }, &out_result );
	}
	void WindowUtility::FillCharacter( const int x, const int y, const char c )
	{
		FillCharacter( { short( x ), short( y ) }, c );
	}

	void WindowUtility::FillColor( const CursorPoint point, const short c )
	{
		DWORD out_result;
		FillConsoleOutputAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), c, 1, { point.x, point.y }, &out_result );
	}
	void WindowUtility::FillColor( const int x, const int y, const short c )
	{
		FillColor( { short( x ), short( y ) }, c );
	}

	void WindowUtility::RequestSleep( const uint32_t m )
	{
		Sleep( m );
	}
}
