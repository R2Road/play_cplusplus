#include "MemoryPoolMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/play_memory_pool.h"

#include "HobbyMenu.h"

r2cm::MenuUp MemoryPoolMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu( director, GetTitle(),
				"memory pool 은 크게..."
		"\n"
		"\n"	"1. 주 메모리 할당, 해제"
		"\n"	"2. 요청받은 메모리의 할당"
		"\n"	"3. 반환받은 메모리의 재사용"
		"\n"
		"\n"	"...으로 나눠 볼 수 있다."
		"\n"
		"\n"	"현 시점에서 MemoryBlack 개체를 사용해 할당, 해제, 요청 처리는 가능하지만 재사용에 대한 계획이 없다."
		"\n"	"재사용과 관련한 자료들을 찾아 보고, 약간의 연구를 거쳐 설계 및 작업을 재 진행 하려 한다."
		"\n"
		"\n"	"2022.07.20 by R"
	) );

	{
		ret->AddItem( '1', play_memory_pool::MemoryBlock_Declaration() );
		ret->AddItem( '2', play_memory_pool::MemoryBlock_New_FundamentalType() );
		ret->AddItem( '3', play_memory_pool::MemoryBlock_Check_FundamentalType() );
		ret->AddItem( '4', play_memory_pool::MemoryBlock_New_UserDefinedType() );


		ret->AddLineFeed();


		ret->AddItem( 'q', play_memory_pool::MemoryPool_Declaration() );
		ret->AddItem( 'w', play_memory_pool::MemoryPool_New() );


		ret->AddSplit();


		ret->AddMenu<HobbyMenu>( 27 );
	}

	return ret;
}