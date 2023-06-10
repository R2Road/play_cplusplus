#include "std_queue_test.h"

#include <queue>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace std_queue_test
{
	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "FIFO, Simple( iterator 없음 )" );
			}

			LS();

			{
				DECLARATION_MAIN( std::queue<int> q );

				LF();

				EXPECT_TRUE( q.empty() );
				EXPECT_EQ( 0, q.size() );
			}

			LS();

			{
				OUTPUT_NOTE( "r-value Move Constructor" );

				LF();

				DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );

				LF();

				EXPECT_FALSE( q.empty() );
				EXPECT_EQ( 3, q.size() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Front_Back::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Front, Back";
		};
	}
	r2tm::DoFunctionT Front_Back::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "빈 컨테이너에 font(), back() 쓰지마라." );
				OUTPUT_NOTE( "release | debug 모두 access violation" );

				LF();

				DECLARATION_MAIN( std::queue<int> q );

				LF();

				OUTPUT_CODE( q.front() );
				OUTPUT_CODE( q.back() );
			}

			LS();

			{
				DECLARATION_MAIN( std::queue<int> q( { 1 } ) );

				LF();

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 1, q.back() );

				LF();

				OUTPUT_VALUE( q.front() );
				OUTPUT_VALUE( q.back() );
			}

			LS();

			{
				DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );

				LF();

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 3, q.back() );

				LF();

				OUTPUT_VALUE( q.front() );
				OUTPUT_VALUE( q.back() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Push_Pop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Push, Pop";
		};
	}
	r2tm::DoFunctionT Push_Pop::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::queue<int> q );
			EXPECT_EQ( 0, q.size() );
			EXPECT_TRUE( q.empty() );

			LS();

			{
				PROCESS_MAIN( q.push( 1 ) );

				LF();

				EXPECT_EQ( 1, q.size() );
				EXPECT_FALSE( q.empty() );

				LF();

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 1, q.back() );
			}

			LS();

			{
				PROCESS_MAIN( q.push( 2 ) );

				LF();

				EXPECT_EQ( 2, q.size() );
				EXPECT_FALSE( q.empty() );

				LF();

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 2, q.back() );
			}

			LS();

			{
				PROCESS_MAIN( q.pop() );

				LF();

				EXPECT_EQ( 1, q.size() );
				EXPECT_FALSE( q.empty() );

				LF();

				EXPECT_EQ( 2, q.front() );
				EXPECT_EQ( 2, q.back() );
			}

			LS();

			{
				PROCESS_MAIN( q.pop() );

				LF();

				EXPECT_EQ( 0, q.size() );
				EXPECT_TRUE( q.empty() );
			}

			LS();

			{
				OUTPUT_NOTE( "빈 컨테이너에 pop() 쓰지마라." );
				OUTPUT_NOTE( "release | debug 예외 발생" );

				LF();

				OUTPUT_CODE( q.pop() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Iteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Iteration";
		};
	}
	r2tm::DoFunctionT Iteration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "Front, Back 외에는 값의 확인이 불가능 하다." );
				OUTPUT_NOTE( "Iterator 도 없다." );
				OUTPUT_NOTE( "그럼 값을 꺼내는 것 말고는 순회할 방법이 없다???" );
			}

			LS();

			DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );

			LS();

			{
				while( !q.empty() )
				{
					const auto& i = q.front();
					OUTPUT_VALUE( i );

					q.pop();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}