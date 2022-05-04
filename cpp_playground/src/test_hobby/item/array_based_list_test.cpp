#include "pch.h"
#include "array_based_list_test.h"

#include "base/r2cm_eTestEndAction.h"
#include "r2/r2_ArrayBasedList.h"
#include "r2/r2_Inspector.h"
#include "r2/r2_PointInt.h"

namespace array_based_list_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PushFront::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : PushFront";
		};
	}
	r2cm::iItem::DoFuncT PushFront::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	// REF : https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
	r2cm::iItem::TitleFuncT IteratorOperator_Indirection_StructureDereference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Iterator : operator*, operator->";
		};
	}
	r2cm::iItem::DoFuncT IteratorOperator_Indirection_StructureDereference::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ListNode<r2::PointInt> node{ { 11, 12 }, nullptr, nullptr };
			r2::ListIterator<r2::PointInt> itr( &node );

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ListNode<r2::Point> node{ { 11, 12 }, nullptr, nullptr };" << r2::linefeed;
				std::cout << r2::tab << "r2::ListIterator<r2::Point> itr( &node );" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ List Iterator Operator : *" << r2::linefeed2;

				EXPECT_EQ( ( *itr ).GetX(), 11 );
				EXPECT_EQ( ( *itr ).GetY(), 12 );
			}

			std::cout << r2::split;

			{
				std::cout << "+ List Iterator Operator : ->" << r2::linefeed2;

				EXPECT_EQ( itr->GetX(), 11 );
				EXPECT_EQ( itr->GetY(), 12 );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : End Iterator";
		};
	}
	r2cm::iItem::DoFuncT EndIterator::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT BeginIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Begin Iterator";
		};
	}
	r2cm::iItem::DoFuncT BeginIterator::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Clear";
		};
	}
	r2cm::iItem::DoFuncT Clear::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PushBack::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : PushBack";
		};
	}
	r2cm::iItem::DoFuncT PushBack::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Erase::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : Erase";
		};
	}
	r2cm::iItem::DoFuncT Erase::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 5> list;
			list.PushBack( 11 );
			list.PushBack( 22 );
			list.PushBack( 33 );

			{
				std::cout << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 5> list" << r2::linefeed;
				std::cout << r2::tab << "list.PushBack( 11 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushBack( 22 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushBack( 33 );" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				EXPECT_EQ( list.GetRestNodeCount(), 2 );
				EXPECT_EQ( list.Size(), 3 );
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::Erase" << r2::linefeed2;

				auto return_itr = list.Erase( ++list.begin() );
				auto copied_itr = return_itr;
				std::cout << r2::tab << "auto return_itr = list.Erase( ( ++list.begin() ) );" << r2::linefeed;
				std::cout << r2::tab << "auto copied_itr = return_itr;" << r2::linefeed2;
				
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2::linefeed;

				EXPECT_EQ( *return_itr, 33 );

				std::cout << r2::linefeed;

				EXPECT_EQ( *( --return_itr ), 11 );
				EXPECT_EQ( ( --return_itr ), list.end() );
				EXPECT_EQ( *( --return_itr ), 33 );

				std::cout << r2::linefeed;

				EXPECT_EQ( ( ++copied_itr ), list.end() );
				EXPECT_EQ( *( ++copied_itr ), 11 );
				EXPECT_EQ( *( ++copied_itr ), 33 );				
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::Erase : Erase End" << r2::linefeed2;

				auto return_itr = list.Erase( list.end() );
				std::cout << r2::tab << "auto return_itr = list.Erase( list.end() );" << r2::linefeed2;

				EXPECT_EQ( return_itr, list.end() );
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT RBegin_REnd::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array Based List : rbegin(), rend()";
		};
	}
	r2cm::iItem::DoFuncT RBegin_REnd::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			r2::ArrayBasedList<int, 5> list;
			list.PushBack( 11 );
			list.PushBack( 22 );
			list.PushBack( 33 );

			{
				std::cout  << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab << "r2::ArrayBasedList<int, 5> list" << r2::linefeed;
				std::cout << r2::tab << "list.PushBack( 11 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushBack( 22 );" << r2::linefeed;
				std::cout << r2::tab << "list.PushBack( 33 );" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "+ r2::ArrayBasedList::rbegin(), ArrayBasedList::rend()" << r2::linefeed2;

				EXPECT_NE( list.rend().mTargetNode, nullptr );
				EXPECT_NE( list.rend().mTargetNode->pPrev, nullptr );
				EXPECT_NE( list.rend().mTargetNode->pNext, nullptr );
				EXPECT_EQ( list.rend().mTargetNode, list.end().mTargetNode );

				std::cout << r2::linefeed;
				
				EXPECT_EQ( *list.rbegin(), 33 );
				EXPECT_EQ( *( ++list.rbegin() ), 22 );
				EXPECT_EQ( *( ++( ++list.rbegin() ) ), 11 );
				EXPECT_EQ( ( ++( ++( ++list.rbegin() ) ) ), list.rend() );
				EXPECT_EQ( ( ++( ++( ++( ++list.rbegin() ) ) ) ), list.rbegin() );

				std::cout << r2::linefeed;

				EXPECT_EQ( ( --list.rbegin() ), list.rend() );
				EXPECT_EQ( *( --( --list.rbegin() ) ), 11 );

				std::cout << r2::linefeed;

				EXPECT_EQ( *( ++list.rend() ), 33 );
				EXPECT_EQ( *( --list.rend() ), 11 );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}