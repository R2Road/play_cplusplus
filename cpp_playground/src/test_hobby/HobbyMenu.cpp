#include "HobbyMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_hobby/item/fsm_v1_test.h"
#include "test_hobby/item/infinite_number_test.h"
#include "test_hobby/item/vector3_test.h"

#include "ArrayBasedListMenu.h"
#include "MemoryPoolMenu.h"

#include "RootMenu.h"

r2cm::MenuUp HobbyMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddMenu<MemoryPoolMenu>( '1' );


		ret->AddSplit();


		ret->AddItem( 'q', infinite_number_test::Basic::GetInstance() );
		ret->AddItem( 'w', fsm_v1_test::Basic::GetInstance() );


		ret->AddSplit();


		ret->AddItem( 'a', vector3_test::Declaration::GetInstance() );
		ret->AddItem( 's', vector3_test::OperatorPlus::GetInstance() );
		ret->AddItem( 'd', vector3_test::OperatorPlusEqual::GetInstance() );
		ret->AddItem( 'f', vector3_test::OperatorMinus::GetInstance() );
		ret->AddItem( 'g', vector3_test::OperatorMinusEqual::GetInstance() );
		ret->AddItem( 'h', vector3_test::OperatorMultiply_With_Scalar::GetInstance() );
		ret->AddItem( 'j', vector3_test::OperatorMultiplyEqual_With_Scalar::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<ArrayBasedListMenu>( 'z' );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}