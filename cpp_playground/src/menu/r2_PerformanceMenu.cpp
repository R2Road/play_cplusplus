#include "pch.h"
#include "r2_PerformanceMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"
#include "r2_RootMenu.h"

#include "test_cpp/performance_1_test.h"
#include "test_cpp/performance_container_iteration_test.h"

namespace r2
{
	r2cm::MenuUp PerformanceMenu::Create( r2cm::Director& director )
	{
		r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

		{
			ret->AddItem( '1', performance_1_test::IncrementOperator::GetInstance() );
			ret->AddItem( '2', performance_1_test::Loop::GetInstance() );
			ret->AddItem( '3', performance_1_test::LoopWithBuildInArray::GetInstance() );
			ret->AddItem( '4', performance_1_test::LoopWithSTDArray::GetInstance() );
			ret->AddItem( '5', performance_1_test::CompareIteratorOperator::GetInstance() );

			ret->AddLineFeed();

			ret->AddItem( 'q', performance_container_iteration_test::BuiltInArrayIteration::GetInstance() );
			ret->AddItem( 'w', performance_container_iteration_test::STDArrayIteration::GetInstance() );
			ret->AddItem( 'e', performance_container_iteration_test::VectorIteration::GetInstance() );
			ret->AddItem( 'r', performance_container_iteration_test::ListIteration::GetInstance() );
			ret->AddItem( 't', performance_container_iteration_test::MapIteration::GetInstance() );
			ret->AddItem( 'y', performance_container_iteration_test::UnorderedMapIteration::GetInstance() );
			ret->AddItem( 'u', performance_container_iteration_test::SetIteration::GetInstance() );
			ret->AddItem( 'i', performance_container_iteration_test::UnorderedSetIteration::GetInstance() );
			ret->AddItem( 'o', performance_container_iteration_test::STDArrayIteration_WithPointer::GetInstance() );


			ret->AddSplit();


			ret->AddItem(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->r2cm::eTestEndAction
				{
					director.Setup( r2::RootMenu::Create( director ) );
					return r2cm::eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}