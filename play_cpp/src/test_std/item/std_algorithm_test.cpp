#include "std_algorithm_test.h"

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

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
	r2tm::TitleFunctionT Shuffle::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "<algorithm> : std::shuffle";
		};
	}
	r2tm::DoFunctionT Shuffle::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<int> container( { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } ) );

			LS();

			{
				std::cout << r2tm::tab << "- container : " << container << r2tm::linefeed;

				LF();

				DECLARATION_MAIN( const auto seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count() );
				DECLARATION_MAIN( std::default_random_engine random_engine( seed ) );
				PROCESS_MAIN( std::shuffle( container.begin(), container.end(), random_engine ) );

				LF();

				std::cout << r2tm::tab << "- container : " << container << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}