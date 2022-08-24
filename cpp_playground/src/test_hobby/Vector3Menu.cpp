#include "Vector3Menu.h"

#include "r2cm/r2cm_Director.h"

#include "item/vector3_test.h"

#include "HobbyMenu.h"

r2cm::MenuUp Vector3Menu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( 'a', vector3_test::Declaration::GetInstance() );
		ret->AddItem( 's', vector3_test::OperatorPlus::GetInstance() );
		ret->AddItem( 'd', vector3_test::OperatorPlusEqual::GetInstance() );
		ret->AddItem( 'f', vector3_test::OperatorMinus::GetInstance() );
		ret->AddItem( 'g', vector3_test::OperatorMinusEqual::GetInstance() );
		ret->AddItem( 'h', vector3_test::OperatorMultiply_With_Scalar::GetInstance() );
		ret->AddItem( 'j', vector3_test::OperatorMultiplyEqual_With_Scalar::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}