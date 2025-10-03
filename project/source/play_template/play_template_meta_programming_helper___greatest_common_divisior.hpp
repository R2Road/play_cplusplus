#pragma once

namespace play_template_meta_programming_01
{
	//
	// 최대 공약수
	//

	template<int A, int B>
	struct GCD_Calculator
	{
		static constexpr const int value = GCD_Calculator<B, A % B>::value;
	};

	template<int A>
	struct GCD_Calculator<A, 0>
	{
		static constexpr const int value = A;
	};
}