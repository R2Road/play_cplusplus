#include "pch.h"
#include <Windows.h>

#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "base/r2_Director.h"
#include "menu/r2_RootMenu.h"

int main()
{
	//
	// Environment : Title
	//
	SetConsoleTitle( TEXT( "cpp_playground" ) );

	//
	// Environment : Size
	//
	system( "mode con lines=60 cols=120" );

	//
	// Environment : Position
	//
	{
		//
		// # MoveWindow( hWnd, 0, 0... ); 만으로는 Window 가 실질적인 0, 0 좌표에 위치하지 않는다.
		// # 아래의 코드를 이용해서 타이틀 바와 얇은 프레임을 제거 해야만 위 코드로 0, 0 위치에 보여진다.
		//		LONG lStyle = GetWindowLong( GetConsoleWindow(), GWL_STYLE );
		//		lStyle &= ~( WS_CAPTION | WS_THICKFRAME );
		//		SetWindowLong( GetConsoleWindow(), GWL_STYLE, lStyle );
		//
		// # 내 목표는 타이틀 바는 남아 있지만 Window 가 0, 0 에 자리하는 것이다.
		// # 따라서 Frame 크기를 계산해서 강제로 0, 0 위치에 보이게 하고자 한다.
		//
		int offset_x = 0;
		offset_x -= GetSystemMetrics( SM_CXBORDER );
		offset_x -= GetSystemMetrics( SM_CXFRAME );
		offset_x -= GetSystemMetrics( SM_CXFIXEDFRAME );

		HWND hWnd = GetConsoleWindow();
		RECT rectClient;
		GetClientRect( hWnd, &rectClient );
		MoveWindow( hWnd, offset_x, 0, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );
	}

	//
	// Setup
	//
	r2::Director director;
	director.Setup( r2::RootMenu::Create( director ) );

	//
	// Process
	//
	director.Update();

	return 0;
}
