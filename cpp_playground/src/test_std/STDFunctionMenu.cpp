#include "STDFunctionMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_std/item/std_function_test.h"
#include "test_std/item/std_function_2_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDFunctionMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_function_test::Basic::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_function_test::Equality_FunctionPointer_1::GetInstance() );
		ret->AddItem( 'w', std_function_test::Equality_FunctionPointer_2::GetInstance() );
		ret->AddItem( 'e', std_function_test::Equality_FunctionPointer_3::GetInstance() );
		ret->AddItem( 'r', std_function_2_test::Equality_STDBind_1::GetInstance() );
		ret->AddItem( 't', std_function_test::Equality_Lambda_1::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}