#include <array>

namespace r2
{
	template<typename T>
	struct ListNode
	{
		using ValueT = T;
		using MyT = ListNode<ValueT>;

		MyT* pPrev = nullptr;
		MyT* pNext = nullptr;
		ValueT MyValue;
	};

	template<typename T>
	class ListIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;

		ListIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}

		ListIterator& operator++()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}

		bool operator==( const ListIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const ListIterator& other ) const
		{
			return !operator==( other );
		}

		T& operator*()
		{
			return mTargetNode->MyValue;
		}

		NodeT* mTargetNode;
	};

	template<typename T, std::size_t N>
	class ArrayBasedList
	{
	public:
		using ValueT = T;
		using SizeT = std::size_t;

		using NodeT = ListNode<ValueT>;
		using ContainerT = std::array<NodeT, N>;

		using IteratorT = ListIterator<ValueT>;
		//using iterator = ListIterator<ValueT>; // ...dev rule?

		ArrayBasedList() : mContainer(), mHead4Rest( nullptr ), mHead4Live( nullptr ), mTail4Live( nullptr )
		{
			Clear();
		}

		//
		// Iteration
		//
		IteratorT begin() { return IteratorT( mHead4Live ); }
		IteratorT end() { return IteratorT( nullptr ); }

		void Clear()
		{
			//
			// 4 Rest
			//
			mHead4Rest = &( *mContainer.begin() );
			if( 1 < mContainer.size() )
			{
				auto current_node = mHead4Rest;

				auto cur = mContainer.begin();
				++cur;
				for( auto end = mContainer.end(); end != cur; ++cur )
				{
					cur->pPrev = current_node;
					current_node->pNext = &( *cur );

					current_node = current_node->pNext;
				}
			}

			//
			// 4 Live
			//
			mHead4Live = nullptr;
			mTail4Live = nullptr;
		}

	private:
		NodeT* GetRestNode()
		{
			R2ASSERT( nullptr != mHead4Rest, "Empty : ArrayBasedList::GetRestNode()" );

			NodeT* ret = mHead4Rest;

			if( nullptr != ret )
			{
				mHead4Rest = ret->pNext;
			}

			ret->pPrev = nullptr;
			ret->pNext = nullptr;

			return ret;
		}
		void Rest( NodeT* rest_node )
		{
			rest_node->pPrev = nullptr;
			rest_node->pNext = nullptr;

			if( nullptr == mHead4Rest )
			{
				mHead4Rest = rest_node;
			}
			else
			{
				rest_node->pNext = mHead4Rest;
				mHead4Rest = rest_node;
			}
		}
		uint32_t CalculateSize( const NodeT* const target_node ) const
		{
			if( nullptr == target_node )
			{
				return 0u;
			}

			auto current_node = target_node;
			int node_count = 0;

			while( nullptr != current_node )
			{
				++node_count;
				current_node = current_node->pNext;
			}

			return node_count;
		}

	public:
		uint32_t GetRestNodeCount() const
		{
			return CalculateSize( mHead4Rest );
		}
		uint32_t Size() const
		{
			return CalculateSize( mHead4Live );
		}

		void PushFront( const ValueT new_value )
		{
			auto node = GetRestNode();
			node->MyValue = new_value;

			if( nullptr == mHead4Live )
			{
				mHead4Live = node;
				mTail4Live = node;
			}
			else
			{
				node->pNext = mHead4Live;
				mHead4Live->pPrev = node;

				mHead4Live = node;
			}
		}
		void PushBack( const ValueT new_value )
		{
			auto node = GetRestNode();
			node->MyValue = new_value;

			if( nullptr == mTail4Live )
			{
				mHead4Live = node;
				mTail4Live = node;
			}
			else
			{
				node->pPrev = mTail4Live;
				mTail4Live->pNext = node;

				mTail4Live = node;
			}
		}
		IteratorT Erase( IteratorT target )
		{
			auto pPrev = target.mTargetNode->pPrev;
			auto pNext = target.mTargetNode->pNext;

			if( nullptr != pPrev )
			{
				pPrev->pNext = pNext;
			}
			if( nullptr != pNext )
			{
				pNext->pPrev = pPrev;
			}

			if( mHead4Live == target.mTargetNode )
			{
				mHead4Live = pNext;
			}
			if( mTail4Live == target.mTargetNode )
			{
				mTail4Live = pPrev;
			}

			Rest( target.mTargetNode );

			return IteratorT( pNext );
		}

	private:
		ContainerT mContainer;
		NodeT* mHead4Rest;

		NodeT* mHead4Live;
		NodeT* mTail4Live;
	};
}