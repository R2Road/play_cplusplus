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
			mHead4Rest = &( *mContainer.begin() );

			//
			// Test Code
			//
			{
				mHead4Rest->MyValue = 0;
			}

			if( 1 < mContainer.size() )
			{
				auto current_node = mHead4Rest;

				auto cur = mContainer.begin();
				++cur;
				for( auto end = mContainer.end(); end != cur; ++cur )
				{
					cur->pPrev = current_node;
					current_node->pNext = &( *cur );

					//
					// Test Code
					//
					{
						current_node->pNext->MyValue = current_node->MyValue + 1;
					}

					current_node = current_node->pNext;
				}
			}
		}

		Node* GetRestNode()
		{
			R2ASSERT( nullptr != mHead4Rest, "Failed : ArrayBasedList::GetRestNode()" );

			Node* ret = mHead4Rest;

			if( nullptr != ret )
			{
				mHead4Rest = ret->pNext;
			}

			return ret;
		}

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

			{
				ArrayBasedList<int, 10> list;

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "ArrayBasedList<int, 10> list" << r2::linefeed;

				std::cout << r2::tab << "+ Rest Nodes" << r2::linefeed2;
				while( 1 )
				{
					auto rest_node = list.GetRestNode();
					if( nullptr == rest_node )
					{
						break;
					}

					std::cout << r2::tab2 << "> " << rest_node->MyValue << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}