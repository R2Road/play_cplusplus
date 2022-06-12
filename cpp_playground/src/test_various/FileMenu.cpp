#include "FileMenu.h"

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Director.h"

#include "test_c/item/c_file_test.h"
#include "test_std/item/std_fstream_test.h"

#include "RootMenu.h"

r2cm::MenuUp FileMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', c_file_test::OpenAndClose::GetInstance() );
		ret->AddItem( '2', c_file_test::GetCharacter::GetInstance() );
		ret->AddItem( '3', c_file_test::GetLine::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', std_fstream_test::OpenAndClose::GetInstance() );
		ret->AddItem( 'w', std_fstream_test::GetCharacter::GetInstance() );
		ret->AddItem( 'e', std_fstream_test::GetLine::GetInstance() );
		ret->AddItem( 'r', std_fstream_test::GetBlank2Blank::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eItemLeaveAction
			{
				director.Setup( RootMenu::Create( director ) );
				return r2cm::eItemLeaveAction::None;
			}
		);
	}

	return ret;
}