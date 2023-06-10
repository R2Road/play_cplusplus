#include "LambdaMenu.h"

#include "r2tm/r2tm_Director.h"

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
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', cpp_lambda_test::Basic() );
		ret->AddItem( '2', cpp_lambda_test::CaptureValue() );
		ret->AddItem( '3', cpp_lambda_test::CaptureValueWithMutable() );
		ret->AddItem( '4', cpp_lambda_test::CaptureReference() );
		ret->AddItem( '5', cpp_lambda_test::CaptureUniquePtr() );
		ret->AddItem( '6', cpp_lambda_test::CaptureValueWithAssign() );



		ret->AddLineFeed();



		ret->AddItem( 'q', cpp_lambda_test::Size_Basic() );
		ret->AddItem( 'w', cpp_lambda_test::Size_CopyCapture() );
		ret->AddItem( 'e', cpp_lambda_test::Size_ReferenceCapture() );
		ret->AddItem( 'r', cpp_lambda_test::Size_ThisCapture() );
		ret->AddItem( 't', cpp_lambda_test::Size_With_STDFunction() );



		ret->AddSplit();



		ret->AddMenu( 27, CPP_Menu() );
	};
}