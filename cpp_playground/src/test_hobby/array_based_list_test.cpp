#include "pch.h"
#include "array_based_list_test.h"

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
			Node* pPrev;
			Node* pNext;
			ValueT MyValue;
		};

		ArrayBasedList() : mContainer(), mHead( nullptr )
		{}

		std::array<Node, N> mContainer;
		Node* mHead;
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
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}