#pragma once

#include "r2/r2_epsilon.hpp"

namespace play_math
{
	struct Mat22
	{
		Mat22() :
			  _11( 1.f ), _12( 0.f )
			, _21( 0.f ), _22( 1.f )
		{}
		explicit Mat22(
			  float __11, float __12
			, float __21, float __22
		) :
			  _11( __11 ), _12( __12 )
			, _21( __21 ), _22( __22 )
		{}

		float _11;
		float _12;

		float _21;
		float _22;
	};
	const Mat22 MAT22_U( 1.f, 0.f, 0.f, 1.f );

	inline bool operator==( const Mat22& m1, const Mat22 m2 )
	{
		return (
			   r2::epsilon_equal( m1._11, m2._11 )
			&& r2::epsilon_equal( m1._12, m2._12 )
			&& r2::epsilon_equal( m1._21, m2._21 )
			&& r2::epsilon_equal( m1._22, m2._22 )
		);
	}

	inline Mat22 operator*( const Mat22& m1, const Mat22& m2 )
	{
		//
		// 가로 x 세로
		//
		// 11, 12
		// 21, 22
		return Mat22{
			  ( m1._11 * m2._11 ) + ( m1._12 * m2._21 )
			, ( m1._11 * m2._12 ) + ( m1._12 * m2._22 )

			, ( m1._21 * m2._11 ) + ( m1._22 * m2._21 )
			, ( m1._21 * m2._12 ) + ( m1._22 * m2._22 )
		};
	}
	inline void operator*=( Mat22& out_m1, const Mat22& m2 )
	{
		out_m1 = ( out_m1 * m2 );
	}
}



#include "play_math___helper_vector2.hpp"

namespace play_math
{
	inline Vec2 operator*( const Mat22& m, const Vec2& v )
	{
		//
		// 가로 x 세로
		//
		// 11, 12
		// 21, 22
		return Vec2{
			  ( m._11 * v.x ) + ( m._12 * v.y )
			, ( m._21 * v.x ) + ( m._22 * v.y )
		};
	}
}



#include <iomanip>

#include "r2tm/r2tm_ostream.hpp"

namespace play_math
{
	inline std::ostream& operator<<( std::ostream& o, const Mat22& v )
	{
		static const int w = 16;

		return o
			<< std::left

			<< "\t"

			<< std::setw( w ) << v._11 << "   "
			<< std::setw( w ) << v._12

			<< "\n\t"

			<< "\t"
			<< std::setw( w ) << v._21 << "   "
			<< std::setw( w ) << v._22

			<< std::right
		;
	}
}