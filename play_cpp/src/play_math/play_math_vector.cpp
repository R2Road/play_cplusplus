#include "play_math_vector.h"
#include "play_math___helper.h"
using namespace play_math;

#include "r2/r2helper_STDPrinter4Vector4.h"

namespace play_math_vector
{
	r2tm::TitleFunctionT Length::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Length";
		};
	}
	r2tm::DoFunctionT Length::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			OUTPUT_SUBJECT( "피타고라스의 정리" );
			OUTPUT_COMMENT( "밑변 = a, 높이 = b, 빗변 = c" );
			OUTPUT_COMMENT( "a^2 + b^2 = c^2" );
			OUTPUT_COMMENT( "sqrt( a^2 + b^2 ) = c" );

			LF();

			OUTPUT_SUBJECT( "피타고라스의 정리를 3차원으로 확장" );
			OUTPUT_COMMENT( "Vec3 A 의 xy 성분만으로 Vec2 B 를 만든다." );
			OUTPUT_COMMENT( "B의 길이를 구한다." );
			OUTPUT_COMMENT( "B의 길이 = 높이, A의 z 성분 = 밑변 으로 피타고라스의 정리 적용." );

			LF();

			OUTPUT_COMMENT( "A의 길이 = sqrt( B의 길이^2 + z^2 )" );
			OUTPUT_COMMENT( "||A|| = sqrt( sqrt( x^2 + y^2 )^2 + z^2 )" );
			OUTPUT_COMMENT( "||A|| = sqrt( x^2 + y^2 + z^2 )" );

			LS();

			OUTPUT_SOURCE_BEGIN;
			const auto L = []( r2::Vector4 v )->float
			{
				return std::sqrt(
					  ( v.x * v.x )
					+ ( v.y * v.y )
					+ ( v.z * v.z )
				);
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				OUTPUT_SUBJECT( "1축" );

				LF();

				EXPECT_EP_EQ( std::sqrt( 4.f ), L( r2::Vector4( 2.f, 0.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( std::sqrt( 4.f ), L( r2::Vector4( 0.f, 2.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( std::sqrt( 4.f ), L( r2::Vector4( 0.f, 0.f, 2.f, 0.f ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "2축" );

				LF();

				EXPECT_EP_EQ( std::sqrt( 8.f ), L( r2::Vector4( 2.f, 2.f, 0.f, 0.f ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "3축" );

				LF();

				EXPECT_EP_EQ( std::sqrt( 12.f ), L( r2::Vector4( 2.f, 2.f, 2.f, 0.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Dot_Product_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Dot Product 1";
		};
	}
	r2tm::DoFunctionT Dot_Product_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			OUTPUT_SUBJECT( "내적은 두 벡터가 같은 방향을 향하는지" );
			OUTPUT_SUBJECT( "또는 정렬되어 있는지를 나타내는 척도." );

			LF();

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