#include "play_math_vector2_transform.hpp"
#include "play_math___helper_common.hpp"
#include "play_math___helper_vector2.hpp"
#include "play_math___helper_matrix22.hpp"
using namespace play_math;

#include "r2tm/r2tm_inspector.hpp"

namespace play_math_vector2_transform
{
	r2tm::TitleFunctionT Rotation_X__Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector2 : Rotation X - Basic";
		};
	}
	r2tm::DoFunctionT Rotation_X__Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUT_SOURCE_READY;

			LS();

			{
				OUT_SUBJECT( "데카르트 좌표계" );
				OUT_COMMENT( "점의 위치를 x, y 와 같이 수평 수직 거리로 표현" );

				LF();

				OUT_SUBJECT( "극좌표계" );
				OUT_COMMENT( "한 점의 위치를 거리와 양의 x축 으로부터의 각으로 표현" );
			}

			LF();

			OUT_SUBJECT( "2차원 벡터 회전 공식 유도 과정" );
			OUT_COMMENT( "P의 좌표가 ( x, y )" );
			OUT_COMMENT( "원점에서 P 까지의 거리 r" );
			OUT_COMMENT( "x축과 P가 이루는 각도 θ" );
			OUT_COMMENT( "x = r * cos(θ)" );
			OUT_COMMENT( "y = r * sin(θ)" );

			LF();

			OUT_COMMENT( "P를 θ` 만큼 회전" );
			OUT_COMMENT( "x` = r * cos(θ + θ`)" );
			OUT_COMMENT( "y` = r * sin(θ + θ`)" );
			OUT_COMMENT( "\t" "삼각함수의 덧셈 정리 적용" );
			OUT_COMMENT( "\t" "cos( A + B ) = ( cos(A) * cos(B) ) - ( sin(A) * sin(B) )" );
			OUT_COMMENT( "\t" "sin( A + B ) = ( sin(A) * cos(B) ) + ( cos(A) * sin(B) )" );
			OUT_COMMENT( "x` = r * ( ( cos(θ) * cos(θ`) ) - ( sin(θ) * sin(θ`) ) )" );
			OUT_COMMENT( "y` = r * ( ( sin(θ) * cos(θ`) ) + ( cos(θ) * sin(θ`) ) )" );

			LF();

			OUT_COMMENT( "x` = ( r * cos(θ) * cos(θ`) ) - ( r * sin(θ) * sin(θ`) )" );
			OUT_COMMENT( "y` = ( r * sin(θ) * cos(θ`) ) + ( r * cos(θ) * sin(θ`) )" );

			LF();

			OUT_COMMENT( "x` = ( x * cos(θ`) ) - ( y * sin(θ`) )" );
			OUT_COMMENT( "y` = ( y * cos(θ`) ) + ( x * sin(θ`) )" );

			LS();

			OUT_SOURCE_BEGIN;
			const auto RX = []( Vec2 v, float radian )->Vec2
			{
				return Vec2(
					  ( v.x * std::cos( radian ) ) - ( v.y * std::sin( radian ) )
					, ( v.x * std::sin( radian ) ) + ( v.y * std::cos( radian ) )
				);
			};
			OUT_SOURCE_END;

			LS();

			{
				EXPECT_EQ( Vec2( -1.f, 0.f ), RX( VEC2_Y, Deg2Rad( 90 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Rotation_X::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector2 : Rotation X";
		};
	}
	r2tm::DoFunctionT Rotation_X::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "2차원 좌표 회전 공식" );
			OUT_COMMENT( "x` = ( x * cos(θ`) ) - ( y * sin(θ`) )" );
			OUT_COMMENT( "y` = ( y * cos(θ`) ) + ( x * sin(θ`) )" );

			LF();

			OUT_SUBJECT( "행렬 변환" );
			OUT_COMMENT( "cos(θ`), -sin(θ`)" );
			OUT_COMMENT( "sin(θ`), cos(θ`)" );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			const auto B = []( const float radian )->Mat22
			{
				return Mat22(
					  std::cos( radian ), -std::sin( radian )
					, std::sin( radian ), std::cos( radian )
				);
			};
			OUT_SOURCE_END;

			LS();

			{
				DECL_MAIN( const Mat22 R = B( Deg2Rad( 90.f ) ) );

				LF();

				EXPECT_EQ( Vec2( -1.f, 0.f ), R * VEC2_Y );
			}

			LS();

			{
				DECL_MAIN( const Mat22 R = B( Deg2Rad( 180.f ) ) );

				LF();

				EXPECT_EQ( Vec2( 0.f, -1.f ), R * VEC2_Y );
			}

			LS();
			{
				DECL_MAIN( const Mat22 R = B( Deg2Rad( 270.f ) ) );

				LF();

				EXPECT_EQ( Vec2( 1.f, 0.f ), R * VEC2_Y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}