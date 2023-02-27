#include "std_vector_test.h"

#include <vector>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_vector_test
{
	std::ostream& operator<<( std::ostream& o, std::vector<int>& container )
	{
		for( const auto& i : container )
		{
			o << i << " ";
		}
		return o;
	}

	r2cm::iItem::TitleFunctionT Resize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Resize";
		};
	}
	r2cm::iItem::DoFunctionT Resize::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );
			std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 2u, container.capacity() );
				PROCESS_MAIN( container.resize( 2u ) );
				EXPECT_EQ( 2u, container.capacity() );
				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 2u, container.capacity() );
				PROCESS_MAIN( container.resize( 4u ) );
				EXPECT_EQ( 4u, container.capacity() );
				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;

				std::cout << r2cm::linefeed2;

				OUTPUT_NOTE( "resize 는 capacity 가 증가한 경우 메모리를 할당하고 이전 데이터를 카피한다." );
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 4u, container.capacity() );
				PROCESS_MAIN( container.resize( 0 ) );
				EXPECT_EQ( 4u, container.capacity() );
				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 4u, container.capacity() );
				PROCESS_MAIN( container.resize( 10 ) );
				EXPECT_EQ( 10u, container.capacity() );
				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT Resize_And_Memory::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Resize And Memory";
		};
	}
	r2cm::iItem::DoFunctionT Resize_And_Memory::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "size가 줄어들 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
				OUTPUT_NOTE( "줄어든 size가 이전 크기로 돌아갈 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container( { 1, 2, 3, 4 } ) );
			OUTPUT_VALUE( container.size() );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container.data() );

			std::cout << r2cm::split;
			{
				PROCESS_MAIN( container.resize( 4 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( container.resize( 2 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( container.resize( 4 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( container.resize( 10 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Clear";
		};
	}
	r2cm::iItem::DoFunctionT Clear::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );
			OUTPUT_VALUE( container.size() );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container.data() );

			std::cout << r2cm::linefeed;

			std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.clear() );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.resize( 2u ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "clear 는 최종적으로 Allocator에 Destory 요청하지만 메모리를 해제하는 것은 아니다." );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Reserve::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Reserve";
		};
	}
	r2cm::iItem::DoFunctionT Reserve::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container.data() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.reserve( 1u ) );
				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container.reserve( 2u ) );
				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container.reserve( 4u ) );
				std::cout << r2cm::tab << "> container : " << container << r2cm::linefeed;
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "capacity 가 증가하면 메모리는 재할당 된다." );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT NoneDefaultConstructor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : None Default Constructor";
		};
	}
	r2cm::iItem::DoFunctionT NoneDefaultConstructor::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( class TestClass
			{
			public:
				TestClass( int ) {}
			} );

			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<TestClass> container );

			std::cout << r2cm::split;

			{
				OUTPUT_CODE( container.resize( 10 ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "## Not Compiled : Need Default Constructor" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT BoolVector::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Bool";
		};
	}
	r2cm::iItem::DoFunctionT BoolVector::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<bool> container );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container._Myvec.capacity() );
			OUTPUT_VALUE( container._Myvec._Myfirst() );
			OUTPUT_VALUE( container._Myvec._Myend() );
			OUTPUT_VALUE( container.begin()._Myptr );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.push_back( 1 ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container._Myvec.capacity() );
				OUTPUT_VALUE( container._Myvec._Myfirst() );
				OUTPUT_VALUE( container._Myvec._Myend() );
				OUTPUT_VALUE( container.begin()._Myptr );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.reserve( 33 ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container._Myvec.capacity() );
				OUTPUT_VALUE( container._Myvec._Myfirst() );
				OUTPUT_VALUE( container._Myvec._Myend() );
				OUTPUT_VALUE( container.begin()._Myptr );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT OthersIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Others Iterator";
		};
	}
	r2cm::iItem::DoFunctionT OthersIterator::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container_1( { 1, 2, 3 } ) );
			DECLARATION_MAIN( std::vector<int> container_2( { 10, 20, 30 } ) );

			std::cout << r2cm::split;

			{
				OUTPUT_CODE( container_2.erase( container_1.begin() ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "## Not Working" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : End Iterator";
		};
	}
	r2cm::iItem::DoFunctionT EndIterator::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container_1( { 1, 2, 3 } ) );

			std::cout << r2cm::split;

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto cur = container_1.end() );
				OUTPUT_CODE( ( *cur ) );
#else
				DECLARATION_MAIN( auto cur = container_1.end() );
				OUTPUT_VALUE( ( *cur ) );
#endif
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto cur = container_1.end() );
				OUTPUT_CODE( ++cur );
#else
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( ++cur );

				OUTPUT_VALUE( ( *cur ) );
#endif
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( --cur );
				OUTPUT_VALUE( ( *cur ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Move::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Move";
		};
	}
	r2cm::iItem::DoFunctionT Move::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> v_1( { 1, 2, 3 } ) );
			DECLARATION_MAIN( std::vector<int> v_2( { 3, 4, 5 } ) );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( v_1.data() );
				OUTPUT_VALUE( v_2.data() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( v_1 = std::move( v_2 ) );
				OUTPUT_VALUE( v_1 );
				OUTPUT_VALUE( v_2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v_1.data() );
				OUTPUT_VALUE( v_2.data() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}