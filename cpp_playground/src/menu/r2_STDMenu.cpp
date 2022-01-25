#include "pch.h"
#include "r2_STDMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "r2_NumericMenu.h"
#include "r2_ContainerMenu.h"

#include "test_cpp/optional_test.h"
#include "test_cpp/std_function_test.h"
#include "test_cpp/std_function_2_test.h"
#include "test_cpp/string_view_test.h"
#include "test_cpp/tuple_test.h"
#include "test_cpp/variant_test.h"

namespace r2
{
	MenuUp STDMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', optional_test::Basic::GetInstance() );
			ret->AddChild( '2', optional_test::Basic_discard::GetInstance() );
			ret->AddChild( '3', stringview_test::Basic::GetInstance() );
			ret->AddChild( '4', tuple_test::Basic::GetInstance() );
			ret->AddChild( '5', variant_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( '5', std_function_test::Equality_FunctionPointer_1::GetInstance() );
			ret->AddChild( '6', std_function_test::Equality_FunctionPointer_2::GetInstance() );
			ret->AddChild( '7', std_function_test::Equality_FunctionPointer_3::GetInstance() );
			ret->AddChild( '8', std_function_2_test::Equality_STDBind_1::GetInstance() );
			ret->AddChild( '9', std_function_test::Equality_Lambda_1::GetInstance() );

			ret->AddLineFeed();


			ret->AddChild(
				'q'
				, []()->const char* { return r2::NumericMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::NumericMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'w'
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