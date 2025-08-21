#include "LambdaMenu.h"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_cpp/item/cpp_lambda_test.h"

#include "CPP_Menu.h"

r2tm::TitleFunctionT LambdaMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Lambda";
	};
}
r2tm::DescriptionFunctionT LambdaMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT LambdaMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', cpp_lambda_test::Basic() );
		mp->AddItem( '2', cpp_lambda_test::CaptureValue() );
		mp->AddItem( '3', cpp_lambda_test::CaptureValueWithMutable() );
		mp->AddItem( '4', cpp_lambda_test::CaptureReference() );
		mp->AddItem( '5', cpp_lambda_test::CaptureUniquePtr() );
		mp->AddItem( '6', cpp_lambda_test::CaptureValueWithAssign() );



		mp->AddLineFeed();



		mp->AddItem( 'q', cpp_lambda_test::Size_Basic() );
		mp->AddItem( 'w', cpp_lambda_test::Size_CopyCapture() );
		mp->AddItem( 'e', cpp_lambda_test::Size_ReferenceCapture() );
		mp->AddItem( 'r', cpp_lambda_test::Size_ThisCapture() );
		mp->AddItem( 't', cpp_lambda_test::Size_With_STDFunction() );



		mp->AddSplit();



		mp->AddMenu( 27, CPP_Menu() );
	};
}