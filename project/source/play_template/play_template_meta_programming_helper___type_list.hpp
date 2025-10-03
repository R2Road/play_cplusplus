#pragma once

#include <type_traits>

namespace play_template_meta_programming_01
{
	template<typename ... Args_T>
	struct Helper_TypeList;


	// 기본 형 선언
	template<typename Search_T, typename TypeList_T, int CurrentIndex = 0>
	struct Helper_GetTypeIndex
	{
		static constexpr int value = -1;
	};

	template<typename Search_T, typename This_T, typename ... Args_T, int CurrentIndex>
	struct Helper_GetTypeIndex<Search_T, Helper_TypeList<This_T, Args_T...>, CurrentIndex>
	{
		static constexpr int value =
			(
				  std::is_same<Search_T, This_T>::value
				? CurrentIndex
				: Helper_GetTypeIndex<Search_T, Helper_TypeList<Args_T...>, CurrentIndex + 1>::value
			);
	};

	template<typename Search_T, int CurrentIndex>
	struct Helper_GetTypeIndex<Search_T, Helper_TypeList<>, CurrentIndex>
	{
		static constexpr int value = -1;
	};
}