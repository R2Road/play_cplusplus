#include "play_tree.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace play_tree
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Tree : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "Tree 의 특징" );
			OUTPUT_COMMENT( "그래프의 일종" );
			OUTPUT_COMMENT( "순환하지 않는 그래프" );
			OUTPUT_COMMENT( "정점의 개수가 N 일때 연결선이 N - 1 개" );

			LS();

			{
				std::cout << "뷰어를 먼저 만들어야겠는데... 뭐지 뭔가... 앞뒤가 잘못된 느낌이야." << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}