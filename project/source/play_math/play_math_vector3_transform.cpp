#include "play_math_vector3_transform.hpp"
#include "play_math___helper_common.hpp"
#include "play_math___helper_vector3.hpp"
#include "play_math___helper_matrix33.hpp"
using namespace play_math;

#include "r2tm/r2tm_inspector.hpp"

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

			OUT_SUBJECT( "2차원 좌표 회전 공식" );
			OUT_COMMENT( "x` = ( x * cos(θ`) ) - ( y * sin(θ`) )" );
			OUT_COMMENT( "y` = ( y * cos(θ`) ) + ( x * sin(θ`) )" );

			LF();

			OUT_SUBJECT( "행렬 변환" );
			OUT_COMMENT( "cos(θ`), -sin(θ`)" );
			OUT_COMMENT( "sin(θ`), cos(θ`)" );

			LF();

			OUT_SUBJECT( "3차원 확장 변환" );
			OUT_COMMENT( "기준 축을 제외한 나머지 축에 2차원 회전 적용" );

			LS();

			{
				OUT_SUBJECT( "Z축 회전" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  std::cos( radian ), -std::sin( radian )  , 0
						, std::sin( radian ), std::cos( radian )   , 0
						, 0                 , 0                    , 1
					);
				};
				OUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( -1.f, 0.f, 0.f ), B( Deg2Rad( 90.f ) ) * VEC3_Y );
				EXPECT_EQ( Vec3( 0.f, -1.f, 0.f ), B( Deg2Rad( 180.f ) ) * VEC3_Y );
			}

			LS();
			
			{
				OUT_SUBJECT( "X축 회전" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  1, 0                 , 0
						, 0, std::cos( radian ), -std::sin( radian )
						, 0, std::sin( radian ), std::cos( radian )
					);
				};
				OUT_SOURCE_END;

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

			OUT_SUBJECT( "오른손 좌표계 회전의 대전제" );
			OUT_COMMENT( "X축 회전은 Y축이 Z축 방향으로 이동" );
			OUT_COMMENT( "Y축 회전은 Z축이 X축 방향으로 이동" );
			OUT_COMMENT( "Z축 회전은 X축이 Y축 방향으로 이동" );

			LF();

			OUT_SUBJECT( "Y축 회전은 위의 대전제에 맞추려면 공식의 조정이 요구된다." );

			LF();

			OUT_SUBJECT( "기존 공식" );
			OUT_COMMENT( "cos(θ`), -sin(θ`)" );
			OUT_COMMENT( "sin(θ`),  cos(θ`)" );

			LF();

			OUT_SUBJECT( "조정된 공식" );
			OUT_COMMENT( " cos(θ`), sin(θ`)" );
			OUT_COMMENT( "-sin(θ`), cos(θ`)" );

			LS();
			
			{
				OUT_SUBJECT( "기존 공식 : 반대 방향으로 회전" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  std::cos( radian ) , 0, -std::sin( radian )
						, 0                  , 1, 0
						, std::sin( radian ) , 0, std::cos( radian )
					);
				};
				OUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( -1.f, 0.f, 0.f ), B( Deg2Rad( 90.f ) ) * VEC3_Z );
				EXPECT_EQ( Vec3( 0.f, 0.f, -1.f ), B( Deg2Rad( 180.f ) ) * VEC3_Z );
			}

			LS();

			{
				OUT_SUBJECT( "조정된 공식" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				const auto B = []( const float radian )->Mat33
				{
					return Mat33(
						  std::cos( radian )  , 0, std::sin( radian )
						, 0                   , 1, 0
						, -std::sin( radian ) , 0, std::cos( radian )
					);
				};
				OUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( 1.f, 0.f, 0.f ), B( Deg2Rad( 90.f ) ) * VEC3_Z );
				EXPECT_EQ( Vec3( 0.f, 0.f, -1.f ), B( Deg2Rad( 180.f ) ) * VEC3_Z );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}