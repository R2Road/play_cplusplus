#pragma once

#include "r2_PointInt.h"

namespace r2
{
	class GridIndexConverter
	{
	public:
		GridIndexConverter( const int width, const int height );

		r2::PointInt To_Point( const int linear_index ) const;
		int To_Linear( const r2::PointInt point_index ) const;
		int To_Linear( const int x, const int y ) const;

	private:
		int mWidth;
		int mHeight;
		int mLinearEnd;
	};
}
