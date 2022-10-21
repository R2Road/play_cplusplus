#include "STDStringViewMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_std/item/std_stringview_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDStringViewMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_stringview_test::Basic::GetInstance() );
		ret->AddItem( '2', std_stringview_test::Literal_Operator_sv::GetInstance() );
		ret->AddItem( '3', std_stringview_test::Utility::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}