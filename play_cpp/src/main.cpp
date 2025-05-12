#if defined( DEBUG ) || defined( _DEBUG )
	#include "vld/include/vld.h"
#endif

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_WindowsUtility.h"

#include "RootMenu.h"

int main()
{
	//
	// Environment : Title
	//
	r2tm::WindowsUtility::ChangeTitle( "play_cpp" );

	//
	// Environment : Size
	//
	r2tm::WindowsUtility::Resize( 960, 960 );

	//
	// Environment : Position
	//
	r2tm::WindowsUtility::Move( 0, 0 );

	r2tm::WindowsUtility::QuickEditEnable( true );

	//
	// Setup
	//
	r2tm::Director director;
	director.Setup( RootMenu() );

	//
	// Process
	//
	director.Run();

	return 0;
}
