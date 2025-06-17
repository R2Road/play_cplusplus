//
// # Version Rule
// - 1.0.0.0 : 사용 가능
// - 0.1.0.0 : 기능 추가/삭제
// - 0.0.1.0 : 기능 개선/변경
// - 0.0.0.1 : 자잘한 변화
//
// # Last Update		: 2025.06.09 PM.10.00
// # Version			: 1.0.0.0
//

#pragma once

//
// _USE_MATH_DEFINES 전처리기는 표준이 아니다.
//
// <numbers> : C++20
//
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>

namespace r2
{
	const float epsilon = 0.00001f;

	inline bool epsilon_equal( const float v1, const float v2 )
	{
		return ( epsilon > std::abs( v1 - v2 ) );
	}
}