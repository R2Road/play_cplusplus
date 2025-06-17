//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.07.07 PM.03.19
// # Version			: 1.2.0
//

#pragma once

#include <limits> // std::numeric_limits

#include "r2_Point.h"

namespace r2
{
	template<typename Coordinate_T, typename Linear_T = std::size_t>
	class GridIndexConverter
	{
	public:
		using CoordinateT = Coordinate_T;
		using LinearT     = Linear_T;
		using PointT      = r2::Point<CoordinateT>;


		explicit GridIndexConverter( const CoordinateT width ) :
			  mWidth( ( 
				  1 < width
				? width
				: 1
			) )
			, mHeight( static_cast<CoordinateT>(
				  std::numeric_limits<LinearT>::max() / mWidth > std::numeric_limits<CoordinateT>::max()
				? std::numeric_limits<CoordinateT>::max()
				: std::numeric_limits<LinearT>::max() / mWidth
			) )
			, mLinearEnd( To_Linear( mWidth, mHeight ) )
		{}

		explicit GridIndexConverter( const CoordinateT width, const CoordinateT height ) :
			  mWidth( (
				  1 < width
				? width
				: 1
			) )
			, mHeight( (
				  1 < height
				? height
				: 1
			) )
			, mLinearEnd( To_Linear( mWidth, mHeight ) )
		{}

		CoordinateT GetWidth() const
		{
			return mWidth;
		}
		CoordinateT GetHeight() const
		{
			return mHeight;
		}
		LinearT GetLinerEnd() const
		{
			return mLinearEnd;
		}

		PointT To_Point( LinearT linear_index ) const
		{
			linear_index = (
				  0 > linear_index
				? 0
				: ( mLinearEnd > linear_index ? linear_index : mLinearEnd )
			);

			const CoordinateT y = static_cast<CoordinateT>( linear_index / mWidth );
			const CoordinateT x = static_cast<CoordinateT>( linear_index - ( y * mWidth ) );

			return PointT{ x, y };
		}
		LinearT To_Linear( const PointT point_index ) const
		{
			return To_Linear( point_index.GetX(), point_index.GetY() );
		}
		LinearT To_Linear( const CoordinateT x, const CoordinateT y ) const
		{
			const LinearT fixed_x = (
				  0 > x
				? 0
				: ( mWidth > x ? x : mWidth - 1 )
			);

			const LinearT fixed_y = (
				  0 > y
				? 0
				: ( mHeight > y ? y : mHeight - 1 )
			);

			return fixed_x + ( fixed_y * mWidth );
		}

	private:
		CoordinateT mWidth;
		CoordinateT mHeight;
		LinearT mLinearEnd;	
	};
}
