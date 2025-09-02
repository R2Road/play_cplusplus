#include "r2_direction4_bitwise.hpp"

namespace r2
{
	Direction4Bitwise::Direction4Bitwise() :
		  mState( eState::NONE )
		, mX( 0 ), mY( 0 )
	{}

	Direction4Bitwise::Direction4Bitwise( const eState state ) :
		  mState( state )
		, mX( 0 ), mY( 0 )
	{
		StateT::ConvertState2Point( mState, &mX, &mY );
	}

	Direction4Bitwise::Direction4Bitwise( const CoordinateT x, const CoordinateT y ) :
		  mState( eState::NONE )
		, mX( 0 ), mY( 0 )
	{
		mState = StateT::ConvertPoint2State( x, y );
		StateT::ConvertState2Point( mState, &mX, &mY );
	}



	void Direction4Bitwise::SetState( const eState state )
	{
		mState = state;
		StateT::ConvertState2Point( mState, &mX, &mY );
	}
	void Direction4Bitwise::SetDirection( const CoordinateT x, const CoordinateT y )
	{
		mState = StateT::ConvertPoint2State( x, y );
		StateT::ConvertState2Point( mState, &mX, &mY );
	}



	void Direction4Bitwise::Rotate( const bool bRight )
	{
		mState = StateT::Rotate( mState, bRight);
		StateT::ConvertState2Point( mState, &mX, &mY );
	}
	void Direction4Bitwise::RotateByAmount( const bool bRight, const int amount )
	{
		for( int i = 0; amount > i; ++i )
		{
			mState = StateT::Rotate( mState, bRight );
		}
		StateT::ConvertState2Point( mState, &mX, &mY );
	}

	void Direction4Bitwise::Reverse()
	{
		mState = StateT::Reverse( mState );
		StateT::ConvertState2Point( mState, &mX, &mY );
	}
}
