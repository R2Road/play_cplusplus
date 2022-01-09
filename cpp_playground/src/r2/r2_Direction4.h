#pragma once

#include "r2_Point.h"

namespace r2
{
	class Direction4
	{
	public:
		enum eState
		{
			None = 0,
			Up = 1,
			Right = 1 << 1,
			Down = 1 << 2,
			Left = 1 << 3,

			FIRST = Up,
			LAST = Left,
			ALL = Up | Right | Down | Left,
		};

		Direction4();
		Direction4( const eState state );

		eState GetState() const { return mState; }
		void SetState( eState state ) { mState = state; }

		void Rotate( const bool rotate_right );

		r2::Point GetPoint() const;

	private:
		eState mState;
	};
}
