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

			{
				OUTPUT_SUBJECT( "View Matrix 를 만들이 위해서 우선 기준 벡터가 필요하다." );
				OUTPUT_COMMENT( "cam_eye     : 카메라 위치" );
				OUTPUT_COMMENT( "cam_forward : 카메라가 보는 방향" );
				OUTPUT_COMMENT( "cam_right   : 카메라가 보는 방향의 오른쪽 방향" );
				OUTPUT_COMMENT( "cam_up      : 카메라의 머리 위 방향" );
			}

			LS();

			OUTPUT_SUBJECT( "보통 사용자가 알고 있을 정보로 시작." );

			LF();

			OUTPUT_COMMENT( "카메라 위치" );
			DECLARATION_MAIN( const Vec4 init_eye( 0, 0, 10, 0 ) );

			LF();

			OUTPUT_COMMENT( "카메라 목표" );
			DECLARATION_MAIN( const Vec4 init_center( 0, 0, 0, 0 ) );

			LF();

			OUTPUT_COMMENT( "카메라 머리 위 방향" );
			DECLARATION_MAIN( const Vec4 init_up( 0, 1, 0, 0 ) );

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

			OUTPUT_SUBJECT( "현재 카메라 행렬 구성해보기" );

			LS();

			DECLARATION_MAIN( const Vec4 init_eye( 0, 0, 10, 0 ) );
			DECLARATION_MAIN( const Vec4 init_center( 10, 0, 0, 0 ) );
			DECLARATION_MAIN( const Vec4 init_up( 0, 1, 0, 0 ) );

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
}