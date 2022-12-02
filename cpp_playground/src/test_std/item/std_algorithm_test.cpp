#include "std_algorithm_test.h"

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_algorithm_test
{
	std::ostream& operator<<( std::ostream& o, std::vector<int>& container )
	{
		for( const auto& i : container )
		{
			o << i << " ";
		}
		return o;
	}
	r2cm::iItem::TitleFunctionT Shuffle::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "<algorithm> : std::shuffle";
		};
	}
	r2cm::iItem::DoFunctionT Shuffle::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container( { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "- container : " << container << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const auto seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count() );
				DECLARATION_MAIN( std::default_random_engine random_engine( seed ) );
				PROCESS_MAIN( std::shuffle( container.begin(), container.end(), random_engine ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- container : " << container << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}