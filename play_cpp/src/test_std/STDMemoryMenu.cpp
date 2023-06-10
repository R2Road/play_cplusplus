#include "STDMemoryMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_memory_shared_ptr_test.h"
#include "test_std/item/std_memory_unique_ptr_test.h"

#include "STDAlignMenu.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDMemoryMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<memory>";
	};
}
r2tm::DescriptionFunctionT STDMemoryMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDMemoryMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_memory_unique_ptr_test::Basic() );
		ret->AddItem( '2', std_memory_unique_ptr_test::Size() );
		ret->AddItem( '3', std_memory_unique_ptr_test::Binary() );
		ret->AddItem( '4', std_memory_unique_ptr_test::Deleter() );
		ret->AddItem( '5', std_memory_unique_ptr_test::TemplateDeleter() );
		ret->AddItem( '6', std_memory_unique_ptr_test::FowardDeclaration() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_memory_shared_ptr_test::Basic() );
		ret->AddItem( 'w', std_memory_shared_ptr_test::Size() );
		ret->AddItem( 'e', std_memory_shared_ptr_test::Binary() );
		ret->AddItem( 'r', std_memory_shared_ptr_test::MakeShared_And_Memory() );



		ret->AddLineFeed();



		ret->AddMenu( 'z', STDAlignMenu() );



		ret->AddSplit();



		ret->AddMenu( 27, STDMenu() );
	};
}