#include "PointerMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', c_pointer_test::Basic() );
		mp->AddItem( '2', c_pointer_test::Offset() );
		mp->AddItem( '3', c_pointer_test::Pointer2Index() );
		mp->AddItem( '4', c_pointer_test::ConstPointer() );



		mp->AddLineFeed();



		mp->AddItem( 'q', c_pointer_test::CharacterPointer_Length_0() );
		mp->AddItem( 'w', c_pointer_test::MemberAddress() );
		mp->AddItem( 'e', c_pointer_test::StackAddress() );



		mp->AddSplit();


		mp->AddMenu( 27, C_Menu() );
	};
}