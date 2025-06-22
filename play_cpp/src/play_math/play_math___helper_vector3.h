#pragma once

namespace play_math
{
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
	const Vec3 VEC3_Y( 0.f, 1.f, 0.f );

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
	inline float vec3_length( const float x, const float y, const float z )
	{
		return std::sqrt(
			  ( x * x )
			+ ( y * y )
			+ ( z * z )
		);
	}

	inline Vec3 vec3_normalize( const Vec3& v )
	{
		const float l = vec3_length( v );
		return Vec3(
			  ( v.x / l )
			, ( v.y / l )
			, ( v.z / l )
		);
	}
	inline Vec3 vec3_normalize( const float x, const float y, const float z )
	{
		const float l = vec3_length( x, y, z );
		return Vec3(
			  ( x / l )
			, ( y / l )
			, ( z / l )
		);
	}

	inline float vec3_dot( const Vec3& v1, const Vec3& v2 )
	{

		return (
			  ( v1.x * v2.x )
			+ ( v1.y * v2.y )
			+ ( v1.z * v2.z )
		);
	};
}



#include <iomanip>

#include "r2tm/r2tm_ostream.h"

namespace play_math
{
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