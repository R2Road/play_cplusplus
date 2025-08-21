#include "NewMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', cpp_new_test::Basic() );
		mp->AddItem( '2', cpp_new_test::Array() );
		mp->AddItem( '3', cpp_new_test::PlacementNew() );



		mp->AddSplit();



		mp->AddMenu( 27, CPP_Menu() );
	};
}