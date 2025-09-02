#pragma once

#include <memory>

#include "r2_list_node.hpp"

namespace r2
{
	template<typename T>
	class ListNodeIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;



		ListNodeIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}



		ListNodeIterator& operator++()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}
		ListNodeIterator& operator--()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}



		bool operator==( const ListNodeIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const ListNodeIterator& other ) const
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
	class ListNodeConstIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;



		ListNodeConstIterator( const NodeT* target_node ) : mTargetNode( target_node )
		{}



		ListNodeConstIterator& operator++()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}
		ListNodeConstIterator& operator--()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}



		bool operator==( const ListNodeConstIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const ListNodeConstIterator& other ) const
		{
			return !operator==( other );
		}



		const ValueT& operator*() const
		{
			return mTargetNode->MyValue;
		}
		const ValueT* operator->() const
		{
			return std::addressof( *( *this ) ); // call : operator*()
		}



		const NodeT* mTargetNode;
	};



	template<typename T>
	class ListNodeReverseIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;



		ListNodeReverseIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}



		ListNodeReverseIterator& operator++()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}
		ListNodeReverseIterator& operator--()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}



		bool operator==( const ListNodeReverseIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const ListNodeReverseIterator& other ) const
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
	class GridNodeConstReverseIterator
	{
	public:
		using ValueT = T;
		using NodeT = ListNode<ValueT>;



		GridNodeConstReverseIterator( const NodeT* target_node ) : mTargetNode( target_node )
		{}



		GridNodeConstReverseIterator& operator++()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}
		GridNodeConstReverseIterator& operator--()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}



		bool operator==( const GridNodeConstReverseIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const GridNodeConstReverseIterator& other ) const
		{
			return !operator==( other );
		}



		const ValueT& operator*() const
		{
			return mTargetNode->MyValue;
		}
		const ValueT* operator->() const
		{
			return std::addressof( *( *this ) ); // call : operator*()
		}



		const NodeT* mTargetNode;
	};
}