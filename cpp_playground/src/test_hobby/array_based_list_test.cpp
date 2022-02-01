#include "pch.h"
#include "array_based_list_test.h"

#include "base/r2_eTestResult.h"
#include "r2/r2_ArrayBasedList.h"
#include "r2/r2_Point.h"

namespace array_based_list_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 10> ablist;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::ArrayBasedList<int, 10> ablist" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Method : GetRestNodeCount" << r2::linefeed2;
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				ablist.PushFront( 11 );
				ablist.PushFront( 22 );
				ablist.PushFront( 33 );
				ablist.PushFront( 44 );

				std::cout << r2::tab << "+ Method : PushFront" << r2::linefeed2;
				std::cout << r2::tab2 << "ablist.PushFront( 11 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushFront( 22 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushFront( 33 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushFront( 44 );" << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ View With ArrayBasedList::begin(), ArrayBasedList::end()" << r2::linefeed2;

				for( auto cur = ablist.begin(), end = ablist.end(); end != cur; ++cur )
				{
					std::cout << r2::tab2 << "> " << ( *cur ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Method : Size" << r2::linefeed2;
				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				ablist.Clear();

				std::cout << r2::tab << "+ Method : Clear" << r2::linefeed2;
				std::cout << r2::tab2 << "ablist.Clear();" << r2::linefeed2;
				
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc PushBack::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : PushBack";
		};
	}
	r2::iTest::DoFunc PushBack::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 10> ablist;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::ArrayBasedList<int, 10> ablist" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				ablist.PushBack( 11 );
				ablist.PushBack( 22 );
				ablist.PushBack( 33 );
				ablist.PushBack( 44 );

				std::cout << r2::tab << "+ Method : PushBack" << r2::linefeed2;
				std::cout << r2::tab2 << "ablist.PushBack( 11 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 22 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 33 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 44 );" << r2::linefeed2;

				std::cout << r2::tab << "+ View" << r2::linefeed2;
				for( const auto& cur : ablist )
				{
					std::cout << r2::tab2 << "> " << cur << r2::linefeed;
				}
				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Erase::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Erase";
		};
	}
	r2::iTest::DoFunc Erase::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 5> ablist;
			ablist.PushBack( 11 );
			ablist.PushBack( 22 );
			ablist.PushBack( 33 );

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::ArrayBasedList<int, 5> ablist" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 11 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 22 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 33 );" << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto target_itr = ablist.begin();
				++target_itr;
				target_itr = ablist.Erase( target_itr );

				std::cout << r2::tab << "+ Method : Erase" << r2::linefeed2;
				std::cout << r2::tab2 << "auto target_itr = ablist.begin();" << r2::linefeed;
				std::cout << r2::tab2 << "++target_itr;" << r2::linefeed;
				std::cout << r2::tab2 << "target_itr = ablist.Erase( target_itr );" << r2::linefeed2;

				std::cout << r2::tab << "+ View" << r2::linefeed2;
				for( const auto& cur : ablist )
				{
					std::cout << r2::tab2 << "> " << cur << r2::linefeed;
				}
				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				for( int i = 0, end = ablist.GetRestNodeCount(); end > i; ++i )
				{
					ablist.PushBack( i );
				}

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "for( int i = 0, end = ablist.GetRestNodeCount(); end > i; ++i )" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "ablist.PushBack( i );" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed2;

				std::cout << r2::tab << "+ View" << r2::linefeed2;
				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;
				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}


	// REF : https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
	r2::iTest::TitleFunc IteratorOperator_Indirection_StructureDereference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Iterator : operator*, operator->";
		};
	}
	r2::iTest::DoFunc IteratorOperator_Indirection_StructureDereference::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<r2::Point, 5> ablist;
			ablist.PushBack( { 11, 12 } );

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::ArrayBasedList<r2::Point, 5> ablist;" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( { 11, 12 } );" << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto target_itr = ablist.begin();

				std::cout << r2::tab << "+ List Iterator Operator : *" << r2::linefeed2;
				std::cout << r2::tab2 << "auto target_itr = ablist.begin();" << r2::linefeed;
				std::cout << r2::tab2 << "( *target_itr ).x;" << " > " << ( *target_itr ).x << r2::linefeed;
				std::cout << r2::tab2 << "( *target_itr ).y;" << " > " << ( *target_itr ).y << r2::linefeed;
			}

			std::cout << r2::split;

			{
				auto target_itr = ablist.begin();

				std::cout << r2::tab << "+ List Iterator Operator : ->" << r2::linefeed2;
				std::cout << r2::tab2 << "auto target_itr = ablist.begin();" << r2::linefeed;
				std::cout << r2::tab2 << "target_itr->x;" << " > " << target_itr->x << r2::linefeed;
				std::cout << r2::tab2 << "target_itr->y;" << " > " << target_itr->y << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc RBegin_REnd::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : rbegin(), rend()";
		};
	}
	r2::iTest::DoFunc RBegin_REnd::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 5> ablist;
			ablist.PushBack( 11 );
			ablist.PushBack( 22 );
			ablist.PushBack( 33 );

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::ArrayBasedList<int, 5> ablist" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 11 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 22 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 33 );" << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << r2::tab << ">" << r2::tab << ablist.Size() << r2::linefeed;
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << r2::tab << ">" << r2::tab << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ View" << r2::linefeed2;
				for( const auto& cur : ablist )
				{
					std::cout << r2::tab2 << "> " << cur << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ View With ArrayBasedList::rbegin(), ArrayBasedList::rend()" << r2::linefeed2;

				for( auto cur = ablist.rbegin(), end = ablist.rend(); end != cur; ++cur )
				{
					std::cout << r2::tab2 << "> " << ( *cur ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}