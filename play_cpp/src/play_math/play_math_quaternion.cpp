#include "play_math_quaternion.h"
#include "play_math___helper_common.h"
#include "play_math___helper_quaternion.h"
#include "play_math___helper_vector3.h"
using namespace play_math;

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace play_math_quaternion
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quaternion : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "쿼터니언 개요 : Quaternion" );
			OUTPUT_COMMENT( "4원수" );
			OUTPUT_COMMENT( "실수부 + 3개의 허수부 = w + x, y, z" );
			OUTPUT_COMMENT( "회전에만 사용" );

			LF();

			OUTPUT_SUBJECT( "성분 설명" );
			OUTPUT_COMMENT( "w" );
			OUTPUT_COMMENT( "    " "스칼라 또는 실수부" );
			OUTPUT_COMMENT( "    " "회전의 크기와 관련된 정보" );
			OUTPUT_COMMENT( "    " "1일 때 회전량 최소. 0일 때 회전량 최대( 180 )" );
			OUTPUT_COMMENT( "x, y, z" );
			OUTPUT_COMMENT( "    " "허수부" );
			OUTPUT_COMMENT( "    " "회전축의 방향을 나타낸다" );
			OUTPUT_COMMENT( "    " "회전 각도의 절반의 사인 값(sin(θ/2))에 해당 축의 단위 벡터 성분을 곱한 값" );

			LF();

			OUTPUT_SUBJECT( "정리" );
			OUTPUT_COMMENT( "k = 회전축" );
			OUTPUT_COMMENT( "q = ( cos( θ / 2 ), k * sin( θ / 2 ) )" );
			OUTPUT_COMMENT( "q = ( w, v )" );
			OUTPUT_COMMENT( "q = ( w, x, y, z )" );
			OUTPUT_COMMENT( "회전 축의 방향과 회전 각도를 4차원 벡터의 형태로 표현한 것." );

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				struct Quaternion
				{
					float w;    // 스칼라
					float x;    // 허수부
					float y;    // 허수부
					float z;    // 허수부
				};
				OUTPUT_SOURCE_END;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Length::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quaternion : Length";
		};
	}
	r2tm::DoFunctionT Length::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "쿼터니언의 길이 계산" );
			OUTPUT_COMMENT( "기본 개념은 Vector 의 길이 계산과 동일." );

			LF();

			OUTPUT_SUBJECT( "계산 공식" );
			OUTPUT_COMMENT( "쿼터니언의 길이 = sqrt( w^2 + x^2 + y^2 + z^2 )" );

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto L = []( Quat q )->float
				{
					return sqrt(
						  ( q.w * q.w )
						+ ( q.x * q.x )
						+ ( q.y * q.y )
						+ ( q.z * q.z )
					);
				};
				OUTPUT_SOURCE_END;

				SS();

				EXPECT_EP_EQ( 1, L( Quat( 1, 0, 0, 0 ) ) );
				EXPECT_EP_EQ( 1, L( Quat( 0, 1, 0, 0 ) ) );
				EXPECT_EP_EQ( 1, L( Quat( 0, 0, 1, 0 ) ) );
				EXPECT_EP_EQ( 1, L( Quat( 0, 0, 0, 1 ) ) );

				SS();

				EXPECT_EP_EQ( 2, L( Quat( 1, 1, 1, 1 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Normalize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quaternion : Normalize";
		};
	}
	r2tm::DoFunctionT Normalize::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "쿼터니언의 정규화" );
			OUTPUT_COMMENT( "쿼터니언의 각 성분을 길이로 나눈다." );

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto L = []( Quat q )->float
				{
					return sqrt(
						  ( q.w * q.w )
						+ ( q.x * q.x )
						+ ( q.y * q.y )
						+ ( q.z * q.z )
					);
				};

				const auto N = [L]( Quat q )->Quat
				{
					const float length = L( q );

					return Quat(
						  q.w / length
						, q.x / length
						, q.y / length
						, q.z / length
					);
				};
				OUTPUT_SOURCE_END;

				SS();

				EXPECT_EQ( Quat( 1, 0, 0, 0 ), N( Quat( 1, 0, 0, 0 ) ) );
				EXPECT_EQ( Quat( 0, 1, 0, 0 ), N( Quat( 0, 1, 0, 0 ) ) );
				EXPECT_EQ( Quat( 0, 0, 1, 0 ), N( Quat( 0, 0, 1, 0 ) ) );
				EXPECT_EQ( Quat( 0, 0, 0, 1 ), N( Quat( 0, 0, 0, 1 ) ) );

				SS();

				{
					DECLARATION_MAIN( const Quat q( 1, 1, 1, 1 ) );

					LF();

					EXPECT_EP_EQ( 2, L( q ) );
					EXPECT_EQ( Quat( 0.5f, 0.5f, 0.5f, 0.5f ), N( q ) );

					LF();

					EXPECT_EP_EQ( 1, L( N( q ) ) );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Rotation::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quaternion : Rotation";
		};
	}
	r2tm::DoFunctionT Rotation::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "REF : qua<T, Q>::operator*=( qua<U, Q> const& r ) : https://github.com/g-truc/glm/blob/master/glm/detail/type_quat.inl" );

			LF();

			OUTPUT_SUBJECT( "Quaternion 과 Vector3 의 곱 : 벡터의 회전" );
			OUTPUT_COMMENT( "1. 벡터를 Pure Quaternion 으로 변환" );
			OUTPUT_COMMENT( "   > "   "Pquat = ( 0, x, y, z )" );
			OUTPUT_COMMENT( "   > "   "Pquat = p" );
			OUTPUT_COMMENT( "2. 곱" );
			OUTPUT_COMMENT( "   > "   "p` = q * p * q^-1" );
			OUTPUT_COMMENT( "   > "   "p` = ( 회전 정의 단위 쿼터니언 ) * p * ( 회전 정의 단위 쿼터니언의 역 )" );

			LF();

			OUTPUT_SUBJECT( "Quaternion의 곱셈 규칙" );
			OUTPUT_COMMENT( "w = ( A.w * B.w ) - ( A.x * B.x ) - ( A.y * B.y ) - ( A.z * B.z )" );
			OUTPUT_COMMENT( "x = ( A.w * B.x ) + ( A.x * B.w ) + ( A.y * B.z ) - ( A.z * B.y )" );
			OUTPUT_COMMENT( "y = ( A.w * B.y ) + ( A.y * B.w ) + ( A.z * B.x ) - ( A.x * B.z )" );
			OUTPUT_COMMENT( "z = ( A.w * B.z ) + ( A.z * B.w ) + ( A.x * B.y ) - ( A.y * B.x )" );

			LF();

			OUTPUT_SUBJECT( "Quaternion 회전 공식" );
			OUTPUT_COMMENT( "k = 회전 축" );
			OUTPUT_COMMENT( "q = { cos( θ / 2 ), k.x * sin( θ / 2 ), k.y * sin( θ / 2 ), k.z * sin( θ / 2 ) }" );

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto B = []( Vec3 pv, float degree )->Quat
				{
					const auto radian = Deg2Rad( degree );

					return Quat(
						  std::cos( radian / 2.f )
						, pv.x * std::sin( radian / 2.f )
						, pv.y * std::sin( radian / 2.f )
						, pv.z * std::sin( radian / 2.f )
					);
				};

				const auto I = []( Quat q )->Quat
				{
					return Quat( q.w, -q.x, -q.y, -q.z );
				};
				OUTPUT_SOURCE_END;

				LF();

				{
					DECLARATION_MAIN( const Quat q = B( VEC3_X, 45.f ) );
					DECLARATION_MAIN( const Quat iq = I( q ) );
					OUTPUT_VALUE( ( q * VEC3_Y ) * iq );
				}

				LF();

				{
					DECLARATION_MAIN( const Quat q = B( VEC3_Y, 45.f ) );
					DECLARATION_MAIN( const Quat iq = I( q ) );
					OUTPUT_VALUE( ( q * VEC3_Z ) * iq );
				}

				LF();

				{
					DECLARATION_MAIN( const Quat q = B( VEC3_Z, 45.f ) );
					DECLARATION_MAIN( const Quat iq = I( q ) );
					OUTPUT_VALUE( ( q * VEC3_X ) * iq );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}