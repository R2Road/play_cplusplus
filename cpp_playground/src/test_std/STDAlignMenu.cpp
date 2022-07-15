#include "STDAlignMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/std_align_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDAlignMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', align_test::Align_0::GetInstance() );
		ret->AddItem( '2', align_test::Align_1::GetInstance() );
		ret->AddItem( '3', align_test::Align_2::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}