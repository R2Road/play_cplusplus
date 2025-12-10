#include "play_performance_1.hpp"

#include <array>
#include <memory>
#include <numeric>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

#include "r2tm/r2tm_stop_watch.hpp"

namespace play_performance_1
{
	r2tm::TitleFunctionT IncrementOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "++Operator";
		};
	}
	r2tm::DoFunctionT IncrementOperator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			const int attempt_limit = std::numeric_limits<int>::max() / 1000;
			const int loop_limit = 4;
			r2tm::StopWatch stop_watch;

			{
				std::cout << r2tm::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2tm::tab2 << "Loop Limit : " << loop_limit << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : Int : ++" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << test_int;
					LF();
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : Int* : ++" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << *test_pointer;
					LF();
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : new Int* : ++" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << *test_pointer;
					LF();
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : Int Up : ++" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << *test_pointer;
					LF();
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : Int Sp : ++" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << *test_pointer;
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Loop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop";
		};
	}
	r2tm::DoFunctionT Loop::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			const int attempt_limit = std::numeric_limits<int>::max() / 10;
			const int loop_limit = 5;
			r2tm::StopWatch stop_watch;

			{
				std::cout << r2tm::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2tm::tab2 << "Loop Limit : " << loop_limit << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : unsigned int : ++" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << test_int;
					LF();
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ While : unsigned int : ++" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << test_int;
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT LoopWithBuildInArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop With Built-In Array";
		};
	}
	r2tm::DoFunctionT LoopWithBuildInArray::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			const unsigned int attempt_limit = 100000;
			const int loop_limit = 5;
			r2tm::StopWatch stop_watch;

			{
				std::cout << r2tm::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2tm::tab2 << "Loop Limit : " << loop_limit << r2tm::linefeed;
			}

			LS();

			int test_container[attempt_limit];
			std::fill_n( test_container, attempt_limit, 1 );

			unsigned int sum_result = 0;

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "int test_container[attempt_limit];" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "std::fill_n( test_container, attempt_limit, 1 );" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "unsigned int sum_result = 0;" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : sum all" << r2tm::linefeed2;

				for( int loop_count = 0; loop_limit > loop_count; ++loop_count )
				{
					sum_result = 0;

					stop_watch.Start();
					for( unsigned int a = 0; attempt_limit > a; ++a )
					{
						sum_result += test_container[a];
					}
					stop_watch.Stop();

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << sum_result;
					LF();
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ While : sum all" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << sum_result;
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT LoopWithSTDArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Loop With std::array";
		};
	}
	r2tm::DoFunctionT LoopWithSTDArray::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			const unsigned int attempt_limit = 100000;
			const int loop_limit = 5;
			r2tm::StopWatch stop_watch;

			{
				std::cout << r2tm::tab << "Attempt Limit : " << attempt_limit;
				std::cout << r2tm::tab2 << "Loop Limit : " << loop_limit << r2tm::linefeed;
			}

			LS();

			std::array<int, attempt_limit> test_container;
			test_container.fill( 1 );

			unsigned int sum_result = 0;

			{
				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::array<int, attempt_limit> test_container;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "test_container.fill( 1 );" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "unsigned int sum_result = 0;" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ For : sum all" << r2tm::linefeed2;

				for( int loop_count = 0; loop_limit > loop_count; ++loop_count )
				{
					sum_result = 0;

					stop_watch.Start();
					for( unsigned int a = 0; attempt_limit > a; ++a )
					{
						sum_result += test_container[a];
					}
					stop_watch.Stop();

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << sum_result;
					LF();
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ While : sum all" << r2tm::linefeed2;

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

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << sum_result;
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CompareIteratorOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Iterator Operator";
		};
	}
	r2tm::DoFunctionT CompareIteratorOperator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SOURCE_READY_N_BEGIN;
			const unsigned int attempt_count = 100000;

			struct TestStruct
			{
				int i = 1;
			};
			std::array<TestStruct, attempt_count> test_container;
			OUT_SOURCE_END;

			unsigned int sum_result = 0;
			r2tm::StopWatch stop_watch;

			LS();

			{
				OUT_SUBJECT( "For And Iterator Operator->" );

				LF();

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += cur->i;
					}
					stop_watch.Stop();

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << sum_result;
					LF();
				}
			}

			LS();

			{
				OUT_SUBJECT( "For And Iterator Operator*" );

				LF();

				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					sum_result = 0;

					stop_watch.Start();
					for( auto cur = test_container.begin(), end = test_container.end(); end != cur; ++cur )
					{
						sum_result += ( *cur ).i;
					}
					stop_watch.Stop();

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					std::cout << r2tm::tab2 << sum_result;
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT StructMemberAccess::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct Member Access";
		};
	}
	r2tm::DoFunctionT StructMemberAccess::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "struct 멤버에 데이터를 쓸 때" );
			OUT_SUBJECT( "각 멤버에 개별 접근해서 데이터를 쓰는 것과" );
			OUT_SUBJECT( "= { ... } 구문을 통해 통짜로 쓸때의 성능 차이를 확인해보자." );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			const unsigned int attempt_count = 100000;

			struct TestStruct
			{
				int i = 0;
				int j = 0;
			};
			TestStruct test_container[attempt_count];
			OUT_SOURCE_END;

			int temp_1 = 0;
			int temp_2 = 0;
			TestStruct temp_struct;
			r2tm::StopWatch stop_watch;

			LS();

			{
				OUT_SUBJECT( "개별 쓰기 | .i =, .j =" );

				LF();

				stop_watch.Reset();
				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					temp_1 = 0;
					temp_2 = 0;

					stop_watch.Start();
					for( auto& cur : test_container )
					{
						cur.i = temp_1;
						cur.j = temp_2;

						++temp_1;
						++temp_2;
					}
					stop_watch.Stop();

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					LF();
				}
			}

			LS();

			{
				OUT_SUBJECT( "통짜 쓰기 | = {}" );

				LF();

				stop_watch.Reset();
				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					temp_1 = 0;
					temp_2 = 0;

					stop_watch.Start();
					for( auto& cur : test_container )
					{
						cur = { temp_1, temp_2 };

						++temp_1;
						++temp_2;
					}
					stop_watch.Stop();

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					LF();
				}
			}

			LS();

			{
				OUT_SUBJECT( "temp_struct 에 값을 할당하고 통짜 쓰기 | =" );

				LF();

				stop_watch.Reset();
				for( int test_index = 0; 5 > test_index; ++test_index )
				{
					temp_1 = 0;
					temp_2 = 0;

					stop_watch.Start();
					for( auto& cur : test_container )
					{
						temp_struct.i = temp_1;
						temp_struct.j = temp_2;
						cur = temp_struct;

						++temp_1;
						++temp_2;
					}
					stop_watch.Stop();

					std::cout << r2tm::tab2;
					stop_watch.PrintElapsedTime_All();
					LF();
				}
			}

			LS();

			OUT_NOTE( "Debug 에서 2 ~ 3배, Release 에서 10배 차이 난다." );
			OUT_NOTE( "{} 가 불리는 과정에서 스택에 메모리 할당이 일어나기 때문인가?" );
			OUT_NOTE( "임시 객체에 데이터를 쓰고 그걸 대입했을 때 성능이 비슷한것을 보니 operator= 작동에 부하가 있는 것 같다." );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}