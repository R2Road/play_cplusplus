#include "performance_container_iteration_test.h"

#include <array>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "r2cm/r2cm_ostream.h"

#include "r2cm/r2cm_StopWatch.h"

namespace performance_container_iteration_test
{
	r2cm::iItem::TitleFunctionT BuiltInArrayIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Built-In Array Iteration";
		};
	}
	r2cm::iItem::DoFunctionT BuiltInArrayIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			int test_container[100000];
			std::fill_n( test_container, sizeof( test_container ) / sizeof( test_container[0] ), 1 );

			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "int test_container[100000];" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "std::fill_n( test_container, sizeof( test_container ) / sizeof( test_container[0] ), 1 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ For with Index" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0u, end = sizeof( test_container ) / sizeof( test_container[0] ); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT STDArrayIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Array Iteration";
		};
	}
	r2cm::iItem::DoFunctionT STDArrayIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::array<int, 100000> test_container;
			test_container.fill( 1 );
			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::array<int, 100000> test_container;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "test_container.fill( 1 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ For with Index" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0u, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT VectorIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector Iteration";
		};
	}
	r2cm::iItem::DoFunctionT VectorIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::vector<int> test_container( 100000, 1 );
			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::vector<int> test_container( 100000, 1 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ For with Index" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ListIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List Iteration";
		};
	}
	r2cm::iItem::DoFunctionT ListIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::list<int> test_container( 100000, 1 );
			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::list<int> test_container( 100000, 1 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MapIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Map Iteration";
		};
	}
	r2cm::iItem::DoFunctionT MapIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::map<std::size_t, int> test_container;
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n, 1 );

			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::map<std::size_t, int> test_container;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "for( int n = 0; n > 100000; ++n ) test_container.emplace( n, 1 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ For with Index" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur.second;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( cur->second );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT UnorderedMapIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unordered-Map Iteration";
		};
	}
	r2cm::iItem::DoFunctionT UnorderedMapIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::unordered_map<std::size_t, int> test_container( 100000 );
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n, 1 );

			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::unordered_map<std::size_t, int> test_container( 100000 );" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "for( int n = 0; n > 100000; ++n ) test_container.emplace( n, 1 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ For with Index" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur.second;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( cur->second );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT SetIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Set Iteration";
		};
	}
	r2cm::iItem::DoFunctionT SetIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::set<int> test_container;
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );

			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::set<int> test_container;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT UnorderedSetIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unordered-Set Iteration";
		};
	}
	r2cm::iItem::DoFunctionT UnorderedSetIteration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::unordered_set<int> test_container( 100000 );
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );

			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::map<int, int> test_container;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT STDArrayIteration_WithPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Array Iteration With Pointer";
		};
	}
	r2cm::iItem::DoFunctionT STDArrayIteration_WithPointer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::array<int*, 100000> test_container;
			for( auto& i : test_container ) i = new int( 1 );

			unsigned int sum_result = 0;
			r2cm::StopWatch stop_watch;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "std::array<int, 100000> test_container;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "for( auto& i : test_container ) i = new int( 1 );" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ For with Index" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0u, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += ( *( test_container[cur] ) );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Range-Based For" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Iterator" << r2cm::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *( *cur ) );
					}
					stop_watch.Stop();

					std::cout << r2cm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2cm::tab2 << "sum_result : " << sum_result;
					std::cout << r2cm::linefeed;
				}
			}

			for( auto& i : test_container ) delete i;

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}