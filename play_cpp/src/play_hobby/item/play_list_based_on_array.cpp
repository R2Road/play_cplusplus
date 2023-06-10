#include "play_list_based_on_array.h"

#include "r2/r2_ListBasedOnArray.h"
#include "r2/r2_PointInt.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace play_list_based_on_array
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 10> list;

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 10> list" << r2tm::linefeed;
			}

			LS();

			{
				EXPECT_EQ( list.GetRestNodeCount(), 10 );
				EXPECT_EQ( list.Size(), 0 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PushFront::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "PushFront";
		};
	}
	r2tm::DoFunctionT PushFront::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 5> list;

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 5> list" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::PushFront" << r2tm::linefeed2;

				list.PushFront( 11 );
				std::cout << r2tm::tab << "list.PushFront( 11 );" << r2tm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 4 );
				EXPECT_EQ( list.Size(), 1 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 22 );
				std::cout << r2tm::tab << "list.PushFront( 22 );" << r2tm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 33 );
				list.PushFront( 44 );
				list.PushFront( 55 );
				std::cout << r2tm::tab << "list.PushFront( 33 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushFront( 44 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushFront( 55 );" << r2tm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 5 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 66 );
				std::cout << r2tm::tab << "list.PushFront( 66 );" << r2tm::linefeed2;
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 5 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	// REF : https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
	r2tm::TitleFunctionT IteratorOperator_Indirection_StructureDereference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Iterator : operator*, operator->";
		};
	}
	r2tm::DoFunctionT IteratorOperator_Indirection_StructureDereference::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListNode<r2::PointInt> node{ { 11, 12 }, nullptr, nullptr };
			r2::ListIterator<r2::PointInt> itr( &node );

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListNode<r2::Point> node{ { 11, 12 }, nullptr, nullptr };" << r2tm::linefeed;
				std::cout << r2tm::tab << "r2::ListIterator<r2::Point> itr( &node );" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "+ List Iterator Operator : *" << r2tm::linefeed2;

				EXPECT_EQ( ( *itr ).GetX(), 11 );
				EXPECT_EQ( ( *itr ).GetY(), 12 );
			}

			LS();

			{
				std::cout << "+ List Iterator Operator : ->" << r2tm::linefeed2;

				EXPECT_EQ( itr->GetX(), 11 );
				EXPECT_EQ( itr->GetY(), 12 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT EndIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "End Iterator";
		};
	}
	r2tm::DoFunctionT EndIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 10> list;

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 10> list" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::End" << r2tm::linefeed2;

				auto end_itr = list.end();
				std::cout << r2tm::tab << "auto end_itr = list.end();" << r2tm::linefeed2;

				EXPECT_NE( end_itr.mTargetNode, nullptr );
				EXPECT_NE( end_itr.mTargetNode->pPrev, nullptr );
				EXPECT_NE( end_itr.mTargetNode->pNext, nullptr );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( end_itr.mTargetNode->pPrev, end_itr.mTargetNode );
				EXPECT_EQ( end_itr.mTargetNode->pNext, end_itr.mTargetNode );
			}

			LS();

			{
				std::cout << "+ Iterator : Operator--" << r2tm::linefeed2;

				EXPECT_TRUE( ( --list.end() ) == list.end() );
			}

			LS();

			{
				std::cout << "+ Iterator : Operator++" << r2tm::linefeed2;

				EXPECT_TRUE( ( ++list.end() ) == list.end() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT BeginIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Begin Iterator";
		};
	}
	r2tm::DoFunctionT BeginIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 3> list;

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 3> list" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::Begin" << r2tm::linefeed2;

				list.PushFront( 11 );
				std::cout << r2tm::tab << "list.PushFront( 11 );" << r2tm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 11 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 22 );
				std::cout << r2tm::tab << "list.PushFront( 22 );" << r2tm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 22 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 33 );
				std::cout << r2tm::tab << "list.PushFront( 33 );" << r2tm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 33 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 44 );
				std::cout << r2tm::tab << "list.PushFront( 44 );" << r2tm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 33 );
			}

			LS();

			{
				auto itr = list.begin();
				std::cout << r2tm::tab << "auto itr = list.begin();" << r2tm::linefeed2;

				EXPECT_EQ( *itr, 33 );
				EXPECT_EQ( *( ++itr ), 22 );
				EXPECT_EQ( *( ++itr ), 11 );
				EXPECT_TRUE( ( ++itr ) == list.end() );
				EXPECT_TRUE( ( ++itr ) == list.begin() );
			}

			LS();

			{
				auto itr = list.begin();
				std::cout << r2tm::tab << "auto itr = list.begin();" << r2tm::linefeed2;

				EXPECT_TRUE( ( --itr ) == list.end() );
				EXPECT_EQ( *( --itr ), 11 );
				EXPECT_EQ( *( --itr ), 22 );
				EXPECT_EQ( *( --itr ), 33 );
				EXPECT_TRUE( ( --itr ) == list.end() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Clear::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Clear";
		};
	}
	r2tm::DoFunctionT Clear::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 3> list;
			list.PushFront( 11 );
			list.PushFront( 22 );
			list.PushFront( 33 );

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 3> list" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushFront( 11 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushFront( 22 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushFront( 33 );" << r2tm::linefeed;
			}

			LS();

			{
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::Clear" << r2tm::linefeed2;

				list.Clear();
				std::cout << r2tm::tab << "list.Clear();" << r2tm::linefeed2;

				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 0 );
			}

			LS();

			{
				list.PushFront( 111 );
				std::cout << r2tm::tab << "list.PushFront( 111 );" << r2tm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 111 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 222 );
				std::cout << r2tm::tab << "list.PushFront( 222 );" << r2tm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 222 );

				std::cout << r2tm::linefeed2;

				list.PushFront( 333 );
				std::cout << r2tm::tab << "list.PushFront( 333 );" << r2tm::linefeed2;
				EXPECT_EQ( ( *list.begin() ), 333 );
			}

			LS();

			{
				auto itr = list.begin();
				std::cout << r2tm::tab << "auto itr = list.begin();" << r2tm::linefeed2;

				EXPECT_EQ( *itr, 333 );
				EXPECT_EQ( *( ++itr ), 222 );
				EXPECT_EQ( *( ++itr ), 111 );
				EXPECT_TRUE( ( ++itr ) == list.end() );
				EXPECT_TRUE( ( ++itr ) == list.begin() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PushBack::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "PushBack";
		};
	}
	r2tm::DoFunctionT PushBack::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 3> list;

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 3> list" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::PushBack" << r2tm::linefeed2;

				list.PushBack( 11 );
				std::cout << r2tm::tab << "list.PushBack( 11 );" << r2tm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( --list.end() ), 11 );
				EXPECT_EQ( list.GetRestNodeCount(), 2 );
				EXPECT_EQ( list.Size(), 1 );				

				std::cout << r2tm::linefeed2;

				list.PushBack( 22 );
				std::cout << r2tm::tab << "list.PushBack( 22 );" << r2tm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( --list.end() ), 22 );
				EXPECT_EQ( list.GetRestNodeCount(), 1 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2tm::linefeed2;

				list.PushBack( 33 );
				std::cout << r2tm::tab << "list.PushBack( 33 );" << r2tm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( ++( ++list.begin() ) ), 33 );
				EXPECT_EQ( *( --list.end() ), 33 );
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );

				std::cout << r2tm::linefeed2;

				list.PushBack( 44 );
				std::cout << r2tm::tab << "list.PushBack( 44 );" << r2tm::linefeed2;
				EXPECT_EQ( *list.begin(), 11 );
				EXPECT_EQ( *( ++list.begin() ), 22 );
				EXPECT_EQ( *( ++( ++list.begin() ) ), 33 );
				EXPECT_TRUE( ++( ++( ++list.begin() ) ) == list.end() );
				EXPECT_EQ( *( --list.end() ), 33 );
				EXPECT_EQ( list.GetRestNodeCount(), 0 );
				EXPECT_EQ( list.Size(), 3 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Erase::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Erase";
		};
	}
	r2tm::DoFunctionT Erase::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 5> list;
			list.PushBack( 11 );
			list.PushBack( 22 );
			list.PushBack( 33 );

			{
				std::cout << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 5> list" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushBack( 11 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushBack( 22 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushBack( 33 );" << r2tm::linefeed;
			}

			LS();

			{
				EXPECT_EQ( list.GetRestNodeCount(), 2 );
				EXPECT_EQ( list.Size(), 3 );
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::Erase" << r2tm::linefeed2;

				auto return_itr = list.Erase( ++list.begin() );
				auto copied_itr = return_itr;
				std::cout << r2tm::tab << "auto return_itr = list.Erase( ( ++list.begin() ) );" << r2tm::linefeed;
				std::cout << r2tm::tab << "auto copied_itr = return_itr;" << r2tm::linefeed2;
				
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( *return_itr, 33 );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( *( --return_itr ), 11 );
				EXPECT_TRUE( ( --return_itr ) == list.end() );
				EXPECT_EQ( *( --return_itr ), 33 );

				std::cout << r2tm::linefeed;

				EXPECT_TRUE( ( ++copied_itr ) == list.end() );
				EXPECT_EQ( *( ++copied_itr ), 11 );
				EXPECT_EQ( *( ++copied_itr ), 33 );				
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::Erase : Erase End" << r2tm::linefeed2;

				auto return_itr = list.Erase( list.end() );
				std::cout << r2tm::tab << "auto return_itr = list.Erase( list.end() );" << r2tm::linefeed2;

				EXPECT_TRUE( return_itr == list.end() );
				EXPECT_EQ( list.GetRestNodeCount(), 3 );
				EXPECT_EQ( list.Size(), 2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT RBegin_REnd::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "rbegin(), rend()";
		};
	}
	r2tm::DoFunctionT RBegin_REnd::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			r2::ListBasedOnArray<int, 5> list;
			list.PushBack( 11 );
			list.PushBack( 22 );
			list.PushBack( 33 );

			{
				std::cout  << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab << "r2::ListBasedOnArray<int, 5> list" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushBack( 11 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushBack( 22 );" << r2tm::linefeed;
				std::cout << r2tm::tab << "list.PushBack( 33 );" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "+ r2::ListBasedOnArray::rbegin(), ListBasedOnArray::rend()" << r2tm::linefeed2;

				EXPECT_NE( list.rend().mTargetNode, nullptr );
				EXPECT_NE( list.rend().mTargetNode->pPrev, nullptr );
				EXPECT_NE( list.rend().mTargetNode->pNext, nullptr );
				EXPECT_EQ( list.rend().mTargetNode, list.end().mTargetNode );

				std::cout << r2tm::linefeed;
				
				EXPECT_EQ( *list.rbegin(), 33 );
				EXPECT_EQ( *( ++list.rbegin() ), 22 );
				EXPECT_EQ( *( ++( ++list.rbegin() ) ), 11 );
				EXPECT_TRUE( ( ++( ++( ++list.rbegin() ) ) ) == list.rend() );
				EXPECT_TRUE( ( ++( ++( ++( ++list.rbegin() ) ) ) ) == list.rbegin() );

				std::cout << r2tm::linefeed;

				EXPECT_TRUE( ( --list.rbegin() ) == list.rend() );
				EXPECT_EQ( *( --( --list.rbegin() ) ), 11 );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( *( ++list.rend() ), 33 );
				EXPECT_EQ( *( --list.rend() ), 11 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}