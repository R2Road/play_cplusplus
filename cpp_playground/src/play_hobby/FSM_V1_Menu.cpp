#include "FSM_V1_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/play_fsm_v1.h"

#include "HobbyMenu.h"

r2cm::MenuUp FSM_V1_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle()	) );

	{
		ret->AddItem( '1', play_fsm_v1::State_Declaration() );
		ret->AddItem( '2', play_fsm_v1::State_Enter_Exit() );



		ret->AddLineFeed();



		ret->AddItem( 'q', play_fsm_v1::Package_Declaration() );
		ret->AddItem( 'w', play_fsm_v1::Package_AddState() );
		ret->AddItem( 'e', play_fsm_v1::Package_AddTransition() );
		ret->AddItem( 'r', play_fsm_v1::Package_DoTransition() );



		ret->AddLineFeed();



		ret->AddItem( 'a', play_fsm_v1::Machine_Basic() );
		ret->AddItem( 's', play_fsm_v1::Machine_Start_Stop() );



		ret->AddLineFeed();



		ret->AddItem( 32, play_fsm_v1::Demo() );



		ret->AddSplit();



		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}