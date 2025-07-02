#include "play_math_quaternion.h"
#include "play_math___helper_common.h"
#include "play_math___helper_quaternion.h"
#include "play_math___helper_vector3.h"
using namespace play_math;

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace play_math_quaternion
{
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

			OUTPUT_SUBJECT( "쿼터니언 개요 : Quaternion" );
			OUTPUT_COMMENT( "4원수" );
			OUTPUT_COMMENT( "실수부 + 3개의 허수부 = w + x, y, z" );
			OUTPUT_COMMENT( "회전에만 사용" );

			LF();

			OUTPUT_SUBJECT( "단위 쿼터니언 : Unit Quaternion" );
			OUTPUT_COMMENT( "크기가 1인 Quaternion" );
			OUTPUT_COMMENT( "쿼터니언의 길이 = sqrt( w^2 + x^2 + y^2 + z^2 )" );

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