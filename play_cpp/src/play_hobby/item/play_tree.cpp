#include "play_tree.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace play_tree
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Tree : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "Tree �� Ư¡" );
			OUTPUT_COMMENT( "�׷����� ����" );
			OUTPUT_COMMENT( "��ȯ���� �ʴ� �׷���" );
			OUTPUT_COMMENT( "������ ������ N �϶� ���ἱ�� N - 1 ��" );

			std::cout << r2cm::split;

			{
				std::cout << "�� ���� �����߰ڴµ�... ���� ����... �յڰ� �߸��� �����̾�." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}