#include "std_list_test.h"

#include <list>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_list_test
{
	std::ostream& operator<<( std::ostream& o, std::list<int>& container )
	{
		for( const auto& i : container )
		{
			o << i << " ";
		}
		return o;
	}
	std::ostream& operator<<( std::ostream& o, std::list<int>::iterator itr )
	{
		o << ( *itr );
		return o;
	}



	r2tm::TitleFunctionT Insert::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::list : Insert";
		};
	}
	r2tm::DoFunctionT Insert::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "insert를 지시한 iterator의 앞에 삽입된다." );

			LS();

			DECLARATION_MAIN( std::list<int> l( { 1, 2, 3 } ) );

			LS();

			{
				DECLARATION_MAIN( auto itr = ( ++l.begin() ) );
				OUTPUT_VALUE( ( *itr ) );

				LF();

				DECLARATION_MAIN( auto result_itr = l.insert( itr, 4 ) );
				OUTPUT_VALUE( result_itr );

				LF();

				OUTPUT_VALUE( l );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Splice_Single::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::list : Splice Single";
		};
	}
	r2tm::DoFunctionT Splice_Single::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3, 4, 5 } ) );
			DECLARATION_MAIN( std::list<int> container_2( { 10, 20, 30, 40, 50 } ) );

			LS();

			{
				OUTPUT_NOTE( "splice는 list의 node를 메모리 할당 없이 통째로 옮긴다." );

				LF();

				DECLARATION_MAIN( auto target_itr = container_1.begin() );
				OUTPUT_VALUE( ( *target_itr ) );
				OUTPUT_VALUE( &( *target_itr ) );

				LF();

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr ) );
				std::cout << r2tm::tab << "- container_1 : " << container_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "- container_2 : " << container_2 << r2tm::linefeed;

				LF();

				OUTPUT_VALUE( &( *container_2.begin() ) );
			}

			LS();

			{
				OUTPUT_NOTE( "이동을 지정한 iterator 의 앞에 삽입된다." );

				LF();

				DECLARATION_MAIN( auto target_itr = std::find( container_1.begin(), container_1.end(), 3 ) );
				OUTPUT_VALUE( ( *target_itr ) );

				LF();

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr ) );
				std::cout << r2tm::tab << "- container_1 : " << container_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "- container_2 : " << container_2 << r2tm::linefeed;
			
				LF();

				PROCESS_MAIN( target_itr = std::find( container_1.begin(), container_1.end(), 2 ) );
				OUTPUT_VALUE( ( *target_itr ) );

				LF();

				PROCESS_MAIN( container_2.splice( container_2.end(), container_1, target_itr ) );
				std::cout << r2tm::tab << "- container_1 : " << container_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "- container_2 : " << container_2 << r2tm::linefeed;
			}

			LS();

			{
				OUTPUT_CODE( container_2.splice( container_2.end(), container_1, container_1.end() ) );

				LF();

				OUTPUT_NOTE( "end() iterator 를 이동하려 들면 터진다." );
				OUTPUT_NOTE( "Debug Mode Not Working, Release Mode Working" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Splice_Range::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::list : Splice Range";
		};
	}
	r2tm::DoFunctionT Splice_Range::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3, 4, 5 } ) );
			DECLARATION_MAIN( std::list<int> container_2( { 10, 20, 30, 40, 50 } ) );

			LS();

			{
				OUTPUT_NOTE( "Splice : target ~ end" );

				LF();

				DECLARATION_MAIN( auto target_itr = std::find( container_1.begin(), container_1.end(), 4 ) );
				OUTPUT_VALUE( ( *target_itr ) );

				LF();

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr, container_1.end() ) );
				std::cout << r2tm::tab << "- container_1 : " << container_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "- container_2 : " << container_2 << r2tm::linefeed;
			}

			LS();

			{
				OUTPUT_NOTE( "Splice : target ~ next" );

				LF();

				DECLARATION_MAIN( auto target_itr = std::find( container_1.begin(), container_1.end(), 1 ) );
				DECLARATION_MAIN( auto next_itr = target_itr );
				PROCESS_MAIN( ++next_itr );
				OUTPUT_VALUE( ( *target_itr ) );
				OUTPUT_VALUE( ( *next_itr ) );

				LF();

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr, next_itr ) );
				std::cout << r2tm::tab << "- container_1 : " << container_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "- container_2 : " << container_2 << r2tm::linefeed;
			}

			LS();

			{
				OUTPUT_NOTE( "범위 이동의 경우 마지막 요소는 이동 대상에 포함되지 않는다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Erase::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::list : Erase";
		};
	}
	r2tm::DoFunctionT Erase::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::list<int> l( { 1, 2, 3 } ) );

			LS();

			{
				DECLARATION_MAIN( auto target = ( ++l.begin() ) );
				OUTPUT_VALUE( target );

				LF();

				PROCESS_MAIN( target = l.erase( target ) );

				LF();

				EXPECT_EQ( 3, *target );
				OUTPUT_VALUE( l );
			}

			LS();

			{
				OUTPUT_NOTE( "end() iterator 의 삭제는 시도하지 말자." );

				LF();

				OUTPUT_CODE( l.erase( l.end() ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Erase_OthersIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::list : Erase - Others Iterator";
		};
	}
	r2tm::DoFunctionT Erase_OthersIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3 } ) );
			DECLARATION_MAIN( std::list<int> container_2( { 10, 20, 30 } ) );

			LS();

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( container_2.erase( container_1.begin() ) );
#else
				PROCESS_MAIN( container_2.erase( container_1.begin() ) );

				LF();

				std::cout << r2tm::tab << "- container_1 : " << container_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "- container_2 : " << container_2 << r2tm::linefeed;
#endif

				LF();

				OUTPUT_NOTE( "남의 iterator 라도 삭제 처리는 된다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::list : End Iterator";
		};
	}
	r2tm::DoFunctionT EndIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3 } ) );

			LS();

			{
				DECLARATION_MAIN( auto cur = container_1.end(); );

#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto v = *cur );
#else
				DECLARATION_MAIN( auto v = *cur );
				OUTPUT_VALUE( v );
#endif
				LF();

				OUTPUT_NOTE( "end() iterator의 값을 사용 할 수 있다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			LS();

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto cur = container_1.end() );
				OUTPUT_CODE( ++cur );
#else
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( ++cur );
				OUTPUT_VALUE( *cur );
#endif
				LF();

				OUTPUT_NOTE( "++end() 는 begin() 이다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			LS();

			{
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( --cur );
				OUTPUT_VALUE( *cur );

				LF();

				OUTPUT_NOTE( "--end() 는 작동한다." );
			}

			LS();

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( std::list<int> container_2 );
				OUTPUT_CODE( auto itr = container_2.end() );
				OUTPUT_CODE( EXPECT_EQ( container_2.end(), ( --itr ) ) );
#else
				DECLARATION_MAIN( std::list<int> container_2 );
				DECLARATION_MAIN( auto itr = container_2.end() );
				EXPECT_EQ( container_2.end(), ( --itr ) );
#endif

				LF();

				OUTPUT_NOTE( "빈 컨테이너의 --end() 는 end() 이다." );
				OUTPUT_NOTE( "빈 컨테이너는 Debug 모드에서 Container Size 검사에 실패한다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}