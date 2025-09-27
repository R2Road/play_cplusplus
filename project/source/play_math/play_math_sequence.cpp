#include "play_math_sequence.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_math_sequence
{
	r2tm::TitleFunctionT ArithmeticSequence_Sum::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "등차 수열의 합";
		};
	}
	r2tm::DoFunctionT ArithmeticSequence_Sum::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "일반 적인 해결책" );
				OUT_COMMENT( "sum = 1 + 2 + ..... + ( n - 1 ) + n" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				const auto S = []( const int start, const int end )->int
				{
					int sum = 0;

					for( int i = start; end >= i; ++i )
					{
						sum += i;
					}

					return sum;
				};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( S( 3, 6 ) );
			}

			LS();

			{
				OUT_SUBJECT( "수학적 귀납법 이용( 연역적 증명 )" );

				LF();

				OUT_SUBJECT( "유도 과정" );
				OUT_COMMENT( "sum 과 sum의 앞/뒤를 바꾼 sum' 를 더한다." );
				OUT_COMMENT( "sum  = 1 + 2 + ..... + ( n - 1 ) + n" );
				OUT_COMMENT( "sum' = n + ( n - 1 ) + ..... + 2 + 1" );

				LF();


				LF();

				OUT_COMMENT( "2sum = ( 1 + n ) + ( 2 + n - 1 ) + ..... + ( 2 + n - 1 ) + ( 1 + n )" );
				OUT_COMMENT( "2sum = ( 1 + n ) + ( 1 + n ) + ..... + ( 1 + n ) + ( 1 + n )" );

				LF();

				OUT_COMMENT( "위 식을 정리하면 " );
				OUT_COMMENT( "2sum = n( 1 + n )" );
				OUT_COMMENT( "sum = ( n( 1 + n ) ) / 2" );

				LF();

				OUT_COMMENT( "위 식을 다양한 수열에 적용되게 정리 하면 " );
				OUT_COMMENT( "sum = ( 수의 갯수( 첫 수 + 끝 수 ) ) / 2" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				const auto S = []( const int start, const int end )->int
				{
					int sum = 0;

					const int n = ( end - start ) + 1;
					sum = ( n * ( start + end ) ) / 2;

					return sum;
				};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( S( 3, 6 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}