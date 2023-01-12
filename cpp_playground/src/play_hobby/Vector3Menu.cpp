#include "Vector3Menu.h"

#include "r2cm/r2cm_Director.h"

#include "item/play_vector3.h"

#include "HobbyMenu.h"

r2cm::MenuUp Vector3Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( 'a', play_vector3::Declaration() );
		ret->AddItem( 's', play_vector3::OperatorPlus() );
		ret->AddItem( 'd', play_vector3::OperatorPlusEqual() );
		ret->AddItem( 'f', play_vector3::OperatorMinus() );
		ret->AddItem( 'g', play_vector3::OperatorMinusEqual() );
		ret->AddItem( 'h', play_vector3::OperatorMultiply_With_Scalar() );
		ret->AddItem( 'j', play_vector3::OperatorMultiplyEqual_With_Scalar() );



		ret->AddSplit();



		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}