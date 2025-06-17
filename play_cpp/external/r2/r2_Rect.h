//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.08.01 PM.10.26
// # Version			: 1.1.1
//

#pragma once

#include <algorithm>
#include <cmath>

#include "r2_Point.h"
#include "r2_Size.h"
#include "r2_RectIterator.h"
#include "r2_TypeTraits.h"

namespace r2
{
	template<typename T>
	class Rect
	{
	public:
		static_assert(
			   r2::is_same_v<T, char>
			|| r2::is_same_v<T, short>
			|| r2::is_same_v<T, int>
			|| r2::is_same_v<T, long long>
			, "r2::Rect - Not Allowed Type"
		);



		using ElementT = T;
		using MyT = Rect<ElementT>;
		using PointT = r2::Point<ElementT>;
		using SizeT = r2::Size<ElementT>;

		using ConstIteratorT = r2::RectConstIterator<MyT>;



		static const MyT& GetZero()
		{
			static const MyT rect_zero( 0, 0, 0, 0 );
			return rect_zero;
		}



		Rect() : mOrigin( 0, 0 ), mSize( 0, 0 )
		{}
		explicit Rect( const ElementT x, const ElementT y, const ElementT width, const ElementT height ) : mOrigin( x, y ), mSize( width, height )
		{}
		explicit Rect( const PointT origin, const SizeT size ) : mOrigin( origin ), mSize( size )
		{}
		explicit Rect( const PointT origin, const ElementT width, const ElementT height ) : mOrigin( origin ), mSize( width, height )
		{}
		explicit Rect( const ElementT x, const ElementT y, const SizeT size ) : mOrigin( x, y ), mSize( size )
		{}
		explicit Rect( const PointT origin ) : mOrigin( origin ), mSize( 0, 0 )
		{}
		explicit Rect( const SizeT size ) : mOrigin( 0, 0 ), mSize( size )
		{}
		explicit Rect( const PointT point1, const PointT point2 )
		{
			Set( point1, point2 );
		}



		//
		// Iterator
		//
		ConstIteratorT begin() const
		{
			return ConstIteratorT( this, GetOrigin() );
		}
		ConstIteratorT end() const
		{
			return ConstIteratorT( this, PointT( GetMinX(), GetMaxY() + 1 ) );
		}



		//
		// Operator
		//
		bool operator==( const MyT& rhs ) const
		{
			return mOrigin == rhs.GetOrigin() && mSize == rhs.GetSize();
		}
		bool operator!=( const MyT& rhs ) const
		{
			return !( *this == rhs );
		}

		MyT& operator=( const MyT& other )
		{
			Set( other.mOrigin.GetX(), other.mOrigin.GetY(), other.mSize.GetWidth(), other.mSize.GetHeight() );
			return *this;
		}



		//
		//
		//
		inline void Set( const ElementT x, const ElementT y, const ElementT width, const ElementT height )
		{
			mOrigin.Set( x, y );
			mSize.Set( width, height );
		}
		inline void Set( const PointT point1, const PointT point2 )
		{
			Set(
				std::min( point1.GetX(), point2.GetX() )
				, std::min( point1.GetY(), point2.GetY() )
				, std::max( point1.GetX(), point2.GetX() ) - std::min( point1.GetX(), point2.GetX() )
				, std::max( point1.GetY(), point2.GetY() ) - std::min( point1.GetY(), point2.GetY() )
			);
		}

		//
		//
		//
		inline void SetOrigin( const ElementT x, const ElementT y )
		{
			mOrigin.Set( x, y );
		}
		inline void SetOrigin( const PointT point )
		{
			mOrigin = ( point );
		}
		inline void MoveOrigin( const ElementT move_x, const ElementT move_y )
		{
			mOrigin.Plus( move_x, move_y );
		}

		//
		//
		//
		inline void SetSize( const ElementT width, const ElementT height )
		{
			mSize.Set( width, height );
		}
		inline void SetSize( const SizeT size )
		{
			mSize = ( size );
		}
		inline void ChangeSize( const ElementT change_w, const ElementT change_h )
		{
			mSize.Plus( change_w, change_h );
		}



		//
		//
		//
		inline const PointT& GetOrigin() const
		{
			return mOrigin;
		}
		inline const SizeT& GetSize() const
		{
			return mSize;
		}

