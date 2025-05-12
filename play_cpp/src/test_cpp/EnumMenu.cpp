#include "EnumMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', enum_test::Basic() );
		mp->AddItem( '2', enum_test::Cast() );



		mp->AddLineFeed();



		mp->AddItem( 'q', enum_test::ConvertWithTemplate() );



		mp->AddLineFeed();



		mp->AddItem( 'a', enum_test::MakeEnumWithMacro() );
		mp->AddItem( 's', enum_test::XMacro_1() );
		mp->AddItem( 'd', enum_test::XMacro_2() );


		mp->AddSplit();


		mp->AddMenu( 27, CPP_Menu() );
	};
}