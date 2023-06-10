#include "PointerMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/c_pointer_test.h"

#include "C_Menu.h"

r2tm::TitleFunctionT PointerMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Pointer";
	};
}
r2tm::DescriptionFunctionT PointerMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT PointerMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', c_pointer_test::Basic() );
		ret->AddItem( '2', c_pointer_test::Offset() );
		ret->AddItem( '3', c_pointer_test::Pointer2Index() );
		ret->AddItem( '4', c_pointer_test::ConstPointer() );



		ret->AddLineFeed();



		ret->AddItem( 'q', c_pointer_test::CharacterPointer_Length_0() );



		ret->AddSplit();


		ret->AddMenu( 27, C_Menu() );
	};
}