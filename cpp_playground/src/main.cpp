#include "pch.h"
#include <Windows.h>

#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2_Director.h"
#include "r2_RootMenu.h"

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
		HWND hWnd = GetConsoleWindow();
		RECT rectClient;
		GetClientRect( hWnd, &rectClient );
		MoveWindow( hWnd, 0, 0, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );
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
