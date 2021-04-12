#include "pch.h"
#include <Windows.h>

#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2_Director.h"
#include "r2_RootScene.h"

int main()
{
	//
	// Environment
	//
	SetConsoleTitle( TEXT( "cpp_playground" ) );
	system( "mode con lines=60 cols=120" );

	//
	// Setup
	//
	r2::Director director;
	director.Setup( r2::RootScene::Create( director ) );

	//
	// Process
	//
	director.Update();

	return 0;
}
