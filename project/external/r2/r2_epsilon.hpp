//
// # Version Rule
// - 1.0.0.0 : 사용 가능
// - 0.1.0.0 : 기능 추가/삭제
// - 0.0.1.0 : 기능 개선/변경
// - 0.0.0.1 : 자잘한 변화
//
// # Last Update		: 2025.07.31 PM.04.30
// # Version			: 1.1.0.0
//

#pragma once

namespace r2
{
	constexpr float epsilon_f = 0.00001f;
	constexpr double epsilon_d = 0.00001;

	inline constexpr bool epsilon_equal( const float v1, const float v2 )
	{
		const float temp = ( v1 - v2 );
		return ( epsilon_f > ( 0.f > temp ? -temp : temp ) );
	}

	inline constexpr bool epsilon_equal( const double v1, const double v2 )
	{
		const double temp = ( v1 - v2 );
		return ( epsilon_d > ( 0.0 > temp ? -temp : temp ) );
	}
}