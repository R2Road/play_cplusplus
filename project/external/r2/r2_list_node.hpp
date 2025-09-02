//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.11.16 PM.00.22
// # Version			: 1.0.0
//

#pragma once

namespace r2
{
	template<typename T>
	struct ListNode
	{
		using ValueT = T;
		using MyT = ListNode<ValueT>;

		ValueT MyValue = {};
		MyT* pPrev = nullptr;
		MyT* pNext = nullptr;
	};

	template<typename T>
	class ListNodeCleaner_ClearValue
	{
	public:
		void operator()( ListNode<T>* node )
		{
			node->pNext = nullptr;
			node->pPrev = nullptr;
			node->MyValue = {};
		}
	};

	template<typename T>
	class ListNodeCleaner_StayValue
	{
	public:
		void operator()( ListNode<T>* node )
		{
			node->pNext = nullptr;
			node->pPrev = nullptr;
		}
	};
}