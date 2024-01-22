#if defined( DEBUG ) || defined( _DEBUG )
	#include "vld/include/vld.h"
#endif

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "RootMenu.h"

int main()
{
	//
	// Environment : Title
	//
	r2tm::WindowUtility::ChangeTitle( "play_cpp" );

	//
	// Environment : Size
	//
	r2tm::WindowUtility::Resize( 960, 960 );

	//
	// Environment : Position
	//
	r2tm::WindowUtility::Move( 0, 0 );

	r2tm::WindowUtility::QuickEditEnable( true );

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
