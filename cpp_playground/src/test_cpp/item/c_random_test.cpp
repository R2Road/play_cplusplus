#include "pch.h"
#include "c_random_test.h"

#include <cstdlib> // rand, srand

#include "r2cm/r2cm_eTestEndAction.h"


namespace c_random_test
{
	r2cm::iItem::TitleFuncT Rand::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Rand : Basic";
		};
	}
	r2cm::iItem::DoFuncT Rand::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2::tab2 << "rand() : " << rand() << r2::linefeed;
				}

				std::cout << r2::linefeed;
				std::cout << r2::tab << "# Message : Same Value Printed When Every Single Execute" << r2::linefeed;
				std::cout << r2::tab << "# Message : ���α׷� ���� �⵿�ص� rand() �� ��ȯ�ϴ� ���� ������ ����." << r2::linefeed;
			}

			std::cout << r2::split;

			{
				srand( 1 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "srand( 1 );" << r2::linefeed2;

				for( int i = 0; 10 > i; ++i )
				{
					std::cout << r2::tab2 << "rand() : " << rand() << r2::linefeed;
				}

				std::cout << r2::linefeed;
				std::cout << r2::tab << "# Message : srand( 1 ) is Default" << r2::linefeed;
				std::cout << r2::tab << "# Message : srand( n ) is init rand() Sequence" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}