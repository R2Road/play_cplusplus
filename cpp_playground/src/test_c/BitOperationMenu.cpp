#include "BitOperationMenu.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"

#include "item/c_bit_operation_test.h"

#include "C_Menu.h"

r2cm::MenuUp BitOperationMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, BitOperationMenu::GetTitle() ) );

	{
		ret->AddItem( '1', bit_operation_test::Basic::GetInstance() );
		ret->AddItem( '2', bit_operation_test::Operator::GetInstance() );
		ret->AddItem( '3', bit_operation_test::Complement::GetInstance() );
		ret->AddItem( '4', bit_operation_test::Add_Remove_Toggle::GetInstance() );
		ret->AddItem( '5', bit_operation_test::Mask::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( '6', bit_operation_test::Operator_XOR::GetInstance() );
		ret->AddItem( '7', bit_operation_test::XOR_Swap::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', bit_operation_test::ETC_1::GetInstance() );
		ret->AddItem( 'w', bit_operation_test::Plus_1::GetInstance() );
		ret->AddItem( 'e', bit_operation_test::Plus_2::GetInstance() );
		ret->AddItem( 'r', bit_operation_test::Minus_1::GetInstance() );
		ret->AddItem( 't', bit_operation_test::Minus_2::GetInstance() );



		ret->AddSplit();


		ret->AddMenu<C_Menu>( 27 );
	}

	return ret;
}