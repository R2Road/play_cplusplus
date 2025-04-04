#include "RandomMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_c/item/c_random_test.h"
#include "test_std/item/std_random_test.h"

#include "RootMenu.h"

r2tm::TitleFunctionT RandomMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Random";
	};
}
r2tm::DescriptionFunctionT RandomMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT RandomMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', c_random_test::Rand() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_random_test::Basic() );
		ret->AddItem( 'w', std_random_test::StatusSaveAndLoad() );
		ret->AddItem( 'e', std_random_test::DiscreateDistribution() );


		ret->AddSplit();


		ret->AddMenu( 27, RootMenu() );
	};
}