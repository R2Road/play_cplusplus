#include "play_math_matrix.h"
#include "play_math___helper_common.h"
#include "play_math___helper_vector2.h"
#include "play_math___helper_matrix22.h"
using namespace play_math;

#include "r2tm/r2tm_Inspector.h"

namespace play_math_matrix
{
	r2tm::TitleFunctionT RotationX__Vector2__Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Matrix : Rotation X : Vector2 - Basic";
		};
	}
	r2tm::DoFunctionT RotationX__Vector2__Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			{
				OUTPUT_SUBJECT( "데카르트 좌표계" );
				OUTPUT_COMMENT( "점의 위치를 x, y 와 같이 수평 수직 거리로 표현" );

				LF();

				OUTPUT_SUBJECT( "극좌표계" );
				OUTPUT_COMMENT( "한 점의 위치를 거리와 양의 x축 으로부터의 각으로 표현" );
			}

			LF();

			OUTPUT_SUBJECT( "2차원 벡터 회전 공식 유도 과정" );
			OUTPUT_COMMENT( "P의 좌표가 ( x, y )" );
			OUTPUT_COMMENT( "원점에서 P 까지의 거리 r" );
			OUTPUT_COMMENT( "x축과 P가 이루는 각도 θ" );
			OUTPUT_COMMENT( "x = r * cos(θ)" );
			OUTPUT_COMMENT( "y = r * sin(θ)" );

			LF();

			OUTPUT_COMMENT( "P를 θ` 만큼 회전" );
			OUTPUT_COMMENT( "x` = r * cos(θ + θ`)" );
			OUTPUT_COMMENT( "y` = r * sin(θ + θ`)" );
			OUTPUT_COMMENT( "\t" "삼각함수의 덧셈 정리 적용" );
			OUTPUT_COMMENT( "\t" "cos( A + B ) = ( cos(A) * cos(B) ) - ( sin(A) * sin(B) )" );
			OUTPUT_COMMENT( "\t" "sin( A + B ) = ( sin(A) * cos(B) ) + ( cos(A) * sin(B) )" );
			OUTPUT_COMMENT( "x` = r * ( ( cos(θ) * cos(θ`) ) - ( sin(θ) * sin(θ`) ) )" );
			OUTPUT_COMMENT( "y` = r * ( ( sin(θ) * cos(θ`) ) + ( cos(θ) * sin(θ`) ) )" );

			LF();

			OUTPUT_COMMENT( "x` = ( r * cos(θ) * cos(θ`) ) - ( r * sin(θ) * sin(θ`) )" );
			OUTPUT_COMMENT( "y` = ( r * sin(θ) * cos(θ`) ) + ( r * cos(θ) * sin(θ`) )" );

			LF();

			OUTPUT_COMMENT( "x` = ( x * cos(θ`) ) - ( y * sin(θ`) )" );
			OUTPUT_COMMENT( "y` = ( y * cos(θ`) ) + ( x * sin(θ`) )" );

			LS();

			OUTPUT_SOURCE_BEGIN;
			const auto RX = []( Vec2 v, float radian )->Vec2
			{
				return Vec2(
					  ( v.x * std::cos( radian ) ) - ( v.y * std::sin( radian ) )
					, ( v.x * std::sin( radian ) ) + ( v.y * std::cos( radian ) )
				);
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				EXPECT_EQ( Vec2( -1.f, 0.f ), RX( VEC2_Y, Deg2Rad( 90 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT RotationX__Vector2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Matrix : Rotation X : Vector2";
		};
	}
	r2tm::DoFunctionT RotationX__Vector2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "2차원 좌표 회전 공식" );
			OUTPUT_COMMENT( "x` = ( x * cos(θ`) ) - ( y * sin(θ`) )" );
			OUTPUT_COMMENT( "y` = ( y * cos(θ`) ) + ( x * sin(θ`) )" );

			LF();

			OUTPUT_SUBJECT( "행렬 변환" );
			OUTPUT_COMMENT( "cos(θ`), -sin(θ`)" );
			OUTPUT_COMMENT( "sin(θ`), cos(θ`)" );

			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			const auto B = []( const float radian )->Mat22
			{
				return Mat22(
					  std::cos( radian ), -std::sin( radian )
					, std::sin( radian ), std::cos( radian )
				);
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				DECLARATION_MAIN( const Mat22 R = B( Deg2Rad( 90.f ) ) );

				LF();

				EXPECT_EQ( Vec2( -1.f, 0.f ), R * VEC2_Y );
			}

			LS();

			{
				DECLARATION_MAIN( const Mat22 R = B( Deg2Rad( 180.f ) ) );

				LF();

				EXPECT_EQ( Vec2( 0.f, -1.f ), R * VEC2_Y );
			}

			LS();
			{
				DECLARATION_MAIN( const Mat22 R = B( Deg2Rad( 270.f ) ) );

				LF();

				EXPECT_EQ( Vec2( 1.f, 0.f ), R * VEC2_Y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}