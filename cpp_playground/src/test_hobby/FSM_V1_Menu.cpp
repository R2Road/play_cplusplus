#include "FSM_V1_Menu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/hobby_fsm_v1_play.h"

#include "HobbyMenu.h"

r2cm::MenuUp FSM_V1_Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle()	) );

	{
		ret->AddItem( '1', hobby_fsm_v1_play::Package_Declaration() );
		ret->AddItem( '2', hobby_fsm_v1_play::Package_Add() );
		ret->AddItem( '3', hobby_fsm_v1_play::Machine_Declaration() );



		ret->AddSplit();



		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}