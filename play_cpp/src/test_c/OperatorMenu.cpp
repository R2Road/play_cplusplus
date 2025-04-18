#include "OperatorMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/c_operator_ternary_test.h"

#include "C_Menu.h"

r2tm::TitleFunctionT OperatorMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Operator";
	};
}
r2tm::DescriptionFunctionT OperatorMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT OperatorMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', c_operator_ternary_test::Basic() );
		ret->AddItem( '2', c_operator_ternary_test::Comma() );
		ret->AddItem( '3', c_operator_ternary_test::Void() );



		ret->AddSplit();


		ret->AddMenu( 27, C_Menu() );
	};
}