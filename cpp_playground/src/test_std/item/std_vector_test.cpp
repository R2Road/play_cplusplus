#include "std_vector_test.h"

#include <vector>

#include "r2cm/r2cm_ostream.h"

namespace std_vector_test
{
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
				std::cout << r2cm::tab << "+ Resize" << r2cm::linefeed2;

				std::vector<int> test_vector = { 1, 2, 3, 4 };
				std::cout << r2cm::tab2 << "std::vector<int> test_vector = { 1, 2, 3, 4 };" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2cm::linefeed2;

				test_vector.resize( 10 );
				std::cout << r2cm::tab2 << "test_vector.resize( 10 );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2cm::linefeed2;

				test_vector.resize( 2 );
				std::cout << r2cm::tab2 << "test_vector.resize( 2 );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2cm::linefeed2;

				test_vector.resize( 20 );
				std::cout << r2cm::tab2 << "test_vector.resize( 10 );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- Print : ";
				for( const auto i : test_vector )
				{
					std::cout << i;
				}

				std::cout << r2cm::linefeed;
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