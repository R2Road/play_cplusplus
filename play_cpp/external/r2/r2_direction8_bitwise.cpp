#include "r2_direction8_bitwise.hpp"

namespace r2
{
	Direction8Bitwise::Direction8Bitwise() :
		  mState( eState::NONE )
		, mX( 0 ), mY( 0 )
	{}

	Direction8Bitwise::Direction8Bitwise( const eState state ) :
		  mState( state )
		, mX( 0 ), mY( 0 )
	{
		StateT::ConvertState2Point( mState, &mX, &mY );
	}

	Direction8Bitwise::Direction8Bitwise( const CoordinateT x, const CoordinateT y ) :
		  mState( eState::NONE )
		, mX( 0 ), mY( 0 )
	{
		StateT::ConvertPoint2State( x, y, &mState );
		StateT::ConvertState2Point( mState, &mX, &mY );
	}



	void Direction8Bitwise::SetState( const eState state )
	{
		mState = state;
		StateT::ConvertState2Point( mState, &mX, &mY );
	}
	void Direction8Bitwise::SetDirection( const CoordinateT x, const CoordinateT y )
	{
		StateT::ConvertPoint2State( x, y, &mState );
		StateT::ConvertState2Point( mState, &mX, &mY );
	}



	void Direction8Bitwise::Rotate( const bool bRight )
	{
		mState = StateT::Rotate( mState, bRight);
		StateT::ConvertState2Point( mState, &mX, &mY );
	}

	void Direction8Bitwise::RotateByAmount( const bool bRight, const int amount )
	{
		for( int i = 0; amount > i; ++i )
		{
			mState = StateT::Rotate( mState, bRight );
		}
		StateT::ConvertState2Point( mState, &mX, &mY );
	}

	void Direction8Bitwise::Reverse()
	{
		mState = StateT::Reverse( mState );
		StateT::ConvertState2Point( mState, &mX, &mY );
	}
}
