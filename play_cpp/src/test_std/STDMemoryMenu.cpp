#include "STDMemoryMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_memory_unique_ptr_test::Basic() );
		mp->AddItem( '2', std_memory_unique_ptr_test::Size() );
		mp->AddItem( '3', std_memory_unique_ptr_test::Binary() );
		mp->AddItem( '4', std_memory_unique_ptr_test::Deleter() );
		mp->AddItem( '5', std_memory_unique_ptr_test::TemplateDeleter() );
		mp->AddItem( '6', std_memory_unique_ptr_test::FowardDeclaration() );



		mp->AddLineFeed();



		mp->AddItem( 'q', std_memory_shared_ptr_test::Basic() );
		mp->AddItem( 'w', std_memory_shared_ptr_test::Size() );
		mp->AddItem( 'e', std_memory_shared_ptr_test::Binary() );
		mp->AddItem( 'r', std_memory_shared_ptr_test::MakeShared_And_Memory() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', STDAlignMenu() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}