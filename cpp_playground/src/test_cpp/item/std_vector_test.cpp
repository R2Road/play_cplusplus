#include "pch.h"
#include "std_vector_test.h"

#include <vector>

#include "r2cm/r2cm_eTestEndAction.h"

namespace std_vector_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Resize" << r2::linefeed2;

				std::vector<int> test_vector = { 1, 2, 3, 4 };
				std::cout << r2::tab2 << "std::vector<int> test_vector = { 1, 2, 3, 4 };" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed2;

				test_vector.resize( 10 );
				std::cout << r2::tab2 << "test_vector.resize( 10 );" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed2;

				test_vector.resize( 2 );
				std::cout << r2::tab2 << "test_vector.resize( 2 );" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed2;

				test_vector.resize( 20 );
				std::cout << r2::tab2 << "test_vector.resize( 10 );" << r2::linefeed;
				std::cout << r2::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT NoneDefaultConstructor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : None Default Constructor";
		};
	}
	r2cm::iItem::DoFuncT NoneDefaultConstructor::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			class TestClass
			{
			public:
				TestClass( int ) {}
			};
			std::vector<TestClass> test_vector;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "class TestClass" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab2 << "public:" << r2::linefeed;
				std::cout << r2::tab3 << "TestClass( int ) {}" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
				std::cout << r2::tab2 << "td::vector<TestClass> test_vector;" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				//test_vector.resize( 10 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "test_vector.resize( 10 );" << r2::linefeed2;


				std::cout << r2::tab << "## Now Working : Need Default Constructor" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT BoolVector::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Bool";
		};
	}
	r2cm::iItem::DoFuncT BoolVector::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::vector<bool> test_vector;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::vector<bool> test_vector;" << r2::linefeed2;
				std::cout << r2::tab2 << "test_vector.capacity()" << " > " << test_vector.capacity() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				test_vector.push_back( 1 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "test_vector.push_back( 1 );" << r2::linefeed2;
				std::cout << r2::tab2 << "test_vector.capacity()" << " > " << test_vector.capacity() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector._Myvec.capacity()" << " > " << test_vector._Myvec.capacity() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector._Myvec._Myfirst()" << " > " << test_vector._Myvec._Myfirst() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector._Myvec._Myend()" << " > " << test_vector._Myvec._Myend() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector.begin()._Myptr" << " > " << test_vector.begin()._Myptr << r2::linefeed;
			}

			std::cout << r2::split;

			{
				test_vector.reserve( 33 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "test_vector.reserve( 33 );" << r2::linefeed2;
				std::cout << r2::tab2 << "test_vector.capacity()" << " > " << test_vector.capacity() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector._Myvec.capacity()" << " > " << test_vector._Myvec.capacity() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector._Myvec._Myfirst()" << " > " << test_vector._Myvec._Myfirst() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector._Myvec._Myend()" << " > " << test_vector._Myvec._Myend() << r2::linefeed;
				std::cout << r2::tab2 << "test_vector.begin()._Myptr" << " > " << test_vector.begin()._Myptr << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT OthersIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Others Iterator";
		};
	}
	r2cm::iItem::DoFuncT OthersIterator::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::vector<int> container_1 = { 1, 2, 3 };
			std::vector<int> container_2 = { 10, 20, 30 };

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::vector<int> container_1 = { 1, 2, 3 };" << r2::linefeed;
				std::cout << r2::tab2 << "std::vector<int> container_2 = { 10, 20, 30 };" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				//auto itr_from_container_1 = container_1.begin();
				//container_2.erase( itr_from_container_1 );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "auto itr_from_container_1 = container_1.begin();" << r2::linefeed;
				std::cout << r2::tab2 << "container_2.erase( itr_from_container_1 );" << r2::linefeed2;

				std::cout << r2::tab << "## Not Working" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : End Iterator";
		};
	}
	r2cm::iItem::DoFuncT EndIterator::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::vector<int> container_1 = { 1, 2, 3 };

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "std::vector<int> container_1 = { 1, 2, 3 };" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process : operator*" << r2::linefeed2;
				std::cout << r2::tab2 << "auto cur = container_1.end();" << r2::linefeed2;

				std::cout << r2::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2::linefeed2;

#if !defined( DEBUG ) && !defined( _DEBUG )
				auto cur = container_1.end();

				std::cout << r2::tab2 << "( *cur );" << " > " << ( *cur ) << r2::linefeed;
#endif
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process : operator++" << r2::linefeed2;
				std::cout << r2::tab2 << "auto cur = container_1.end();" << r2::linefeed;
				std::cout << r2::tab2 << "++cur;" << r2::linefeed2;

				std::cout << r2::tab << "## Not Working In Debug Mode : _STL_VERIFY" << r2::linefeed2;

#if !defined( DEBUG ) && !defined( _DEBUG )
				auto cur = container_1.end();
				++cur;

				std::cout << r2::tab2 << "( *cur );" << " > " << ( *cur ) << r2::linefeed;
#endif
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process : operator--" << r2::linefeed2;
				std::cout << r2::tab2 << "auto cur = container_1.end();" << r2::linefeed;
				std::cout << r2::tab2 << "--cur;" << r2::linefeed2;

				auto cur = container_1.end();
				--cur;

				std::cout << r2::tab2 << "( *cur );" << " > " << ( *cur ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}