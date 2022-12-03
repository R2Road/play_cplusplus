#include "STDMemoryMenu.h"

#include "r2cm/r2cm_Director.h"

#include "test_std/item/std_memory_shared_ptr_test.h"
#include "test_std/item/std_memory_unique_ptr_test.h"

#include "STDMenu.h"

r2cm::MenuUp STDMemoryMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', std_memory_unique_ptr_test::Basic::GetInstance() );
		ret->AddItem( '2', std_memory_unique_ptr_test::Deleter::GetInstance() );
		ret->AddItem( '3', std_memory_unique_ptr_test::TemplateDeleter::GetInstance() );
		ret->AddItem( '4', std_memory_unique_ptr_test::FowardDeclaration::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', std_memory_shared_ptr_test::Basic::GetInstance() );
		ret->AddItem( 'w', std_memory_shared_ptr_test::MakeShared_And_Memory::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<STDMenu>( 27 );
	}

	return ret;
}