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
				DECLARATION_MAIN( std::queue<int> q );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "r-value Move Constructor" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::queue<int> q( { 1, 2, 3 } ) );
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
				OUTPUT_NOTE( "빈 컨테이너에 font(), back() 쓰지마라." );
				OUTPUT_NOTE( "release | debug 모두 access violation" );

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