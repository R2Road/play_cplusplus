#include "r2_direction4_bitwise_state.hpp"

#include "r2_random.hpp"

namespace r2
{
	Direction4BitwiseState::eState Direction4BitwiseState::GetRandomState()
	{
		return static_cast<eState>( 1 << r2::Random::GetInt(
			0
			, static_cast<int>( Direction4BitwiseState::eState::SIZE )
		) );
	}



	void Direction4BitwiseState::ConvertState2Point( const eState state, CoordinateT* out_x, CoordinateT* out_y )
	{
		switch( state )
		{
		case eState::Up:
			( *out_x ) = 0; ( *out_y ) = 1;
			break;
		case eState::Right:
			( *out_x ) = 1; ( *out_y ) = 0;
			break;
		case eState::Down:
			( *out_x ) = 0; ( *out_y ) = -1;
			break;
		case eState::Left:
			( *out_x ) = -1; ( *out_y ) = 0;
			break;

			//case eState::NONE:
		default:
			( *out_x ) = 0; ( *out_y ) = 0;
			break;
		}
	}
	Direction4BitwiseState::eState Direction4BitwiseState::ConvertPoint2State( const CoordinateT x, const CoordinateT y )
	{
		if( 1 <= x )
		{
			return eState::Right;
		}
		else if( -1 >= x )
		{
			return eState::Left;
		}
		else if( 1 <= y )
		{
			return eState::Up;
		}
		else if( -1 >= y )
		{
			return eState::Down;
		}

		return eState::NONE;
	}



	Direction4BitwiseState::eState Direction4BitwiseState::ConvertInteger2State( const int value )
	{
		eState ret = static_cast<eState>( value );

		switch( ret )
		{
		case eState::Up:
		case eState::Right:
		case eState::Down:
		case eState::Left:
			break;

			//case eState::NONE:
		default:
			ret = eState::NONE;
			break;
		}

		return ret;
	}



	Direction4BitwiseState::eState Direction4BitwiseState::Rotate( const eState state, const bool bRight )
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
	Direction4BitwiseState::eState Direction4BitwiseState::Reverse( const eState state )
	{
		eState ret = ConvertInteger2State( static_cast<int>( state ) );

		//
		// Up_Left 에서 Up 으로 넘어가는 것을 피하기 위해
		// 전체 상태의 절반 이전에는 <<
		// 전체 상태의 절반 이후에는 >>
		//
		if( eState::Down > ret )
		{
			ret = static_cast<eState>( static_cast<int>( ret ) << static_cast<int>( eState::HALF_SIZE ) );
		}
		else
		{
			ret = static_cast<eState>( static_cast<int>( ret ) >> static_cast<int>( eState::HALF_SIZE ) );
		}

		return ret;
	}
}
