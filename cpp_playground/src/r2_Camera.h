#pragma once

#include "r2_PointInt.h"

namespace r2
{
	class Camera
	{
	public:
		Camera();

		void SetPoint( const r2::PointInt& point )
		{
			mPoint = point;
		}
		void SetPoint( const int x, const int y )
		{
			mPoint.Set( x, y );
		}

	private:
		r2::PointInt mPoint;
	};
}