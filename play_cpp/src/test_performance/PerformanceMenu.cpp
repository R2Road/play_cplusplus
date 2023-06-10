#include "PerformanceMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/performance_1_test.h"
#include "item/performance_container_iteration_test.h"

#include "RootMenu.h"

r2tm::TitleFunctionT PerformanceMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Performance";
	};
}
r2tm::DescriptionFunctionT PerformanceMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT PerformanceMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
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


		ret->AddMenu( 27, RootMenu() );
	};
}