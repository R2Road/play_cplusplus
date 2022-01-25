#include "pch.h"
#include "r2_STDMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "r2_NumericMenu.h"
#include "r2_ContainerMenu.h"

#include "test_cpp/std_function_test.h"
#include "test_cpp/std_function_2_test.h"
#include "test_cpp/std_optional_test.h"
#include "test_cpp/string_view_test.h"
#include "test_cpp/tuple_test.h"
#include "test_cpp/variant_test.h"

namespace r2
{
	MenuUp STDMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', std_optional_test::Basic::GetInstance() );
			ret->AddChild( '2', std_optional_test::Constructor::GetInstance() );
			ret->AddChild( '3', std_optional_test::Reference::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( '5', stringview_test::Basic::GetInstance() );
			ret->AddChild( '6', tuple_test::Basic::GetInstance() );
			ret->AddChild( '7', variant_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'q', std_function_test::Equality_FunctionPointer_1::GetInstance() );
			ret->AddChild( 'w', std_function_test::Equality_FunctionPointer_2::GetInstance() );
			ret->AddChild( 'e', std_function_test::Equality_FunctionPointer_3::GetInstance() );
			ret->AddChild( 'r', std_function_2_test::Equality_STDBind_1::GetInstance() );
			ret->AddChild( 't', std_function_test::Equality_Lambda_1::GetInstance() );

			ret->AddLineFeed();


			ret->AddChild(
				'a'
				, []()->const char* { return r2::NumericMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::NumericMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				's'
				, []()->const char* { return r2::ContainerMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::ContainerMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestResult
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
		}

		return ret;
	}
}