//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.08.04 PM.05.30
// # Version			: 1.0.0
//

#pragma once

namespace r2
{
	template<typename T>
	struct RemovePointer
	{
		using type = T;
	};

	template<typename T>
	struct RemovePointer<T*>
	{
		using type = T;
	};

	template<typename T>
	struct RemovePointer<T* const>
	{
		using type = T;
	};

	template<typename T>
	struct RemovePointer<T* volatile>
	{
		using type = T;
	};

	template<typename T>
	struct RemovePointer<T* const volatile>
	{
		using type = T;
	};

	template<typename T>
	using RemovePointer_T = typename RemovePointer<T>::type;
}