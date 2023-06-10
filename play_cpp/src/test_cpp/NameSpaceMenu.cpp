#include "NameSpaceMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/cpp_namespace_test.h"

#include "CPP_Menu.h"

r2tm::TitleFunctionT NameSpaceMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "NameSpace";
	};
}
r2tm::DescriptionFunctionT NameSpaceMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT NameSpaceMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', cpp_namespace_test::Basic() );
		ret->AddItem( '2', cpp_namespace_test::Alias() );



		ret->AddSplit();



		ret->AddMenu( 27, CPP_Menu() );
	};
}