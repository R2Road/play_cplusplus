#include "OperatorMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/c_operator_priority_test.h"
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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', c_operator_priority_test::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'q', c_operator_ternary_test::Basic() );
		mp->AddItem( 'w', c_operator_ternary_test::Comma() );
		mp->AddItem( 'e', c_operator_ternary_test::Void() );



		mp->AddSplit();


		mp->AddMenu( 27, C_Menu() );
	};
}