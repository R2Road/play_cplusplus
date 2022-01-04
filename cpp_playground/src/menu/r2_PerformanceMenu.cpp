#include "pch.h"
#include "r2_PerformanceMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/performance_1_test.h"
#include "test_cpp/performance_2_test.h"

namespace r2
{
	MenuUp PerformanceMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu( director, GetTitle() ) );

		{
			ret->AddChild( '1', performance_1_test::IncrementOperator::GetInstance() );
			ret->AddChild( '2', performance_1_test::Loop::GetInstance() );
			ret->AddChild( '3', performance_1_test::LoopWithBuildInArray::GetInstance() );
			ret->AddChild( '4', performance_1_test::LoopWithSTDArray::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'q', performance_2_test::BuiltInArrayIteration::GetInstance() );
			ret->AddChild( 'w', performance_2_test::STDArrayIteration::GetInstance() );
			ret->AddChild( 'e', performance_2_test::VectorIteration::GetInstance() );
			ret->AddChild( 'r', performance_2_test::ListIteration::GetInstance() );
			ret->AddChild( 't', performance_2_test::MapIteration::GetInstance() );
			ret->AddChild( 'y', performance_2_test::UnorderedMapIteration::GetInstance() );


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