#include "LambdaMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_cpp/item/cpp_lambda_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp LambdaMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', cpp_lambda_test::Basic::GetInstance() );
		ret->AddItem( '2', cpp_lambda_test::CaptureValue::GetInstance() );
		ret->AddItem( '3', cpp_lambda_test::CaptureValueWithMutable::GetInstance() );
		ret->AddItem( '4', cpp_lambda_test::CaptureReference::GetInstance() );
		ret->AddItem( '5', cpp_lambda_test::CaptureUniquePtr::GetInstance() );
		ret->AddItem( '6', cpp_lambda_test::CaptureValueWithAssign::GetInstance() );
		ret->AddItem( '7', cpp_lambda_test::Size::GetInstance() );
		ret->AddItem( '8', cpp_lambda_test::Size_2::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}