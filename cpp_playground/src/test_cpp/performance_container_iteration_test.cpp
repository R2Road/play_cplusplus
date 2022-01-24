#include "pch.h"
#include "performance_container_iteration_test.h"

#include <array>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "base/r2_eTestResult.h"

#include "util/r2util_StopWatch.h"

namespace performance_container_iteration_test
{
	r2::iTest::TitleFunc BuiltInArrayIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Built-In Array Iteration";
		};
	}
	r2::iTest::DoFunc BuiltInArrayIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			int test_container[100000];
			std::fill_n( test_container, sizeof( test_container ) / sizeof( test_container[0] ), 1 );

			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "int test_container[100000];" << r2::linefeed;
			std::cout << r2::tab2 << "std::fill_n( test_container, sizeof( test_container ) / sizeof( test_container[0] ), 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For with Index" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0u, end = sizeof( test_container ) / sizeof( test_container[0] ); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc STDArrayIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Array Iteration";
		};
	}
	r2::iTest::DoFunc STDArrayIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::array<int, 100000> test_container;
			test_container.fill( 1 );
			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::array<int, 100000> test_container;" << r2::linefeed;
			std::cout << r2::tab2 << "test_container.fill( 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For with Index" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0u, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc VectorIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector Iteration";
		};
	}
	r2::iTest::DoFunc VectorIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::vector<int> test_container( 100000, 1 );
			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::vector<int> test_container( 100000, 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For with Index" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc ListIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List Iteration";
		};
	}
	r2::iTest::DoFunc ListIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::list<int> test_container( 100000, 1 );
			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::list<int> test_container( 100000, 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc MapIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Map Iteration";
		};
	}
	r2::iTest::DoFunc MapIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::map<std::size_t, int> test_container;
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n, 1 );

			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::map<std::size_t, int> test_container;" << r2::linefeed;
			std::cout << r2::tab2 << "for( int n = 0; n > 100000; ++n ) test_container.emplace( n, 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For with Index" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur.second;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( cur->second );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc UnorderedMapIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unordered-Map Iteration";
		};
	}
	r2::iTest::DoFunc UnorderedMapIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::unordered_map<std::size_t, int> test_container( 100000 );
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n, 1 );

			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::unordered_map<std::size_t, int> test_container( 100000 );" << r2::linefeed;
			std::cout << r2::tab2 << "for( int n = 0; n > 100000; ++n ) test_container.emplace( n, 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For with Index" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += test_container[cur];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur.second;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( cur->second );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc SetIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Set Iteration";
		};
	}
	r2::iTest::DoFunc SetIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::set<int> test_container;
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );

			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::set<int> test_container;" << r2::linefeed;
			std::cout << r2::tab2 << "for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc UnorderedSetIteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unordered-Set Iteration";
		};
	}
	r2::iTest::DoFunc UnorderedSetIteration::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::unordered_set<int> test_container( 100000 );
			for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );

			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::map<int, int> test_container;" << r2::linefeed;
			std::cout << r2::tab2 << "for( int n = 0; 100000 > n; ++n ) test_container.emplace( n );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += cur;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc STDArrayIteration_WithPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "STD Array Iteration With Pointer";
		};
	}
	r2::iTest::DoFunc STDArrayIteration_WithPointer::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::array<int*, 100000> test_container;
			for( auto& i : test_container ) i = new int( 1 );

			unsigned int sum_result = 0;
			r2util::StopWatch stop_watch;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "std::array<int, 100000> test_container;" << r2::linefeed;
			std::cout << r2::tab2 << "for( auto& i : test_container ) i = new int( 1 );" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For with Index" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( std::size_t cur = 0u, end = test_container.size(); end > cur; ++cur )
					{
						sum_result += ( *( test_container[cur] ) );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Range-Based For" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( const auto& cur : test_container )
					{
						sum_result += ( *cur );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Iterator" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *( *cur ) );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << "sum_result : " << sum_result;
					std::cout << r2::linefeed;
				}
			}

			for( auto& i : test_container ) delete i;

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}