		inline ElementT GetMinX() const
		{
			return mOrigin.GetX();
		}
		inline ElementT GetMinY() const
		{
			return mOrigin.GetY();
		}

		inline ElementT GetMaxX() const
		{
			return mOrigin.GetX() + mSize.GetWidth();
		}
		inline ElementT GetMaxY() const
		{
			return mOrigin.GetY() + mSize.GetHeight();
		}
		inline PointT GetMax() const
		{
			return PointT( GetMaxX(), GetMaxY() );
		}

		inline ElementT GetMidX() const
		{
			return mOrigin.GetX() + ( mSize.GetWidth() / 2 );
		}
		inline ElementT GetMidY() const
		{
			return mOrigin.GetY() + ( mSize.GetHeight() / 2 );
		}
		inline PointT GetMid() const
		{
			return PointT( GetMidX(), GetMidY() );
		}

		inline ElementT GetWidth() const
		{
			//
			// Summury
			// - default size is "1"
			//
			// Example
			// - size 4, 3
			//  @***	- "@" is origin
			//  ****	- "*" is size
			//  ****
			//
			return static_cast<ElementT>( std::abs( mSize.GetWidth() ) ) + 1;
		}
		inline ElementT GetHeight() const
		{
			return static_cast<ElementT>( std::abs( mSize.GetHeight() ) ) + 1;
		}
		inline std::size_t GetWide() const
		{
			return GetWidth() * GetHeight();
		}
		inline double GetDiagonalLength() const
		{
			return std::sqrt( ( GetWidth() * GetWidth() ) + ( GetHeight() * GetHeight() ) );
		}



		//
		//
		//
		bool IsIn( const PointT& point ) const
		{
			return IsIn( point.GetX(), point.GetY() );
		}
		bool IsIn( const ElementT x, const ElementT y ) const
		{
			return ( 
				   x >= GetMinX() && x <= GetMaxX()
				&& y >= GetMinY() && y <= GetMaxY()
			);
		}



		//
		//
		//
		PointT Clamp( const PointT& point ) const
		{
			return Clamp( point.GetX(), point.GetY() );
		}
		PointT Clamp( const ElementT x, const ElementT y ) const
		{
			ElementT fx = 0;
			ElementT fy = 0;

			//
			// X 좌표가 사각형의 가로 영역 안에 있다면 dx = x
			// X 좌표가 사각형의 가로 영역 밖에 있다면 계산
			//
			//       X X X X X
			//       
			//       # # # # #
			//       # # # # # 
			//       # # # # #
			//       # # # # #
			//       # # # # #
			//
			//       X X X X X
			//
			// 그 밖의 경우에는 각 모서리와의 거리를 계산하여 작은 쪽을 사용한다.
			//
			fx = static_cast<ElementT>(
				  ( GetMinX() > x || x > GetMaxX() )

				// Rect 영역 밖이면 가까운 모서리 값을 사용
				? ( std::abs( GetMinX() - x ) < std::abs( GetMaxX() - x ) ? GetMinX() : GetMaxX() )

				: ( x )
			);

			fy = static_cast<ElementT>(
				  ( GetMinY() > y || y > GetMaxY() )

				// Rect 영역 밖이면 가까운 모서리 값을 사용
				? ( std::abs( GetMinY() - y ) < std::abs( GetMaxY() - y ) ? GetMinY() : GetMaxY() )

				: ( y )
			);

			return PointT( fx, fy );
		}



		//
		//
		//
		PointT Distance( const PointT& point ) const
		{
			return Distance( point.GetX(), point.GetY() );
		}
		PointT Distance( const ElementT x, const ElementT y ) const
		{
			ElementT dx = 0;
			ElementT dy = 0;

			//
			// X 좌표가 사각형의 가로 영역 안에 있다면 dx = 0
			// X 좌표가 사각형의 가로 영역 밖에 있다면 계산
			//
			//       X X X X X
			//       
			//       # # # # #
			//       # # # # # 
			//       # # # # #
			//       # # # # #
			//       # # # # #
			//
			//       X X X X X
			//
			// 위의 경우 dx = 0
			//
			// 그 밖의 경우에는 각 모서리와의 거리를 계산하여 작은 쪽을 사용한다.
			//
			dx = static_cast<ElementT>(
				  ( GetMinX() > x || x > GetMaxX() )
				? ( std::min( std::abs( GetMinX() - x ), std::abs( GetMaxX() - x ) ) )
				: 0
			);

			dy = static_cast<ElementT>(
				  ( GetMinY() > y || y > GetMaxY() )
				? ( std::min( std::abs( GetMinY() - y ), std::abs( GetMaxY() - y ) ) )
				: 0
			);

			return PointT( dx, dy );
		}



