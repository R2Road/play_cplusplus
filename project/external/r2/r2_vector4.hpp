//
// # Version Rule
// - 1.0.0.0 : 사용 가능
// - 0.1.0.0 : 기능 추가/삭제
// - 0.0.1.0 : 기능 개선/변경
// - 0.0.0.1 : 자잘한 변화
//
// # Last Update		: 2025.07.21 PM.04.30
// # Version			: 1.1.0.0
//

#pragma once

#include <cmath>

#include "r2_epsilon.hpp"

namespace r2
{
	struct Vector4
	{
		constexpr Vector4() : x( 0.f ), y( 0.f ), z( 0.f ), w( 0.f )
		{}
		explicit constexpr Vector4( const float new_x, const float new_y, const float new_z, const float new_w ) :
			  x( new_x )
			, y( new_y )
			, z( new_z )
			, w( new_w )
		{}

		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
		float w = 0.f;
	};
	constexpr Vector4 VEC4_X( 1.f, 0.f, 0.f, 1.f );
	constexpr Vector4 VEC4_Y( 0.f, 1.f, 0.f, 1.f );
	constexpr Vector4 VEC4_Z( 0.f, 0.f, 1.f, 1.f );



	inline bool operator==( const Vector4& v1, const Vector4& v2 )
	{
		return (
			   r2::epsilon_equal( v1.x, v2.x )
			&& r2::epsilon_equal( v1.y, v2.y )
			&& r2::epsilon_equal( v1.z, v2.z )
			&& r2::epsilon_equal( v1.w, v2.w )
		);
	}
	inline bool operator!=( const Vector4& v1, const Vector4& v2 )
	{
		return !operator==( v1, v2 );
	}



	inline Vector4 operator+( const Vector4& v1, const Vector4& v2 )
	{
		return Vector4{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w };
	}
	inline void operator+=( Vector4& v1, const Vector4& v2 )
	{
		v1.x += v2.x;
		v1.y += v2.y;
		v1.z += v2.z;
		v1.w += v2.w;
	}
	inline Vector4 operator-( const Vector4& v1 )
	{
		return Vector4{ -v1.x, -v1.y, -v1.z, -v1.w };
	}
	inline Vector4 operator-( const Vector4& v1, const Vector4& v2 )
	{
		return Vector4{ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w };
	}
	inline void operator-=( Vector4& v1, const Vector4& v2 )
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		v1.z -= v2.z;
		v1.w -= v2.w;
	}



	inline Vector4 operator*( const Vector4& v1, const float scalar )
	{
		return Vector4{ v1.x * scalar, v1.y * scalar, v1.z * scalar, v1.w * scalar };
	}
	inline void operator*=( Vector4& v1, const float scalar )
	{
		v1.x *= scalar;
		v1.y *= scalar;
		v1.z *= scalar;
		v1.w *= scalar;
	}
	inline Vector4 operator/( const Vector4& v1, const float scalar )
	{
		return Vector4{ v1.x / scalar, v1.y / scalar, v1.z / scalar, v1.w / scalar };
	}
	inline void operator/=( Vector4& v1, const float scalar )
	{
		v1.x /= scalar;
		v1.y /= scalar;
		v1.z /= scalar;
		v1.w /= scalar;
	}



	inline float length( const Vector4& v )
	{
		return std::sqrt( ( v.x * v.x ) + ( v.y * v.y ) + ( v.z * v.z ) );
	}
	inline Vector4 normalize( const Vector4& v )
	{
		const float l = r2::length( v );
		return (
			  r2::epsilon_equal( l, 0.f )
			? Vector4{
				  0.f
				, 0.f
				, 0.f
				, v.w
			}
			: Vector4{
				  v.x / l
				, v.y / l
				, v.z / l
				, v.w
			}
		);
	}
	inline float dot( const Vector4& v1, const Vector4& v2 )
	{
		return ( v1.x * v2.x ) + ( v1.y * v2.y ) + ( v1.z * v2.z ) + ( v1.w * v2.w );
	}
	inline Vector4 cross( const Vector4& v1, const Vector4& v2 )
	{
		return Vector4{
			  ( v1.y * v2.z ) - ( v1.z * v2.y )
			, ( v1.z * v2.x ) - ( v1.x * v2.z )
			, ( v1.x * v2.y ) - ( v1.y * v2.x )
			, 0.f
		};
	}
}