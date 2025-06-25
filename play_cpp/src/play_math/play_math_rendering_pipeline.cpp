#include "play_math_rendering_pipeline.h"
#include "play_math___helper_common.h"
#include "play_math___helper_vector4.h"
#include "play_math___helper_matrix44.h"
using namespace play_math;

#include "r2tm/r2tm_Inspector.h"

namespace play_math_rendering_pipeline
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

			OUTPUT_SUBJECT( "View Matrix 구성을 위한 준비" );

			LS();

			{
				OUTPUT_SUBJECT( "View Matrix 구성을 위해 기준 벡터가 필요하다." );
				OUTPUT_COMMENT( "cam_eye     : 카메라 위치" );
				OUTPUT_COMMENT( "cam_forward : 카메라가 보는 방향" );
				OUTPUT_COMMENT( "cam_right   : 카메라가 보는 방향의 오른쪽 방향" );
				OUTPUT_COMMENT( "cam_up      : 카메라의 머리 위 방향" );
			}

			LS();

			OUTPUT_SUBJECT( "사용자가 알고 있을 정보로 시작." );

			LF();

			OUTPUT_COMMENT( "카메라 위치" );
			DECLARATION_MAIN( const Vec4 init_eye( 0, 0, 10, 1 ) );

			LF();

			OUTPUT_COMMENT( "카메라 목표" );
			DECLARATION_MAIN( const Vec4 init_center( 0, 0, 0, 1 ) );

			LF();

			OUTPUT_COMMENT( "카메라 머리 위 방향" );
			DECLARATION_MAIN( const Vec4 init_up( 0, 1, 0, 1 ) );

			LS();

			{
				OUTPUT_SUBJECT( "Forward" );

				LF();

				DECLARATION_MAIN( Vec4 cam_forward = vec4_normalize( init_eye - init_center ) );
				OUTPUT_VALUE( cam_forward );

				LF();

				OUTPUT_SUBJECT( "Right" );

				LF();

				DECLARATION_MAIN( Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) ) );
				OUTPUT_VALUE( cam_right );

				LF();

				OUTPUT_SUBJECT( "Up" );

				LF();

				DECLARATION_MAIN( Vec4 cam_up = vec4_cross( cam_forward, cam_right ) );
				OUTPUT_VALUE( cam_up );
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

			OUTPUT_SUBJECT( "Camera Matrix 구성해보기" );

			LS();

			DECLARATION_MAIN( const Vec4 init_eye( 0, 0, 10, 1 ) );
			DECLARATION_MAIN( const Vec4 init_center( 10, 0, 0, 1 ) );
			DECLARATION_MAIN( const Vec4 init_up( 0, 1, 0, 1 ) );

			LS();

			{
				OUTPUT_SUBJECT( "Ready" );

				LF();

				DECLARATION_MAIN( Vec4 cam_forward = vec4_normalize( init_eye - init_center ) );
				DECLARATION_MAIN( Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) ) );
				DECLARATION_MAIN( Vec4 cam_up = vec4_cross( cam_forward, cam_right ) );


				SS();


				OUTPUT_SUBJECT( "Camera Matrix" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				const Mat44 cam_mat4(
					  cam_right.x, cam_up.x, cam_forward.x, init_eye.x
					, cam_right.y, cam_up.y, cam_forward.y, init_eye.y
					, cam_right.z, cam_up.z, cam_forward.z, init_eye.z
					, 0.f        , 0.f     , 0.f          , 1.f
				);
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( cam_mat4 );


				SS();


				DECLARATION_MAIN( Vec4 cam_vec4( 0, 0, 10, 1 ) );
				PROCESS_MAIN( cam_vec4 = cam_mat4 * cam_vec4 );

				LF();

				OUTPUT_VALUE( cam_vec4 );

				LF();

				OUTPUT_NOTE( "원점을 중심으로 45도 회전 후 이동해서 현재의 위치가 된다." );
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
			OUTPUT_SOURCE_READY;

			LS();

			OUTPUT_SUBJECT( "View 행렬 구성" );

			LS();

			DECLARATION_MAIN( const Vec4 init_eye( 0, 0, 10, 1 ) );
			DECLARATION_MAIN( const Vec4 init_center( 10, 0, 0, 1 ) );
			DECLARATION_MAIN( const Vec4 init_up( 0, 1, 0, 1 ) );
			DECLARATION_MAIN( Vec4 cam_forward = vec4_normalize( init_eye - init_center ) );
			DECLARATION_MAIN( Vec4 cam_right = vec4_normalize( vec4_cross( init_up, cam_forward ) ) );
			DECLARATION_MAIN( Vec4 cam_up = vec4_cross( cam_forward, cam_right ) );

			LS();

			{
				OUTPUT_SUBJECT( "Rotation Matrix : Camera Rotation의 전치" );

				LF();

				OUTPUT_SOURCE_BEGIN;
				const Mat44 cam_mat4(
					  cam_right.x    , cam_right.y    , cam_right.z    , 0.f
					, cam_up.x       , cam_up.y       , cam_up.z       , 0.f
					, cam_forward.x  , cam_forward.y  , cam_forward.z  , 0.f
					, 0.f            , 0.f            , 0.f            , 1.f
				);
				OUTPUT_SOURCE_END;
			}

			LS();

			{
				OUTPUT_SUBJECT( "Translate Matrix : Camera Position의 음수 값" );

				LF();

				OUTPUT_SOURCE_BEGIN;
				const Mat44 view_translate_mat4(
					  0.f, 0.f, 0.f, -init_eye.x
					, 0.f, 0.f, 0.f, -init_eye.y
					, 0.f, 0.f, 0.f, -init_eye.z
					, 0.f, 0.f, 0.f, 1.f
				);
				OUTPUT_SOURCE_END;
			}

			LS();

			{
				OUTPUT_SUBJECT( "Final Matrix" );
				OUTPUT_COMMENT( "-vec4_dot( cam_right, init_eye )" );
				OUTPUT_COMMENT( "카메라의 회전된 로컬 축을 기준으로 eye 위치를 반대 방향으로 이동" );

				LF();

				OUTPUT_SOURCE_BEGIN;
				const Mat44 view_final_mat4(
					  cam_right.x    , cam_right.y    , cam_right.z    , -vec4_dot( cam_right, init_eye )
					, cam_up.x       , cam_up.y       , cam_up.z       , -vec4_dot( cam_up, init_eye )
					, cam_forward.x  , cam_forward.y  , cam_forward.z  , -vec4_dot( cam_forward, init_eye )
					, 0.f            , 0.f            , 0.f            , 1.f
				);
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( view_final_mat4 );


				SS();


				OUTPUT_SUBJECT( "Demo" );

				LF();

				OUTPUT_VALUE( view_final_mat4 * init_eye );
				OUTPUT_VALUE( view_final_mat4 * init_center );
				OUTPUT_VALUE( view_final_mat4 * Vec4( 0, 0, 0, 1 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ProjectionMatrix_Step1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Projection Matrix : Step 1";
		};
	}
	r2tm::DoFunctionT ProjectionMatrix_Step1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "Orthographic : 직교 투영" );
			OUTPUT_COMMENT( "-1 ~ +1 : 로 표현되는 좌표계로 변환" );
			OUTPUT_COMMENT( "Z 범위만 0 ~ 1" );

			LS();

			DECLARATION_MAIN( const int viewport_w = 400 );
			DECLARATION_MAIN( const int viewport_h = 300 );

			LF();

			OUTPUT_SUBJECT( "left = 0, bottom = 0 으로 설정하면" );
			OUTPUT_SUBJECT( "0, 0, 0 좌표는 viewport 왼쪽 하단 끝 -1, -1 으로 배치된다." );
			DECLARATION_MAIN( const float left = -viewport_w / 2 );
			DECLARATION_MAIN( const float right = viewport_w / 2 );
			DECLARATION_MAIN( const float bottom = -viewport_h / 2 );
			DECLARATION_MAIN( const float top = viewport_h / 2 );
			DECLARATION_MAIN( const float near_plane = 0.1f ); // 가까운 절단면
			DECLARATION_MAIN( const float far_plane = 100.f ); // 먼 절단면

			LS();

			{
				// https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl

				OUTPUT_SOURCE_READY_N_BEGIN;
				const Mat44 projection_mat4(
					  2 / ( right - left )  , 0.f                   , 0.f                             , -( right + left ) / ( right - left )
					, 0.f                   , 2 / ( top - bottom )  , 0.f                             , -( top + bottom ) / ( top - bottom )
					, 0.f                   , 0.f                   , 1 / ( far_plane - near_plane )  , -near_plane / ( far_plane - near_plane )
					, 0.f                   , 0.f                   , 0.f                             , 1.f
				);
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( projection_mat4 );

				
				SS();


				EXPECT_EP_EQ( 0, ( projection_mat4 * VEC4_0 ).x );
				EXPECT_EP_EQ( 0, ( projection_mat4 * VEC4_0 ).y );

				LF();

				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( viewport_w / 2, viewport_h / 2, 0, 1 ) ).x );
				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( viewport_w / 2, viewport_h / 2, 0, 1 ) ).y );

				LF();

				EXPECT_EP_EQ( -1, ( projection_mat4 * Vec4( -viewport_w / 2, -viewport_h / 2, 0, 1 ) ).x );
				EXPECT_EP_EQ( -1, ( projection_mat4 * Vec4( -viewport_w / 2, -viewport_h / 2, 0, 1 ) ).y );

				LF();

				EXPECT_EP_EQ( 0, ( projection_mat4 * Vec4( 0, 0, near_plane, 1 ) ).z );
				EXPECT_EP_EQ( 1, ( projection_mat4 * Vec4( 0, 0, far_plane, 1 ) ).z );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}