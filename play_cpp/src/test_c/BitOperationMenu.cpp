#include "BitOperationMenu.h"

#include "r2tm/r2tm_Director.h"

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
	return[]( r2tm::MenuProcessor* ret )
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


		ret->AddMenu( 27, C_Menu() );
	};
}