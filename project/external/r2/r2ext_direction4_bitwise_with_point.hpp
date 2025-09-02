//
// # Version Rule
// - 1.0.0.0 : 사용 가능
// - 0.1.0.0 : 기능 추가/삭제
// - 0.0.1.0 : 기능 개선/변경
// - 0.0.0.1 : 자잘한 변화
//
// # Last Update		: 2025.08.26 PM.02.35
// # Version			: 1.0.0.0
//

#pragma once

#include "r2_direction4_bitwise.hpp"
#include "r2_point.hpp"

//
// Point With Direction
//
template<typename T>
inline r2::Point<T> operator+( const r2::Point<T>& p, const r2::Direction4Bitwise& d )
{
	return r2::Point<T>( p.GetX() + d.GetX(), p.GetY() + d.GetY() );
}

template<typename T>
inline void operator+=( r2::Point<T>& p, const r2::Direction4Bitwise& d )
{
	p.Plus( d.GetX(), d.GetY() );
}



template<typename T>
inline r2::Point<T> operator-( const r2::Point<T>& p, const r2::Direction4Bitwise& d )
{
	return r2::Point<T>( p.GetX() - d.GetX(), p.GetY() - d.GetY() );
}

template<typename T>
inline void operator-=( r2::Point<T>& p, const r2::Direction4Bitwise& d )
{
	p.Minus( d.GetX(), d.GetY() );
}



namespace r2
{
	template<typename T>
	inline r2::Point<T> dir2point( const r2::Direction4Bitwise& d )
	{
		return r2::Point<T>( static_cast< T >( d.GetX() ), static_cast< T >( d.GetY() ) );
	}
}






//
// Point With State
//
template<typename T>
inline r2::Point<T> operator+( const r2::Point<T>& p, const r2::Direction4Bitwise::eState& s )
{
	const r2::Direction4Bitwise d( s );
	return p + d;
}

template<typename T>
inline void operator+=( r2::Point<T>& p, const r2::Direction4Bitwise::eState& s )
{
	const r2::Direction4Bitwise d( s );
	p += d;
}



template<typename T>
inline r2::Point<T> operator-( const r2::Point<T>& p, const r2::Direction4Bitwise::eState& s )
{
	const r2::Direction4Bitwise d( s );
	return p - d;
}

template<typename T>
inline void operator-=( r2::Point<T>& p, const r2::Direction4Bitwise::eState& s )
{
	const r2::Direction4Bitwise d( s );
	p -= d;
}



namespace r2
{
	template<typename T>
	inline r2::Point<T> dir2point( const r2::Direction4Bitwise::eState& s )
	{
		const r2::Direction4Bitwise d( s );
		return r2::Point<T>( static_cast< T >( d.GetX() ), static_cast< T >( d.GetY() ) );
	}
}