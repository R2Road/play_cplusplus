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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', etc_test::ShowBinary() );
		mp->AddItem( '2', etc_test::LifeTimeTest() );
		mp->AddItem( '3', etc_test::STDFunctionImplement() );
		mp->AddItem( '4', etc_test::Braces_PrimitiveType() );

		mp->AddItem( '5', etc_test::CircularReference() );



		mp->AddLineFeed();



		mp->AddItem( 'q', etc_test::E() );


		mp->AddSplit();


		mp->AddMenu( 27, RootMenu() );
	};
}