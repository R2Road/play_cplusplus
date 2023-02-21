#if defined( DEBUG ) || defined( _DEBUG )
	#include "vld/include/vld.h"
#endif

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_WindowUtility.h"

#include "RootMenu.h"

int main()
{
	//
	// Environment : Title
	//
	r2cm::WindowUtility::ChangeTitle( "play_cpp" );

	//
	// Environment : Size
	//
	r2cm::WindowUtility::Resize( 960, 960 );

	//
	// Environment : Position
	//
	r2cm::WindowUtility::Move( 0, 0 );

	//
	// Setup
	//
	r2cm::Director director;
	director.Setup( RootMenu::Create( director ) );

	//
	// Process
	//
	director.Run();

	return 0;
}
