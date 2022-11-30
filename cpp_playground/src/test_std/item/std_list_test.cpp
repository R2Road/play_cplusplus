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
			std::cout << i << " ";
		}
		return o;
	}

	r2cm::iItem::TitleFunctionT Splice_Single::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : Splice Single";
		};
	}
	r2cm::iItem::DoFunctionT Splice_Single::GetDoFunction()
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
	r2cm::iItem::DoFunctionT Splice_Range::GetDoFunction()
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
	r2cm::iItem::DoFunctionT OthersIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::list<int> container_1 = { 1, 2, 3 };
			std::list<int> container_2 = { 10, 20, 30 };

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::list<int> container_1 = { 1, 2, 3 };" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::list<int> container_2 = { 10, 20, 30 };" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto itr_from_container_1 = container_1.begin();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "container_2.erase( itr_from_container_1 );" << r2cm::linefeed2;

				std::cout << r2cm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2cm::linefeed;

#if !defined( DEBUG ) && !defined( _DEBUG )
				std::cout << r2cm::linefeed2;

				auto itr_from_container_1 = container_1.begin();
				container_2.erase( itr_from_container_1 );

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- container_1 : ";
				for( const auto i : container_1 )
				{
					std::cout << i << " ";
				}
				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- container_2 : ";
				for( const auto i : container_2 )
				{
					std::cout << i << " ";
				}
				std::cout << r2cm::linefeed;
#endif
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
	r2cm::iItem::DoFunctionT EndIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::list<int> container_1 = { 1, 2, 3 };

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::list<int> container_1 = { 1, 2, 3 };" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process : operator*" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto cur = container_1.end();" << r2cm::linefeed2;

				std::cout << r2cm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2cm::linefeed2;

#if !defined( DEBUG ) && !defined( _DEBUG )
				auto cur = container_1.end();

				std::cout << r2cm::tab2 << "( *cur );" << " > " << ( *cur ) << r2cm::linefeed;
#endif
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process : operator++" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto cur = container_1.end();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "++cur;" << r2cm::linefeed2;

				std::cout << r2cm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2cm::linefeed2;

#if !defined( DEBUG ) && !defined( _DEBUG )
				auto cur = container_1.end();
				++cur;

				std::cout << r2cm::tab2 << "( *cur );" << " > " << ( *cur ) << r2cm::linefeed;
#endif
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process : operator--" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto cur = container_1.end();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "--cur;" << r2cm::linefeed2;

				auto cur = container_1.end();
				--cur;

				std::cout << r2cm::tab2 << "( *cur );" << " > " << ( *cur ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}