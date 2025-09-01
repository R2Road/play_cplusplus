#include "std_vector_test.h"

#include <vector>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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

			DECL_MAIN( std::vector<int> container( { 2, 3 } ) );
			std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

			LS();

			{
				EXPECT_EQ( 2u, container.capacity() );
				PROC_MAIN( container.resize( 2u ) );
				EXPECT_EQ( 2u, container.capacity() );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
			}

			LS();

			{
				EXPECT_EQ( 2u, container.capacity() );
				PROC_MAIN( container.resize( 4u ) );
				EXPECT_EQ( 4u, container.capacity() );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

				std::cout << r2tm::linefeed2;

				OUT_NOTE( "resize 는 capacity 가 증가한 경우 메모리를 할당하고 이전 데이터를 카피한다." );
			}

			LS();

			{
				EXPECT_EQ( 4u, container.capacity() );
				PROC_MAIN( container.resize( 0 ) );
				EXPECT_EQ( 4u, container.capacity() );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
			}

			LS();

			{
				EXPECT_EQ( 4u, container.capacity() );
				PROC_MAIN( container.resize( 10 ) );
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
				OUT_NOTE( "size가 줄어들 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
				OUT_NOTE( "줄어든 size가 이전 크기로 돌아갈 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
			}

			LS();

			DECL_MAIN( std::vector<int> container( { 1, 2, 3, 4 } ) );
			OUT_VALUE( container.size() );
			OUT_VALUE( container.capacity() );
			OUT_VALUE( container.data() );

			LS();
			{
				PROC_MAIN( container.resize( 4 ) );
				OUT_VALUE( container.size() );
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				std::cout << r2tm::linefeed2;

				PROC_MAIN( container.resize( 2 ) );
				OUT_VALUE( container.size() );
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				std::cout << r2tm::linefeed2;

				PROC_MAIN( container.resize( 4 ) );
				OUT_VALUE( container.size() );
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				std::cout << r2tm::linefeed2;

				PROC_MAIN( container.resize( 10 ) );
				OUT_VALUE( container.size() );
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );
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

			DECL_MAIN( std::vector<int> container( { 2, 3 } ) );
			OUT_VALUE( container.size() );
			OUT_VALUE( container.capacity() );
			OUT_VALUE( container.data() );

			LF();

			std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

			LS();

			{
				PROC_MAIN( container.clear() );
				OUT_VALUE( container.size() );
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				LF();

				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
			}

			LS();

			{
				PROC_MAIN( container.resize( 2u ) );
				OUT_VALUE( container.size() );
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				LF();

				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;

				LF();

				OUT_NOTE( "clear 는 최종적으로 Allocator에 Destory 요청하지만 메모리를 해제하는 것은 아니다." );
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

			DECL_MAIN( std::vector<int> container( { 2, 3 } ) );
			OUT_VALUE( container.capacity() );
			OUT_VALUE( container.data() );

			LS();

			{
				PROC_MAIN( container.reserve( 1u ) );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				LF();

				PROC_MAIN( container.reserve( 2u ) );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				LF();

				PROC_MAIN( container.reserve( 4u ) );
				std::cout << r2tm::tab << "> container : " << container << r2tm::linefeed;
				OUT_VALUE( container.capacity() );
				OUT_VALUE( container.data() );

				LF();

				OUT_NOTE( "capacity 가 증가하면 메모리는 재할당 된다." );
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

			DECL_MAIN( class TestClass
			{
			public:
				TestClass( int ) {}
			} );

			LS();

			DECL_MAIN( std::vector<TestClass> container );

			LS();

			{
				OUT_CODE( container.resize( 10 ) );

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

			DECL_MAIN( std::vector<bool> container );
			OUT_VALUE( container.capacity() );
			OUT_VALUE( container._Myvec.capacity() );
			OUT_VALUE( container.begin()._Myptr );

			LS();

			{
				PROC_MAIN( container.push_back( 1 ) );

				LF();

				OUT_VALUE( container.capacity() );
				OUT_VALUE( container._Myvec.capacity() );
				OUT_BINARIES( &container._Myvec.front(), 1 );
				OUT_VALUE( container.begin()._Myptr );
			}

			LS();

			{
				PROC_MAIN( container.reserve( 33 ) );

				LF();

				OUT_VALUE( container.capacity() );
				OUT_VALUE( container._Myvec.capacity() );
				OUT_BINARIES( &container._Myvec.front(), 2 );
				OUT_VALUE( container.begin()._Myptr );
			}

			LS();

			{
				PROC_MAIN( container.clear() );
				PROC_MAIN( for( std::size_t i = 0; i < 32; ++i ) { container.push_back( true ); } );


				LF();

				OUT_VALUE( container.capacity() );
				OUT_VALUE( container._Myvec.capacity() );
				OUT_BINARIES( &container._Myvec.front(), 2 );
				OUT_VALUE( container.begin()._Myptr );
			}

			LS();

			{
				PROC_MAIN( container.push_back( 1 ) );

				LF();

				OUT_VALUE( container.capacity() );
				OUT_VALUE( container._Myvec.capacity() );
				OUT_BINARIES( &container._Myvec.front(), 2 );
				OUT_VALUE( container.begin()._Myptr );
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

			DECL_MAIN( std::vector<int> container_1( { 1, 2, 3 } ) );
			DECL_MAIN( std::vector<int> container_2( { 10, 20, 30 } ) );

			LS();

			{
				OUT_CODE( container_2.erase( container_1.begin() ) );

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

			DECL_MAIN( std::vector<int> container_1( { 1, 2, 3 } ) );

			LS();

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUT_CODE( auto cur = container_1.end() );
				OUT_CODE( ( *cur ) );
#else
				DECL_MAIN( auto cur = container_1.end() );
				OUT_VALUE( ( *cur ) );
#endif
				LF();

				std::cout << r2tm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2tm::linefeed;
			}

			LS();

			{
#if defined( DEBUG ) || defined( _DEBUG )
				OUT_CODE( auto cur = container_1.end() );
				OUT_CODE( ++cur );
#else
				DECL_MAIN( auto cur = container_1.end() );
				PROC_MAIN( ++cur );

				OUT_VALUE( ( *cur ) );
#endif
				LF();

				std::cout << r2tm::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2tm::linefeed;
			}

			LS();

			{
				DECL_MAIN( auto cur = container_1.end() );
				PROC_MAIN( --cur );
				OUT_VALUE( ( *cur ) );
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

			DECL_MAIN( std::vector<int> v_1( { 1, 2, 3 } ) );
			DECL_MAIN( std::vector<int> v_2( { 3, 4, 5 } ) );

			LS();

			{
				OUT_VALUE( v_1.data() );
				OUT_VALUE( v_2.data() );

				LF();

				PROC_MAIN( v_1 = std::move( v_2 ) );
				OUT_VALUE( v_1 );
				OUT_VALUE( v_2 );

				LF();

				OUT_VALUE( v_1.data() );
				OUT_VALUE( v_2.data() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}