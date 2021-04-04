#include <Windows.h>

#include "r2_Director.h"
#include "r2_Scene.h"

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
	director.Setup( r2::Scene::Create( &director ) );

	//
	// Process
	//
	director.Update();

	return 0;
}
