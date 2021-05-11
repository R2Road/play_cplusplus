#pragma once

#include "r2_Point.h"

namespace r2
{
	class Camera
	{
	public:
		Camera();

		void SetPoint( const r2::Point& point )
		{
			mPoint = point;
		}

	private:
		r2::Point mPoint;
	};
}