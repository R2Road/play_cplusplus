#include "LambdaMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_cpp/item/cpp_lambda_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp LambdaMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

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
		ret->AddItem( 'r', cpp_lambda_test::Size_3() );



		ret->AddSplit();



		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}