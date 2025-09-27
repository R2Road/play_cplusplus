#pragma once

#include "r2/r2_epsilon.hpp"

namespace play_math
{
	struct Mat33
	{
		Mat33() :
			  _11( 1.f ), _12( 0.f ), _13( 0.f )
			, _21( 0.f ), _22( 1.f ), _23( 0.f )
			, _31( 0.f ), _32( 0.f ), _33( 1.f )
		{}
		explicit Mat33(
			  float __11, float __12, float __13
			, float __21, float __22, float __23
			, float __31, float __32, float __33
		) :
			  _11( __11 ), _12( __12 ), _13( __13 )
			, _21( __21 ), _22( __22 ), _23( __23 )
			, _31( __31 ), _32( __32 ), _33( __33 )
		{}

		float _11;
		float _12;
		float _13;

		float _21;
		float _22;
		float _23;

		float _31;
		float _32;
		float _33;
	};
	const Mat33 MAT33_U(
		  1.f, 0.f, 0.f
		, 0.f, 1.f, 0.f
		, 0.f, 0.f, 1.f
	);

	inline bool operator==( const Mat33& m1, const Mat33 m2 )
	{
		return (
			   r2::epsilon_equal( m1._11, m2._11 ) && r2::epsilon_equal( m1._12, m2._12 ) && r2::epsilon_equal( m1._13, m2._13 )
			&& r2::epsilon_equal( m1._21, m2._21 ) && r2::epsilon_equal( m1._22, m2._22 ) && r2::epsilon_equal( m1._23, m2._23 )
			&& r2::epsilon_equal( m1._31, m2._31 ) && r2::epsilon_equal( m1._32, m2._32 ) && r2::epsilon_equal( m1._33, m2._33 )
		);
	}

	inline Mat33 operator*( const Mat33& m1, const Mat33& m2 )
	{
		//
		// 가로 x 세로
		//
		// 11, 12, 13
		// 21, 22, 23
		// 31, 32, 33
		return Mat33{
			  ( m1._11 * m2._11 ) + ( m1._12 * m2._21 ) + ( m1._13 * m2._31 )
			, ( m1._11 * m2._12 ) + ( m1._12 * m2._22 ) + ( m1._13 * m2._32 )
			, ( m1._11 * m2._13 ) + ( m1._12 * m2._23 ) + ( m1._13 * m2._33 )

			, ( m1._21 * m2._11 ) + ( m1._22 * m2._21 ) + ( m1._23 * m2._31 )
			, ( m1._21 * m2._12 ) + ( m1._22 * m2._22 ) + ( m1._23 * m2._32 )
			, ( m1._21 * m2._13 ) + ( m1._22 * m2._23 ) + ( m1._23 * m2._33 )

			, ( m1._31 * m2._11 ) + ( m1._32 * m2._21 ) + ( m1._33 * m2._31 )
			, ( m1._31 * m2._12 ) + ( m1._32 * m2._22 ) + ( m1._33 * m2._32 )
			, ( m1._31 * m2._13 ) + ( m1._32 * m2._23 ) + ( m1._33 * m2._33 )
		};
	}
	inline void operator*=( Mat33& out_m1, const Mat33& m2 )
	{
		out_m1 = ( out_m1 * m2 );
	}
}



#include "play_math___helper_vector3.hpp"

namespace play_math
{
	inline Vec3 operator*( const Mat33& m, const Vec3& v )
	{
		//
		// 가로 x 세로
		//
		// 11, 12, 13
		// 21, 22, 23
		// 31, 32, 33
		return Vec3{
			  ( m._11 * v.x ) + ( m._12 * v.y ) + ( m._13 * v.z )
			, ( m._21 * v.x ) + ( m._22 * v.y ) + ( m._23 * v.z )
			, ( m._31 * v.x ) + ( m._32 * v.y ) + ( m._33 * v.z )
		};
	}
}



#include <iomanip>

#include "r2tm/r2tm_ostream.hpp"

namespace play_math
{
	inline std::ostream& operator<<( std::ostream& o, const Mat33& v )
	{
		static const int w = 16;

		return o
			<< std::left

			<< "\t"

			<< std::setw( w ) << v._11 << "   "
			<< std::setw( w ) << v._12 << "   "
			<< std::setw( w ) << v._13

			<< "\n\t"

			<< "\t"
			<< std::setw( w ) << v._21 << "   "
			<< std::setw( w ) << v._22 << "   "
			<< std::setw( w ) << v._23

			<< "\n\t"

			<< "\t"
			<< std::setw( w ) << v._31 << "   "
			<< std::setw( w ) << v._32 << "   "
			<< std::setw( w ) << v._33

			<< std::right
		;
	}
}