#include "play_math_vector.h"
#include "play_math___helper.h"
using namespace play_math;

#include "r2/r2helper_STDPrinter4Vector4.h"

namespace play_math_vector
{
	r2tm::TitleFunctionT Dot_Product::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Dot Product";
		};
	}
	r2tm::DoFunctionT Dot_Product::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			OUTPUT_SUBJECT( "내적의 대수적 정의" );
			OUTPUT_COMMENT( "A dot B = AxBx + AyBy + AzBz + AwBw" );

			LS();

			OUTPUT_SOURCE_BEGIN;
			const auto DOT = []( r2::Vector4 v1, r2::Vector4 v2 )->float
			{

				return (
					  ( v1.x * v2.x )
					+ ( v1.y * v2.y )
					+ ( v1.z * v2.z )
					+ ( v1.w * v2.w )
				);
			};
			OUTPUT_SOURCE_END;

			LS();

			DECLARATION_MAIN( const r2::Vector4 v_y( 0.f, 1.f, 0.f, 0.f ) );

			LS();

			{
				OUTPUT_SUBJECT( "같은 벡터" );

				LF();

				DECLARATION_MAIN( const float r = DOT( v_y, v_y ) );
				EXPECT_EP_EQ( 1.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "수직 벡터 1" );

				LF();

				DECLARATION_MAIN( const float r = DOT( v_y, r2::Vector4( 1.f, 0.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( 0.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "수직 벡터 2" );

				LF();

				DECLARATION_MAIN( const float r = DOT( v_y, r2::Vector4( -1.f, 0.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( 0.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "뒤집힌 벡터" );

				LF();

				DECLARATION_MAIN( const float r = DOT( v_y, r2::Vector4( 0.f, -1.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( -1.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "대각선 확인" );

				LF();

				EXPECT_EP_EQ( 0.3f, DOT( v_y, r2::Vector4( 0.3f, 0.3f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( -0.3f, DOT( v_y, r2::Vector4( 0.3f, -0.3f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( 0.3f, DOT( v_y, r2::Vector4( -0.3f, 0.3f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( -0.3f, DOT( v_y, r2::Vector4( -0.3f, -0.3f, 0.f, 0.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}