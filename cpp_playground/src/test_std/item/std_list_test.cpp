#include "std_list_test.h"

#include <list>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

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

	r2cm::iItem::TitleFunctionT Splice_Single::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : Splice Single";
		};
	}
	r2cm::iItem::DoFunctionT Splice_Single::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3, 4, 5 } ) );
			DECLARATION_MAIN( std::list<int> container_2( { 10, 20, 30, 40, 50 } ) );

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "splice는 list의 node를 메모리 할당 없이 통째로 옮긴다." );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto target_itr = container_1.begin() );
				OUTPUT_VALUE( ( *target_itr ) );
				OUTPUT_VALUE( &( *target_itr ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr ) );
				std::cout << r2cm::tab << "- container_1 : " << container_1 << r2cm::linefeed;
				std::cout << r2cm::tab << "- container_2 : " << container_2 << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( &( *container_2.begin() ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "이동을 지정한 iterator 의 앞에 삽입된다." );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto target_itr = std::find( container_1.begin(), container_1.end(), 3 ) );
				OUTPUT_VALUE( ( *target_itr ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr ) );
				std::cout << r2cm::tab << "- container_1 : " << container_1 << r2cm::linefeed;
				std::cout << r2cm::tab << "- container_2 : " << container_2 << r2cm::linefeed;
			
				std::cout << r2cm::linefeed;

				PROCESS_MAIN( target_itr = std::find( container_1.begin(), container_1.end(), 2 ) );
				OUTPUT_VALUE( ( *target_itr ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container_2.splice( container_2.end(), container_1, target_itr ) );
				std::cout << r2cm::tab << "- container_1 : " << container_1 << r2cm::linefeed;
				std::cout << r2cm::tab << "- container_2 : " << container_2 << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				OUTPUT_CODE( container_2.splice( container_2.end(), container_1, container_1.end() ) );

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "end() iterator 를 이동하려 들면 터진다." );
				OUTPUT_NOTE( "Debug Mode Not Working, Release Mode Working" );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Splice_Range::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : Splice Range";
		};
	}
	r2cm::iItem::DoFunctionT Splice_Range::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3, 4, 5 } ) );
			DECLARATION_MAIN( std::list<int> container_2( { 10, 20, 30, 40, 50 } ) );

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Splice : target ~ end" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto target_itr = std::find( container_1.begin(), container_1.end(), 4 ) );
				OUTPUT_VALUE( ( *target_itr ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr, container_1.end() ) );
				std::cout << r2cm::tab << "- container_1 : " << container_1 << r2cm::linefeed;
				std::cout << r2cm::tab << "- container_2 : " << container_2 << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Splice : target ~ next" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto target_itr = std::find( container_1.begin(), container_1.end(), 1 ) );
				DECLARATION_MAIN( auto next_itr = target_itr );
				PROCESS_MAIN( ++next_itr );
				OUTPUT_VALUE( ( *target_itr ) );
				OUTPUT_VALUE( ( *next_itr ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr, next_itr ) );
				std::cout << r2cm::tab << "- container_1 : " << container_1 << r2cm::linefeed;
				std::cout << r2cm::tab << "- container_2 : " << container_2 << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "범위 이동의 경우 마지막 요소는 이동 대상에 포함되지 않는다." );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT OthersIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : Others Iterator";
		};
	}
	r2cm::iItem::DoFunctionT OthersIterator::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3 } ) );
			DECLARATION_MAIN( std::list<int> container_2( { 10, 20, 30 } ) );

			std::cout << r2cm::split;

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( container_2.erase( container_1.begin() ) );
#else
				PROCESS_MAIN( container_2.erase( container_1.begin() ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- container_1 : " << container_1 << r2cm::linefeed;
				std::cout << r2cm::tab << "- container_2 : " << container_2 << r2cm::linefeed;
#endif

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "남의 iterator 라도 삭제 처리는 된다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : End Iterator";
		};
	}
	r2cm::iItem::DoFunctionT EndIterator::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::list<int> container_1( { 1, 2, 3 } ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto cur = container_1.end(); );

#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto v = *cur );
#else
				DECLARATION_MAIN( auto v = *cur );
				OUTPUT_VALUE( v );
#endif
				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "end() iterator의 값을 사용 할 수 있다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			std::cout << r2cm::split;

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto cur = container_1.end() );
				OUTPUT_CODE( ++cur );
#else
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( ++cur );
				OUTPUT_VALUE( *cur );
#endif
				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "++end() 는 begin() 이다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( --cur );
				OUTPUT_VALUE( *cur );

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "--end() 는 작동한다." );
			}

			std::cout << r2cm::split;

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

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "빈 컨테이너의 --end() 는 end() 이다." );
				OUTPUT_NOTE( "빈 컨테이너는 Debug 모드에서 Container Size 검사에 실패한다." );
				OUTPUT_NOTE( "Not Working In Debug Mode : _STL_VERIFY" );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Erase::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : Erase";
		};
	}
	r2cm::iItem::DoFunctionT Erase::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::list<int> l( { 1, 2, 3 } ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto target = ( ++l.begin() ) );
				OUTPUT_VALUE( target );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( target = l.erase( target ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 3, *target );
				OUTPUT_VALUE( l );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}