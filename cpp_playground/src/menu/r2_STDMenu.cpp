#include "pch.h"
#include "r2_STDMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "r2_AlgorithmMenu.h"

#include "test_cpp/optional_test.h"
#include "test_cpp/variant_test.h"
#include "test_cpp/tuple_test.h"

namespace r2
{
	MenuUp STDMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', optional_test::Basic::GetInstance() );
			ret->AddChild( '2', variant_test::Basic::GetInstance() );
			ret->AddChild( '3', tuple_test::Basic::GetInstance() );


			ret->AddLineFeed();


			ret->AddChild(
				'q'
				, []()->const char* { return r2::AlgorithmMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::AlgorithmMenu::Create( director ) );
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