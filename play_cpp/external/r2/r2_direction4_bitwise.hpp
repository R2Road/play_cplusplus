//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2025.08.26 PM.01.40
// # Version			: 1.1.0
//

#pragma once

#include "r2_direction4_bitwise_state.hpp"

namespace r2
{
	class Direction4Bitwise
	{
	public:
		using StateT = r2::Direction4BitwiseState;
		using eState = StateT::eState;
		using CoordinateT = StateT::CoordinateT;



		Direction4Bitwise();
		explicit Direction4Bitwise( const eState state );
		explicit Direction4Bitwise( const CoordinateT x, const CoordinateT y );

		

		//
		//
		//
		eState GetState() const
		{
			return mState;
		}
		CoordinateT GetX() const
		{
			return mX;
		}
		CoordinateT GetY() const
		{
			return mY;
		}



		bool Equal( const CoordinateT x, const CoordinateT y ) const
		{
			return ( x == mX ) && ( y == mY );
		}



		//
		//
		//
		void SetState( const eState state );
		void SetDirection( const CoordinateT x, const CoordinateT y );



		//
		//
		//
		void Rotate( const bool bRight );
		void RotateByAmount( const bool bRight, const int amount );
		void Reverse();



	private:
		eState mState;
		CoordinateT mX;
		CoordinateT mY;
	};
}
