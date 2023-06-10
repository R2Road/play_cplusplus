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
			std::cout << r2tm::split;

			OUTPUT_NOTE( "Tree �� Ư¡" );
			OUTPUT_COMMENT( "�׷����� ����" );
			OUTPUT_COMMENT( "��ȯ���� �ʴ� �׷���" );
			OUTPUT_COMMENT( "������ ������ N �϶� ���ἱ�� N - 1 ��" );

			std::cout << r2tm::split;

			{
				std::cout << "�� ���� �����߰ڴµ�... ���� ����... �յڰ� �߸��� �����̾�." << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}