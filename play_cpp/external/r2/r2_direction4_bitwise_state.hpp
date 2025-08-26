//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.06.02 AM.05.21
// # Version			: 1.0.1
//

#pragma once

namespace r2
{
	class Direction4BitwiseState
	{
	public:
		enum class eState
		{
			NONE = 0,

			Up			= 1 << 0,
			Right		= 1 << 1,
			Down		= 1 << 2,
			Left		= 1 << 3,

			FIRST = Up,
			END = Left,

			SIZE = 4,
			HALF_SIZE = SIZE / 2,

			ALL = Up | Right | Down | Left,
		};

		using CoordinateT = char;


		static eState GetRandomState();

		static void ConvertState2Point( const eState state, CoordinateT* out_x, CoordinateT* out_y );
		static eState ConvertPoint2State( const CoordinateT x, const CoordinateT y );

		static eState ConvertInteger2State( const int value );

		static eState Rotate( const eState state, const bool bRight );
		static eState Reverse( const eState state );
	};
}
