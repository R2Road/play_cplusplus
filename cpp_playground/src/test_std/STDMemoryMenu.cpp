#include "STDMemoryMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_std/item/std_memory_shared_ptr_test.h"
#include "test_std/item/std_memory_unique_ptr_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDMemoryMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_memory_unique_ptr_test::Basic() );
		ret->AddItem( '2', std_memory_unique_ptr_test::Size() );
		ret->AddItem( '3', std_memory_unique_ptr_test::Deleter() );
		ret->AddItem( '4', std_memory_unique_ptr_test::TemplateDeleter() );
		ret->AddItem( '5', std_memory_unique_ptr_test::FowardDeclaration() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_memory_shared_ptr_test::Basic() );
		ret->AddItem( 'w', std_memory_shared_ptr_test::Size() );
		ret->AddItem( 'e', std_memory_shared_ptr_test::MakeShared_And_Memory() );



		ret->AddSplit();



		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}