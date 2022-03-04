#include "pch.h"
#include "std_algorithm_test.h"

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "base/r2_eTestEndAction.h"

namespace std_algorithm_test
{
	r2cm::iItem::TitleFuncT Shuffle::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Algorithm : Shuffle";
		};
	}
	r2cm::iItem::DoFuncT Shuffle::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::vector<int> container_1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::vector<int> container_1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ View" << r2::linefeed2;
				std::cout << r2::tab2;
				for( const auto i : container_1 )
				{
					std::cout << i << "  ";
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				const auto seed = static_cast<unsigned int>( std::chrono::system_clock::now().time_since_epoch().count() );
				std::default_random_engine random_engine( seed );
				std::shuffle( container_1.begin(), container_1.end(), random_engine );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "const auto seed = static_cast<unsigned int>( std::chrono::system_clock::now().time_since_epoch().count() );" << r2::linefeed;
				std::cout << r2::tab2 << "std::default_random_engine random_engine( seed );" << r2::linefeed;
				std::cout << r2::tab2 << "std::shuffle( container_1.begin(), container_1.end(), random_engine );" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ View" << r2::linefeed2;
				std::cout << r2::tab2;
				for( const auto i : container_1 )
				{
					std::cout << i << "  ";
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}