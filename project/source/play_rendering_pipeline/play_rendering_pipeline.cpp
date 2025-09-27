#include "play_rendering_pipeline.h"

#include <conio.h>

#include "play_math/play_math___helper_common.hpp"
#include "play_math/play_math___helper_quaternion.hpp"
#include "play_math/play_math___helper_vector4.hpp"
#include "play_math/play_math___helper_matrix44.hpp"
using namespace play_math;

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

#include "r2/r2_fps_timer.hpp"

namespace play_rendering_pipeline
{
	r2tm::TitleFunctionT ViewMatrix_Step1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "View Matrix : Step 1";
		};
	}
	r2tm::DoFunctionT ViewMatrix_Step1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{

			LS();

			OUT_SUBJECT( "View Matrix 구성을 위한 준비" );

			LS();

			{
				OUT_SUBJECT( "View Matrix 구성을 위해 기준 벡터가 필요하다." );
				OUT_COMMENT( "cam_eye     : 카메라 위치" );
				OUT_COMMENT( "cam_forward : 카메라가 보는 방향" );
				OUT_COMMENT( "cam_right   : 카메라가 보는 방향의 오른쪽 방향" );
				OUT_COMMENT( "cam_up      : 카메라의 머리 위 방향" );
			}

			LS();

			OUT_SUBJECT( "사용자가 알고 있을 정보로 시작." );

			LF();

			OUT_COMMENT( "카메라 위치" );
			DECL_MAIN( const Vec4 init_eye( 0, 0, 10, 1 ) );

			LF();

			OUT_COMMENT( "카메라 목표" );
			DECL_MAIN( const Vec4 init_center( 0, 0, 0, 1 ) );

			LF();

			OUT_COMMENT( "카메라 머리 위 방향" );
			DECL_MAIN( const Vec4 init_up( 0, 1, 0, 1 ) );

			LS();

			{
				OUT_SUBJECT( "Forward : Z-axis" );

				LF();

				DECL_MAIN( Vec4 cam_forward = vec4_normalize( init_eye - init_center ) );
				OUT_VALUE( cam_forward );

				LF();

				OUT_SUBJECT( "Right : X-axis" );

				LF();

				DECL_MAIN( Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) ) );
				OUT_VALUE( cam_right );

				LF();

				OUT_SUBJECT( "Up : Y-axis" );

				LF();

				DECL_MAIN( Vec4 cam_up = vec4_cross( cam_forward, cam_right ) );
				OUT_VALUE( cam_up );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ViewMatrix_Step2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "View Matrix : Step 2";
		};
	}
	r2tm::DoFunctionT ViewMatrix_Step2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "Camera Matrix 구성해보기" );

			LS();

			DECL_MAIN( const Vec4 init_eye( 0, 0, 10, 1 ) );
			DECL_MAIN( const Vec4 init_center( 10, 0, 0, 1 ) );
			DECL_MAIN( const Vec4 init_up( 0, 1, 0, 1 ) );

			LS();

			{
				OUT_SUBJECT( "Ready" );

				LF();

				DECL_MAIN( Vec4 cam_forward = vec4_normalize( init_eye - init_center ) );
				DECL_MAIN( Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) ) );
				DECL_MAIN( Vec4 cam_up = vec4_cross( cam_forward, cam_right ) );


				SS();


				OUT_SUBJECT( "Camera Matrix" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				const Mat44 cam_mat4(
					  cam_right.x, cam_up.x, cam_forward.x, init_eye.x
					, cam_right.y, cam_up.y, cam_forward.y, init_eye.y
					, cam_right.z, cam_up.z, cam_forward.z, init_eye.z
					, 0.f        , 0.f     , 0.f          , 1.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( cam_mat4 );


				SS();


				DECL_MAIN( Vec4 cam_vec4( 0, 0, 10, 1 ) );
				PROC_MAIN( cam_vec4 = cam_mat4 * cam_vec4 );

				LF();

				OUT_VALUE( cam_vec4 );

				LF();

				OUT_NOTE( "원점을 중심으로 45도 회전 후 이동해서 현재의 위치가 된다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ViewMatrix_Step3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "View Matrix : Step 3";
		};
	}
	r2tm::DoFunctionT ViewMatrix_Step3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUT_SOURCE_READY;

			LS();

			OUT_SUBJECT( "View 행렬 구성" );

			LS();

			DECL_MAIN( const Vec4 init_eye( 0, 0, 10, 1 ) );
			DECL_MAIN( const Vec4 init_center( 10, 0, 0, 1 ) );
			DECL_MAIN( const Vec4 init_up( 0, 1, 0, 1 ) );
			DECL_MAIN( Vec4 cam_forward = vec4_normalize( init_eye - init_center ) );
			DECL_MAIN( Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) ) );
			DECL_MAIN( Vec4 cam_up = vec4_cross( cam_forward, cam_right ) );

			LS();

			{
				OUT_SUBJECT( "Rotation Matrix : Camera Rotation의 전치" );

				LF();

				OUT_SOURCE_BEGIN;
				const Mat44 view_rotation_mat4(
					  cam_right.x    , cam_right.y    , cam_right.z    , 0.f
					, cam_up.x       , cam_up.y       , cam_up.z       , 0.f
					, cam_forward.x  , cam_forward.y  , cam_forward.z  , 0.f
					, 0.f            , 0.f            , 0.f            , 1.f
				);
				OUT_SOURCE_END;
			}

			LS();

			{
				OUT_SUBJECT( "Translate Matrix : Camera Position의 음수 값" );

				LF();

				OUT_SOURCE_BEGIN;
				const Mat44 view_translate_mat4(
					  0.f, 0.f, 0.f, -init_eye.x
					, 0.f, 0.f, 0.f, -init_eye.y
					, 0.f, 0.f, 0.f, -init_eye.z
					, 0.f, 0.f, 0.f, 1.f
				);
				OUT_SOURCE_END;
			}

			LS();

			{
				OUT_SUBJECT( "Final Matrix" );
				OUT_COMMENT( "-vec4_dot( cam_right, init_eye )" );
				OUT_COMMENT( "카메라의 회전된 로컬 축을 기준으로 eye 위치를 반대 방향으로 이동" );

				LF();

				OUT_SOURCE_BEGIN;
				const Mat44 view_final_mat4(
					  cam_right.x    , cam_right.y    , cam_right.z    , -vec4_dot( cam_right, init_eye )
					, cam_up.x       , cam_up.y       , cam_up.z       , -vec4_dot( cam_up, init_eye )
					, cam_forward.x  , cam_forward.y  , cam_forward.z  , -vec4_dot( cam_forward, init_eye )
					, 0.f            , 0.f            , 0.f            , 1.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( view_final_mat4 );


				SS();


				OUT_SUBJECT( "Demo" );

				LF();

				OUT_VALUE( view_final_mat4 * init_eye );
				OUT_VALUE( view_final_mat4 * init_center );
				OUT_VALUE( view_final_mat4 * Vec4( 0, 0, 0, 1 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Orthographic_Step1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Orthographic : Step 1";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Orthographic_Step1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "REF : orthoRH_NO : https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl" );

				LF();

				OUT_SUBJECT( "orthoRH_NO" );
				OUT_COMMENT( "Orthographic : 직교 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환" );
			}

			LS();

			DECL_MAIN( const int viewport_w = 400 );
			DECL_MAIN( const int viewport_h = 300 );

			LF();

			OUT_SUBJECT( "left = 0, bottom = 0 으로 설정하면     |     0, 0, 0 좌표는 viewport 왼쪽 하단 끝 -1, -1 으로 배치된다." );
			DECL_MAIN( const float left = -viewport_w / 2 );
			DECL_MAIN( const float right = viewport_w / 2 );
			DECL_MAIN( const float bottom = -viewport_h / 2 );
			DECL_MAIN( const float top = viewport_h / 2 );
			DECL_MAIN( const float near_plane = 0.1f ); // 가까운 절단면
			DECL_MAIN( const float far_plane = 100.f ); // 먼 절단면

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const Mat44 projection_mat4(
					  2 / ( right - left )  , 0.f                   , 0.f                             , -( right + left ) / ( right - left )
					, 0.f                   , 2 / ( top - bottom )  , 0.f                             , -( top + bottom ) / ( top - bottom )
					, 0.f                   , 0.f                   , 2 / ( far_plane - near_plane )  , -( far_plane + near_plane ) / ( far_plane - near_plane )
					, 0.f                   , 0.f                   , 0.f                             , 1.f
				);
				OUT_SOURCE_END;
				OUT_VALUE( projection_mat4 );

				
				SS();


				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( viewport_w / 2, viewport_h / 2, 0, 1 ) ).x );
				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( viewport_w / 2, viewport_h / 2, 0, 1 ) ).y );

				LF();

				EXPECT_EP_EQ( -1, ( projection_mat4 * Vec4( -viewport_w / 2, -viewport_h / 2, 0, 1 ) ).x );
				EXPECT_EP_EQ( -1, ( projection_mat4 * Vec4( -viewport_w / 2, -viewport_h / 2, 0, 1 ) ).y );

				LF();

				EXPECT_EP_EQ( -1, ( projection_mat4 * Vec4( 0, 0, near_plane, 1 ) ).z );
				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( 0, 0, far_plane, 1 ) ).z );

				LF();

				OUT_VALUE( ( projection_mat4 * Vec4( 0, 0, -near_plane, 1 ) ).z );
				OUT_VALUE( ( projection_mat4 * Vec4( 0, 0, -far_plane, 1 ) ).z );

				LF();

				OUT_NOTE( "이 행렬은 벡터의 z 값이 양수 일 때만 정상 작동한다." );
				OUT_NOTE( "실제로 사용한다면 카메라가 양수 방향 z축을 바라보고 있어야 한다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Orthographic_Step2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Orthographic : Step 2";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Orthographic_Step2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "REF : orthoRH_ZO : https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl" );

				LF();

				OUT_SUBJECT( "orthoRH_ZO" );
				OUT_COMMENT( "Orthographic : 직교 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환     |     Z 범위만 0 ~ 1" );
			}

			LS();

			DECL_MAIN( const int viewport_w = 400 );
			DECL_MAIN( const int viewport_h = 300 );

			LF();

			OUT_SUBJECT( "left = 0, bottom = 0 으로 설정하면     |     0, 0, 0 좌표는 viewport 왼쪽 하단 끝 -1, -1 으로 배치된다." );
			DECL_MAIN( const float left = -viewport_w / 2 );
			DECL_MAIN( const float right = viewport_w / 2 );
			DECL_MAIN( const float bottom = -viewport_h / 2 );
			DECL_MAIN( const float top = viewport_h / 2 );
			DECL_MAIN( const float near_plane = 0.1f ); // 가까운 절단면
			DECL_MAIN( const float far_plane = 100.f ); // 먼 절단면

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const Mat44 projection_mat4(
					  2 / ( right - left )  , 0.f                   , 0.f                             , -( right + left ) / ( right - left )
					, 0.f                   , 2 / ( top - bottom )  , 0.f                             , -( top + bottom ) / ( top - bottom )
					, 0.f                   , 0.f                   , 1 / ( far_plane - near_plane )  , -near_plane / ( far_plane - near_plane )
					, 0.f                   , 0.f                   , 0.f                             , 1.f
				);
				OUT_SOURCE_END;
				OUT_VALUE( projection_mat4 );


				SS();


				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( viewport_w / 2, viewport_h / 2, 0, 1 ) ).x );
				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( viewport_w / 2, viewport_h / 2, 0, 1 ) ).y );

				LF();

				EXPECT_EP_EQ( -1, ( projection_mat4 * Vec4( -viewport_w / 2, -viewport_h / 2, 0, 1 ) ).x );
				EXPECT_EP_EQ( -1, ( projection_mat4 * Vec4( -viewport_w / 2, -viewport_h / 2, 0, 1 ) ).y );

				LF();

				EXPECT_EP_EQ( 0, ( projection_mat4 * Vec4( 0, 0, near_plane, 1 ) ).z );
				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( 0, 0, far_plane, 1 ) ).z );

				LF();

				OUT_VALUE( ( projection_mat4 * Vec4( 0, 0, -near_plane, 1 ) ).z );
				OUT_VALUE( ( projection_mat4 * Vec4( 0, 0, -far_plane, 1 ) ).z );

				LF();

				OUT_NOTE( "-near_plane, -far_plane을 인자로 줬을때 값이 정확히 맞지 않는다 = 부동 소수점 오차" );
				OUT_NOTE( "z값이 뒤집혀 나온다." );
				OUT_NOTE( "실제로 사용한다면 카메라 z 축을 확인하고 뒤집는 작업이 필요 한가?" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
	


	r2tm::TitleFunctionT ProjectionMatrix_Frustum_Step1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Frustum : Step 1";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Frustum_Step1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "REF : frustumRH_NO : https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl" );

				LF();

				OUT_SUBJECT( "frustumRH_NO" );
				OUT_COMMENT( "Perspective : 원근 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환     |     fov 없는 원근 투영     |     더 낮은 수준에서 원근 투영을 제어 할 때 사용" );
			}

			LS();

			DECL_MAIN( const int viewport_w = 400 );
			DECL_MAIN( const int viewport_h = 300 );
			DECL_MAIN( const float l = -viewport_w / 2 );
			DECL_MAIN( const float r = viewport_w / 2 );
			DECL_MAIN( const float b = -viewport_h / 2 );
			DECL_MAIN( const float t = viewport_h / 2 );
			DECL_MAIN( const float near = 10.f );
			DECL_MAIN( const float far = 100.f );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const Mat44 projection_mat4(
					  ( 2 * near ) / ( r - l )  , 0.f                       , ( r + l ) / ( r - l )             , 0.f
					, 0.f                       , ( 2 * near ) / ( t - b )  , ( t + b ) / ( t - b )             , 0.f
					, 0.f                       , 0.f                       , -( far + near ) / ( far - near )  , -( 2 * far * near ) / ( far - near )
					, 0.f                       , 0.f                       , -1.f                              , 0.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( projection_mat4 );

				LF();

				OUT_SUBJECT( "행렬과 벡터를 곱하고 나온 결과 벡터의 각 성분을 결과 벡터의 w 값으로 나누어야 원근 조정이 완료된다." );
				OUT_SUBJECT( "이 과정은 보통 파이프라인 에서 알아서 처리 하기 때문에 유저에겐 보이지 않는다고 한다." );

				
				SS();


				{
					DECL_MAIN( auto v = projection_mat4 * Vec4( 0, 0, -far, 1 ) );
					OUT_VALUE( v );
					PROC_MAIN( v /= v.w );
					OUT_VALUE( v );
					EXPECT_EP_EQ( 0.f, v.x );
					EXPECT_EP_EQ( 0.f, v.y );
					EXPECT_EP_EQ( 1.f, v.z );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Frustum_Step2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Frustum : Step 2";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Frustum_Step2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "REF : frustumRH_ZO : https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl" );

				LF();

				OUT_SUBJECT( "frustumRH_ZO" );
				OUT_COMMENT( "Perspective : 원근 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환, z = 0 ~ 1     |     fov 없는 원근 투영     |     더 낮은 수준에서 원근 투영을 제어 할 때 사용" );
			}

			LS();

			DECL_MAIN( const int viewport_w = 400 );
			DECL_MAIN( const int viewport_h = 300 );
			DECL_MAIN( const float l = -viewport_w / 2 );
			DECL_MAIN( const float r = viewport_w / 2 );
			DECL_MAIN( const float b = -viewport_h / 2 );
			DECL_MAIN( const float t = viewport_h / 2 );
			DECL_MAIN( const float near = 10.f );
			DECL_MAIN( const float far = 100.f );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const Mat44 projection_mat4(
					  ( 2 * near ) / ( r - l )  , 0.f                       , ( r + l ) / ( r - l )  , 0.f
					, 0.f                       , ( 2 * near ) / ( t - b )  , ( t + b ) / ( t - b )  , 0.f
					, 0.f                       , 0.f                       , far / ( near - far )   , -( far * near ) / ( far - near )
					, 0.f                       , 0.f                       , -1.f                   , 0.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( projection_mat4 );

				LF();

				OUT_SUBJECT( "행렬과 벡터를 곱하고 나온 결과 벡터의 각 성분을 결과 벡터의 w 값으로 나누어야 원근 조정이 완료된다." );
				OUT_SUBJECT( "이 과정은 보통 파이프라인 에서 알아서 처리 하기 때문에 유저에겐 보이지 않는다고 한다." );

				
				SS();


				{
					DECL_MAIN( auto v = projection_mat4 * Vec4( 0, 0, -far, 1 ) );
					OUT_VALUE( v );
					PROC_MAIN( v /= v.w );
					OUT_VALUE( v );
					EXPECT_EP_EQ( 0.f, v.x );
					EXPECT_EP_EQ( 0.f, v.y );
					EXPECT_EP_EQ( 1.f, v.z );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
	


	r2tm::TitleFunctionT ProjectionMatrix_Perspective_Step1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Perspective : Step 1";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Perspective_Step1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "fov를 사용하는 원근 투영( Perspective Projection )의 기초" );
				OUT_COMMENT( "-1 ~ +1 : 로 표현되는 좌표계로 변환     |     fovY : 수직 시야각     |     aspect : 뷰포트의 너비 / 높이" );
			}

			LS();

			DECL_MAIN( const int viewport_w = 400 );
			DECL_MAIN( const int viewport_h = 200 );
			DECL_MAIN( const float fovY = Deg2Rad( 90.f ) );
			DECL_MAIN( const float aspect = viewport_w / viewport_h );
			DECL_MAIN( const float near = 0.1f );
			DECL_MAIN( const float far = 100.f );

			LF();

			OUT_VALUE( fovY );
			OUT_VALUE( aspect );

			LS();

			{
				DECL_MAIN( const float top = near * std::tan( fovY / 2 ) );
				OUT_VALUE( top );
				
				LF();

				DECL_MAIN( const float bottom = -top );
				OUT_VALUE( bottom );

				LF();

				DECL_MAIN( const float right = top * aspect );
				OUT_VALUE( right );

				LF();

				DECL_MAIN( const float left = -right );
				OUT_VALUE( left );
			}

			LS();

			{
				DECL_MAIN( const float top = far * std::tan( fovY / 2 ) );
				OUT_VALUE( top );

				LF();

				DECL_MAIN( const float bottom = -top );
				OUT_VALUE( bottom );

				LF();

				DECL_MAIN( const float right = top * aspect );
				OUT_VALUE( right );

				LF();

				DECL_MAIN( const float left = -right );
				OUT_VALUE( left );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Perspective_Step2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Perspective : Step 2";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Perspective_Step2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "REF : perspectiveRH_NO : https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl" );

				LF();

				OUT_SUBJECT( "perspectiveRH_NO" );
				OUT_COMMENT( "Perspective : 원근 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환     |     fovY : 수직 시야각     |     aspect : 뷰포트의 너비 / 높이" );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const float viewport_w = 400;
				const float viewport_h = 300;
				const float fovY = Deg2Rad( 90.f );
				const float aspect = viewport_w / viewport_h;
				const float near = 10.f;
				const float far = 100.f;

				const float tanHalfFovY = std::tan( fovY / 2 );

				const Mat44 projection_mat4(
					  1 / ( aspect * tanHalfFovY )  , 0.f              , 0.f                               , 0.f
					, 0.f                           , 1 / tanHalfFovY  , 0.f                               , 0.f
					, 0.f                           , 0.f              , -( far + near ) / ( far - near )  , -( 2 * far * near ) / ( far - near )
					, 0.f                           , 0.f              , -1.f                              , 0.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( projection_mat4 );

				LF();

				OUT_SUBJECT( "행렬과 벡터를 곱하고 나온 결과 벡터의 각 성분을 결과 벡터의 w 값으로 나누어야 원근 조정이 완료된다." );
				OUT_SUBJECT( "이 과정은 보통 파이프라인 에서 알아서 처리 하기 때문에 유저에겐 보이지 않는다고 한다." );


				SS();


				{
					DECL_MAIN( auto v = projection_mat4 * Vec4( 0, 0, -far, 1 ) );
					OUT_VALUE( v );
					PROC_MAIN( v /= v.w );
					OUT_VALUE( v );
					EXPECT_EP_EQ( 0.f, v.x );
					EXPECT_EP_EQ( 0.f, v.y );
					EXPECT_EP_EQ( 1.f, v.z );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Perspective_Step3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Perspective : Step 3";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Perspective_Step3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "REF : perspectiveRH_ZO : https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl" );

				LF();

				OUT_SUBJECT( "perspectiveRH_ZO" );
				OUT_COMMENT( "Perspective : 원근 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환, z = 0 ~ 1     |     fovY : 수직 시야각     |     aspect : 뷰포트의 너비 / 높이" );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const float viewport_w = 400;
				const float viewport_h = 300;
				const float fovY = Deg2Rad( 90.f );
				const float aspect = viewport_w / viewport_h;
				const float near = 10.f;
				const float far = 100.f;

				const float tanHalfFovY = std::tan( fovY / 2 );

				const Mat44 projection_mat4(
					  1 / ( aspect * tanHalfFovY )  , 0.f              , 0.f                   , 0.f
					, 0.f                           , 1 / tanHalfFovY  , 0.f                   , 0.f
					, 0.f                           , 0.f              , far / ( near - far )  , -( far * near ) / ( far - near )
					, 0.f                           , 0.f              , -1.f                  , 0.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( projection_mat4 );

				LF();

				OUT_SUBJECT( "행렬과 벡터를 곱하고 나온 결과 벡터의 각 성분을 결과 벡터의 w 값으로 나누어야 원근 조정이 완료된다." );
				OUT_SUBJECT( "이 과정은 보통 파이프라인 에서 알아서 처리 하기 때문에 유저에겐 보이지 않는다고 한다." );


				SS();


				{
					DECL_MAIN( auto v = projection_mat4 * Vec4( 0, 0, -far, 1 ) );
					OUT_VALUE( v );
					PROC_MAIN( v /= v.w );
					OUT_VALUE( v );
					EXPECT_EP_EQ( 0.f, v.x );
					EXPECT_EP_EQ( 0.f, v.y );
					EXPECT_EP_EQ( 1.f, v.z );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Viewport_Matrix_Step1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Viewport Matrix : Step 1";
		};
	}
	r2tm::DoFunctionT Viewport_Matrix_Step1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "Screen 좌표로 변환" );
				OUT_SUBJECT( "x, y : 스크린 좌표로 변환     |     z = -1 ~ 1 범위의 z를 지정한 범위로 변환" );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const float viewport_w = 400;
				const float viewport_h = 300;
				const float near = 0.f;
				const float far = 100.f;

				const Mat44 viewport_mat4(
					  viewport_w / 2.f  , 0.f               , 0.f                   , viewport_w / 2.f
					, 0.f               , viewport_h / 2.f  , 0.f                   , viewport_h / 2.f
					, 0.f               , 0.f               , ( far - near ) / 2.f  , ( near + far ) / 2.f
					, 0.f               , 0.f               , 0.f                   , 1.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( viewport_mat4 );


				SS();

				{
					OUT_SUBJECT( "가운데" );
					DECL_MAIN( const auto v = viewport_mat4 * Vec4( 0, 0, 0, 1 ) );
					EXPECT_EP_EQ( 200.f, v.x );
					EXPECT_EP_EQ( 150.f, v.y );
				}

				LF();

				{
					OUT_SUBJECT( "왼 + 위" );
					DECL_MAIN( const auto v = viewport_mat4 * Vec4( 1, 1, 0, 1 ) );
					EXPECT_EP_EQ( 400.f, v.x );
					EXPECT_EP_EQ( 300.f, v.y );
				}

				LF();

				{
					OUT_SUBJECT( "0, 0" );
					DECL_MAIN( const auto v = viewport_mat4 * Vec4( -1, -1, 0, 1 ) );
					EXPECT_EP_EQ( 0.f, v.x );
					EXPECT_EP_EQ( 0.f, v.y );
				}

				LF();

				{
					OUT_SUBJECT( "" );
					EXPECT_EP_EQ( 0.f, ( viewport_mat4 * Vec4( 0, 0, -1, 1 ) ).z );
					EXPECT_EP_EQ( 50.f, ( viewport_mat4 * Vec4( 0, 0, 0, 1 ) ).z );
					EXPECT_EP_EQ( 100.f, ( viewport_mat4 * Vec4( 0, 0, 1, 1 ) ).z );
				}

				LF();

				{
					OUT_SUBJECT( "잘못된 범위" );
					EXPECT_EP_EQ( -50.f, ( viewport_mat4 * Vec4( 0, 0, -2, 1 ) ).z );
					EXPECT_EP_EQ( 150.f, ( viewport_mat4 * Vec4( 0, 0, 2, 1 ) ).z );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Viewport_Matrix_Step2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Viewport Matrix : Step 2";
		};
	}
	r2tm::DoFunctionT Viewport_Matrix_Step2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "Screen 좌표로 변환" );
				OUT_SUBJECT( "x, y : 스크린 좌표로 변환     |     z = 0 ~ 1 범위의 z를 지정한 범위로 변환" );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const float viewport_w = 400;
				const float viewport_h = 300;
				const float near = 0.f;
				const float far = 100.f;

				const Mat44 viewport_mat4(
					  viewport_w / 2.f  , 0.f               , 0.f             , viewport_w / 2.f
					, 0.f               , viewport_h / 2.f  , 0.f             , viewport_h / 2.f
					, 0.f               , 0.f               , ( far - near )  , near
					, 0.f               , 0.f               , 0.f             , 1.f
				);
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( viewport_mat4 );


				SS();

				{
					OUT_SUBJECT( "가운데" );
					DECL_MAIN( const auto v = viewport_mat4 * Vec4( 0, 0, 0, 1 ) );
					EXPECT_EP_EQ( 200.f, v.x );
					EXPECT_EP_EQ( 150.f, v.y );
				}

				LF();

				{
					OUT_SUBJECT( "왼 + 위" );
					DECL_MAIN( const auto v = viewport_mat4 * Vec4( 1, 1, 0, 1 ) );
					EXPECT_EP_EQ( 400.f, v.x );
					EXPECT_EP_EQ( 300.f, v.y );
				}

				LF();

				{
					OUT_SUBJECT( "0, 0" );
					DECL_MAIN( const auto v = viewport_mat4 * Vec4( -1, -1, 0, 1 ) );
					EXPECT_EP_EQ( 0.f, v.x );
					EXPECT_EP_EQ( 0.f, v.y );
				}

				LF();

				{
					OUT_SUBJECT( "Z" );
					EXPECT_EP_EQ( 0.f, ( viewport_mat4 * Vec4( 0, 0, 0, 1 ) ).z );
					EXPECT_EP_EQ( 100.f, ( viewport_mat4 * Vec4( 0, 0, 1, 1 ) ).z );
				}

				LF();

				{
					OUT_SUBJECT( "잘못된 범위" );
					EXPECT_EP_EQ( -100.f, ( viewport_mat4 * Vec4( 0, 0, -1, 1 ) ).z );
					EXPECT_EP_EQ( 200.f, ( viewport_mat4 * Vec4( 0, 0, 2, 1 ) ).z );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Composition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Composition";
		};
	}
	r2tm::DoFunctionT Composition::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( const Vec4 init_eye( 0, 0, 10, 1 ) );
			DECL_MAIN( const Vec4 init_center( 10, 0, 0, 1 ) );
			DECL_MAIN( const Vec4 init_up( 0, 1, 0, 1 ) );

			LS();

			DECL_MAIN( Vec4 p = Vec4( 0, 0, 0, 1 ) );

			LS();

			{
				const Vec4 cam_forward = vec4_normalize( init_eye - init_center );
				const Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) );
				const Vec4 cam_up = vec4_cross( cam_forward, cam_right );

				const Mat44 view_mat4(
					  cam_right.x    , cam_right.y    , cam_right.z    , -vec4_dot( cam_right, init_eye )
					, cam_up.x       , cam_up.y       , cam_up.z       , -vec4_dot( cam_up, init_eye )
					, cam_forward.x  , cam_forward.y  , cam_forward.z  , -vec4_dot( cam_forward, init_eye )
					, 0.f            , 0.f            , 0.f            , 1.f
				);

				OUT_SUBJECT( "View 행렬 적용" );

				LF();

				PROC_MAIN( p = view_mat4 * p );
				OUT_VALUE( p );
			}

			LS();

			DECL_MAIN( const float viewport_w = 400 );
			DECL_MAIN( const float viewport_h = 300 );
			DECL_MAIN( const float near = 1.f );
			DECL_MAIN( const float far = 100.f );

			LS();

			{
				const float fovY = Deg2Rad( 90.f );
				const float aspect = viewport_w / viewport_h;
				const float tanHalfFovY = std::tan( fovY / 2 );

				const Mat44 projection_mat4(
					  1 / ( aspect * tanHalfFovY )  , 0.f              , 0.f                               , 0.f
					, 0.f                           , 1 / tanHalfFovY  , 0.f                               , 0.f
					, 0.f                           , 0.f              , -( far + near ) / ( far - near )  , -( 2 * far * near ) / ( far - near )
					, 0.f                           , 0.f              , -1.f                              , 0.f
				);

				OUT_SUBJECT( "Projection 행렬 적용" );
				OUT_COMMENT( "perspectiveRH_NO     |     -1 ~ +1 : 로 표현되는 좌표계로 변환     |     fovY : 수직 시야각     |     aspect : 뷰포트의 너비 / 높이" );

				LF();

				PROC_MAIN( p = projection_mat4 * p );
				OUT_VALUE( p );
				PROC_MAIN( p /= p.w );
				OUT_VALUE( p );
			}

			LS();

			DECL_MAIN( const float viewport_near = 0.f );
			DECL_MAIN( const float viewport_far = 1.f );

			LS();

			{
				const Mat44 viewport_mat4(
					  viewport_w / 2.f  , 0.f               , 0.f                                     , viewport_w / 2.f
					, 0.f               , viewport_h / 2.f  , 0.f                                     , viewport_h / 2.f
					, 0.f               , 0.f               , ( viewport_far - viewport_near ) / 2.f  , ( viewport_near + viewport_far ) / 2.f
					, 0.f               , 0.f               , 0.f                                     , 1.f
				);

				OUT_SUBJECT( "Viewport 행렬 적용" );
				OUT_COMMENT( "x, y : 스크린 좌표로 변환     |     z = -1 ~ 1 범위의 z를 지정한 범위로 변환" );

				LF();

				PROC_MAIN( p = viewport_mat4 * p );
				OUT_VALUE( p );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Orthographic_Z_Range::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Orthographic : Z Range";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Orthographic_Z_Range::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "테스트 조건 : orthoRH_ZO" );
				OUT_COMMENT( "Orthographic : 직교 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환     |     Z 범위만 0 ~ 1" );
			}

			LS();

			{
				const int viewport_w = 400;
				const int viewport_h = 300;
				const float left = -viewport_w / 2;
				const float right = viewport_w / 2;
				const float bottom = -viewport_h / 2;
				const float top = viewport_h / 2;
				DECL_MAIN( const float near = 0.1f ); // 가까운 절단면
				DECL_MAIN( const float far = 100.f ); // 먼 절단면

				const Mat44 projection_mat4(
					  2 / ( right - left )  , 0.f                   , 0.f                 , -( right + left ) / ( right - left )
					, 0.f                   , 2 / ( top - bottom )  , 0.f                 , -( top + bottom ) / ( top - bottom )
					, 0.f                   , 0.f                   , 1 / ( far - near )  , -near / ( far - near )
					, 0.f                   , 0.f                   , 0.f                 , 1.f
				);


				SS();

				OUT_NOTE( "직교 투영 == 선형 매핑" );

				SS();


				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, near, 1 ) );
					OUT_VALUE( ( v / v.w ) );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, far * 0.3f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, far * 0.5f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, far * 0.8f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, far * 0.9f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, far * 0.95f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, far, 1 ) );
					OUT_VALUE( v / v.w );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Perspective_Z_Range::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Perspective : Z Range";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Perspective_Z_Range::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "테스트 조건 : perspectiveRH_ZO" );
				OUT_COMMENT( "Perspective : 원근 투영     |     -1 ~ +1 : 로 표현되는 좌표계로 변환, z = 0 ~ 1     |     fovY : 수직 시야각     |     aspect : 뷰포트의 너비 / 높이" );
			}

			LS();

			{
				const float viewport_w = 400;
				const float viewport_h = 300;
				const float fovY = Deg2Rad( 90.f );
				const float aspect = viewport_w / viewport_h;
				DECL_MAIN( const float near = 10.f );
				DECL_MAIN( const float far = 100.f );

				const float tanHalfFovY = std::tan( fovY / 2 );

				const Mat44 projection_mat4(
					  1 / ( aspect * tanHalfFovY )  , 0.f              , 0.f                   , 0.f
					, 0.f                           , 1 / tanHalfFovY  , 0.f                   , 0.f
					, 0.f                           , 0.f              , far / ( near - far )  , -( far * near ) / ( far - near )
					, 0.f                           , 0.f              , -1.f                  , 0.f
				);


				SS();

				OUT_NOTE( "위치에 따른 Z 값이 일관 되지 않는다." );
				OUT_NOTE( "가까운 쪽의 범위가 넓고 먼쪽의 범위가 좁다." );
				OUT_NOTE( "비선형 매핑" );

				SS();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, -near, 1 ) );
					OUT_VALUE( ( v / v.w ) );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, -far * 0.3f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, -far * 0.5f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, -far * 0.8f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, -far * 0.9f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, -far * 0.95f, 1 ) );
					OUT_VALUE( v / v.w );
				}

				LF();

				{
					DECL_MAIN( const auto v = projection_mat4 * Vec4( 0, 0, -far, 1 ) );
					OUT_VALUE( v / v.w );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	

	r2tm::TitleFunctionT Demo_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo 1 : Rendering Pipeline : Rotation with Matrix";
		};
	}
	r2tm::DoFunctionT Demo_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			const Vec4 init_eye( 0, 0, 10, 1 );
			const Vec4 init_center( 0, 0, 0, 1 );
			const Vec4 init_up( 0, 1, 0, 1 );

			

			const Vec4 cam_forward = vec4_normalize( init_eye - init_center );
			const Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) );
			const Vec4 cam_up = vec4_cross( cam_forward, cam_right );

			const Mat44 view_mat4(
				  cam_right.x    , cam_right.y    , cam_right.z    , -vec4_dot( cam_right, init_eye )
				, cam_up.x       , cam_up.y       , cam_up.z       , -vec4_dot( cam_up, init_eye )
				, cam_forward.x  , cam_forward.y  , cam_forward.z  , -vec4_dot( cam_forward, init_eye )
				, 0.f            , 0.f            , 0.f            , 1.f
			);

			

			const float viewport_w = 60;
			const float viewport_h = 30;
			const float near = 1.f;
			const float far = 100.f;

			const float fovY = Deg2Rad( 90.f );
			const float aspect = viewport_w / viewport_h;
			const float tanHalfFovY = std::tan( fovY / 2 );

			const Mat44 projection_mat4(
				  1 / ( aspect * tanHalfFovY )  , 0.f              , 0.f                               , 0.f
				, 0.f                           , 1 / tanHalfFovY  , 0.f                               , 0.f
				, 0.f                           , 0.f              , -( far + near ) / ( far - near )  , -( 2 * far * near ) / ( far - near )
				, 0.f                           , 0.f              , -1.f                              , 0.f
			);

			

			const float viewport_near = 0.f;
			const float viewport_far = 1.f;

			const Mat44 viewport_mat4(
				  viewport_w / 2.f  , 0.f               , 0.f                                     , viewport_w / 2.f
				, 0.f               , viewport_h / 2.f  , 0.f                                     , viewport_h / 2.f
				, 0.f               , 0.f               , ( viewport_far - viewport_near ) / 2.f  , ( viewport_near + viewport_far ) / 2.f
				, 0.f               , 0.f               , 0.f                                     , 1.f
			);

			

			const auto RY = []( const float degree )->Mat44
			{
				//
				//  c,  -,  s,  -
				//  -,  -,  -,  -
				// -s,  -,  c,  -
				//  -,  -,  -,  -
				//

				const float radian = Deg2Rad( degree );

				Mat44 ret;

				// diagonal
				ret._11 = std::cos( radian );
				ret._33 = std::cos( radian );

				ret._13 = std::sin( radian );
				ret._31 = -std::sin( radian );

				return ret;
			};


			{
				OUT_SUBJECT( "시작" );

				const int v_size = 3;
				const Vec4 vs[v_size] = {
					  Vec4{ 0, -4, 0, 1 }
					, Vec4{ 6, 3, 0, 1 }
					, Vec4{ -6, 3, 0, 1 }
				};
				Vec4 fixed_vs[v_size];


				const auto pivot = r2tm::WindowsUtility::GetCursorPoint();

				r2::FPSTimer timer( 30 );
				float accumulate_time = 0.f;
				do
				{
					if( timer.Update() )
					{
						accumulate_time += ( timer.GetElapsedTime() * 0.5f );
						accumulate_time -= ( int )accumulate_time;

						r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot );

						// Draw : vs
						{
							for( int i = 0; v_size > i; ++i )
							{
								// setup
								auto& v = fixed_vs[i] = vs[i];

								// Model Rotation
								v = RY( 360 * accumulate_time ) * v;

								v = view_mat4 * v;

								v = projection_mat4 * v;
								v /= v.w;

								v = viewport_mat4 * v;
							}

							Vec4 v_start;
							Vec4 v_end;
							Vec4 v_dir;
							for( int i = 0; v_size > i; ++i )
							{
								v_start = fixed_vs[i];
								v_end = ( i + 1 == v_size ? fixed_vs[0] : fixed_vs[i + 1] );

								v_dir = v_end - v_start;

								int divider = int( std::abs( v_dir.x ) > std::abs( v_dir.y ) ? std::abs( v_dir.x ) : std::abs( v_dir.y ) );
								v_dir.x /= divider;
								v_dir.y /= divider;

								for( int j = 0; divider > j; ++j )
								{
									auto v = v_start + ( v_dir * j );

									r2tm::WindowsUtility::FillCharacter( pivot + r2tm::WindowsUtility::CursorPoint( ( short )v.x, ( short )v.y ), 'c' );
								}
							}
						}

						// Draw : 0, 0
						{
							auto v = view_mat4 * VEC4_0;

							v = projection_mat4 * v;
							v /= v.w;

							v = viewport_mat4 * v;

							r2tm::WindowsUtility::FillCharacter( pivot + r2tm::WindowsUtility::CursorPoint( ( short )v.x, ( short )v.y ), '0', r2tm::WindowsUtility::eColor::FG_Green );
						}

						r2tm::WindowsUtility::MoveCursorPoint( r2tm::WindowsUtility::CursorPoint( 0, pivot.y + ( short )viewport_h ) );
						
						LS();
					}

				} while( !_kbhit() );
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
	
	

	r2tm::TitleFunctionT Demo_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Demo 2 : Rendering Pipeline : Rotation with Quaternion";
		};
	}
	r2tm::DoFunctionT Demo_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			const Vec4 init_eye( 0, 0, 10, 1 );
			const Vec4 init_center( 0, 0, 0, 1 );
			const Vec4 init_up( 0, 1, 0, 1 );

			

			const Vec4 cam_forward = vec4_normalize( init_eye - init_center );
			const Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) );
			const Vec4 cam_up = vec4_cross( cam_forward, cam_right );

			const Mat44 view_mat4(
				  cam_right.x    , cam_right.y    , cam_right.z    , -vec4_dot( cam_right, init_eye )
				, cam_up.x       , cam_up.y       , cam_up.z       , -vec4_dot( cam_up, init_eye )
				, cam_forward.x  , cam_forward.y  , cam_forward.z  , -vec4_dot( cam_forward, init_eye )
				, 0.f            , 0.f            , 0.f            , 1.f
			);

			

			const float viewport_w = 60;
			const float viewport_h = 30;
			const float near = 1.f;
			const float far = 100.f;

			const float fovY = Deg2Rad( 90.f );
			const float aspect = viewport_w / viewport_h;
			const float tanHalfFovY = std::tan( fovY / 2 );

			const Mat44 projection_mat4(
				  1 / ( aspect * tanHalfFovY )  , 0.f              , 0.f                               , 0.f
				, 0.f                           , 1 / tanHalfFovY  , 0.f                               , 0.f
				, 0.f                           , 0.f              , -( far + near ) / ( far - near )  , -( 2 * far * near ) / ( far - near )
				, 0.f                           , 0.f              , -1.f                              , 0.f
			);

			

			const float viewport_near = 0.f;
			const float viewport_far = 1.f;

			const Mat44 viewport_mat4(
				  viewport_w / 2.f  , 0.f               , 0.f                                     , viewport_w / 2.f
				, 0.f               , viewport_h / 2.f  , 0.f                                     , viewport_h / 2.f
				, 0.f               , 0.f               , ( viewport_far - viewport_near ) / 2.f  , ( viewport_near + viewport_far ) / 2.f
				, 0.f               , 0.f               , 0.f                                     , 1.f
			);

			

			const Vec4 pv = vec4_normalize( Vec4( 1, 1, 0, 0 ) );
			const auto R = [pv]( const Vec4& v, float degree )->Vec4
			{
				const auto radian = Deg2Rad( degree );

				const Quat q(
					  std::cos( radian / 2.f )
					, pv.x * std::sin( radian / 2.f )
					, pv.y * std::sin( radian / 2.f )
					, pv.z * std::sin( radian / 2.f )
				);

				//
				// Rotation
				//
				const Quat ret = ( q * Quat( v ) ) * quat_inverse( q );

				return Vec4( ret.x, ret.y, ret.z, 1 );
			};


			{
				OUT_SUBJECT( "시작" );

				const int v_size = 3;
				const Vec4 vs[v_size] = {
					  Vec4{ 0, -4, 0, 1 }
					, Vec4{ 6, 3, 0, 1 }
					, Vec4{ -6, 3, 0, 1 }
				};
				Vec4 fixed_vs[v_size];


				const auto pivot = r2tm::WindowsUtility::GetCursorPoint();

				r2::FPSTimer timer( 30 );
				float accumulate_time = 0.f;
				do
				{
					if( timer.Update() )
					{
						accumulate_time += ( timer.GetElapsedTime() * 0.5f );
						accumulate_time -= ( int )accumulate_time;

						r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot );

						// Draw : vs
						{
							for( int i = 0; v_size > i; ++i )
							{
								// setup
								auto& v = fixed_vs[i] = vs[i];

								// Model Rotation
								v = R( v, 360 * accumulate_time );

								v = view_mat4 * v;

								v = projection_mat4 * v;
								v /= v.w;

								v = viewport_mat4 * v;
							}

							Vec4 v_start;
							Vec4 v_end;
							Vec4 v_dir;
							for( int i = 0; v_size > i; ++i )
							{
								v_start = fixed_vs[i];
								v_end = ( i + 1 == v_size ? fixed_vs[0] : fixed_vs[i + 1] );

								v_dir = v_end - v_start;

								int divider = int( std::abs( v_dir.x ) > std::abs( v_dir.y ) ? std::abs( v_dir.x ) : std::abs( v_dir.y ) );
								v_dir.x /= divider;
								v_dir.y /= divider;

								for( int j = 0; divider > j; ++j )
								{
									auto v = v_start + ( v_dir * j );

									if( 0 > v.x || v.x > viewport_w )
									{
										continue;
									}
									if( 0 > v.y || v.y > viewport_h )
									{
										continue;
									}

									r2tm::WindowsUtility::FillCharacter( pivot + r2tm::WindowsUtility::CursorPoint( ( short )v.x, ( short )v.y ), 'c' );
								}
							}
						}

						// Draw : 0, 0
						{
							auto v = view_mat4 * VEC4_0;

							v = projection_mat4 * v;
							v /= v.w;

							v = viewport_mat4 * v;

							r2tm::WindowsUtility::FillCharacter( pivot + r2tm::WindowsUtility::CursorPoint( ( short )v.x, ( short )v.y ), '0', r2tm::WindowsUtility::eColor::FG_Green );
						}

						r2tm::WindowsUtility::MoveCursorPoint( r2tm::WindowsUtility::CursorPoint( 0, pivot.y + ( short )viewport_h ) );
						
						LS();
					}

				} while( !_kbhit() );
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}