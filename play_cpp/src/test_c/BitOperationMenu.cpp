#include "BitOperationMenu.h"

#include "r2cm/r2cm_Director.h"

#include "item/c_bit_operation_test.h"

#include "C_Menu.h"

r2cm::MenuUp BitOperationMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, BitOperationMenu::GetTitle() ) );

	{
		ret->AddItem( '1', c_bit_operation_test::Operator() );
		ret->AddItem( '2', c_bit_operation_test::Complement() );
		ret->AddItem( '3', c_bit_operation_test::Add_Remove_Toggle() );
		ret->AddItem( '4', c_bit_operation_test::Mask() );



		ret->AddLineFeed();



		ret->AddItem( '6', c_bit_operation_test::Operator_XOR() );
		ret->AddItem( '7', c_bit_operation_test::XOR_Swap() );



		ret->AddLineFeed();



		ret->AddItem( 'q', c_bit_operation_test::Plus_1() );
		ret->AddItem( 'w', c_bit_operation_test::Plus_2() );
		ret->AddItem( 'e', c_bit_operation_test::Minus_1() );
		ret->AddItem( 'r', c_bit_operation_test::Minus_2() );



		ret->AddLineFeed();



		ret->AddItem( 'a', c_bit_operation_test::ETC_1() );



		ret->AddSplit();


		ret->AddMenu<C_Menu>( 27 );
	}

	return ret;
}