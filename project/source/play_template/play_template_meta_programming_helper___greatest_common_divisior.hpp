#pragma once

namespace play_template_meta_programming_01
{
	//
	// 최대 공약수
	//

	template<int A, int B>
	struct GCDCalculator
	{
		static constexpr const int value = GCDCalculator<B, A% B>::value;
	};

	template<int A>
	struct GCDCalculator<A, 0>
	{
		static constexpr const int value = A;
	};
}