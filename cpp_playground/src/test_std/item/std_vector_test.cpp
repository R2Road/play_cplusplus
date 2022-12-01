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
			return "Vector : Resize";
		};
	}
	r2cm::iItem::DoFunctionT Resize::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );

			std::cout << r2cm::split;

			{
				EXPECT_EQ( 2, container[0] );
				EXPECT_EQ( 3, container[1] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container.resize( 2u ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, container[0] );
				EXPECT_EQ( 3, container[1] );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.resize( 4u ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 2, container[0] );
				EXPECT_EQ( 3, container[1] );
				EXPECT_EQ( 0, container[2] );
				EXPECT_EQ( 0, container[3] );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "크기가 줄어들 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
				OUTPUT_NOTE( "줄어든 메모리가 이전 크기로 돌아갈 때 메모리가 재할당 되는지 궁금했다. > 재할당 없다." );
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> test_vector( { 1, 2, 3, 4 } ) );
			std::cout << r2cm::tab << "- test_vector : " << test_vector << r2cm::linefeed;
			OUTPUT_VALUE( ( &test_vector[0] ) );
			OUTPUT_VALUE( test_vector.capacity() );

			std::cout << r2cm::split;
			{
				PROCESS_MAIN( test_vector.resize( 2 ) );
				std::cout << r2cm::tab << "- test_vector : " << test_vector << r2cm::linefeed;
				OUTPUT_VALUE( ( &test_vector[0] ) );
				OUTPUT_VALUE( test_vector.capacity() );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( test_vector.resize( 4 ) );
				std::cout << r2cm::tab << "- test_vector : " << test_vector << r2cm::linefeed;
				OUTPUT_VALUE( ( &test_vector[0] ) );
				OUTPUT_VALUE( test_vector.capacity() );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( test_vector.resize( 10 ) );
				std::cout << r2cm::tab << "- test_vector : " << test_vector << r2cm::linefeed;
				OUTPUT_VALUE( ( &test_vector[0] ) );
				OUTPUT_VALUE( test_vector.capacity() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Clear";
		};
	}
	r2cm::iItem::DoFunctionT Clear::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( std::vector<int> container( { 2, 3 } ) );
			OUTPUT_VALUE( container.capacity() );
			OUTPUT_VALUE( container.data() );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.clear() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container.resize( 2u ) );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( container.clear() );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( container.resize( 4u ) );
				OUTPUT_VALUE( container.capacity() );
				OUTPUT_VALUE( container.data() );

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "clear 는 최종적으로 Allocator에 Destory 요청하지만 메모리를 해제하는 것은 아니다." );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT NoneDefaultConstructor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : None Default Constructor";
		};
	}
	r2cm::iItem::DoFunctionT NoneDefaultConstructor::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			class TestClass
			{
			public:
				TestClass( int ) {}
			};
			std::vector<TestClass> test_vector;

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestClass" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "TestClass( int ) {}" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "td::vector<TestClass> test_vector;" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				//test_vector.resize( 10 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "test_vector.resize( 10 );" << r2cm::linefeed2;


				std::cout << r2cm::tab << "## Now Working : Need Default Constructor" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT BoolVector::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Bool";
		};
	}
	r2cm::iItem::DoFunctionT BoolVector::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::vector<bool> test_vector;

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::vector<bool> test_vector;" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "test_vector.capacity()" << " > " << test_vector.capacity() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				test_vector.push_back( 1 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "test_vector.push_back( 1 );" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "test_vector.capacity()" << " > " << test_vector.capacity() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector._Myvec.capacity()" << " > " << test_vector._Myvec.capacity() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector._Myvec._Myfirst()" << " > " << test_vector._Myvec._Myfirst() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector._Myvec._Myend()" << " > " << test_vector._Myvec._Myend() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector.begin()._Myptr" << " > " << test_vector.begin()._Myptr << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				test_vector.reserve( 33 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "test_vector.reserve( 33 );" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "test_vector.capacity()" << " > " << test_vector.capacity() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector._Myvec.capacity()" << " > " << test_vector._Myvec.capacity() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector._Myvec._Myfirst()" << " > " << test_vector._Myvec._Myfirst() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector._Myvec._Myend()" << " > " << test_vector._Myvec._Myend() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "test_vector.begin()._Myptr" << " > " << test_vector.begin()._Myptr << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT OthersIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Others Iterator";
		};
	}
	r2cm::iItem::DoFunctionT OthersIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::vector<int> container_1 = { 1, 2, 3 };
			std::vector<int> container_2 = { 10, 20, 30 };

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::vector<int> container_1 = { 1, 2, 3 };" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "std::vector<int> container_2 = { 10, 20, 30 };" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				//auto itr_from_container_1 = container_1.begin();
				//container_2.erase( itr_from_container_1 );

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto itr_from_container_1 = container_1.begin();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "container_2.erase( itr_from_container_1 );" << r2cm::linefeed2;

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
			return "Vector : End Iterator";
		};
	}
	r2cm::iItem::DoFunctionT EndIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::vector<int> container_1 = { 1, 2, 3 };

			{
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::vector<int> container_1 = { 1, 2, 3 };" << r2cm::linefeed;
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