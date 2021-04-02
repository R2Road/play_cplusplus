#include <Windows.h>

#include "r2_Scene.h"

int main()
{
	SetConsoleTitle( TEXT( "cpp_playground" ) );
	system( "mode con lines=60 cols=120" );

	r2::Scene scene;
	scene.Do();

	return 0;
}
