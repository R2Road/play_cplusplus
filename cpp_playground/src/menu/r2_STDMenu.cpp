#include "pch.h"
#include "r2_STDMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "r2_NumericMenu.h"
#include "r2_STDContainerMenu.h"

#include "test_cpp/std_function_test.h"
#include "test_cpp/std_function_2_test.h"
#include "test_cpp/std_optional_test.h"
#include "test_cpp/std_stringview_test.h"
#include "test_cpp/std_tuple_test.h"
#include "test_cpp/std_variant_test.h"

#include "r2_STDMemoryMenu.h"
#include "r2_ThreadMenu.h"

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

			ret->AddChild( '5', std_stringview_test::Basic::GetInstance() );
			ret->AddChild( '6', std_tuple_test::Basic::GetInstance() );
			ret->AddChild( '7', std_variant_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'q', std_function_test::Equality_FunctionPointer_1::GetInstance() );
			ret->AddChild( 'w', std_function_test::Equality_FunctionPointer_2::GetInstance() );
			ret->AddChild( 'e', std_function_test::Equality_FunctionPointer_3::GetInstance() );
			ret->AddChild( 'r', std_function_2_test::Equality_STDBind_1::GetInstance() );
			ret->AddChild( 't', std_function_test::Equality_Lambda_1::GetInstance() );

			ret->AddLineFeed();


			ret->AddChild(
				'a'
				, []()->const char* { return r2::STDMemoryMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::STDMemoryMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				's'
				, []()->const char* { return r2::NumericMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::NumericMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'd'
				, []()->const char* { return r2::STDContainerMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::STDContainerMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);
			ret->AddChild(
				'f'
				, []()->const char* { return r2::ThreadMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::ThreadMenu::Create( director ) );
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