		//
		//
		//
		bool IntersectsRect( const MyT& rect ) const
		{
			return !(
				GetMaxX() < rect.GetMinX()
				|| rect.GetMaxX() < GetMinX()
				|| GetMaxY() < rect.GetMinY()
				|| rect.GetMaxY() < GetMinY()
			);
		}
		bool ContainsRect( const MyT& rect ) const
		{
			return !(
				GetMinX() > rect.GetMinX()
				|| GetMaxX() < rect.GetMaxX()
				|| GetMinY() > rect.GetMinY()
				|| GetMaxY() < rect.GetMaxY()
			);
		}



		//
		//
		//
		void Merge( const MyT& rect )
		{
			const ElementT minX = std::min( GetMinX(), rect.GetMinX() );
			const ElementT minY = std::min( GetMinY(), rect.GetMinY() );
			const ElementT maxX = std::max( GetMaxX(), rect.GetMaxX() );
			const ElementT maxY = std::max( GetMaxY(), rect.GetMaxY() );
			Set( minX, minY, maxX - minX, maxY - minY );
		}

		//
		//
		//
		MyT UnionWithRect( const MyT & rect ) const
		{
			ElementT thisLeftX = GetMinX();
			ElementT thisRightX = GetMaxX();
			ElementT thisTopY = GetMinY();
			ElementT thisBottomY = GetMaxY();

			if( thisRightX < thisLeftX )
			{
				std::swap( thisRightX, thisLeftX );   // This rect has negative width
			}

			if( thisBottomY < thisTopY )
			{
				std::swap( thisTopY, thisBottomY );   // This rect has negative height
			}

			ElementT otherLeftX = rect.GetMinX();
			ElementT otherRightX = rect.GetMaxX();
			ElementT otherTopY = rect.GetMinY();
			ElementT otherBottomY = rect.GetMaxY();

			if( otherRightX < otherLeftX )
			{
				std::swap( otherRightX, otherLeftX );   // Other rect has negative width
			}

			if( otherBottomY < otherTopY )
			{
				std::swap( otherTopY, otherBottomY );   // Other rect has negative height
			}

			ElementT combinedLeftX = std::min( thisLeftX, otherLeftX );
			ElementT combinedRightX = std::max( thisRightX, otherRightX );
			ElementT combinedTopY = std::min( thisTopY, otherTopY );
			ElementT combinedBottomY = std::max( thisBottomY, otherBottomY );

			return MyT( combinedLeftX, combinedTopY, combinedRightX - combinedLeftX, combinedBottomY - combinedTopY );
		}



		//
		//
		//
		MyT IntersectsWithRect( const MyT & rect ) const
		{
			ElementT thisLeftX = GetMinX();
			ElementT thisRightX = GetMaxX();
			ElementT thisTopY = GetMinY();
			ElementT thisBottomY = GetMaxY();

			if( thisRightX < thisLeftX )
			{
				std::swap( thisRightX, thisLeftX );   // This rect has negative width
			}

			if( thisBottomY < thisTopY )
			{
				std::swap( thisTopY, thisBottomY );   // This rect has negative height
			}

			ElementT otherLeftX = rect.GetMinX();
			ElementT otherRightX = rect.GetMaxX();
			ElementT otherTopY = rect.GetMinY();
			ElementT otherBottomY = rect.GetMaxY();

			if( otherRightX < otherLeftX )
			{
				std::swap( otherRightX, otherLeftX );   // Other rect has negative width
			}

			if( otherBottomY < otherTopY )
			{
				std::swap( otherTopY, otherBottomY );   // Other rect has negative height
			}

			ElementT combinedLeftX = std::max( thisLeftX, otherLeftX );
			ElementT combinedRightX = std::min( thisRightX, otherRightX );
			ElementT combinedTopY = std::max( thisTopY, otherTopY );
			ElementT combinedBottomY = std::min( thisBottomY, otherBottomY );

			return MyT( combinedLeftX, combinedTopY, combinedRightX - combinedLeftX, combinedBottomY - combinedTopY );
		}



	private:
		PointT mOrigin;
		SizeT mSize;
	};
}