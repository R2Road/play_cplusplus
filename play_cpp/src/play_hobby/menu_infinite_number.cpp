#include "menu_infinite_number.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_infinite_number.hpp"

#include "menu_hobby.hpp"

r2tm::TitleFunctionT Menu_InfiniteNumber::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Infinite Number";
	};
}
r2tm::DescriptionFunctionT Menu_InfiniteNumber::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_InfiniteNumber::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "숫자 조각을 만들고 이어 붙여서 큰 숫자를 구현 한다.", r2tm::eColor::FG_LightGreen );
		mp->AddMessage( "생각해본 숫자 조각 구현 방식은 2가지가 있다.", r2tm::eColor::FG_LightGreen );
		mp->AddMessage( "    "  "1. 정석", r2tm::eColor::FG_LightYellow);
		mp->AddMessage( "    "  "    > "  "온전한 바이너리 연산 지원 : +, -, x 필요.", r2tm::eColor::FG_LightYellow );
		mp->AddMessage( "    "  "    > "  "출력 기능 지원", r2tm::eColor::FG_LightYellow );
		mp->AddMessage( "    "  "2. 꼼수", r2tm::eColor::FG_LightYellow );
		mp->AddMessage( "    "  "    > "  "+ 연산으로 오버플로우가 없을 범위에서 10진수 숫자 조각을 만들어서 사용", r2tm::eColor::FG_LightYellow );
		mp->AddMessage( "    "  "    > "  "999 단위로 만든다면 출력 할 때 편하다.", r2tm::eColor::FG_LightYellow );

		mp->AddLineFeed();

		mp->AddMessage( "일단 2번으로 진행", r2tm::eColor::FG_LightGreen );



		mp->AddLineFeed();



		mp->AddItem( '1', play_infinite_number::Declaration() );
		mp->AddItem( '2', play_infinite_number::Operator_Plus() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Hobby() );
	};
}