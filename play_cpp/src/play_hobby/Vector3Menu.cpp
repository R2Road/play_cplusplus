#include "Vector3Menu.h"

#include "r2tm/r2tm_Director.h"

#include "item/play_vector3.h"

#include "HobbyMenu.h"

r2tm::TitleFunctionT Vector3Menu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Vector3";
	};
}
r2tm::DescriptionFunctionT Vector3Menu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Vector3Menu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( 'a', play_vector3::Declaration() );
		ret->AddItem( 's', play_vector3::OperatorPlus() );
		ret->AddItem( 'd', play_vector3::OperatorPlusEqual() );
		ret->AddItem( 'f', play_vector3::OperatorMinus() );
		ret->AddItem( 'g', play_vector3::OperatorMinusEqual() );
		ret->AddItem( 'h', play_vector3::OperatorMultiply_With_Scalar() );
		ret->AddItem( 'j', play_vector3::OperatorMultiplyEqual_With_Scalar() );



		ret->AddSplit();



		ret->AddMenu( 27, HobbyMenu() );
	};
}