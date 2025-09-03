#pragma once

#include "r2/r2_epsilon.hpp"

namespace play_math
{
	struct Vec2
	{
		Vec2() : x( 0.f ), y( 0.f )
		{}
		explicit Vec2( const float new_x, const float new_y ) :
			  x( new_x )
			, y( new_y )
		{}

		float x = 0.f;
		float y = 0.f;
	};
	const Vec2 VEC2_Y( 0.f, 1.f );

	inline bool operator==( const Vec2& v1, const Vec2 v2 )
	{
		return ( r2::epsilon_equal( v1.x, v2.x ) && r2::epsilon_equal( v1.y, v2.y ) );
	}

	inline Vec2 operator*( const Vec2& v1, const float scalar )
	{
		return Vec2{ v1.x * scalar, v1.y * scalar };
	}

	inline float vec2_length( const Vec2& v )
	{
		return std::sqrt(
			  ( v.x * v.x )
			+ ( v.y * v.y )
		);
	}
	inline float vec2_length( const float x, const float y )
	{
		return std::sqrt(
			  ( x * x )
			+ ( y * y )
		);
	}

	inline Vec2 vec2_normalize( const Vec2& v )
	{
		const float l = vec2_length( v );
		return Vec2(
			  ( v.x / l )
			, ( v.y / l )
		);
	}
	inline Vec2 vec2_normalize( const float x, const float y )
	{
		const float l = vec2_length( x, y );
		return Vec2(
			  ( x / l )
			, ( y / l )
		);
	}

	inline float vec2_dot( const Vec2& v1, const Vec2& v2 )
	{
		return (
			  ( v1.x * v2.x )
			+ ( v1.y * v2.y )
		);
	};
}



#include <iomanip>

#include "r2tm/r2tm_ostream.hpp"

namespace play_math
{
	inline std::ostream& operator<<( std::ostream& o, const Vec2& v )
	{
		static const int w = 10;

		return o
			<< std::left

			<< "\t"

			<< std::setw( w ) << v.x
			<< "   "
			<< std::setw( w ) << v.y

			<< std::right;
	}
}