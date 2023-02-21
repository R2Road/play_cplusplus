#include "AlignMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_cpp/item/cpp_alignas_test.h"
#include "test_cpp/item/cpp_alignof_test.h"

#include "CPP_Menu.h"

r2cm::MenuUp AlignMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', cpp_alignof_test::PrimitiveType() );
		ret->AddItem( '2', cpp_alignof_test::STDContainer() );
		ret->AddItem( '3', cpp_alignof_test::Struct() );
		ret->AddItem( '4', cpp_alignof_test::MixedStruct() );



		ret->AddLineFeed();



		ret->AddItem( 'q', cpp_align_test::AlignAs() );



		ret->AddSplit();



		ret->AddMenu<CPP_Menu>( 27 );
	}

	return ret;
}