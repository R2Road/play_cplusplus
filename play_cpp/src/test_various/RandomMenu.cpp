#include "RandomMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_c/item/c_random_test.h"
#include "test_std/item/std_random_test.h"

#include "menu_root.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', c_random_test::Rand() );


		mp->AddLineFeed();


		mp->AddItem( 'q', std_random_test::Basic() );
		mp->AddItem( 'w', std_random_test::StatusSaveAndLoad() );
		mp->AddItem( 'e', std_random_test::DiscreateDistribution() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}