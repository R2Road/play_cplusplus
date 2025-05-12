#include "STDFunctionalMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_functional_hash_test.h"
#include "test_std/item/std_functional_invoke_test.h"
#include "test_std/item/std_function_test.h"
#include "test_std/item/std_function_2_test.h"
#include "test_std/item/std_functional_mem_fn_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDFunctionalMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "<functional>";
	};
}
r2tm::DescriptionFunctionT STDFunctionalMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDFunctionalMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_functional_invoke_test::Basic() );



		mp->AddLineFeed();



		mp->AddItem( '6', std_functional_mem_fn_test::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'q', std_function_test::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'w', std_function_test::Equality_FunctionPointer_1() );
		mp->AddItem( 'e', std_function_test::Equality_FunctionPointer_2() );
		mp->AddItem( 'r', std_function_test::Equality_FunctionPointer_3() );
		mp->AddItem( 't', std_function_2_test::Equality_STDBind_1() );
		mp->AddItem( 'y', std_function_test::Equality_Lambda_1() );



		mp->AddLineFeed();



		mp->AddItem( 'a', std_functional_hash_test::Basic() );
		mp->AddItem( 's', std_functional_hash_test::CString() );



		mp->AddSplit();



		mp->AddMenu( 27, STDMenu() );
	};
}