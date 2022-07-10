#include "STDStringMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_constant.h"

#include "test_std/item/std_string_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDStringMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_string_test::Find::GetInstance() );
		ret->AddItem( '2', std_string_test::Find_And_Split::GetInstance() );
		ret->AddItem( '3', std_string_test::Line_Count::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}