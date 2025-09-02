#include "menu_performance.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_performance_1.hpp"
#include "play_performance_container_iteration.hpp"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Performance::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Performance";
	};
}
r2tm::DescriptionFunctionT Menu_Performance::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Performance::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_performance_1::IncrementOperator() );
		mp->AddItem( '2', play_performance_1::Loop() );
		mp->AddItem( '3', play_performance_1::LoopWithBuildInArray() );
		mp->AddItem( '4', play_performance_1::LoopWithSTDArray() );
		mp->AddItem( '5', play_performance_1::CompareIteratorOperator() );

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