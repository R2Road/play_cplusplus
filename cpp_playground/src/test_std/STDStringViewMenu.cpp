#include "STDStringViewMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_std/item/std_string_view_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDStringViewMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_string_view_test::Basic::GetInstance() );
		ret->AddItem( '2', std_string_view_test::Literal_Operator_sv::GetInstance() );
		ret->AddItem( '3', std_string_view_test::Remove::GetInstance() );
		ret->AddItem( '4', std_string_view_test::SubStr::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}