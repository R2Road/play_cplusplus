#include "STDMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_std/item/std_algorithm_test.h"
#include "test_std/item/std_cout_test.h"
#include "test_std/item/std_regex_test.h"
#include "test_std/item/std_string_test.h"
#include "test_std/item/std_system_test.h"
#include "test_std/item/std_tuple_test.h"
#include "test_std/item/std_variant_test.h"


#include "menu_root.hpp"
#include "STDCinMenu.h"
#include "STDContainerMenu.h"
#include "STDCoutMenu.h"
#include "STDFileSystemMenu.h"
#include "STDFstreamMenu.h"
#include "STDFunctionalMenu.h"
#include "STDMemoryMenu.h"
#include "STDNumericMenu.h"
#include "STDOptionalMenu.h"
#include "STDStringMenu.h"
#include "STDStringViewMenu.h"
#include "STDThreadMenu.h"

r2tm::TitleFunctionT STDMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "STD";
	};
}
r2tm::DescriptionFunctionT STDMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_system_test::Demo() );
		mp->AddMenu( '2', STDCoutMenu() );
		mp->AddMenu( '3', STDCinMenu() );
		mp->AddMenu( '4', STDFileSystemMenu() );
		mp->AddMenu( '5', STDFstreamMenu() );
		mp->AddMenu( '6', STDOptionalMenu() );
		mp->AddMenu( '7', STDStringMenu() );
		mp->AddMenu( '8', STDStringViewMenu() );



		mp->AddLineFeed();



		mp->AddItem( '8', std_tuple_test::Basic() );
		mp->AddItem( '9', std_variant_test::Basic() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', STDFunctionalMenu() );



		mp->AddLineFeed();



		mp->AddItem( 'a', std_regex_test::Basic() );
		mp->AddItem( 's', std_algorithm_test::Shuffle() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', STDMemoryMenu() );
		mp->AddMenu( 'x', STDNumericMenu() );
		mp->AddMenu( 'c', STDContainerMenu() );
		mp->AddMenu( 'v', STDThreadMenu() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}