//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.05.07 AM.08.18
// # Version			: 1.0.0
//

#pragma once

#include "r2_list_node_allocator_based_on_array.hpp"
#include "r2_list_node_iterator.hpp"

#include "r2_assert.hpp"

namespace r2
{
	//
	// # Warning
	//
	// ValueT 로 std::shared_ptr 등을 사용하고 있다면 NodeCleaner 를 ListNodeCleaner_ClearValue 로 설정.
	//

	template<typename T, uint32_t N, typename NodeCleaner = ListNodeCleaner_StayValue<T>>
	class ListBasedOnArray
	{
	public:
		using ValueT = T;
		using SizeT = uint32_t;

		using NodeT = ListNode<ValueT>;
		using AllocatorT = ListNodeAllocatorBasedOnArray<ValueT, N + 1u, NodeCleaner>; // N + Head

		using IteratorT = ListNodeIterator<ValueT>;
		//using iterator = ListNodeIterator<ValueT>; // ...dev rule?
		using ConstIteratorT = ListNodeConstIterator<ValueT>;
		using ReverseIteratorT = ListNodeReverseIterator<ValueT>;
		using ConstReverseIteratorT = GridNodeConstReverseIterator<ValueT>;



		ListBasedOnArray() : mAllocator(), mEndNode( nullptr ), mSize( 0u )
		{
			Clear();
		}



		//
		// Iteration
		//
		IteratorT begin()
		{
			return IteratorT( mEndNode->pNext );
		}
		IteratorT end()
		{
			return IteratorT( mEndNode );
		}
		ConstIteratorT begin() const
		{
			return ConstIteratorT( mEndNode->pNext );
		}
		ConstIteratorT end() const
		{
			return ConstIteratorT( mEndNode );
		}
		ConstIteratorT cbegin() const
		{
			return begin();
		}
		ConstIteratorT cend() const
		{
			return end();
		}

		ReverseIteratorT rbegin()
		{
			return ReverseIteratorT( mEndNode->pPrev );
		}
		ReverseIteratorT rend()
		{
			return ReverseIteratorT( mEndNode );
		}
		ConstReverseIteratorT rbegin() const
		{
			return ConstReverseIteratorT( mEndNode->pPrev );
		}
		ConstReverseIteratorT rend() const
		{
			return ConstReverseIteratorT( mEndNode );
		}
		ConstReverseIteratorT crbegin() const
		{
			return rbegin();
		}
		ConstReverseIteratorT crend() const
		{
			return rend();
		}



		//
		//
		//
		void Clear()
		{
			//
			// Clear
			//
			mAllocator.Clear();

			//
			// 4 Live
			//
			mEndNode = mAllocator.Pop();

			mEndNode->pPrev = mEndNode;
			mEndNode->pNext = mEndNode;

			mSize = 0u;
		}



		//
		//
		//
		SizeT Size() const
		{
			return mSize;
		}
		bool Empty() const
		{
			return ( 0u == mSize );
		}
		SizeT GetRestNodeCount() const
		{
			return mAllocator.Size();
		}



		//
		//
		//
		void PushFront( const ValueT& value )
		{
			Insert( begin(), value );
		}
		void PushBack( const ValueT& value )
		{
			Insert( end(), value );
		}
		IteratorT Insert( IteratorT pivot, const ValueT& value )
		{
			if( mAllocator.Empty() )
			{
				return end();
			}

			auto node = mAllocator.Pop();
			node->MyValue = value;

			//
			// ### pivot 의 앞에 새 노드를 배치한다.
			//

			//
			// 새 노드의 전, 후 설정
			//
			node->pPrev = pivot.mTargetNode->pPrev;
			node->pNext = pivot.mTargetNode;

			//
			// 이전 노드와 새 노드 연결
			//
			node->pPrev->pNext = node;

			//
			// Pivot Node 와 새 노드 연결
			//
			pivot.mTargetNode->pPrev = node;

			//
			//
			//
			++mSize;

			return IteratorT( pivot.mTargetNode->pPrev );
		}
		void PopFront()
		{
			Erase( begin() );
		}
		void PopBack()
		{
			Erase( --end() );
		}
		IteratorT Erase( IteratorT target )
		{
			if( end() == target )
			{
				return end();
			}

			auto node = target;
			++node;

			//
			// 다음 노드와 이전 노드 연결
			//
			node.mTargetNode->pPrev = target.mTargetNode->pPrev;

			//
			// 이전 노드와 다음 노드 연결
			//
			target.mTargetNode->pPrev->pNext = node.mTargetNode;

			//
			//
			//
			mAllocator.Push( target.mTargetNode );

			//
			//
			//
			--mSize;

			return node;
		}



		//
		// Get Value
		//
		const ValueT& Front() const
		{
			return mEndNode->pNext->MyValue;
		}
		const ValueT& Back() const
		{
			return mEndNode->pPrev->MyValue;
		}



	private:
		AllocatorT mAllocator;

		NodeT* mEndNode;
		SizeT mSize;
	};
}