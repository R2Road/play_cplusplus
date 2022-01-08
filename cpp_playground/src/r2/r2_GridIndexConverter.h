#pragma once

#include "r2_Point.h"

namespace r2
{
	class GridIndexConverter
	{
	public:
		GridIndexConverter( const int width, const int height );

		r2::Point To_Point( const int linear_index ) const;
		int To_Linear( const r2::Point point_index ) const;
		int To_Linear( const int x, const int y ) const;

	private:
		int mWidth;
		int mHeight;
		int mLinearEnd;
	};
}
