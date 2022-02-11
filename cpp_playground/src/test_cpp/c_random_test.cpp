#include "pch.h"
#include "c_random_test.h"

#include <cstdlib> // rand, srand

#include "base/r2_eTestResult.h"


namespace c_random_test
{
	r2::iTest::TitleFunc Rand::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C Rand : Basic";
		};
	}
	r2::iTest::DoFunc Rand::GetDoFunction()
	{
		return []()->r2::eTestEndAction
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
				std::cout << r2::tab << "# Message : 프로그램 새로 기동해도 rand() 가 반환하는 값과 순서는 같다." << r2::linefeed;
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

			return r2::eTestEndAction::Pause;
		};
	}
}