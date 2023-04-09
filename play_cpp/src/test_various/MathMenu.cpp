#include "MathMenu.h"

#include "r2cm/r2cm_Director.h"

#include "RootMenu.h"

r2cm::MenuUp MathMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}