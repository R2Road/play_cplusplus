#include "pch.h"
#include "array_based_list_test.h"

#include <array>

#include "base/r2_eTestResult.h"

namespace
{
	template<typename T, std::size_t N>
	class ArrayBasedList
	{
	public:
		using ValueT = T;
		using SizeT = std::size_t;

		struct Node
		{
			Node* pPrev = nullptr;
			Node* pNext = nullptr;
			ValueT MyValue;
		};

		using ContainerT = std::array<Node, N>;

		ArrayBasedList() : mContainer(), mHead4Rest( nullptr ), mHead4Live( nullptr )
		{
			Clear();
		}

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
		}

	private:
		Node* GetRestNode()
		{
			R2ASSERT( nullptr != mHead4Rest, "Empty : ArrayBasedList::GetRestNode()" );

			Node* ret = mHead4Rest;

			if( nullptr != ret )
			{
				mHead4Rest = ret->pNext;
			}

			ret->pPrev = nullptr;
			ret->pNext = nullptr;

			return ret;
		}
		uint32_t CalculateSize( const Node* const target_node ) const
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
			}
			else
			{
				node->pNext = mHead4Live;
				mHead4Live->pPrev = node;

				mHead4Live = node;
			}
		}

		Node* GetHead_discard()
		{
			return mHead4Live;
		}

	private:
		ContainerT mContainer;
		Node* mHead4Rest;
		Node* mHead4Live;
	};
}

namespace array_based_list_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "ARRAY BASED LIST( In Progress )";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			ArrayBasedList<int, 10> list;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "ArrayBasedList<int, 10> list" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Method : GetRestNodeCount" << r2::linefeed2;
				std::cout << r2::tab2 << "list.GetRestNodeCount();" << r2::tab << ">" << r2::tab << list.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				list.PushFront( 11 );
				list.PushFront( 22 );
				list.PushFront( 33 );
				list.PushFront( 44 );

				std::cout << r2::tab << "+ Method : Push Front" << r2::linefeed2;
				std::cout << r2::tab2 << "list.PushFront( 11 );" << r2::linefeed;
				std::cout << r2::tab2 << "list.PushFront( 22 );" << r2::linefeed;
				std::cout << r2::tab2 << "list.PushFront( 33 );" << r2::linefeed;
				std::cout << r2::tab2 << "list.PushFront( 44 );" << r2::linefeed2;

				std::cout << r2::tab << "+ View" << r2::linefeed2;
				auto current_node = list.GetHead_discard();
				while( 1 )
				{
					if( nullptr == current_node )
					{
						break;
					}

					std::cout << r2::tab2 << "> " << current_node->MyValue << r2::linefeed;

					current_node = current_node->pNext;
				}

				std::cout << r2::linefeed;
				std::cout << r2::tab2 << "list.GetRestNodeCount();" << r2::tab << ">" << r2::tab << list.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Method : Size" << r2::linefeed2;
				std::cout << r2::tab2 << "list.Size();" << r2::tab << ">" << r2::tab << list.Size() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				list.Clear();

				std::cout << r2::tab << "+ Method : Clear" << r2::linefeed2;
				std::cout << r2::tab2 << "list.Clear();" << r2::linefeed2;
				
				std::cout << r2::tab2 << "list.GetRestNodeCount();" << r2::tab << ">" << r2::tab << list.GetRestNodeCount() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}