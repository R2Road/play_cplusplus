#include "STDAlignMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/std_memory_align_test.h"

#include "STDMemoryMenu.h"

r2cm::MenuUp STDAlignMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_memory_align_test::Basic() );
		ret->AddItem( '2', std_memory_align_test::Bound() );
		ret->AddItem( '3', std_memory_align_test::Play() );


		ret->AddSplit();


		ret->AddMenu<STDMemoryMenu>( 27 );
	}

	return ret;
}