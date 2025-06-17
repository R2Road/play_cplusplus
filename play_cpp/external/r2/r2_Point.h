//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.08.04 PM.05.30
// # Version			: 1.0.0
//

#pragma once

#include <cmath>
#include <stdint.h>

#include "r2_TypeTraits.h"

namespace r2
{
	template<typename T>
	class Point
	{
	public:
		static_assert(
			   r2::is_same_v<T, char>
			|| r2::is_same_v<T, unsigned char>

			|| r2::is_same_v<T, int16_t>
			|| r2::is_same_v<T, uint16_t>

			|| r2::is_same_v<T, int32_t>
			|| r2::is_same_v<T, uint32_t>

			|| r2::is_same_v<T, int64_t>
			|| r2::is_same_v<T, uint64_t>
		);
		using ValueT = T;
		using MyT = r2::Point<ValueT>;

		using LinearT = std::size_t;



		//
		//
		//
		static const MyT& GetZERO()
		{
			static const MyT ZERO( 0, 0 );
			return ZERO;
		}
		static const MyT& GetMINUS_ONE()
		{
			static const MyT MINUS_ONE( -1, -1 );
			return MINUS_ONE;
		}



		//
		//
		//
		Point() : mX( 0 ), mY( 0 )
		{}
		explicit Point( const ValueT x, const ValueT y ) : mX( x ), mY( y )
		{}



		//
		//
		//
		inline bool operator==( const MyT& right ) const
		{
			return Equal( right.mX, right.mY );
		}
		inline bool operator!=( const MyT& right ) const
		{
			return !Equal( right.mX, right.mY );
		}

		inline bool operator<( const MyT& right ) const
		{
			return ( mY < right.mY )
				? true
				: ( mY == right.mY ? mX < right.mX : false );
		}

		inline MyT operator-( const MyT& right ) const
		{
			return MyT( mX - right.mX, mY - right.mY );
		}
		inline MyT operator+( const MyT& right ) const
		{
			return MyT( mX + right.mX, mY + right.mY );
		}

		inline MyT& operator+=( const MyT& right )
		{
			Plus( right.mX, right.mY );
			return *this;
		}
		inline MyT& operator-=( const MyT& right )
		{
			Minus( right.mX, right.mY );
			return *this;
		}



		inline bool Equal( const ValueT x, const ValueT y ) const
		{
			return ( x == mX && y == mY );
		}



		//
		//
		//
		inline void SetZero()
		{
			mX = MyT::GetZERO().mX;
			mY = MyT::GetZERO().mY;
		}
		inline void SetMIinusOne()
		{
			mX = MyT::GetMINUS_ONE().mX;
			mY = MyT::GetMINUS_ONE().mY;
		}
		inline void Set( const ValueT x, const ValueT y )
		{
			mX = x;
			mY = y;
		}
		inline void SetX( const ValueT x )
		{
			mX = x;
		}
		inline void SetY( const ValueT y )
		{
			mY = y;
		}
		inline ValueT GetX() const
		{
			return mX;
		}
		inline ValueT GetY() const
		{
			return mY;
		}



		//
		//
		//
		inline void Plus( const ValueT x, const ValueT y )
		{
			mX += x;
			mY += y;
		}
		inline void PlusX( const ValueT x )
		{
			mX += x;
		}
		inline void PlusY( const ValueT y )
		{
			mY += y;
		}
		inline void Minus( const ValueT x, const ValueT y )
		{
			mX -= x;
			mY -= y;
		}
		inline void MinusX( const ValueT x )
		{
			mX -= x;
		}
		inline void MinusY( const ValueT y )
		{
			mY -= y;
		}



		//
		//
		//
		inline LinearT Distance( const ValueT x, const ValueT y ) const
		{
			return std::abs( mX - x ) + std::abs( mY - y );
		}
		inline LinearT Distance( const MyT& target ) const
		{
			return Distance( target.mX, target.mY );
		}
		inline LinearT Distance_DiagonalIsOne( const MyT& target ) const
		{
			const LinearT tempX = std::abs( mX - target.mX );
			const LinearT tempY = std::abs( mY - target.mY );
			return (
				  tempX >= tempY
				? tempX
				: tempY
			);
		}



		inline LinearT Length() const
		{
			return std::abs( mX ) + std::abs( mY );
		}



	private:
		ValueT mX;
		ValueT mY;
	};
}