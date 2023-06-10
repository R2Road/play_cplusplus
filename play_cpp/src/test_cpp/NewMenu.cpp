#include "NewMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/cpp_new_test.h"

#include "CPP_Menu.h"

r2tm::TitleFunctionT NewMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "New";
	};
}
r2tm::DescriptionFunctionT NewMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT NewMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', cpp_new_test::Basic() );
		ret->AddItem( '2', cpp_new_test::Array() );
		ret->AddItem( '3', cpp_new_test::PlacementNew() );



		ret->AddSplit();



		ret->AddMenu( 27, CPP_Menu() );
	};
}