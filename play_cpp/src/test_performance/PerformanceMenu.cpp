#include "PerformanceMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "item/performance_1_test.h"
#include "item/performance_container_iteration_test.h"

#include "menu_root.h"

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
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', performance_1_test::IncrementOperator() );
		mp->AddItem( '2', performance_1_test::Loop() );
		mp->AddItem( '3', performance_1_test::LoopWithBuildInArray() );
		mp->AddItem( '4', performance_1_test::LoopWithSTDArray() );
		mp->AddItem( '5', performance_1_test::CompareIteratorOperator() );

		mp->AddLineFeed();

		mp->AddItem( 'q', performance_container_iteration_test::BuiltInArrayIteration() );
		mp->AddItem( 'w', performance_container_iteration_test::STDArrayIteration() );
		mp->AddItem( 'e', performance_container_iteration_test::VectorIteration() );
		mp->AddItem( 'r', performance_container_iteration_test::ListIteration() );
		mp->AddItem( 't', performance_container_iteration_test::MapIteration() );
		mp->AddItem( 'y', performance_container_iteration_test::UnorderedMapIteration() );
		mp->AddItem( 'u', performance_container_iteration_test::SetIteration() );
		mp->AddItem( 'i', performance_container_iteration_test::UnorderedSetIteration() );
		mp->AddItem( 'o', performance_container_iteration_test::STDArrayIteration_WithPointer() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}