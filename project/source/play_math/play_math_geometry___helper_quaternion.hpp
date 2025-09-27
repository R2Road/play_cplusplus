#pragma once

#include "r2/r2_epsilon.hpp"
#include "play_math/play_math_geometry___helper_vector3.hpp"
#include "play_math/play_math_geometry___helper_vector4.hpp"

namespace play_math_geometry
{
	struct Quat
	{
		Quat() : w( 0.f ), x( 0.f ), y( 0.f ), z( 0.f )
		{}
		explicit Quat( const float new_w, const float new_x, const float new_y, const float new_z ) :
			  w( new_w )
			, x( new_x )
			, y( new_y )
			, z( new_z )
		{}
		explicit Quat( const Vec3 v ) :
			  w( 0 )
			, x( v.x )
			, y( v.y )
			, z( v.z )
		{}
		explicit Quat( const Vec4 v ) :
			w( 0 )
			, x( v.x )
			, y( v.y )
			, z( v.z )
		{}

		float w;
		float x;
		float y;
		float z;
	};

	inline bool operator==( const Quat& a, const Quat& b )
	{
		return (
			   r2::epsilon_equal( a.w, b.w )
			&& r2::epsilon_equal( a.x, b.x )
			&& r2::epsilon_equal( a.y, b.y )
			&& r2::epsilon_equal( a.z, b.z )
		);
	}

	inline Quat operator*( const Quat& a, const Quat& b )
	{
		return Quat(
			  ( a.w * b.w ) - ( a.x * b.x ) - ( a.y * b.y ) - ( a.z * b.z )
			, ( a.w * b.x ) + ( a.x * b.w ) + ( a.y * b.z ) - ( a.z * b.y )
			, ( a.w * b.y ) + ( a.y * b.w ) + ( a.z * b.x ) - ( a.x * b.z )
			, ( a.w * b.z ) + ( a.z * b.w ) + ( a.x * b.y ) - ( a.y * b.x )
		);
	}

	inline Quat quat_inverse( const Quat& q )
	{
		return Quat( q.w, -q.x, -q.y, -q.z );
	}

	inline Quat operator*( const Quat& q, const Vec3& v )
	{
		return ( q * Quat( v ) ) * quat_inverse( q );
	}
	inline Quat operator*( const Quat& q, const Vec4& v )
	{
		return ( q * Vec3( v.x, v.y, v.z ) );
	}

	inline float quat_length( const Quat& q )
	{
		return sqrt(
			  ( q.w * q.w )
			+ ( q.x * q.x )
			+ ( q.y * q.y )
			+ ( q.z * q.z )
		);
	}
}



#include <iomanip>

#include "r2tm/r2tm_ostream.hpp"

namespace play_math_geometry
{
	inline std::ostream& operator<<( std::ostream& o, const Quat& q )
	{
		static const int w = 10;

		return o
			<< std::left

			<< "\t"

			<< std::setw( w ) << q.w
			<< "   "
			<< std::setw( w ) << q.x
			<< "   "
			<< std::setw( w ) << q.y
			<< "   "
			<< std::setw( w ) << q.z

			<< std::right;
	}
}