#include "MemoryPoolMenu.h"

#include "r2tm/r2tm_Director.h"

#include "item/play_memory_pool.h"

#include "HobbyMenu.h"

r2tm::TitleFunctionT MemoryPoolMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Memory Pool Menu ( Researching... )";
	};
}
r2tm::DescriptionFunctionT MemoryPoolMenu::GetDescriptionFunction() const
{
	return []()->const char* { return
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
		;
	};
}
r2tm::WriteFunctionT MemoryPoolMenu::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', play_memory_pool::MemoryBlock_Declaration() );
		ret->AddItem( '2', play_memory_pool::MemoryBlock_New_FundamentalType() );
		ret->AddItem( '3', play_memory_pool::MemoryBlock_Check_FundamentalType() );
		ret->AddItem( '4', play_memory_pool::MemoryBlock_New_UserDefinedType() );


		ret->AddLineFeed();


		ret->AddItem( 'q', play_memory_pool::MemoryPool_Declaration() );
		ret->AddItem( 'w', play_memory_pool::MemoryPool_New() );


		ret->AddSplit();


		ret->AddMenu( 27, HobbyMenu() );
	};
}