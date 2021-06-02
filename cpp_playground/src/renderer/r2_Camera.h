#pragma once

#include "r2_RectInt.h"

namespace r2
{
	class Camera
	{
	public:
		Camera();

		int GetX() const
		{
			return mRect.GetOrigin().GetX();
		}
		int GetY() const
		{
			return mRect.GetOrigin().GetY();
		}
		r2::RectInt::MyPointT GetPoint() const
		{
			return mRect.GetOrigin();
		}
		r2::RectInt GetRect() const
		{
			return mRect;
		}

		void SetPoint( const r2::RectInt::MyPointT& point )
		{
			mRect.SetOrigin( point );
		}
		void SetPoint( const int x, const int y )
		{
			mRect.SetOrigin( x, y );
		}

	private:
		r2::RectInt mRect;
	};
}