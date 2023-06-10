#include "ETCMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/etc_0_test.h"

#include "RootMenu.h"

r2tm::TitleFunctionT ETCMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "ETC";
	};
}
r2tm::DescriptionFunctionT ETCMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT ETCMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', etc_test::ShowBinary() );
		ret->AddItem( '2', etc_test::LifeTimeTest() );
		ret->AddItem( '3', etc_test::STDFunctionImplement() );
		ret->AddItem( '4', etc_test::Braces_PrimitiveType() );

		ret->AddItem( '5', etc_test::CircularReference() );


		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}