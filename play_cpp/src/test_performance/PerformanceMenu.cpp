#include "PerformanceMenu.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Director.h"

#include "item/performance_1_test.h"
#include "item/performance_container_iteration_test.h"

#include "RootMenu.h"

r2cm::MenuUp PerformanceMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', performance_1_test::IncrementOperator() );
		ret->AddItem( '2', performance_1_test::Loop() );
		ret->AddItem( '3', performance_1_test::LoopWithBuildInArray() );
		ret->AddItem( '4', performance_1_test::LoopWithSTDArray() );
		ret->AddItem( '5', performance_1_test::CompareIteratorOperator() );

		ret->AddLineFeed();

		ret->AddItem( 'q', performance_container_iteration_test::BuiltInArrayIteration() );
		ret->AddItem( 'w', performance_container_iteration_test::STDArrayIteration() );
		ret->AddItem( 'e', performance_container_iteration_test::VectorIteration() );
		ret->AddItem( 'r', performance_container_iteration_test::ListIteration() );
		ret->AddItem( 't', performance_container_iteration_test::MapIteration() );
		ret->AddItem( 'y', performance_container_iteration_test::UnorderedMapIteration() );
		ret->AddItem( 'u', performance_container_iteration_test::SetIteration() );
		ret->AddItem( 'i', performance_container_iteration_test::UnorderedSetIteration() );
		ret->AddItem( 'o', performance_container_iteration_test::STDArrayIteration_WithPointer() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}