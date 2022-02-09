#include "pch.h"
#include "array_based_list_test.h"

#include "base/r2_eTestResult.h"
#include "r2/r2_ArrayBasedList.h"
#include "r2/r2_Point.h"

#include "base/r2_Inspector.h"

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

			r2::ArrayBasedList<int, 10> list;

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 10> list" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				EXPECT_EQ( list.GetRestNodeCount(), 10 );
				EXPECT_EQ( list.Size(), 0 );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc PushFront::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : PushFront";
		};
	}
	r2::iTest::DoFunc PushFront::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 5> list;

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 5> list" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::PushFront" << r2::linefeed2;

				list.PushFront( 11 );
				std::cout << r2::tab << "list.PushFront( 11 );" << r2::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 4 );
				EXPECT_EQ( list.Size(), 1 );

				std::cout << r2::linefeed2;

				list.PushFront( 22 );
				std::cout << r2::tab << "list.PushFront( 22 );" << r2::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2::linefeed2;

				list.PushFront( 33 );
				list.PushFront( 44 );
				list.PushFront( 55 );
				std::cout << r2::tab << "list.PushFront( 33 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushFront( 44 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushFront( 55 );" << r2::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 5 );

				std::cout << r2::linefeed2;

				list.PushFront( 66 );
				std::cout << r2::tab << "list.PushFront( 66 );" << r2::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 5 );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : End Iterator";
		};
	}
	r2::iTest::DoFunc EndIterator::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 10> list;

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 10> list" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::End" << r2::linefeed2;

				auto end_itr = list.end();
				std::cout << r2::tab << "auto end_itr = list.end();" << r2::linefeed2;

				EXPECT_NE( end_itr.mTargetNode, nullptr );
				EXPECT_NE( end_itr.mTargetNode->pPrev, nullptr );
				EXPECT_NE( end_itr.mTargetNode->pNext, nullptr );

				std::cout << r2::linefeed;

				EXPECT_EQ( end_itr.mTargetNode->pPrev, end_itr.mTargetNode );
				EXPECT_EQ( end_itr.mTargetNode->pNext, end_itr.mTargetNode );
			}

			std::cout << r2::split;

			{
				std::cout << "+ Iterator : Operator--" << r2::linefeed2;

				EXPECT_EQ( ( --list.end() ), list.end() );
			}

			std::cout << r2::split;

			{
				std::cout << "+ Iterator : Operator++" << r2::linefeed2;

				EXPECT_EQ( ( ++list.end() ), list.end() );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc BeginIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Begin Iterator";
		};
	}
	r2::iTest::DoFunc BeginIterator::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 3> list;

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 3> list" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::Begin" << r2::linefeed2;

				list.PushFront( 11 );
				std::cout << r2::tab << "list.PushFront( 11 );" << r2::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 11 );

				std::cout << r2::linefeed2;

				list.PushFront( 22 );
				std::cout << r2::tab << "list.PushFront( 22 );" << r2::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 22 );

				std::cout << r2::linefeed2;

				list.PushFront( 33 );
				std::cout << r2::tab << "list.PushFront( 33 );" << r2::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 33 );

				std::cout << r2::linefeed2;

				list.PushFront( 44 );
				std::cout << r2::tab << "list.PushFront( 44 );" << r2::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 33 );
			}

			std::cout << r2::split;

			{
				auto itr = list.begin();
				std::cout << r2::tab << "auto itr = list.begin();" << r2::linefeed2;

				EXPECT_EQ( *itr, 33 );
				EXPECT_EQ( *( ++itr ), 22 );
				EXPECT_EQ( *( ++itr ), 11 );
				EXPECT_EQ( ( ++itr ), list.end() );
				EXPECT_EQ( ( ++itr ), list.begin() );
			}

			std::cout << r2::split;

			{
				auto itr = list.begin();
				std::cout << r2::tab << "auto itr = list.begin();" << r2::linefeed2;

				EXPECT_EQ( ( --itr ), list.end() );
				EXPECT_EQ( *( --itr ), 11 );
				EXPECT_EQ( *( --itr ), 22 );
				EXPECT_EQ( *( --itr ), 33 );
				EXPECT_EQ( ( --itr ), list.end() );
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
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<r2::Point, 5> ablist;" << r2::linefeed;
				std::cout << r2::tab << "ablist.PushBack( { 11, 12 } );" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ List Iterator Operator : *" << r2::linefeed2;

				EXPECT_EQ( ( *ablist.begin() ).x, 11 );
				EXPECT_EQ( ( *ablist.begin() ).y, 12 );
			}

			std::cout << r2::split;

			{
				std::cout << "+ List Iterator Operator : ->" << r2::linefeed2;
				
				EXPECT_EQ( ablist.begin()->x, 11 );
				EXPECT_EQ( ablist.begin()->y, 12 );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Clear";
		};
	}
	r2::iTest::DoFunc Clear::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 3> list;
			list.PushFront( 11 );
			list.PushFront( 22 );
			list.PushFront( 33 );

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 3> list" << r2::linefeed;
				std::cout << r2::tab << "list.PushFront( 11 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushFront( 22 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushFront( 33 );" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::Clear" << r2::linefeed2;

				list.Clear();
				std::cout << r2::tab << "list.Clear();" << r2::linefeed2;

				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 0 );
			}

			std::cout << r2::split;

			{
				list.PushFront( 111 );
				std::cout << r2::tab << "list.PushFront( 111 );" << r2::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 111 );

				std::cout << r2::linefeed2;

				list.PushFront( 222 );
				std::cout << r2::tab << "list.PushFront( 222 );" << r2::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 222 );

				std::cout << r2::linefeed2;

				list.PushFront( 333 );
				std::cout << r2::tab << "list.PushFront( 333 );" << r2::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 333 );
			}

			std::cout << r2::split;

			{
				auto itr = list.begin();
				std::cout << r2::tab << "auto itr = list.begin();" << r2::linefeed2;

				EXPECT_EQ( *itr, 333 );
				EXPECT_EQ( *( ++itr ), 222 );
				EXPECT_EQ( *( ++itr ), 111 );
				EXPECT_EQ( ( ++itr ), list.end() );
				EXPECT_EQ( ( ++itr ), list.begin() );
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

			r2::ArrayBasedList<int, 3> list;

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 3> list" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::PushBack" << r2::linefeed2;

				list.PushBack( 11 );
				std::cout << r2::tab << "list.PushBack( 11 );" << r2::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( --list.end() ), 11 );
				EXPECT_EQ( list.GetRestNodeCount(), 2 );
				EXPECT_EQ( list.Size(), 1 );				

				std::cout << r2::linefeed2;

				list.PushBack( 22 );
				std::cout << r2::tab << "list.PushBack( 22 );" << r2::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( --list.end() ), 22 );
				EXPECT_EQ( list.GetRestNodeCount(), 1 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2::linefeed2;

				list.PushBack( 33 );
				std::cout << r2::tab << "list.PushBack( 33 );" << r2::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( ++( ++list.begin() ) ), 33 );
				EXPECT_EQ( *( --list.end() ), 33 );
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );

				std::cout << r2::linefeed2;

				list.PushBack( 44 );
				std::cout << r2::tab << "list.PushBack( 44 );" << r2::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( ++( ++list.begin() ) ), 33 );
				EXPECT_EQ( ++( ++( ++list.begin() ) ), list.end() );
				EXPECT_EQ( *( --list.end() ), 33 );
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Erase_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Erase 1";
		};
	}
	r2::iTest::DoFunc Erase_1::GetDoFunction()
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

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
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

				std::cout << r2::tab << "+ View With Ranged For" << r2::linefeed2;
				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;
				
				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
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

				std::cout << r2::tab << "+ View With Ranged For" << r2::linefeed2;
				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;
				
				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Erase_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Erase 2";
		};
	}
	r2::iTest::DoFunc Erase_2::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 5> ablist;
			ablist.PushBack( 11 );
			ablist.PushBack( 22 );
			ablist.PushBack( 33 );

			auto target_itr = ablist.begin();
			++target_itr;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::ArrayBasedList<int, 5> ablist" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 11 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 22 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 33 );" << r2::linefeed2;

				std::cout << r2::tab2 << "auto target_itr = ablist.begin();" << r2::linefeed;
				std::cout << r2::tab2 << "++target_itr;" << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				target_itr = ablist.Erase( target_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "target_itr = ablist.Erase( target_itr );" << r2::linefeed2;

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				target_itr = ablist.Erase( target_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "target_itr = ablist.Erase( target_itr );" << r2::linefeed2;

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				target_itr = ablist.Erase( target_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "target_itr = ablist.Erase( target_itr );" << r2::linefeed2;

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Erase_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Erase 3";
		};
	}
	r2::iTest::DoFunc Erase_3::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 5> ablist;
			ablist.PushBack( 11 );
			ablist.PushBack( 22 );
			ablist.PushBack( 33 );

			auto target_itr = ablist.begin();

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "r2::ArrayBasedList<int, 5> ablist" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 11 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 22 );" << r2::linefeed;
				std::cout << r2::tab2 << "ablist.PushBack( 33 );" << r2::linefeed2;

				std::cout << r2::tab2 << "auto target_itr = ablist.begin();" << r2::linefeed2;

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				target_itr = ablist.Erase( target_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "target_itr = ablist.Erase( target_itr );" << r2::linefeed2;

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				target_itr = ablist.Erase( target_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "target_itr = ablist.Erase( target_itr );" << r2::linefeed2;

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				target_itr = ablist.Erase( target_itr );

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "target_itr = ablist.Erase( target_itr );" << r2::linefeed2;

				std::cout << r2::tab2;
				for( const auto& cur : ablist )
				{
					std::cout << "> " << cur << r2::tab;
				}
				std::cout << r2::linefeed2;

				std::cout << r2::tab2 << "ablist.Size();" << " > " << ablist.Size();
				std::cout << r2::tab2 << "ablist.GetRestNodeCount();" << " > " << ablist.GetRestNodeCount() << r2::linefeed;
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
				std::cout << r2::tab << "+ View With Ranged For" << r2::linefeed2;
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



	r2::iTest::TitleFunc ImprovedEndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : improved End Iterator";
		};
	}
	r2::iTest::DoFunc ImprovedEndIterator::GetDoFunction()
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
				std::cout << r2::tab << "+ View With ArrayBasedList::begin() And For( 10 > i )" << r2::linefeed2;
				auto cur = ablist.begin();
				for( int i = 0; 10 > i; ++i, ++cur )
				{
					std::cout << r2::tab2 << "> " << ( *cur ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ View With ArrayBasedList::rbegin() And For( 10 > i )" << r2::linefeed2;
				auto cur = ablist.rbegin();
				for( int i = 0; 10 > i; ++i, ++cur )
				{
					std::cout << r2::tab2 << "> " << ( *cur ) << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}