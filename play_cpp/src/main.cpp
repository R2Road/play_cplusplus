#if defined( DEBUG ) || defined( _DEBUG )
	#include "vld/include/vld.h"
#endif

#include "r2tm/r2tm_director.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

#include "menu_root.h"

int main()
{
	//
	// Environment : Title
	//
	r2tm::WindowsUtility::ChangeTitle( "play_cpp" );

	//
	// Environment : Size
	//
	r2tm::WindowsUtility::Resize( 1680, 1080 );

	//
	// Environment : Position
	//
	r2tm::WindowsUtility::Move( 0, 0 );

	r2tm::WindowsUtility::QuickEditEnable( true );

	//
	// Setup
	//
	r2tm::Director director;
	director.Setup( Menu_Root() );

	//
	// Process
	//
	director.Run();

	return 0;
}
