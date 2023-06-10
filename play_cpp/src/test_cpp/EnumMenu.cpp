#include "EnumMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/enum_test.h"

#include "CPP_Menu.h"

r2tm::TitleFunctionT EnumMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Enum";
	};
}
r2tm::DescriptionFunctionT EnumMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT EnumMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', enum_test::Basic() );
		ret->AddItem( '2', enum_test::Cast() );



		ret->AddLineFeed();



		ret->AddItem( 'q', enum_test::ConvertWithTemplate() );



		ret->AddLineFeed();



		ret->AddItem( 'a', enum_test::MakeEnumWithMacro() );
		ret->AddItem( 's', enum_test::XMacro_1() );
		ret->AddItem( 'd', enum_test::XMacro_2() );


		ret->AddSplit();


		ret->AddMenu( 27, CPP_Menu() );
	};
}