#include "FSM_V1_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/hobby_fsm_v1_play.h"

#include "HobbyMenu.h"

r2cm::MenuUp FSM_V1_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle()	) );

	{
		ret->AddItem( '1', hobby_fsm_v1_play::State_Declaration() );



		ret->AddLineFeed();



		ret->AddItem( 'q', hobby_fsm_v1_play::Package_Declaration() );
		ret->AddItem( 'w', hobby_fsm_v1_play::Package_Add() );
		ret->AddItem( 'e', hobby_fsm_v1_play::Package_Transition() );



		ret->AddLineFeed();



		ret->AddItem( 'a', hobby_fsm_v1_play::Machine_Declaration() );
		ret->AddItem( 's', hobby_fsm_v1_play::Machine_Start_Stop() );



		ret->AddLineFeed();



		ret->AddItem( 32, hobby_fsm_v1_play::Demo() );



		ret->AddSplit();



		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}