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

			OUTPUT_NOTE( "Tree �� Ư¡" );
			OUTPUT_COMMENT( "�׷����� ����" );
			OUTPUT_COMMENT( "��ȯ���� �ʴ� �׷���" );
			OUTPUT_COMMENT( "������ ������ N �϶� ���ἱ�� N - 1 ��" );

			LS();

			{
				std::cout << "�� ���� �����߰ڴµ�... ���� ����... �յڰ� �߸��� �����̾�." << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}