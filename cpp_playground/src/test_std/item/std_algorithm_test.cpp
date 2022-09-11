#include "std_algorithm_test.h"

#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#include "r2cm/r2cm_ostream.h"

namespace std_algorithm_test
{
	r2cm::iItem::TitleFunctionT Shuffle::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Algorithm : Shuffle";
		};
	}
	r2cm::iItem::DoFunctionT Shuffle::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::vector<int> container_1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::vector<int> container_1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ View" << r2cm::linefeed2;
				std::cout << r2cm::tab2;
				for( const auto i : container_1 )
				{
					std::cout << i << "  ";
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const auto seed = static_cast<unsigned int>( std::chrono::system_clock::now().time_since_epoch().count() );
				std::default_random_engine random_engine( seed );
				std::shuffle( container_1.begin(), container_1.end(), random_engine );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "const auto seed = static_cast<unsigned int>( std::chrono::system_clock::now().time_since_epoch().count() );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::default_random_engine random_engine( seed );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::shuffle( container_1.begin(), container_1.end(), random_engine );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ View" << r2cm::linefeed2;
				std::cout << r2cm::tab2;
				for( const auto i : container_1 )
				{
					std::cout << i << "  ";
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}