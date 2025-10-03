#pragma once

namespace play_template_meta_programming_01
{
	template<typename ... TypeList_T>
	struct Helper_TypeList;



	template<typename ... TypeList_T>
	struct Helper_TypeList_Checker
	{
		using type = Helper_TypeList<TypeList_T ...>;
	};

	// 같은 template 인자를 받더라도 특수화 가능.
	template<typename ... TypeList_T>
	struct Helper_TypeList_Checker<Helper_TypeList<TypeList_T ...>>
	{
		using type = Helper_TypeList<TypeList_T ...>;
	};
}