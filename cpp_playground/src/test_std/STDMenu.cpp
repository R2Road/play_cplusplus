#include "STDMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_std/item/std_algorithm_test.h"
#include "test_std/item/std_cout_test.h"
#include "test_std/item/std_regex_test.h"
#include "test_std/item/std_string_test.h"
#include "test_std/item/std_tuple_test.h"
#include "test_std/item/std_variant_test.h"


#include "RootMenu.h"
#include "STDAlignMenu.h"
#include "STDContainerMenu.h"
#include "STDCoutMenu.h"
#include "STDFileSystemMenu.h"
#include "STDFunctionalMenu.h"
#include "STDMemoryMenu.h"
#include "STDNumericMenu.h"
#include "STDOptionalMenu.h"
#include "STDStringMenu.h"
#include "STDStringViewMenu.h"
#include "STDThreadMenu.h"

r2cm::MenuUp STDMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddMenu<STDCoutMenu>( '1' );
		ret->AddMenu<STDFileSystemMenu>( '2' );
		ret->AddMenu<STDAlignMenu>( '3' );
		ret->AddMenu<STDOptionalMenu>( '4' );
		ret->AddMenu<STDStringMenu>( '5' );
		ret->AddMenu<STDStringViewMenu>( '6' );



		ret->AddLineFeed();



		ret->AddItem( '8', std_tuple_test::Basic::GetInstance() );
		ret->AddItem( '9', std_variant_test::Basic::GetInstance() );



		ret->AddLineFeed();



		ret->AddMenu<STDFunctionalMenu>( 'q' );



		ret->AddLineFeed();



		ret->AddItem( 'a', std_regex_test::Basic::GetInstance() );
		ret->AddItem( 's', std_algorithm_test::Shuffle::GetInstance() );



		ret->AddLineFeed();



		ret->AddMenu<STDMemoryMenu>( 'z' );
		ret->AddMenu<STDNumericMenu>( 'x' );
		ret->AddMenu<STDContainerMenu>( 'c' );
		ret->AddMenu<STDThreadMenu>( 'v' );



		ret->AddSplit();



		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}