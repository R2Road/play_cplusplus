#include "MemoryPoolMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "test_hobby/item/memory_pool_test.h"

#include "HobbyMenu.h"

r2cm::MenuUp MemoryPoolMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle() ) );

	{
		ret->AddItem( '1', memory_pool_test::MemoryBlock_Declaration::GetInstance() );
		ret->AddItem( '2', memory_pool_test::MemoryBlock_New_FundamentalType::GetInstance() );
		ret->AddItem( '3', memory_pool_test::MemoryBlock_New_UserDefinedType::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( 'q', memory_pool_test::MemoryPool_Declaration::GetInstance() );
		ret->AddItem( 'w', memory_pool_test::MemoryPool_New::GetInstance() );


		ret->AddSplit();


		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}