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

#include <array>

#include "r2_Assert.h"
#include "r2_Node4List.h"

namespace r2
{
	//
	// # Warning
	//
	// ValueT 로 std::shared_ptr 등을 사용하고 있다면 Cleaner 를 ClearValue 로 설정.
	//

	template<typename T, uint32_t N, typename NodeCleaner = Node4ListCleaner_StayValue<T>>
	class Node4ListAllocatorBasedOnArray
	{
	public:
		using ValueT = T;
		using SizeT = uint32_t;

		using NodeT = Node4List<ValueT>;
		using ContainerT = std::array<NodeT, N>;



		Node4ListAllocatorBasedOnArray() : mContainer(), mNodeCleaner(), mHead( nullptr ), mSize( 0u )
		{
			Clear();
		}



		//
		//
		//
		SizeT Size() const
		{
			return mSize;
		}
		SizeT Capacity() const
		{
			return static_cast<SizeT>( mContainer.size() );
		}
		bool Empty() const
		{
			return ( 0u == mSize );
		}



		//
		//
		//
		void Clear()
		{
			//
			// Cleanup
			//
			for( auto& n : mContainer )
			{
				mNodeCleaner( &n );
			}

			//
			// Build Chain
			//
			mHead = &( *mContainer.begin() );
			if( 1 < mContainer.size() )
			{
				auto current_node = mHead;

				auto cur = mContainer.begin();
				++cur;
				for( auto end = mContainer.end(); end != cur; ++cur )
				{
					cur->pPrev = current_node;
					current_node->pNext = &( *cur );

					current_node = current_node->pNext;
				}
			}
			mSize = static_cast<uint32_t>( mContainer.size() );
		}



		//
		//
		//
		NodeT* Pop()
		{
			R2ASSERT( nullptr != mHead, "Empty : Node4ListAllocatorBasedOnArray::Pop()" );

			NodeT* ret = mHead;

			if( nullptr != ret )
			{
				mHead = ret->pNext;
				--mSize;
			}

			return ret;
		}
		void Push( NodeT* rest_node )
		{
			//
			//
			//
			mNodeCleaner( rest_node );

			//
			//
			//
			if( nullptr == mHead )
			{
				mHead = rest_node;
			}
			else
			{
				rest_node->pNext = mHead;
				mHead = rest_node;
			}

			++mSize;
		}



	private:
		ContainerT mContainer;
		NodeCleaner mNodeCleaner;
		NodeT* mHead;
		SizeT mSize;
	};
}