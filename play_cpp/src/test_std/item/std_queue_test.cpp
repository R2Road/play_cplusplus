#include "std_queue_test.h"

#include <queue>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace std_queue_test
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "FIFO, Simple( iterator ���� )" );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::queue<int> q );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( q.empty() );
				EXPECT_EQ( 0, q.size() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "r-value Move Constructor" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( q.empty() );
				EXPECT_EQ( 3, q.size() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Front_Back::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Front, Back";
		};
	}
	r2cm::iItem::DoFunctionT Front_Back::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "�� �����̳ʿ� font(), back() ��������." );
				OUTPUT_NOTE( "release | debug ��� access violation" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::queue<int> q );

				std::cout << r2cm::linefeed;

				OUTPUT_CODE( q.front() );
				OUTPUT_CODE( q.back() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::queue<int> q( { 1 } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 1, q.back() );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( q.front() );
				OUTPUT_VALUE( q.back() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 3, q.back() );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( q.front() );
				OUTPUT_VALUE( q.back() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Push_Pop::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Push, Pop";
		};
	}
	r2cm::iItem::DoFunctionT Push_Pop::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::queue<int> q );
			EXPECT_EQ( 0, q.size() );
			EXPECT_TRUE( q.empty() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( q.push( 1 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, q.size() );
				EXPECT_FALSE( q.empty() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 1, q.back() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( q.push( 2 ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, q.size() );
				EXPECT_FALSE( q.empty() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, q.front() );
				EXPECT_EQ( 2, q.back() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( q.pop() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, q.size() );
				EXPECT_FALSE( q.empty() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, q.front() );
				EXPECT_EQ( 2, q.back() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( q.pop() );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 0, q.size() );
				EXPECT_TRUE( q.empty() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "�� �����̳ʿ� pop() ��������." );
				OUTPUT_NOTE( "release | debug ���� �߻�" );

				std::cout << r2cm::linefeed;

				OUTPUT_CODE( q.pop() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Iteration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::queue : Iteration";
		};
	}
	r2cm::iItem::DoFunctionT Iteration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Front, Back �ܿ��� ���� Ȯ���� �Ұ��� �ϴ�." );
				OUTPUT_NOTE( "Iterator �� ����." );
				OUTPUT_NOTE( "�׷� ���� ������ �� ������ ��ȸ�� ����� ����???" );
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );

			std::cout << r2cm::split;

			{
				while( !q.empty() )
				{
					const auto& i = q.front();
					OUTPUT_VALUE( i );

					q.pop();
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}