#pragma once

#include "r2tm/r2tm_ostream.hpp"

namespace play_template_meta_programming_01
{
	//
	// 최대 공약수
	//
	template<int A, int B>
	struct GCD_ProcessPrinter
	{
		static void Do()
		{
			std::cout << A << " : " << B << r2tm::linefeed;
			GCD_ProcessPrinter<B, A% B>::Do();
		}
	};

	//
	// 함수 템플릿은 부분 특수화를 허용하지 않는다. => <A, 0> 이런 구문을 허용하지 않는다. 2025.10.03
	// 
	// 완전한 특수화는 허용하므로 함수 대신에 struct 를 사용한다.
	//
	template<int A>
	struct GCD_ProcessPrinter<A, 0>
	{
		static void Do()
		{
			std::cout << A << " : " << 0 << r2tm::linefeed;
			std::cout << "result : " << A << r2tm::linefeed;
		}
	};
}