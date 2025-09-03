#include "play_math_quaternion.h"
#include "play_math___helper_common.h"
#include "play_math___helper_quaternion.h"
#include "play_math___helper_vector3.h"
#include "play_math___helper_matrix44.h"
using namespace play_math;

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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

			OUT_SUBJECT( "쿼터니언 개요 : Quaternion" );
			OUT_COMMENT( "4원수" );
			OUT_COMMENT( "실수부 + 3개의 허수부 = w + x, y, z" );
			OUT_COMMENT( "회전에만 사용" );
			OUT_COMMENT( "일반적으로 길이가 1 이다." );

			LF();

			OUT_SUBJECT( "성분 설명" );
			OUT_COMMENT( "w" );
			OUT_COMMENT( "    " "스칼라 또는 실수부" );
			OUT_COMMENT( "    " "회전의 크기와 관련된 정보" );
			OUT_COMMENT( "    " "1일 때 회전량 최소. 0일 때 회전량 최대( 180 )" );
			OUT_COMMENT( "x, y, z" );
			OUT_COMMENT( "    " "허수부" );
			OUT_COMMENT( "    " "회전축의 방향을 나타낸다" );
			OUT_COMMENT( "    " "회전 각도의 절반의 사인 값(sin(θ/2))에 해당 축의 단위 벡터 성분을 곱한 값" );

			LF();

			OUT_SUBJECT( "정리" );
			OUT_COMMENT( "k = 회전축" );
			OUT_COMMENT( "q = ( cos( θ / 2 ), k * sin( θ / 2 ) )" );
			OUT_COMMENT( "q = ( w, v )" );
			OUT_COMMENT( "q = ( w, x, y, z )" );
			OUT_COMMENT( "회전 축의 방향과 회전 각도를 4차원 벡터의 형태로 표현한 것." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct Quaternion
				{
					float w;    // 스칼라
					float x;    // 허수부
					float y;    // 허수부
					float z;    // 허수부
				};
				OUT_SOURCE_END;
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

			OUT_SUBJECT( "쿼터니언의 길이 계산" );
			OUT_COMMENT( "기본 개념은 Vector 의 길이 계산과 동일." );

			LF();

			OUT_SUBJECT( "계산 공식" );
			OUT_COMMENT( "쿼터니언의 길이 = sqrt( w^2 + x^2 + y^2 + z^2 )" );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const auto L = []( Quat q )->float
				{
					return sqrt(
						  ( q.w * q.w )
						+ ( q.x * q.x )
						+ ( q.y * q.y )
						+ ( q.z * q.z )
					);
				};
				OUT_SOURCE_END;

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

			OUT_SUBJECT( "쿼터니언의 정규화" );
			OUT_COMMENT( "쿼터니언의 각 성분을 길이로 나눈다." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const auto N = []( Quat q )->Quat
				{
					const float length = quat_length( q );

					return Quat(
						  q.w / length
						, q.x / length
						, q.y / length
						, q.z / length
					);
				};
				OUT_SOURCE_END;

				SS();

				EXPECT_EQ( Quat( 1, 0, 0, 0 ), N( Quat( 1, 0, 0, 0 ) ) );
				EXPECT_EQ( Quat( 0, 1, 0, 0 ), N( Quat( 0, 1, 0, 0 ) ) );
				EXPECT_EQ( Quat( 0, 0, 1, 0 ), N( Quat( 0, 0, 1, 0 ) ) );
				EXPECT_EQ( Quat( 0, 0, 0, 1 ), N( Quat( 0, 0, 0, 1 ) ) );

				SS();

				{
					DECL_MAIN( const Quat q( 1, 1, 1, 1 ) );

					LF();

					EXPECT_EP_EQ( 2, quat_length( q ) );
					EXPECT_EQ( Quat( 0.5f, 0.5f, 0.5f, 0.5f ), N( q ) );

					LF();

					EXPECT_EP_EQ( 1, quat_length( N( q ) ) );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Inverse::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quaternion : Inverse";
		};
	}
	r2tm::DoFunctionT Inverse::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "쿼터니언의 역 : Inverse Quaternion" );
			OUT_COMMENT( "회전을 되돌리는 쿼터니언" );

			LF();

			OUT_SUBJECT( "식" );
			OUT_COMMENT( "qc = 켤레 쿼터니언, 허수부의 부호만 반대로 바꾼 쿼터니언" );
			OUT_COMMENT( "qi = qc / ( ||q||^2 )" );
			OUT_COMMENT( "qi = qc / ( sqrt( w^2 + x^2 + y^2 + z^2 )^2 )" );
			OUT_COMMENT( "qi = qc / ( w^2 + x^2 + y^2 + z^2 )" );
			OUT_COMMENT( "qi = {" );
			OUT_COMMENT( "    " "   w / ( w^2 + x^2 + y^2 + z^2 )" );
			OUT_COMMENT( "    " ", -x / ( w^2 + x^2 + y^2 + z^2 )" );
			OUT_COMMENT( "    " ", -y / ( w^2 + x^2 + y^2 + z^2 )" );
			OUT_COMMENT( "    " ", -z / ( w^2 + x^2 + y^2 + z^2 )" );
			OUT_COMMENT( "}" );
			LF();

			OUT_SUBJECT( "적용" );
			OUT_COMMENT( "일반적으로 회전을 표현하는 쿼터니언은 길이가 1 이다." );
			OUT_COMMENT( "qi = qc / ( ||q||^2 )" );
			OUT_COMMENT( "qi = qc / ( 1^2 )" );
			OUT_COMMENT( "qi = qc / 1" );
			OUT_COMMENT( "qi = qc" );
			OUT_COMMENT( "qi = { w, -x, -y, -z }" );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const auto I = []( Quat q )->Quat
				{
					return Quat( q.w, -q.x, -q.y, -q.z );
				};
				OUT_SOURCE_END;

				SS();

				EXPECT_EQ( Quat( 1, -2, -3, -4 ), I( Quat( 1, 2, 3, 4 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Multiply::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quaternion : Multiply";
		};
	}
	r2tm::DoFunctionT Multiply::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "REF : qua<T, Q>::operator*=( qua<U, Q> const& r ) : https://github.com/g-truc/glm/blob/master/glm/detail/type_quat.inl" );

				LF();

				OUT_SUBJECT( "쿼터니언의 대수적 정의" );
				OUT_COMMENT( "q = w + xi + yj + zk" );

				LF();

				OUT_SUBJECT( "쿼터니언 A * B" );
				OUT_COMMENT( "A * B = ( A.w + A.xi + A.yj + A.zk ) * ( B.w2 + B.xi + B.yj + B.zk )" );
				OUT_COMMENT( "위 식을 전개후 정리하면 아래의 식이 나온다." );

				LF();

				OUT_SUBJECT( "식" );
				OUT_COMMENT( "w = ( A.w * B.w ) - ( A.x * B.x ) - ( A.y * B.y ) - ( A.z * B.z )" );
				OUT_COMMENT( "x = ( A.w * B.x ) + ( A.x * B.w ) + ( A.y * B.z ) - ( A.z * B.y )" );
				OUT_COMMENT( "y = ( A.w * B.y ) + ( A.y * B.w ) + ( A.z * B.x ) - ( A.x * B.z )" );
				OUT_COMMENT( "z = ( A.w * B.z ) + ( A.z * B.w ) + ( A.x * B.y ) - ( A.y * B.x )" );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const auto M = []( Quat a, Quat b )->Quat
				{
					return Quat(
						  ( a.w * b.w ) - ( a.x * b.x ) - ( a.y * b.y ) - ( a.z * b.z )
						, ( a.w * b.x ) + ( a.x * b.w ) + ( a.y * b.z ) - ( a.z * b.y )
						, ( a.w * b.y ) + ( a.y * b.w ) + ( a.z * b.x ) - ( a.x * b.z )
						, ( a.w * b.z ) + ( a.z * b.w ) + ( a.x * b.y ) - ( a.y * b.x )
					);
				};
				OUT_SOURCE_END;

				SS();

				EXPECT_EQ( Quat( -2, 2, 2, 2 ), M( Quat( 1, 1, 1, 1 ), Quat( 1, 1, 1, 1 ) ) );
				EXPECT_EQ( Quat( -28, 4, 6, 8 ), M( Quat( 1, 2, 3, 4 ), Quat( 1, 2, 3, 4 ) ) );
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

			OUT_SUBJECT( "벡터의 회전 == Quaternion 과 Vector의 곱 개요" );
			OUT_COMMENT( "샌드위치 곱" );

			LF();

			OUT_SUBJECT( "쿼터니언 구성 식" );
			OUT_COMMENT( "k = 회전 축" );
			OUT_COMMENT( "q = { cos( θ / 2 ), k.x * sin( θ / 2 ), k.y * sin( θ / 2 ), k.z * sin( θ / 2 ) }" );

			LF();

			OUT_SUBJECT( "연산 과정" );
			OUT_COMMENT( "1. 벡터를 Pure Quaternion 으로 변환" );
			OUT_COMMENT( "     "   "Pquat = ( 0, x, y, z )" );
			OUT_COMMENT( "     "   "Pquat = p" );
			OUT_COMMENT( "2. 곱 : 샌드위치 곱" );
			OUT_COMMENT( "     "   "q = 회전 정의 단위 쿼터니언" );
			OUT_COMMENT( "     "   "qi = q의 역" );
			OUT_COMMENT( "     "   "p` = q * p * qi" );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
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
				OUT_SOURCE_END;

				SS();

				{
					DECL_MAIN( const Quat q = B( VEC3_Z, 45.f ) );
					OUT_VALUE( ( q * Quat( VEC3_X ) ) );
					OUT_VALUE( ( q * Quat( VEC3_X ) ) * quat_inverse( q ) );
				}

				SS();

				{
					{
						DECL_MAIN( const Quat q = B( VEC3_X, 90.f ) );
						EXPECT_EQ( Quat( 0, 0, 0, 1 ), ( q * Quat( VEC3_Y ) ) * quat_inverse( q ) );
					}

					LF();

					{
						DECL_MAIN( const Quat q = B( VEC3_Y, 90.f ) );
						EXPECT_EQ( Quat( 0, 1, 0, 0 ), ( q * Quat( VEC3_Z ) ) * quat_inverse( q ) );
					}

					LF();

					{
						DECL_MAIN( const Quat q = B( VEC3_Z, 90.f ) );
						EXPECT_EQ( Quat( 0, 0, 1, 0 ), ( q * Quat( VEC3_X ) ) * quat_inverse( q ) );
					}
				}

				SS();

				{
					{
						DECL_MAIN( const Quat q = B( VEC3_X, 90.f ) );
						EXPECT_EQ( Quat( 0, 0, 0, 1 ), ( q * VEC3_Y ) );
					}

					LF();

					{
						DECL_MAIN( const Quat q = B( VEC3_Y, 90.f ) );
						EXPECT_EQ( Quat( 0, 1, 0, 0 ), ( q * VEC3_Z ) );
					}

					LF();

					{
						DECL_MAIN( const Quat q = B( VEC3_Z, 90.f ) );
						EXPECT_EQ( Quat( 0, 0, 1, 0 ), ( q * VEC3_X ) );
					}
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Convert_2_Matrix::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Quaternion : Convert_2_Matrix";
		};
	}
	r2tm::DoFunctionT Convert_2_Matrix::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "쿼터니언을 행렬로 변환" );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				const auto B = []( Vec4 pv, float degree )->Quat
				{
					const auto radian = Deg2Rad( degree );

					return Quat(
						std::cos( radian / 2.f )
						, pv.x * std::sin( radian / 2.f )
						, pv.y * std::sin( radian / 2.f )
						, pv.z * std::sin( radian / 2.f )
					);
				};

				const auto C = []( Quat q )->Mat44
				{
					return Mat44(
						  1 - ( 2 *  q.y * q.y ) - ( 2 * q.z * q.z )  , ( 2 * q.x * q.y ) - ( 2 * q.z * q.w )      , ( 2 * q.x * q.z ) + ( 2 * q.y * q.w )      , 0
						, ( 2 * q.x * q.y ) + ( 2 * q.z * q.w )       , 1 - ( 2 * q.x * q.x ) - ( 2 * q.z * q.z )  , ( 2 * q.y * q.z ) - ( 2 * q.x * q.w )      , 0
						, ( 2 * q.x * q.z ) - ( 2 * q.y * q.w )       , ( 2 * q.y * q.z ) + ( 2 * q.x * q.w )      , 1 - ( 2 * q.x * q.x ) - ( 2 * q.y * q.y )  , 0
						, 0                                           , 0                                          , 0                                          , 1
					);
				};
				OUT_SOURCE_END;

				SS();

				{
					DECL_MAIN( const Quat q = B( VEC4_X, 90.f ) );
					DECL_MAIN( const Mat44 m = C( q ) );
					EXPECT_EQ( VEC4_Z, m * VEC4_Y );
				}

				LF();

				{
					DECL_MAIN( const Quat q = B( VEC4_Y, 90.f ) );
					DECL_MAIN( const Mat44 m = C( q ) );
					EXPECT_EQ( VEC4_X, m * VEC4_Z );
				}

				LF();

				{
					DECL_MAIN( const Quat q = B( VEC4_Z, 90.f ) );
					DECL_MAIN( const Mat44 m = C( q ) );
					EXPECT_EQ( VEC4_Y, m * VEC4_X );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}