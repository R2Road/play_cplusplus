#include <array>
#include <memory>

namespace r2
{
	template<typename T>
	struct ListNode
	{
		using ValueT = T;
		using MyT = ListNode<ValueT>;

		ValueT MyValue;
		MyT* pPrev = nullptr;
		MyT* pNext = nullptr;
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
		ListIterator& operator--()
		{
			mTargetNode = mTargetNode->pPrev;
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

		ValueT& operator*() const
		{
			return mTargetNode->MyValue;
		}
		ValueT* operator->() const
		{
			return std::addressof( *( *this ) ); // call : operator*()
		}

		NodeT* mTargetNode;
	};

	template<typename T>
	class ListReverseIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;

		ListReverseIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}

		ListReverseIterator& operator++()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}

		bool operator==( const ListReverseIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const ListReverseIterator& other ) const
		{
			return !operator==( other );
		}

		ValueT& operator*() const
		{
			return mTargetNode->MyValue;
		}
		ValueT* operator->() const
		{
			return std::addressof( *( *this ) ); // call : operator*()
		}

		NodeT* mTargetNode;
	};

	template<typename T, uint32_t N>
	class ArrayBasedList
	{
	public:
		using ValueT = T;
		using SizeT = uint32_t;

		using NodeT = ListNode<ValueT>;
		using ContainerT = std::array<NodeT, N + 1u>; // N + Head

		using IteratorT = ListIterator<ValueT>;
		//using iterator = ListIterator<ValueT>; // ...dev rule?
		using ReverseIteratorT = ListReverseIterator<ValueT>;

		ArrayBasedList() : mContainer(), mHead4Rest( nullptr ), mSize4Rest( 0u ), mEnd4Live( nullptr ), mSize( 0u )
		{
			Clear();
		}

		//
		// Iteration
		//
		IteratorT begin() { return IteratorT( mEnd4Live->pNext ); }
		IteratorT end() { return IteratorT( mEnd4Live ); }
		ReverseIteratorT rbegin() const { return ReverseIteratorT( mEnd4Live->pPrev ); }
		ReverseIteratorT rend() const { return ReverseIteratorT( mEnd4Live ); }

		void Clear()
		{
			//
			// Cleanup
			//
			for( auto& n : mContainer )
			{
				n.pPrev = nullptr;
				n.pNext = nullptr;
			}

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
			mSize4Rest = static_cast<uint32_t>( mContainer.size() );

			//
			// 4 Live
			//
			mEnd4Live = mHead4Rest;
			mHead4Rest = mHead4Rest->pNext;

			mEnd4Live->pPrev = mEnd4Live;
			mEnd4Live->pNext = mEnd4Live;

			--mSize4Rest;

			mSize = 0u;
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

			--mSize4Rest;

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

			++mSize4Rest;
		}

	public:
		SizeT GetRestNodeCount() const
		{
			return mSize4Rest;
		}
		SizeT Size() const
		{
			return mSize;
		}
		bool Empty() const
		{
			return ( 0u == mSize );
		}

		void PushFront( const ValueT new_value )
		{
			if( 0 == GetRestNodeCount() )
			{
				return;
			}

			auto new_front_node = GetRestNode();
			new_front_node->MyValue = new_value;

			// Prev
			mEnd4Live->pNext->pPrev = new_front_node;

			// New
			new_front_node->pPrev = mEnd4Live;
			new_front_node->pNext = mEnd4Live->pNext;

			// NExt
			mEnd4Live->pNext = new_front_node;

			++mSize;
		}
		void PushBack( const ValueT new_value )
		{
			if( 0 == GetRestNodeCount() )
			{
				return;
			}

			auto new_back_node = GetRestNode();
			new_back_node->MyValue = new_value;

			// Prev
			mEnd4Live->pPrev->pNext = new_back_node;

			// New
			new_back_node->pPrev = mEnd4Live->pPrev;
			new_back_node->pNext = mEnd4Live;

			// Next
			mEnd4Live->pPrev = new_back_node;

			++mSize;
		}
		IteratorT Erase( IteratorT target )
		{
			if( mEnd4Live == target.mTargetNode )
			{
				return IteratorT( mEnd4Live );
			}

			auto pPrev = target.mTargetNode->pPrev;
			auto pNext = target.mTargetNode->pNext;

			pPrev->pNext = pNext;
			pNext->pPrev = pPrev;

			--mSize;

			Rest( target.mTargetNode );

			return IteratorT( pNext );
		}

	private:
		ContainerT mContainer;
		NodeT* mHead4Rest;
		SizeT mSize4Rest;

		NodeT* mEnd4Live;
		SizeT mSize;
	};
}