#include "FileMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_c/item/c_file_test.h"
#include "test_std/item/std_fstream_test.h"

#include "RootMenu.h"

r2cm::MenuUp FileMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', c_file_test::OpenAndClose() );
		ret->AddItem( '2', c_file_test::GetCharacter() );
		ret->AddItem( '3', c_file_test::GetLine() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_fstream_test::OpenAndClose() );
		ret->AddItem( 'w', std_fstream_test::GetCharacter() );
		ret->AddItem( 'e', std_fstream_test::GetLine() );
		ret->AddItem( 'r', std_fstream_test::GetBlank2Blank() );


		ret->AddSplit();


		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}