#pragma once

namespace r2
{
	class Direction8BitwiseState
	{
	public:
		enum class eState
		{
			NONE = 0,

			Up			= 1 << 0,
			Up_Right	= 1 << 1,
			Right		= 1 << 2,
			Down_Right	= 1 << 3,
			Down		= 1 << 4,
			Down_Left	= 1 << 5,
			Left		= 1 << 6,
			Up_Left		= 1 << 7,

			FIRST = Up,
			END = Up_Left,

			SIZE = 8,
			HALF_SIZE = SIZE / 2,

			ALL = Up | Up_Right | Right | Down_Right | Down | Down_Left | Left | Up_Left,
		};

		using CoordinateT = char;


		static eState GetRandomState();

		static void ConvertState2Point( const eState state, CoordinateT* out_x, CoordinateT* out_y );
		static void ConvertPoint2State( const CoordinateT x, const CoordinateT y, eState* out_state );

		static eState ConvertInteger2State( const int value );

		static bool IsDiagonalState( const eState state );

		static eState Rotate( const eState state, const bool bRight );
		static eState Reverse( const eState state );
	};
}
