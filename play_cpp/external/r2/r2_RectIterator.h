//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.08.01 PM.08.22
// # Version			: 1.0.0
//

#pragma once

#include "r2_Assert.h"
#include "r2_RemovePointer.h"

namespace r2
{
	template<typename T>
	class RectConstIterator
	{
	public:
		using ValueT = r2::RemovePointer_T<T>;
		using PointT = typename ValueT::PointT;



		RectConstIterator() : mpRect( nullptr ), mPoint( 0, 0 )
		{}
		explicit RectConstIterator( const ValueT* rect_ptr ) : mpRect( rect_ptr ), mPoint( 0, 0 )
		{
			R2ASSERT( nullptr != mpRect, "" );

			mPoint = rect_ptr->GetOrigin();
		}
		explicit RectConstIterator( const ValueT* rect_ptr, const PointT& p ) : mpRect( rect_ptr ), mPoint( p )
		{
			R2ASSERT( nullptr != mpRect, "" );
		}



		RectConstIterator& operator++()
		{
			mPoint.PlusX( 1 );

			if( mpRect->GetMaxX() < mPoint.GetX() )
			{
				mPoint.SetX( mpRect->GetMinX() );
				mPoint.PlusY( 1 );
			}

			return ( *this );
		}
		RectConstIterator& operator--()
		{
			mPoint.MinusX( 1 );
			return ( *this );
		}



		bool operator==( const RectConstIterator& other ) const
		{
			return ( other.mpRect == mpRect ) && ( other.mPoint == mPoint );
		}
		bool operator!=( const RectConstIterator& other ) const
		{
			return !operator==( other );
		}



		const PointT& operator*() const
		{
			return ( *( operator->() ) );
		}
		const PointT* operator->() const
		{
			R2ASSERT( nullptr != mpRect, "" );

			return &mPoint;
		}



		const ValueT* mpRect;
		PointT mPoint;
	};
}