#include "r2_direction8_bitwise_state.hpp"

#include "r2_random.hpp"

namespace r2
{
	Direction8BitwiseState::eState Direction8BitwiseState::GetRandomState()
	{
		return static_cast<eState>( 1 << r2::Random::GetInt( 0, 7 ) );
	}



	void Direction8BitwiseState::ConvertState2Point( const eState state, CoordinateT* out_x, CoordinateT* out_y )
	{
		switch( state )
		{
		case eState::Up:
			( *out_x ) = 0; ( *out_y ) = 1;
			break;
		case eState::Up_Right:
			( *out_x ) = 1; ( *out_y ) = 1;
			break;
		case eState::Right:
			( *out_x ) = 1; ( *out_y ) = 0;
			break;
		case eState::Down_Right:
			( *out_x ) = 1; ( *out_y ) = -1;
			break;
		case eState::Down:
			( *out_x ) = 0; ( *out_y ) = -1;
			break;
		case eState::Down_Left:
			( *out_x ) = -1; ( *out_y ) = -1;
			break;
		case eState::Left:
			( *out_x ) = -1; ( *out_y ) = 0;
			break;
		case eState::Up_Left:
			( *out_x ) = -1; ( *out_y ) = 1;
			break;

			//case eState::NONE:
		default:
			( *out_x ) = 0; ( *out_y ) = 0;
			break;
		}
	}
	void Direction8BitwiseState::ConvertPoint2State( const CoordinateT x, const CoordinateT y, eState* out_state )
	{
		if( x == 0 && y >= 1 )
		{
			( *out_state ) = eState::Up;
		}
		else if( x >= 1 && y >= 1 )
		{
			( *out_state ) = eState::Up_Right;
		}
		else if( x >= 1 && y == 0 )
		{
			( *out_state ) = eState::Right;
		}
		else if( x >= 1 && y <= -1 )
		{
			( *out_state ) = eState::Down_Right;
		}
		else if( x == 0 && y <= -1 )
		{
			( *out_state ) = eState::Down;
		}
		else if( x <= -1 && y <= -1 )
		{
			( *out_state ) = eState::Down_Left;
		}
		else if( x <= -1 && y == 0 )
		{
			( *out_state ) = eState::Left;
		}
		else if( x <= -1 && y >= 1 )
		{
			( *out_state ) = eState::Up_Left;
		}
		else
		{
			( *out_state ) = eState::NONE;
		}
	}



	Direction8BitwiseState::eState Direction8BitwiseState::ConvertInteger2State( const int value )
	{
		eState ret = static_cast<eState>( value );

		switch( ret )
		{
		case eState::Up:
		case eState::Up_Right:
		case eState::Right:
		case eState::Down_Right:
		case eState::Down:
		case eState::Down_Left:
		case eState::Left:
		case eState::Up_Left:
			break;

			//case eState::NONE:
		default:
			ret = eState::NONE;
			break;
		}

		return ret;
	}



	bool Direction8BitwiseState::IsDiagonalState( const eState state )
	{
		return (
			eState::Up_Right == state
			|| eState::Down_Right == state
			|| eState::Down_Left == state
			|| eState::Up_Left == state
		);
	}



	Direction8BitwiseState::eState Direction8BitwiseState::Rotate( const eState state, const bool bRight )
	{
		eState ret = ConvertInteger2State( static_cast<int>( state ) );

		if( eState::NONE != ret && eState::END >= ret )
		{
			ret = (
				bRight
				? ( eState::END <= ret ? eState::FIRST : static_cast<eState>( static_cast<int>( ret ) << 1 ) )
				: ( eState::FIRST >= ret ? eState::END : static_cast<eState>( static_cast<int>( ret ) >> 1 ) )
			);
		}

		return ret;
	}
	Direction8BitwiseState::eState Direction8BitwiseState::Reverse( const eState state )
	{
		eState ret = ConvertInteger2State( static_cast<int>( state ) );

		//
		// Up_Left 에서 Up 으로 넘어가는 것을 피하기 위해
		// 전체 상태의 절반 이전에는 <<
		// 전체 상태의 절반 이후에는 >>
		//
		if( eState::Down > ret )
		{
			ret = static_cast<eState>( static_cast<int>( ret ) << 4 );
		}
		else
		{
			ret = static_cast<eState>( static_cast<int>( ret ) >> 4 );
		}

		return ret;
	}
}
