#pragma once

#include <memory>

#include "r2_Node4List.h"

namespace r2
{
	template<typename T>
	class Node4ListIterator
	{
	public:
		using ValueT = T;
		using NodeT = Node4List<ValueT>;



		Node4ListIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}



		Node4ListIterator& operator++()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}
		Node4ListIterator& operator--()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}



		bool operator==( const Node4ListIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const Node4ListIterator& other ) const
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
	class Node4ListConstIterator
	{
	public:
		using ValueT = T;
		using NodeT = Node4List<ValueT>;



		Node4ListConstIterator( const NodeT* target_node ) : mTargetNode( target_node )
		{}



		Node4ListConstIterator& operator++()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}
		Node4ListConstIterator& operator--()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}



		bool operator==( const Node4ListConstIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const Node4ListConstIterator& other ) const
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
	class Node4ListReverseIterator
	{
	public:
		using ValueT = T;
		using NodeT = Node4List<ValueT>;



		Node4ListReverseIterator( NodeT* target_node ) : mTargetNode( target_node )
		{}



		Node4ListReverseIterator& operator++()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}
		Node4ListReverseIterator& operator--()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}



		bool operator==( const Node4ListReverseIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const Node4ListReverseIterator& other ) const
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
	class Node4ListConstReverseIterator
	{
	public:
		using ValueT = T;
		using NodeT = Node4List<ValueT>;



		Node4ListConstReverseIterator( const NodeT* target_node ) : mTargetNode( target_node )
		{}



		Node4ListConstReverseIterator& operator++()
		{
			mTargetNode = mTargetNode->pPrev;
			return ( *this );
		}
		Node4ListConstReverseIterator& operator--()
		{
			mTargetNode = mTargetNode->pNext;
			return ( *this );
		}



		bool operator==( const Node4ListConstReverseIterator& other ) const
		{
			return mTargetNode == other.mTargetNode;
		}
		bool operator!=( const Node4ListConstReverseIterator& other ) const
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