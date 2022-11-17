#include "list_based_on_array_test.h"

#include "r2/r2_ListBasedOnArray.h"
#include "r2/r2_PointInt.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace list_based_on_array_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 10> list;

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 10> list" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( list.GetRestNodeCount(), 10 );
				EXPECT_EQ( list.Size(), 0 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PushFront::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "PushFront";
		};
	}
	r2cm::iItem::DoFunctionT PushFront::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 5> list;

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 5> list" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::PushFront" << r2cm::linefeed2;

				list.PushFront( 11 );
				std::cout << r2cm::tab << "list.PushFront( 11 );" << r2cm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 4 );
				EXPECT_EQ( list.Size(), 1 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 22 );
				std::cout << r2cm::tab << "list.PushFront( 22 );" << r2cm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 33 );
				list.PushFront( 44 );
				list.PushFront( 55 );
				std::cout << r2cm::tab << "list.PushFront( 33 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushFront( 44 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushFront( 55 );" << r2cm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 5 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 66 );
				std::cout << r2cm::tab << "list.PushFront( 66 );" << r2cm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 5 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	// REF : https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
	r2cm::iItem::TitleFunctionT IteratorOperator_Indirection_StructureDereference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Iterator : operator*, operator->";
		};
	}
	r2cm::iItem::DoFunctionT IteratorOperator_Indirection_StructureDereference::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListNode<r2::PointInt> node{ { 11, 12 }, nullptr, nullptr };
			r2::ListIterator<r2::PointInt> itr( &node );

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListNode<r2::Point> node{ { 11, 12 }, nullptr, nullptr };" << r2cm::linefeed;
				std::cout << r2cm::tab << "r2::ListIterator<r2::Point> itr( &node );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ List Iterator Operator : *" << r2cm::linefeed2;

				EXPECT_EQ( ( *itr ).GetX(), 11 );
				EXPECT_EQ( ( *itr ).GetY(), 12 );
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ List Iterator Operator : ->" << r2cm::linefeed2;

				EXPECT_EQ( itr->GetX(), 11 );
				EXPECT_EQ( itr->GetY(), 12 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "End Iterator";
		};
	}
	r2cm::iItem::DoFunctionT EndIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 10> list;

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 10> list" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::End" << r2cm::linefeed2;

				auto end_itr = list.end();
				std::cout << r2cm::tab << "auto end_itr = list.end();" << r2cm::linefeed2;

				EXPECT_NE( end_itr.mTargetNode, nullptr );
				EXPECT_NE( end_itr.mTargetNode->pPrev, nullptr );
				EXPECT_NE( end_itr.mTargetNode->pNext, nullptr );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( end_itr.mTargetNode->pPrev, end_itr.mTargetNode );
				EXPECT_EQ( end_itr.mTargetNode->pNext, end_itr.mTargetNode );
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ Iterator : Operator--" << r2cm::linefeed2;

				EXPECT_TRUE( ( --list.end() ) == list.end() );
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ Iterator : Operator++" << r2cm::linefeed2;

				EXPECT_TRUE( ( ++list.end() ) == list.end() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT BeginIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Begin Iterator";
		};
	}
	r2cm::iItem::DoFunctionT BeginIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 3> list;

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 3> list" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::Begin" << r2cm::linefeed2;

				list.PushFront( 11 );
				std::cout << r2cm::tab << "list.PushFront( 11 );" << r2cm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 11 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 22 );
				std::cout << r2cm::tab << "list.PushFront( 22 );" << r2cm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 22 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 33 );
				std::cout << r2cm::tab << "list.PushFront( 33 );" << r2cm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 33 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 44 );
				std::cout << r2cm::tab << "list.PushFront( 44 );" << r2cm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 33 );
			}

			std::cout << r2cm::split;

			{
				auto itr = list.begin();
				std::cout << r2cm::tab << "auto itr = list.begin();" << r2cm::linefeed2;

				EXPECT_EQ( *itr, 33 );
				EXPECT_EQ( *( ++itr ), 22 );
				EXPECT_EQ( *( ++itr ), 11 );
				EXPECT_TRUE( ( ++itr ) == list.end() );
				EXPECT_TRUE( ( ++itr ) == list.begin() );
			}

			std::cout << r2cm::split;

			{
				auto itr = list.begin();
				std::cout << r2cm::tab << "auto itr = list.begin();" << r2cm::linefeed2;

				EXPECT_TRUE( ( --itr ) == list.end() );
				EXPECT_EQ( *( --itr ), 11 );
				EXPECT_EQ( *( --itr ), 22 );
				EXPECT_EQ( *( --itr ), 33 );
				EXPECT_TRUE( ( --itr ) == list.end() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Clear";
		};
	}
	r2cm::iItem::DoFunctionT Clear::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 3> list;
			list.PushFront( 11 );
			list.PushFront( 22 );
			list.PushFront( 33 );

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 3> list" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushFront( 11 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushFront( 22 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushFront( 33 );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::Clear" << r2cm::linefeed2;

				list.Clear();
				std::cout << r2cm::tab << "list.Clear();" << r2cm::linefeed2;

				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 0 );
			}

			std::cout << r2cm::split;

			{
				list.PushFront( 111 );
				std::cout << r2cm::tab << "list.PushFront( 111 );" << r2cm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 111 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 222 );
				std::cout << r2cm::tab << "list.PushFront( 222 );" << r2cm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 222 );

				std::cout << r2cm::linefeed2;

				list.PushFront( 333 );
				std::cout << r2cm::tab << "list.PushFront( 333 );" << r2cm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 333 );
			}

			std::cout << r2cm::split;

			{
				auto itr = list.begin();
				std::cout << r2cm::tab << "auto itr = list.begin();" << r2cm::linefeed2;

				EXPECT_EQ( *itr, 333 );
				EXPECT_EQ( *( ++itr ), 222 );
				EXPECT_EQ( *( ++itr ), 111 );
				EXPECT_TRUE( ( ++itr ) == list.end() );
				EXPECT_TRUE( ( ++itr ) == list.begin() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PushBack::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "PushBack";
		};
	}
	r2cm::iItem::DoFunctionT PushBack::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 3> list;

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 3> list" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::PushBack" << r2cm::linefeed2;

				list.PushBack( 11 );
				std::cout << r2cm::tab << "list.PushBack( 11 );" << r2cm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( --list.end() ), 11 );
				EXPECT_EQ( list.GetRestNodeCount(), 2 );
				EXPECT_EQ( list.Size(), 1 );				

				std::cout << r2cm::linefeed2;

				list.PushBack( 22 );
				std::cout << r2cm::tab << "list.PushBack( 22 );" << r2cm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( --list.end() ), 22 );
				EXPECT_EQ( list.GetRestNodeCount(), 1 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2cm::linefeed2;

				list.PushBack( 33 );
				std::cout << r2cm::tab << "list.PushBack( 33 );" << r2cm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( ++( ++list.begin() ) ), 33 );
				EXPECT_EQ( *( --list.end() ), 33 );
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );

				std::cout << r2cm::linefeed2;

				list.PushBack( 44 );
				std::cout << r2cm::tab << "list.PushBack( 44 );" << r2cm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( ++( ++list.begin() ) ), 33 );
				EXPECT_TRUE( ++( ++( ++list.begin() ) ) == list.end() );
				EXPECT_EQ( *( --list.end() ), 33 );
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Erase::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Erase";
		};
	}
	r2cm::iItem::DoFunctionT Erase::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 5> list;
			list.PushBack( 11 );
			list.PushBack( 22 );
			list.PushBack( 33 );

			{
				std::cout << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 5> list" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushBack( 11 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushBack( 22 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushBack( 33 );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				EXPECT_EQ( list.GetRestNodeCount(), 2 );
				EXPECT_EQ( list.Size(), 3 );
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::Erase" << r2cm::linefeed2;

				auto return_itr = list.Erase( ++list.begin() );
				auto copied_itr = return_itr;
				std::cout << r2cm::tab << "auto return_itr = list.Erase( ( ++list.begin() ) );" << r2cm::linefeed;
				std::cout << r2cm::tab << "auto copied_itr = return_itr;" << r2cm::linefeed2;
				
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( *return_itr, 33 );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( *( --return_itr ), 11 );
				EXPECT_TRUE( ( --return_itr ) == list.end() );
				EXPECT_EQ( *( --return_itr ), 33 );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( ( ++copied_itr ) == list.end() );
				EXPECT_EQ( *( ++copied_itr ), 11 );
				EXPECT_EQ( *( ++copied_itr ), 33 );				
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::Erase : Erase End" << r2cm::linefeed2;

				auto return_itr = list.Erase( list.end() );
				std::cout << r2cm::tab << "auto return_itr = list.Erase( list.end() );" << r2cm::linefeed2;

				EXPECT_TRUE( return_itr == list.end() );
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT RBegin_REnd::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "rbegin(), rend()";
		};
	}
	r2cm::iItem::DoFunctionT RBegin_REnd::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			r2::ListBasedOnArray<int, 5> list;
			list.PushBack( 11 );
			list.PushBack( 22 );
			list.PushBack( 33 );

			{
				std::cout  << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab << "r2::ListBasedOnArray<int, 5> list" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushBack( 11 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushBack( 22 );" << r2cm::linefeed;
				std::cout << r2cm::tab << "list.PushBack( 33 );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "+ r2::ListBasedOnArray::rbegin(), ListBasedOnArray::rend()" << r2cm::linefeed2;

				EXPECT_NE( list.rend().mTargetNode, nullptr );
				EXPECT_NE( list.rend().mTargetNode->pPrev, nullptr );
				EXPECT_NE( list.rend().mTargetNode->pNext, nullptr );
				EXPECT_EQ( list.rend().mTargetNode, list.end().mTargetNode );

				std::cout << r2cm::linefeed;
				
				EXPECT_EQ( *list.rbegin(), 33 );
				EXPECT_EQ( *( ++list.rbegin() ), 22 );
				EXPECT_EQ( *( ++( ++list.rbegin() ) ), 11 );
				EXPECT_TRUE( ( ++( ++( ++list.rbegin() ) ) ) == list.rend() );
				EXPECT_TRUE( ( ++( ++( ++( ++list.rbegin() ) ) ) ) == list.rbegin() );

				std::cout << r2cm::linefeed;

				EXPECT_TRUE( ( --list.rbegin() ) == list.rend() );
				EXPECT_EQ( *( --( --list.rbegin() ) ), 11 );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( *( ++list.rend() ), 33 );
				EXPECT_EQ( *( --list.rend() ), 11 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}