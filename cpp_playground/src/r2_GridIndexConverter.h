#pragma once

#include "r2_Point.h"

namespace r2
{
	class GridIndexConverter
	{
	public:
		GridIndexConverter( const int width, const int height );

		int GetWidth() const { return mWidth; }
		int GetHeight() const { return mHeight; }
		int GetLinerEnd() const { return mLinearEnd; }

		r2::Point To_Point( const int linear_index ) const;
		int To_Linear( const r2::Point point_index ) const;
		int To_Linear( const int x, const int y ) const;

	private:
		const int mWidth;
		const int mHeight;
		const int mLinearEnd;	
	};
}
