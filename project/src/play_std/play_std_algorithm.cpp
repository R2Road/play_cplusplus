#include "play_std_algorithm.hpp"

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_std_algorithm
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

			DECL_MAIN( std::vector<int> container( { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } ) );

			LF();

			OUT_VALUE( container );

			LS();

			{
				DECL_SUB( const auto seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count() );
				DECL_SUB( std::default_random_engine random_engine( seed ) );

				LF();

				PROC_MAIN( std::shuffle( container.begin(), container.end(), random_engine ) );

				LF();

				OUT_VALUE( container );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}