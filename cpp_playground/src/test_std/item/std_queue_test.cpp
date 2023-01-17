#include "std_queue_test.h"

#include <queue>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace std_queue_test
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::queue<int> q );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "r-value Move Constructor" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}