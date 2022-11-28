#include "AlignMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_cpp/item/alignof_test.h"
#include "test_cpp/item/alignas_test.h"
#include "test_cpp/item/struct_member_alignment_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp AlignMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', struct_member_alignment_test::Basic::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( '2', alignof_test::PrimitiveType::GetInstance() );
		ret->AddItem( '3', alignof_test::Basic::GetInstance() );
		ret->AddItem( '4', alignof_test::MixedStruct::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', align_test::AlignAs::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}