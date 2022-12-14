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
		ret->AddItem( '1', std_array_test::Basic::GetInstance() );
		ret->AddItem( '2', std_array_test::Fill::GetInstance() );
		ret->AddItem( '3', std_array_test::Copy::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( '6', std_bitset_test::All_Any_None::GetInstance() );
		ret->AddItem( '7', std_bitset_test::Set_And_Test::GetInstance() );
		ret->AddItem( '8', std_bitset_test::Size::GetInstance() );
		ret->AddItem( '9', std_bitset_test::Operator::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_list_test::Splice_Single::GetInstance() );
		ret->AddItem( 'w', std_list_test::Splice_Range::GetInstance() );
		ret->AddItem( 'e', std_list_test::OthersIterator::GetInstance() );
		ret->AddItem( 'r', std_list_test::EndIterator::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'a', std_vector_test::Resize::GetInstance() );
		ret->AddItem( 's', std_vector_test::Resize_And_Memory::GetInstance() );
		ret->AddItem( 'd', std_vector_test::Clear::GetInstance() );
		ret->AddItem( 'f', std_vector_test::Reserve::GetInstance() );
		ret->AddItem( 'g', std_vector_test::NoneDefaultConstructor::GetInstance() );
		ret->AddItem( 'h', std_vector_test::BoolVector::GetInstance() );
		ret->AddItem( 'j', std_vector_test::OthersIterator::GetInstance() );
		ret->AddItem( 'k', std_vector_test::EndIterator::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}