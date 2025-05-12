#include "STDAlignMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/std_memory_align_test.h"

#include "STDMemoryMenu.h"

r2tm::TitleFunctionT STDAlignMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "STDAlign";
	};
}
r2tm::DescriptionFunctionT STDAlignMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDAlignMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_memory_align_test::Basic() );
		mp->AddItem( '2', std_memory_align_test::Bound() );
		mp->AddItem( '3', std_memory_align_test::Play() );


		mp->AddSplit();


		mp->AddMenu( 27, STDMemoryMenu() );
	};
}