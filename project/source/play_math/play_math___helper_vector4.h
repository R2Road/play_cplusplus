#pragma once

#include "r2/r2_epsilon.hpp"

namespace play_math
{
	struct Vec4
	{
		Vec4() : x( 0.f ), y( 0.f ), z( 0.f ), w( 1.f )
		{}
		explicit Vec4( const float new_x, const float new_y, const float new_z, const float new_w ) :
			  x( new_x )
			, y( new_y )
			, z( new_z )
			, w( new_w )
		{}

		float x;
		float y;
		float z;
		float w;
	};
	const Vec4 VEC4_X( 1.f, 0.f, 0.f, 1.f );
	const Vec4 VEC4_Y( 0.f, 1.f, 0.f, 1.f );
	const Vec4 VEC4_Z( 0.f, 0.f, 1.f, 1.f );
	const Vec4 VEC4_0( 0.f, 0.f, 0.f, 1.f );



	inline bool operator==( const Vec4& v1, const Vec4& v2 )
	{
		return (
			   r2::epsilon_equal( v1.x, v2.x )
			&& r2::epsilon_equal( v1.y, v2.y )
			&& r2::epsilon_equal( v1.z, v2.z )
			&& r2::epsilon_equal( v1.w, v2.w )
		);
	}

	inline Vec4 operator*( const Vec4& v1, const float scalar )
	{
		return Vec4{ v1.x * scalar, v1.y * scalar, v1.z * scalar, v1.w };
	}
	inline Vec4 operator*( const Vec4& v1, const int scalar )
	{
		return ( v1 * static_cast<float>( scalar ) );
	}

	inline Vec4 operator/( const Vec4& v1, const float scalar )
	{
		return Vec4{ v1.x / scalar, v1.y / scalar, v1.z / scalar, v1.w / scalar };
	}
	inline void operator/=( Vec4& v1, const float scalar )
	{
		v1.x /= scalar;
		v1.y /= scalar;
		v1.z /= scalar;
		v1.w /= scalar;
	}

	inline Vec4 operator+( const Vec4& v1, const Vec4& v2 )
	{
		return Vec4{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, 1.f };
	}
	inline Vec4 operator-( const Vec4& v1, const Vec4& v2 )
	{
		return Vec4{ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, 1.f };
	}



	inline float vec4_length( const Vec4& v )
	{
		return std::sqrt(
			  ( v.x * v.x )
			+ ( v.y * v.y )
			+ ( v.z * v.z )
		);
	}
	inline float vec4_length( const float x, const float y, const float z )
	{
		return std::sqrt(
			  ( x * x )
			+ ( y * y )
			+ ( z * z )
		);
	}

	inline Vec4 vec4_normalize( const Vec4& v )
	{
		const float l = vec4_length( v );
		return Vec4(
			  ( v.x / l )
			, ( v.y / l )
			, ( v.z / l )
			, 1.f
		);
	}
	inline Vec4 vec4_normalize( const float x, const float y, const float z )
	{
		const float l = vec4_length( x, y, z );
		return Vec4(
			  ( x / l )
			, ( y / l )
			, ( z / l )
			, 1.f
		);
	}

	inline float vec4_dot( const Vec4& v1, const Vec4& v2 )
	{

		return (
			  ( v1.x * v2.x )
			+ ( v1.y * v2.y )
			+ ( v1.z * v2.z )
		);
	};

	inline Vec4 vec4_cross( const Vec4& v1, const Vec4& v2 )
	{
		return Vec4{
			  ( v1.y * v2.z ) - ( v1.z * v2.y )
			, ( v1.z * v2.x ) - ( v1.x * v2.z )
			, ( v1.x * v2.y ) - ( v1.y * v2.x )
			, 1.f
		};
	}
}



#include <iomanip>

#include "r2tm/r2tm_ostream.hpp"

namespace play_math
{
	inline std::ostream& operator<<( std::ostream& o, const Vec4& v )
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
			<< "   "
			<< std::setw( w ) << v.w

			<< std::right;
	}
}