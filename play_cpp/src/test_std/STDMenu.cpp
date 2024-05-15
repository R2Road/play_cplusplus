#include "STDMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_algorithm_test.h"
#include "test_std/item/std_cout_test.h"
#include "test_std/item/std_regex_test.h"
#include "test_std/item/std_string_test.h"
#include "test_std/item/std_system_test.h"
#include "test_std/item/std_tuple_test.h"
#include "test_std/item/std_variant_test.h"


#include "RootMenu.h"
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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', std_system_test::Demo() );
		ret->AddMenu( '2', STDCoutMenu() );
		ret->AddMenu( '3', STDCinMenu() );
		ret->AddMenu( '4', STDFileSystemMenu() );
		ret->AddMenu( '5', STDFstreamMenu() );
		ret->AddMenu( '6', STDOptionalMenu() );
		ret->AddMenu( '7', STDStringMenu() );
		ret->AddMenu( '8', STDStringViewMenu() );



		ret->AddLineFeed();



		ret->AddItem( '8', std_tuple_test::Basic() );
		ret->AddItem( '9', std_variant_test::Basic() );



		ret->AddLineFeed();



		ret->AddMenu( 'q', STDFunctionalMenu() );



		ret->AddLineFeed();



		ret->AddItem( 'a', std_regex_test::Basic() );
		ret->AddItem( 's', std_algorithm_test::Shuffle() );



		ret->AddLineFeed();



		ret->AddMenu( 'z', STDMemoryMenu() );
		ret->AddMenu( 'x', STDNumericMenu() );
		ret->AddMenu( 'c', STDContainerMenu() );
		ret->AddMenu( 'v', STDThreadMenu() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}