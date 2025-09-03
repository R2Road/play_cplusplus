#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace play_math
{
	const float R_PI = static_cast< float >( M_PI );
	const float R_2PI = R_PI * 2;
	const float R_PI_2 = static_cast< float >( M_PI_2 );
	const float R_PI_4 = static_cast< float >( M_PI_4 );

	inline float Deg2Rad( float degree )
	{
		static const float t = R_PI / 180.f;
		return ( degree * t );
	};

	inline float Rad2Deg( float radian )
	{
		static const float t = 180.f / R_PI;
		return ( radian * t );
	};
}