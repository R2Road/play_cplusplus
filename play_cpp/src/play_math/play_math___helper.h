#pragma once

#include <iomanip>

#define _USE_MATH_DEFINES
#include <math.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

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






	struct Vec3
	{
		Vec3() : x( 0.f ), y( 0.f ), z( 0.f )
		{}
		explicit Vec3( const float new_x, const float new_y, const float new_z ) :
			x( new_x )
			, y( new_y )
			, z( new_z )
		{}

		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
	};
	inline Vec3 operator*( const Vec3& v1, const float scalar )
	{
		return Vec3{ v1.x * scalar, v1.y * scalar, v1.z * scalar };
	}

	inline float vec3_length( const Vec3& v )
	{
		return std::sqrt(
			  ( v.x * v.x )
			+ ( v.y * v.y )
			+ ( v.z * v.z )
		);
	}






	inline std::ostream& operator<<( std::ostream& o, const Vec3& v )
	{
		static const int w = 10;

		return o
			<< std::left

			<< "\t"

			<< std::setw( w ) << v.x
			<< "   "
			<< std::setw( w ) << v.y
			<< "   "
			<< std::setw( w ) << v.z

			<< std::right;
	}
}