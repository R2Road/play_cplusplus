#include "PropertyMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/play_property.h"

#include "HobbyMenu.h"

r2cm::MenuUp PropertyMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', play_property::Functor() );



		ret->AddSplit();



		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}