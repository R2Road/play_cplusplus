#include "std_list_test.h"

#include <list>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_list_test
{
	r2cm::iItem::TitleFunctionT Splice::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "List : Splice";
		};
	}
	r2cm::iItem::DoFunctionT Splice::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::list<int> container_1 = { 1, 2, 3, 4, 5 };
			std::list<int> container_2 = { 10, 20, 30, 40, 50 };

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::list<int> container_1 = { 1, 2, 3, 4, 5 };" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::list<int> container_2 = { 10, 20, 30, 40, 50 };" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				auto target_itr = std::find( container_1.begin(), container_1.end(), 3 );
				container_2.splice( container_2.begin(), container_1, target_itr );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto target_itr = std::find( container_1.begin(), container_1.end(), 3 );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "container_2.splice( container_2.begin(), container_1, target_itr );" << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
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
			}

			std::cout << r2cm::split;

			{
				auto target_itr = std::find( container_1.begin(), container_1.end(), 4 );
				container_2.splice( container_2.begin(), container_1, target_itr, container_1.end() );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto target_itr = std::find( container_1.begin(), container_1.end(), 4 );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "container_2.splice( container_2.begin(), container_1, target_itr, container_1.end() );" << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
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
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Splice : target ~ next" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( auto target_itr = std::find( container_1.begin(), container_1.end(), 1 ) );
				DECLARATION_MAIN( auto next_itr = target_itr );
				PROCESS_MAIN( ++next_itr );
				PROCESS_MAIN( container_2.splice( container_2.begin(), container_1, target_itr, next_itr ) );

				std::cout << r2cm::linefeed;
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
			}

			std::cout << r2cm::split;

			{
				//container_2.splice( container_2.begin(), container_1, container_1.end() );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "container_2.splice( container_2.begin(), container_1, container_1.end() );" << r2cm::linefeed2;

				//std::cout << r2cm::tab << "+ Result" << r2cm::linefeed;
				//std::cout << r2cm::tab2 << "- container_1 : ";
				//for( const auto i : container_1 )
				//{
				//	std::cout << i << " ";
				//}
				//std::cout << r2cm::linefeed;
				//std::cout << r2cm::tab2 << "- container_2 : ";
				//for( const auto i : container_2 )
				//{
				//	std::cout << i << " ";
				//}
				//std::cout << r2cm::linefeed2;

				std::cout << r2cm::tab << "Message : Debug Mode Not Working, Release Mode Working" << r2cm::linefeed;
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