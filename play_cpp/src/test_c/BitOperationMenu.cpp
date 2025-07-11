#include "BitOperationMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "item/c_bit_operation_test.h"

#include "C_Menu.h"

r2tm::TitleFunctionT BitOperationMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Bit Operation";
	};
}
r2tm::DescriptionFunctionT BitOperationMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT BitOperationMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', c_bit_operation_test::Operator() );
		mp->AddItem( '2', c_bit_operation_test::Operator_2() );
		mp->AddItem( '3', c_bit_operation_test::Complement() );
		mp->AddItem( '4', c_bit_operation_test::Add_Remove_Toggle() );
		mp->AddItem( '5', c_bit_operation_test::Mask() );



		mp->AddLineFeed();



		mp->AddItem( '6', c_bit_operation_test::Operator_XOR() );
		mp->AddItem( '7', c_bit_operation_test::XOR_Swap() );



		mp->AddLineFeed();



		mp->AddItem( 'q', c_bit_operation_test::Plus_1() );
		mp->AddItem( 'w', c_bit_operation_test::Plus_2() );
		mp->AddItem( 'e', c_bit_operation_test::Minus_1() );
		mp->AddItem( 'r', c_bit_operation_test::Minus_2() );



		mp->AddLineFeed();



		mp->AddItem( 'a', c_bit_operation_test::ETC_1() );
		mp->AddItem( 's', c_bit_operation_test::ETC_2() );



		mp->AddSplit();


		mp->AddMenu( 27, C_Menu() );
	};
}