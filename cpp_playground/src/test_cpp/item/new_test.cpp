#include "new_test.h"

#include <new>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace new_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int* i = new int( 1 ) );
				OUTPUT_VALUE( *i );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int* i = new ( std::nothrow ) int( 2 ) );
				OUTPUT_VALUE( *i );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete i );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Array::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array";
		};
	}
	r2cm::iItem::DoFunctionT Array::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int* i = new int[10] );
				OUTPUT_VALUE( *i );
				OUTPUT_VALUE( i[1] );
				OUTPUT_VALUE( i[2] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] i );
			}

			std::cout << r2cm::split;

			{
				int* i = new int[10]{ 1, 2, 3 };

				std::cout << "int* i = new int[10]{ 1, 2, 3 };" << r2cm::linefeed;
				OUTPUT_VALUE( *i );
				OUTPUT_VALUE( i[1] );
				OUTPUT_VALUE( i[2] );
				OUTPUT_VALUE( i[3] );
				OUTPUT_VALUE( i[4] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char* str = new char[7] );
				OUTPUT_VALUE( str );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] str );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char* str = new char[7]{ "abc" } );
				OUTPUT_VALUE( str );
				OUTPUT_VALUE( str[3] );
				OUTPUT_VALUE( str[4] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( delete[] str );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PlacementNew::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Placement New";
		};
	}
	r2cm::iItem::DoFunctionT PlacementNew::GetDoFunction()
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