#include "MemoryPoolMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/memory_pool_test.h"

#include "HobbyMenu.h"

r2cm::MenuUp MemoryPoolMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle(),
				"memory pool �� ũ��..."
		"\n"
		"\n"	"1. �� �޸� �Ҵ�, ����"
		"\n"	"2. ��û���� �޸��� �Ҵ�"
		"\n"	"3. ��ȯ���� �޸��� ����"
		"\n"
		"\n"	"...���� ���� �� �� �ִ�."
		"\n"
		"\n"	"�� �������� MemoryBlack ��ü�� ����� �Ҵ�, ����, ��û ó���� ���������� ���뿡 ���� ��ȹ�� ����."
		"\n"	"����� ������ �ڷ���� ã�� ����, �ణ�� ������ ���� ���� �� �۾��� �� ���� �Ϸ� �Ѵ�."
		"\n"
		"\n"	"2022.07.20 by R"
	) );

	{
		ret->AddItem( '1', memory_pool_test::MemoryBlock_Declaration() );
		ret->AddItem( '2', memory_pool_test::MemoryBlock_New_FundamentalType() );
		ret->AddItem( '3', memory_pool_test::MemoryBlock_Check_FundamentalType() );
		ret->AddItem( '4', memory_pool_test::MemoryBlock_New_UserDefinedType() );


		ret->AddLineFeed();


		ret->AddItem( 'q', memory_pool_test::MemoryPool_Declaration() );
		ret->AddItem( 'w', memory_pool_test::MemoryPool_New() );


		ret->AddSplit();


		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}