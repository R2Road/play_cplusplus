#include "TreeMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/play_tree.h"

#include "HobbyMenu.h"

r2cm::MenuUp TreeMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle()	) );

	{
		ret->AddItem( '1', play_tree::Basic() );



		ret->AddSplit();



		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}