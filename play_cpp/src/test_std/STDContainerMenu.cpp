#include "STDContainerMenu.h"

#include "r2tm/r2tm_Director.h"

#include "test_std/item/std_array_test.h"
#include "test_std/item/std_bitset_test.h"
#include "test_std/item/std_list_test.h"
#include "test_std/item/std_queue_test.h"
#include "test_std/item/std_unordered_map_test.h"
#include "test_std/item/std_vector_test.h"

#include "STDMenu.h"

r2tm::TitleFunctionT STDContainerMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Container";
	};
}
r2tm::DescriptionFunctionT STDContainerMenu::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT STDContainerMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', std_array_test::Basic() );
		mp->AddItem( '2', std_array_test::Fill() );
		mp->AddItem( '3', std_array_test::Copy() );


		mp->AddLineFeed();


		mp->AddItem( '6', std_bitset_test::All_Any_None() );
		mp->AddItem( '7', std_bitset_test::Set_And_Test() );
		mp->AddItem( '8', std_bitset_test::Size() );
		mp->AddItem( '9', std_bitset_test::Operator() );


		mp->AddLineFeed();


		mp->AddItem( 'q', std_list_test::Insert() );
		mp->AddItem( 'w', std_list_test::Splice_Single() );
		mp->AddItem( 'e', std_list_test::Splice_Range() );
		mp->AddItem( 'r', std_list_test::Erase() );
		mp->AddItem( 't', std_list_test::Erase_OthersIterator() );
		mp->AddItem( 'y', std_list_test::EndIterator() );


		mp->AddLineFeed();


		mp->AddItem( 'a', std_vector_test::Resize() );
		mp->AddItem( 's', std_vector_test::Resize_And_Memory() );
		mp->AddItem( 'd', std_vector_test::Clear() );
		mp->AddItem( 'f', std_vector_test::Reserve() );
		mp->AddItem( 'g', std_vector_test::NoneDefaultConstructor() );
		mp->AddItem( 'h', std_vector_test::BoolVector() );
		mp->AddItem( 'j', std_vector_test::OthersIterator() );
		mp->AddItem( 'k', std_vector_test::EndIterator() );
		mp->AddItem( 'l', std_vector_test::Move() );


		mp->AddLineFeed();


		mp->AddItem( 'z', std_queue_test::Declaration() );
		mp->AddItem( 'x', std_queue_test::Front_Back() );
		mp->AddItem( 'c', std_queue_test::Push_Pop() );
		mp->AddItem( 'v', std_queue_test::Iteration() );


		mp->AddLineFeed();


		mp->AddItem( 'n', std_unordered_map_test::CString() );


		mp->AddSplit();


		mp->AddMenu( 27, STDMenu() );
	};
}