#include "play_math_numbers.hpp"
#include "play_math___helper_common.hpp"
#include "play_math___helper_vector3.hpp"
#include "play_math___helper_matrix33.hpp"
using namespace play_math;

#include "r2tm/r2tm_inspector.hpp"

namespace play_math_numbers
{
	r2tm::TitleFunctionT _1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Numbers 1 : 기억할 값들";
		};
	}
	r2tm::DoFunctionT _1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			const auto RY = []( const float radian )->Mat33
			{
				return Mat33(
						std::cos( radian )  , 0, std::sin( radian )
					, 0                   , 1, 0
					, -std::sin( radian ) , 0, std::cos( radian )
				);
			};

			const auto RX = []( const float radian )->Mat33
			{
				return Mat33(
						1, 0                 , 0
					, 0, std::cos( radian ), -std::sin( radian )
					, 0, std::sin( radian ), std::cos( radian )
				);
			};

			{
				OUT_SUBJECT( "대각선 벡터의 길이" );

				LF();

				OUT_VALUE( vec3_length( Vec3( 1, 1, 0 ) ) );

				LF();

				OUT_VALUE( vec3_length( Vec3( 1, 1, 1 ) ) );
			}

			LS();

			{
				OUT_SUBJECT( "단위 벡터가 45도 회전했을 때의 위치" );

				LF();

				OUT_VALUE( ( RY( Deg2Rad( 45.f ) ) * VEC3_Z ) );

				LF();

				OUT_VALUE( std::cos( Deg2Rad( 45.f ) ) );

				LF();

				OUT_VALUE( std::sin( Deg2Rad( 45.f ) ) );
			}

			LS();

			{
				OUT_SUBJECT( "단위 벡터가 45도, 45도 회전했을 때의 위치" );

				LF();

				DECL_MAIN( Vec3 v );

				LF();

				PROC_MAIN( v = RY( Deg2Rad( 45.f ) ) * VEC3_Z );
				OUT_VALUE( Rad2Deg( vec3_angle( v, VEC3_Z ) ) );
				OUT_VALUE( v );

				LF();

				PROC_MAIN( v = RX( Deg2Rad( 45.f ) ) * v );
				OUT_VALUE( Rad2Deg( vec3_angle( v, VEC3_Z ) ) );
				OUT_VALUE( v );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}