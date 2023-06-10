#include "std_vector_test.h"

#include <vector>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

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

	r2tm::TitleFunctionT Resize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Resize";
		};
	}
	r2tm::DoFunctionT Resize::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );
			std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

			LS();

			{
				EXPECT_EQ( 2u, container.capacity() );
				PROCESS_MAIN( container.resize( 2u ) );
				EXPECT_EQ( 2u, container.capacity() );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
			}

			LS();

			{
				EXPECT_EQ( 2u, container.capacity() );
				PROCESS_MAIN( container.resize( 4u ) );
				EXPECT_EQ( 4u, container.capacity() );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

				std::cout << r2tm::linefeed2;

				OUTPUT_NOTE( "resize 는 capacity 가 증가한 경우 메모리를 할당하고 이전 데이터를 카피한다." );
			}

			LS();

			{
				EXPECT_EQ( 4u, container.capacity() );
				PROCESS_MAIN( container.resize( 0 ) );
				EXPECT_EQ( 4u, container.capacity() );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
			}

			LS();

			{
				EXPECT_EQ( 4u, container.capacity() );
				PROCESS_MAIN( container.resize( 10 ) );
				EXPECT_EQ( 10u, container.capacity() );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT Resize_And_Memory::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Resize And Memory";
		};
	}
	r2tm::DoFunctionT Resize_And_Memory::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "size가 줄어들 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
				OUTPUT_NOTE( "줄어든 size가 이전 크기로 돌아갈 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
			}

			LS();

			DECLARATION_MAIN( std::vector<int> container( { 1, 2, 3, 4 } ) );
			OUTPUT_VALUE( container.size() );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container.data() );

			LS();
			{
				PROCESS_MAIN( container.resize( 4 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( container.resize( 2 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( container.resize( 4 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( container.resize( 10 ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Clear";
		};
	}
	r2tm::DoFunctionT Clear::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );
			OUTPUT_VALUE( container.size() );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container.data() );

			LF();

			std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

			LS();

			{
				PROCESS_MAIN( container.clear() );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				LF();

				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
			}

			LS();

			{
				PROCESS_MAIN( container.resize( 2u ) );
				OUTPUT_VALUE( container.size() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				LF();

				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

				LF();

				OUTPUT_NOTE( "clear 는 최종적으로 Allocator에 Destory 요청하지만 메모리를 해제하는 것은 아니다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Reserve::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Reserve";
		};
	}
	r2tm::DoFunctionT Reserve::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container.data() );

			LS();

			{
				PROCESS_MAIN( container.reserve( 1u ) );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				LF();

				PROCESS_MAIN( container.reserve( 2u ) );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				LF();

				PROCESS_MAIN( container.reserve( 4u ) );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				LF();

				OUTPUT_NOTE( "capacity 가 증가하면 메모리는 재할당 된다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT NoneDefaultConstructor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : None Default Constructor";
		};
	}
	r2tm::DoFunctionT NoneDefaultConstructor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( class TestClass
			{
			public:
				TestClass( int ) {}
			} );

			LS();

			DECLARATION_MAIN( std::vector<TestClass> container );

			LS();

			{
				OUTPUT_CODE( container.resize( 10 ) );

				LF();

				std::cout << r2tm::tab << "## Not Compiled : Need Default Constructor" << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT BoolVector::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Bool";
		};
	}
	r2tm::DoFunctionT BoolVector::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<bool> container );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container._Myvec.capacity() );
			OUTPUT_VALUE( container._Myvec._Myfirst() );
			OUTPUT_VALUE( container._Myvec._Myend() );
			OUTPUT_VALUE( container.begin()._Myptr );

			LS();

			{
				PROCESS_MAIN( container.push_back( 1 ) );

				LF();

				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container._Myvec.capacity() );
				OUTPUT_VALUE( container._Myvec._Myfirst() );
				OUTPUT_VALUE( container._Myvec._Myend() );
				OUTPUT_VALUE( container.begin()._Myptr );
			}

			LS();

			{
				PROCESS_MAIN( container.reserve( 33 ) );

				LF();

				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container._Myvec.capacity() );
				OUTPUT_VALUE( container._Myvec._Myfirst() );
				OUTPUT_VALUE( container._Myvec._Myend() );
				OUTPUT_VALUE( container.begin()._Myptr );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT OthersIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Others Iterator";
		};
	}
	r2tm::DoFunctionT OthersIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<int> container_1( { 1, 2, 3 } ) );
			DECLARATION_MAIN( std::vector<int> container_2( { 10, 20, 30 } ) );

			LS();

			{
				OUTPUT_CODE( container_2.erase( container_1.begin() ) );

				LF();

				std::cout << r2tm::tab << "## Not Working" << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : End Iterator";
		};
	}
	r2tm::DoFunctionT EndIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<int> container_1( { 1, 2, 3 } ) );

			LS();

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto cur = container_1.end() );
				OUTPUT_CODE( ( *cur ) );
#else
				DECLARATION_MAIN( auto cur = container_1.end() );
				OUTPUT_VALUE( ( *cur ) );
#endif
				LF();

				std::cout << r2tm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2tm::linefeed;
			}

			LS();

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUTPUT_CODE( auto cur = container_1.end() );
				OUTPUT_CODE( ++cur );
#else
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( ++cur );

				OUTPUT_VALUE( ( *cur ) );
#endif
				LF();

				std::cout << r2tm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2tm::linefeed;
			}

			LS();

			{
				DECLARATION_MAIN( auto cur = container_1.end() );
				PROCESS_MAIN( --cur );
				OUTPUT_VALUE( ( *cur ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Move::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::vector : Move";
		};
	}
	r2tm::DoFunctionT Move::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::vector<int> v_1( { 1, 2, 3 } ) );
			DECLARATION_MAIN( std::vector<int> v_2( { 3, 4, 5 } ) );

			LS();

			{
				OUTPUT_VALUE( v_1.data() );
				OUTPUT_VALUE( v_2.data() );

				LF();

				PROCESS_MAIN( v_1 = std::move( v_2 ) );
				OUTPUT_VALUE( v_1 );
				OUTPUT_VALUE( v_2 );

				LF();

				OUTPUT_VALUE( v_1.data() );
				OUTPUT_VALUE( v_2.data() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}