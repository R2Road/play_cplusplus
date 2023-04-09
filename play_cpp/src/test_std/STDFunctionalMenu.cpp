#include "STDFunctionalMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_std/item/std_functional_hash_test.h"
#include "test_std/item/std_functional_invoke_test.h"
#include "test_std/item/std_function_test.h"
#include "test_std/item/std_function_2_test.h"
#include "test_std/item/std_functional_mem_fn_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDFunctionalMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_functional_invoke_test::Basic() );



		ret->AddLineFeed();



		ret->AddItem( '6', std_functional_mem_fn_test::Basic() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_function_test::Basic() );



		ret->AddLineFeed();



		ret->AddItem( 'w', std_function_test::Equality_FunctionPointer_1() );
		ret->AddItem( 'e', std_function_test::Equality_FunctionPointer_2() );
		ret->AddItem( 'r', std_function_test::Equality_FunctionPointer_3() );
		ret->AddItem( 't', std_function_2_test::Equality_STDBind_1() );
		ret->AddItem( 'y', std_function_test::Equality_Lambda_1() );



		ret->AddLineFeed();



		ret->AddItem( 'a', std_functional_hash_test::Basic() );
		ret->AddItem( 's', std_functional_hash_test::CString() );



		ret->AddSplit();



		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}