#include "pch.h"
#include "performance_1_test.h"

#include <array>
#include <memory>
#include <numeric>

#include "base/r2_eTestEndAction.h"

#include "utility/r2utility_StopWatch.h"

namespace performance_1_test
{
	r2cm::iItem::TitleFuncT IncrementOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "++Operator";
		};
	}
	r2cm::iItem::DoFuncT IncrementOperator::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;

			const int attempt_limit = std::numeric_limits<int>::max() / 1000;
			const int loop_limit = 4;
			r2utility::StopWatch stop_watch;

			{
				std::cout << r2::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2::tab2 << "Loop Limit : " << loop_limit << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : Int : ++" << r2::linefeed2;

				int test_int = 0;			

				for( int i = 0; loop_limit > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					while( attempt_limit > test_int )
					{
						++test_int;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : Int* : ++" << r2::linefeed2;

				int test_int = 0;
				int* test_pointer = &test_int;

				for( int i = 0; loop_limit > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					while( attempt_limit > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : new Int* : ++" << r2::linefeed2;

				std::unique_ptr<int> test_unique_pointer( new int( 0 ) );
				int* test_pointer = test_unique_pointer.get();

				for( int i = 0; loop_limit > i; ++i )
				{
					*test_pointer = 0;

					stop_watch.Start();
					while( attempt_limit > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : Int Up : ++" << r2::linefeed2;

				std::unique_ptr<int> test_pointer( new int( 0 ) );

				for( int i = 0; loop_limit > i; ++i )
				{
					*test_pointer = 0;

					stop_watch.Start();
					while( attempt_limit > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : Int Sp : ++" << attempt_limit << r2::linefeed2;

				std::shared_ptr<int> test_pointer( new int( 0 ) );

				for( int i = 0; loop_limit > i; ++i )
				{
					*test_pointer = 0;

					stop_watch.Start();
					while( attempt_limit > *test_pointer )
					{
						++( *test_pointer );
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << *test_pointer;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Loop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop";
		};
	}
	r2cm::iItem::DoFuncT Loop::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;

			const int attempt_limit = std::numeric_limits<int>::max() / 10;
			const int loop_limit = 5;
			r2utility::StopWatch stop_watch;

			{
				std::cout << r2::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2::tab2 << "Loop Limit : " << loop_limit << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : unsigned int : ++" << r2::linefeed2;

				unsigned int test_int = 0;

				for( int i = 0; loop_limit > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					for( ; attempt_limit > test_int; )
					{
						++test_int;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ While : unsigned int : ++" << r2::linefeed2;

				unsigned int test_int = 0;

				for( int i = 0; loop_limit > i; ++i )
				{
					test_int = 0;

					stop_watch.Start();
					while( attempt_limit > test_int )
					{
						++test_int;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << test_int;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT LoopWithBuildInArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop With Built-In Array";
		};
	}
	r2cm::iItem::DoFuncT LoopWithBuildInArray::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			const unsigned int attempt_limit = 100000;
			const int loop_limit = 5;
			r2utility::StopWatch stop_watch;

			{
				std::cout << r2::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2::tab2 << "Loop Limit : " << loop_limit << r2::linefeed;
			}

			std::cout << r2::split;

			int test_container[attempt_limit];
			std::fill_n( test_container, attempt_limit, 1 );

			unsigned int sum_result = 0;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "int test_container[attempt_limit];" << r2::linefeed;
				std::cout << r2::tab2 << "std::fill_n( test_container, attempt_limit, 1 );" << r2::linefeed2;
				std::cout << r2::tab2 << "unsigned int sum_result = 0;" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : sum all" << r2::linefeed2;

				for( int loop_count = 0; loop_limit > loop_count; ++loop_count )
				{
					sum_result = 0;

					stop_watch.Start();
					for( unsigned int a = 0; attempt_limit > a; ++a )
					{
						sum_result += test_container[a];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ While : sum all" << r2::linefeed2;

				for( int loop_count = 0; loop_limit > loop_count; ++loop_count )
				{
					sum_result = 0;

					stop_watch.Start();
					unsigned int a = 0;
					while( attempt_limit > a )
					{
						sum_result += test_container[a];

						++a;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT LoopWithSTDArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop With std::array";
		};
	}
	r2cm::iItem::DoFuncT LoopWithSTDArray::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			const unsigned int attempt_limit = 100000;
			const int loop_limit = 5;
			r2utility::StopWatch stop_watch;

			{
				std::cout << r2::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2::tab2 << "Loop Limit : " << loop_limit << r2::linefeed;
			}

			std::cout << r2::split;

			std::array<int, attempt_limit> test_container;
			test_container.fill( 1 );

			unsigned int sum_result = 0;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::array<int, attempt_limit> test_container;" << r2::linefeed;
				std::cout << r2::tab2 << "test_container.fill( 1 );" << r2::linefeed2;
				std::cout << r2::tab2 << "unsigned int sum_result = 0;" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For : sum all" << r2::linefeed2;

				for( int loop_count = 0; loop_limit > loop_count; ++loop_count )
				{
					sum_result = 0;

					stop_watch.Start();
					for( unsigned int a = 0; attempt_limit > a; ++a )
					{
						sum_result += test_container[a];
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ While : sum all" << r2::linefeed2;

				for( int loop_count = 0; loop_limit > loop_count; ++loop_count )
				{
					sum_result = 0;

					stop_watch.Start();
					unsigned int a = 0;
					while( attempt_limit > a )
					{
						sum_result += test_container[a];

						++a;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT CompareIteratorOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Iterator Operator";
		};
	}
	r2cm::iItem::DoFuncT CompareIteratorOperator::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			const unsigned int attempt_count = 100000;

			struct TestStruct
			{
				int i = 1;
			};
			std::array<TestStruct, attempt_count> test_container;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "const unsigned int attempt_count = 100000;" << r2::linefeed;
				std::cout << r2::tab2 << "struct TestStruct" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "int i = 1;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed2;
				std::cout << r2::tab2 << "std::array<TestStruct, attempt_count> test_container;" << r2::linefeed;
			}

			unsigned int sum_result = 0;
			r2utility::StopWatch stop_watch;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For And Iterator Operator->" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += cur->i;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ For And Iterator Operator*" << r2::linefeed2;

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur ).i;
					}
					stop_watch.Stop();

					std::cout << r2::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2::tab2 << sum_result;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}