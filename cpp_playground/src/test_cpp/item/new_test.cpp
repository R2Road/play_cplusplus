#include "new_test.h"

#include <new>

#include "r2cm/r2cm_constant.h"

namespace new_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int* i = new int( 1 );

				std::cout << r2cm::tab << "+ int* i = new int( 1 );" <<  r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << *i << r2cm::linefeed;

				delete i;
				std::cout << r2cm::tab << "+ delete i;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int* i = new ( std::nothrow ) int( 2 );

				std::cout << r2cm::tab << "+ int* i = new ( std::nothrow ) int( 2 );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << *i << r2cm::linefeed;

				delete i;
				std::cout << r2cm::tab << "+ delete i;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int* i = new int[10];

				std::cout << r2cm::tab << "+ int* i = new int[10];" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << *i << r2cm::linefeed;

				delete[] i;
				std::cout << r2cm::tab << "+ delete[] i;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int* i = new int[10]{ 1, 2, 3 };

				std::cout << r2cm::tab << "+ int* i = new int[10]{ 1, 2, 3 };" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << *i << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- [3] : " << i[3] << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- [4] : " << i[4] << r2cm::linefeed;

				delete[] i;
				std::cout << r2cm::tab << "+ delete[] i;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				char* str = new char[7];

				std::cout << r2cm::tab << "+ char* str = new char[7];" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << str << r2cm::linefeed;

				delete[] str;
				std::cout << r2cm::tab << "+ delete[] str;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				char* str = new char[7]{ "abc" };

				std::cout << r2cm::tab << "+ char* str = new char[7]{ \"abc\" };" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << str << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- [3] : " << str[3] << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- [4] : " << str[4] << r2cm::linefeed;

				delete[] str;
				std::cout << r2cm::tab << "+ delete[] str;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PlacementNew::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Placement New";
		};
	}
	r2cm::iItem::DoFuncT PlacementNew::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int i = 123;
				float* fp = new (&i) float;

				std::cout << r2cm::tab << "+ int i = 123;" << r2cm::linefeed;
				std::cout << r2cm::tab << "+ float* fp = new (&i) float;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print fp : " << *fp << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				*fp = 3.14f;
				std::cout << r2cm::tab << "+ *fp = 3.14f;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print fp : " << *fp << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int i = 65;
				std::cout << r2cm::tab << "+ int i = 65;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print i : " << i << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				char* cp = new ( &i ) char;
				std::cout << r2cm::tab << "+ char* cp = new ( &i ) char;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print cp : " << *cp << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}