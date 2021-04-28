#include "pch.h"
#include "new_test.h"

#include <new>

#include "r2_eTestResult.h"

namespace new_test
{
	const r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "New : Basic";
		};
	}
	const r2::iTest::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			{
				int* i = new int( 1 );

				std::cout << "\t" << "+ int* i = new int( 1 );" <<  r2::linefeed;
				std::cout << "\t\t" << "- " << *i << r2::linefeed;

				delete i;
				std::cout << "\t" << "+ delete i;" << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				int* i = new ( std::nothrow ) int( 2 );

				std::cout << "\t" << "+ int* i = new ( std::nothrow ) int( 2 );" << r2::linefeed;
				std::cout << "\t\t" << "- " << *i << r2::linefeed;

				delete i;
				std::cout << "\t" << "+ delete i;" << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				char* str = new char[7];

				std::cout << "\t" << "+ char* str = new char[7];" << r2::linefeed;
				std::cout << "\t\t" << "- " << str << r2::linefeed;

				delete[] str;
				std::cout << "\t" << "+ delete[] str;" << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iTest::TitleFunc PlacementNew::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Placement New : Basic";
		};
	}
	const r2::iTest::DoFunc PlacementNew::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			{
				int i = 123;
				float* fp = new (&i) float;

				std::cout << "\t" << "+ int i = 123;" << r2::linefeed;
				std::cout << "\t" << "+ float* fp = new (&i) float;" << r2::linefeed;
				std::cout << "\t\t" << "- Print fp : " << *fp << r2::linefeed;

				std::cout << r2::linefeed;

				*fp = 3.14;
				std::cout << "\t" << "+ *fp = 3.14;" << r2::linefeed;
				std::cout << "\t\t" << "- Print fp : " << *fp << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				int i = 65;
				std::cout << "\t" << "+ int i = 65;" << r2::linefeed;
				std::cout << "\t\t" << "- Print i : " << i << r2::linefeed;

				std::cout << r2::linefeed;

				char* cp = new ( &i ) char;
				std::cout << "\t" << "+ char* cp = new ( &i ) char;" << r2::linefeed;
				std::cout << "\t\t" << "- Print cp : " << *cp << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}