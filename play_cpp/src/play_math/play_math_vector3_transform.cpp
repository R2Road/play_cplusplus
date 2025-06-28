#include "play_math_vector3_transform.h"
#include "play_math___helper_common.h"
#include "play_math___helper_vector3.h"
#include "play_math___helper_matrix33.h"
using namespace play_math;

#include "r2tm/r2tm_Inspector.h"

namespace play_math_vector3_transform
{
	r2tm::TitleFunctionT Rotation_XZ::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Rotation X, Z";
		};
	}
	r2tm::DoFunctionT Rotation_XZ::GetDoFunction() const
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

			LF();

			OUTPUT_SUBJECT( "3차원 확장 변환" );
			OUTPUT_COMMENT( "기준 축을 제외한 나머지 축에 2차원 회전 적용" );

			LS();

			{
				OUTPUT_SUBJECT( "Z축 회전" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  std::cos( radian ), -std::sin( radian )  , 0
						, std::sin( radian ), std::cos( radian )   , 0
						, 0                 , 0                    , 1
					);
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( -1.f, 0.f, 0.f ), B( Deg2Rad( 90.f ) ) * VEC3_Y );
				EXPECT_EQ( Vec3( 0.f, -1.f, 0.f ), B( Deg2Rad( 180.f ) ) * VEC3_Y );
			}

			LS();
			
			{
				OUTPUT_SUBJECT( "X축 회전" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  1, 0                 , 0
						, 0, std::cos( radian ), -std::sin( radian )
						, 0, std::sin( radian ), std::cos( radian )
					);
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( 0.f, 0.f, 1.f ), B( Deg2Rad( 90.f ) ) * VEC3_Y );
				EXPECT_EQ( Vec3( 0.f, -1.f, 0.f ), B( Deg2Rad( 180.f ) ) * VEC3_Y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Rotation_Y::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Rotation Y";
		};
	}
	r2tm::DoFunctionT Rotation_Y::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "오른손 좌표계 회전의 대전제" );
			OUTPUT_COMMENT( "X축 회전은 Y축이 Z축 방향으로 이동" );
			OUTPUT_COMMENT( "Y축 회전은 Z축이 X축 방향으로 이동" );
			OUTPUT_COMMENT( "Z축 회전은 X축이 Y축 방향으로 이동" );

			LF();

			OUTPUT_SUBJECT( "Y축 회전은 위의 대전제에 맞추려면 공식의 조정이 요구된다." );

			LF();

			OUTPUT_SUBJECT( "기존 공식" );
			OUTPUT_COMMENT( "cos(θ`), -sin(θ`)" );
			OUTPUT_COMMENT( "sin(θ`),  cos(θ`)" );

			LF();

			OUTPUT_SUBJECT( "조정된 공식" );
			OUTPUT_COMMENT( " cos(θ`), sin(θ`)" );
			OUTPUT_COMMENT( "-sin(θ`), cos(θ`)" );

			LS();
			
			{
				OUTPUT_SUBJECT( "기존 공식 : 반대 방향으로 회전" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  std::cos( radian ) , 0, -std::sin( radian )
						, 0                  , 1, 0
						, std::sin( radian ) , 0, std::cos( radian )
					);
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( -1.f, 0.f, 0.f ), B( Deg2Rad( 90.f ) ) * VEC3_Z );
				EXPECT_EQ( Vec3( 0.f, 0.f, -1.f ), B( Deg2Rad( 180.f ) ) * VEC3_Z );
			}

			LS();

			{
				OUTPUT_SUBJECT( "조정된 공식" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  std::cos( radian )  , 0, std::sin( radian )
						, 0                   , 1, 0
						, -std::sin( radian ) , 0, std::cos( radian )
					);
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( 1.f, 0.f, 0.f ), B( Deg2Rad( 90.f ) ) * VEC3_Z );
				EXPECT_EQ( Vec3( 0.f, 0.f, -1.f ), B( Deg2Rad( 180.f ) ) * VEC3_Z );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Need::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Need : 기억할 필요가 있는 값들";
		};
	}
	r2tm::DoFunctionT Need::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "대각선 벡터의 길이" );

				LF();

				OUTPUT_VALUE( vec3_length( Vec3( 1, 1, 0 ) ) );

				LF();

				OUTPUT_VALUE( vec3_length( Vec3( 1, 1, 1 ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "단위 벡터가 45도 회전했을 때의 위치" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  std::cos( radian )  , 0, std::sin( radian )
						, 0                   , 1, 0
						, -std::sin( radian ) , 0, std::cos( radian )
					);
				};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( ( B( Deg2Rad( 45.f ) ) * VEC3_Z ) );

				LF();

				OUTPUT_VALUE( std::cos( Deg2Rad( 45.f ) ) );

				LF();

				OUTPUT_VALUE( std::sin( Deg2Rad( 45.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}