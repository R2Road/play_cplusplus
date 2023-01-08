#include "STDContainerMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_std/item/std_array_test.h"
#include "test_std/item/std_bitset_test.h"
#include "test_std/item/std_list_test.h"
#include "test_std/item/std_vector_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDContainerMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_array_test::Basic() );
		ret->AddItem( '2', std_array_test::Fill() );
		ret->AddItem( '3', std_array_test::Copy() );


		ret->AddLineFeed();


		ret->AddItem( '6', std_bitset_test::All_Any_None() );
		ret->AddItem( '7', std_bitset_test::Set_And_Test() );
		ret->AddItem( '8', std_bitset_test::Size() );
		ret->AddItem( '9', std_bitset_test::Operator() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_list_test::Splice_Single() );
		ret->AddItem( 'w', std_list_test::Splice_Range() );
		ret->AddItem( 'e', std_list_test::OthersIterator() );
		ret->AddItem( 'r', std_list_test::EndIterator() );


		ret->AddLineFeed();


		ret->AddItem( 'a', std_vector_test::Resize() );
		ret->AddItem( 's', std_vector_test::Resize_And_Memory() );
		ret->AddItem( 'd', std_vector_test::Clear() );
		ret->AddItem( 'f', std_vector_test::Reserve() );
		ret->AddItem( 'g', std_vector_test::NoneDefaultConstructor() );
		ret->AddItem( 'h', std_vector_test::BoolVector() );
		ret->AddItem( 'j', std_vector_test::OthersIterator() );
		ret->AddItem( 'k', std_vector_test::EndIterator() );
		ret->AddItem( 'l', std_vector_test::Move() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}