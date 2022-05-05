#include "pch.h"

#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "base/r2cm_Director.h"
#include "r2_RootMenu.h"
#include "utility/r2utility_WindowUtil.h"

int main()
{
	//
	// Environment : Title
	//
	r2utility::ChangeWindowTitle( L"cpp_playground" );

	//
	// Environment : Size
	//
	r2utility::ResizeWindow( 960, 960 );

	//
	// Environment : Position
	//
	r2utility::MoveWindow( 0, 0 );

	//
	// Setup
	//
	r2cm::Director director;
	director.Setup( r2::RootMenu::Create( director ) );

	//
	// Process
	//
	director.Run();

	return 0;
}
