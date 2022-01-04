#include "pch.h"
#include "r2_PerformanceMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"
#include "r2_RootMenu.h"

#include "test_cpp/performance_1_test.h"
#include "test_cpp/performance_container_iteration_test.h"

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

			ret->AddChild( 'q', performance_container_iteration_test::BuiltInArrayIteration::GetInstance() );
			ret->AddChild( 'w', performance_container_iteration_test::STDArrayIteration::GetInstance() );
			ret->AddChild( 'e', performance_container_iteration_test::VectorIteration::GetInstance() );
			ret->AddChild( 'r', performance_container_iteration_test::ListIteration::GetInstance() );
			ret->AddChild( 't', performance_container_iteration_test::MapIteration::GetInstance() );
			ret->AddChild( 'y', performance_container_iteration_test::UnorderedMapIteration::GetInstance() );
			ret->AddChild( 'u', performance_container_iteration_test::SetIteration::GetInstance() );
			ret->AddChild( 'i', performance_container_iteration_test::UnorderedSetIteration::GetInstance() );
			ret->AddChild( 'o', performance_container_iteration_test::STDArrayIteration_WithPointer::GetInstance() );


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