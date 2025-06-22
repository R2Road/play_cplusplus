#include "play_math_vector.h"
#include "play_math___helper.h"
using namespace play_math;

#include "r2tm/r2tm_Inspector.h"

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
			const auto L = []( Vec3 v )->float
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

				EXPECT_EP_EQ( std::sqrt( 4.f ), L( Vec3( 2.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( std::sqrt( 4.f ), L( Vec3( 0.f, 2.f, 0.f ) ) );
				EXPECT_EP_EQ( std::sqrt( 4.f ), L( Vec3( 0.f, 0.f, 2.f ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "2축" );

				LF();

				EXPECT_EP_EQ( std::sqrt( 8.f ), L( Vec3( 2.f, 2.f, 0.f ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "3축" );

				LF();

				EXPECT_EP_EQ( std::sqrt( 12.f ), L( Vec3( 2.f, 2.f, 2.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Normalize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Normalize";
		};
	}
	r2tm::DoFunctionT Normalize::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			OUTPUT_SUBJECT( "벡터의 정규화" );
			OUTPUT_COMMENT( "벡터의 방향은 유지 하면서 길이를 1로 만든다." );
			OUTPUT_COMMENT( "벡터의 각 성분을 길이로 나눈다." );

			LS();

			OUTPUT_SOURCE_BEGIN;
			const auto N = []( Vec3 v )->Vec3
			{
				const float l = vec3_length( v );
				return Vec3(
					  ( v.x / l )
					, ( v.y / l )
					, ( v.z / l )
				);
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				OUTPUT_SUBJECT( "Demo" );

				LF();

				DECLARATION_MAIN( const Vec3 v( 2.f, 2.f, 2.f ) );
				DECLARATION_MAIN( const auto v_n = N( v ) );
				DECLARATION_MAIN( const auto length = vec3_length( v ) );

				LF();

				EXPECT_EQ( v_n.x, v.x / length );
				EXPECT_EQ( v_n.y, v.y / length );
				EXPECT_EQ( v_n.z, v.z / length );

				SS();

				OUTPUT_VALUE( v_n );

				LF();

				OUTPUT_VALUE( length );
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
			const auto DOT = []( Vec3 v1, Vec3 v2 )->float
			{

				return (
					  ( v1.x * v2.x )
					+ ( v1.y * v2.y )
					+ ( v1.z * v2.z )
				);
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				OUTPUT_SUBJECT( "같은 벡터" );

				LF();

				DECLARATION_MAIN( const float r = DOT( VEC3_Y, VEC3_Y ) );
				EXPECT_EP_EQ( 1.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "수직 벡터 1" );

				LF();

				DECLARATION_MAIN( const float r = DOT( VEC3_Y, Vec3( 1.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( 0.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "수직 벡터 2" );

				LF();

				DECLARATION_MAIN( const float r = DOT( VEC3_Y, Vec3( -1.f, 0.f, 0.f ) ) );
				EXPECT_EP_EQ( 0.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "뒤집힌 벡터" );

				LF();

				DECLARATION_MAIN( const float r = DOT( VEC3_Y, Vec3( 0.f, -1.f, 0.f ) ) );
				EXPECT_EP_EQ( -1.f, r );
			}

			LS();

			{
				OUTPUT_SUBJECT( "대각선 확인" );

				LF();

				EXPECT_EP_EQ( 0.3f, DOT( VEC3_Y, Vec3( 0.3f, 0.3f, 0.f ) ) );
				EXPECT_EP_EQ( -0.3f, DOT( VEC3_Y, Vec3( 0.3f, -0.3f, 0.f ) ) );
				EXPECT_EP_EQ( 0.3f, DOT( VEC3_Y, Vec3( -0.3f, 0.3f, 0.f ) ) );
				EXPECT_EP_EQ( -0.3f, DOT( VEC3_Y, Vec3( -0.3f, -0.3f, 0.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Dot_Product_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Dot Product 2 : Projection";
		};
	}
	r2tm::DoFunctionT Dot_Product_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "단위 벡터에 투영" );

				LF();

				EXPECT_EP_EQ( 1.f, vec3_dot( VEC3_Y, Vec3( 0.f, 1.f, 0.f ) ) );
				EXPECT_EP_EQ( 0.8f, vec3_dot( VEC3_Y, Vec3( 0.f, 0.8f, 0.f ) ) );
				EXPECT_EP_EQ( 0.4f, vec3_dot( VEC3_Y, Vec3( 0.f, 0.4f, 0.f ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "임의의 벡터에 투영한 값은 그대로 사용은 어렵다." );

				LF();

				DECLARATION_MAIN( const Vec3 v_p( 5.f, 5.f, 5.f ) );

				LF();

				EXPECT_EP_EQ( 15.f, vec3_dot( v_p, Vec3( 1.f, 1.f, 1.f ) ) );
				EXPECT_EP_EQ( 30.f, vec3_dot( v_p, Vec3( 2.f, 2.f, 2.f ) ) );

				SS();

				OUTPUT_SUBJECT( "기준 벡터 길이의 제곱값과 나눠서 비율을 구한다." );

				LF();

				DECLARATION_MAIN( const float l = vec3_length( v_p ) );
				EXPECT_EP_EQ( 0.2f, vec3_dot( v_p, Vec3( 1.f, 1.f, 1.f ) ) / ( l * l ) );

				SS();

				OUTPUT_SUBJECT( "약간의 연산을 더해 투영된 벡터를 구한다." );

				LF();

				DECLARATION_MAIN( const float d = vec3_dot( v_p, VEC3_Y ) );
				DECLARATION_MAIN( const float rate = d / ( l * l ) );
				DECLARATION_MAIN( const auto v_2 = v_p * rate );

				EXPECT_EP_EQ( d, vec3_dot( v_p, v_2 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Angle_Between_Two_Vectors::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Angle Between Two Vectors";
		};
	}
	r2tm::DoFunctionT Angle_Between_Two_Vectors::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			OUTPUT_SUBJECT( "두 벡터의 각은 내적을 이용해 구한다." );

			LS();

			{
				OUTPUT_SUBJECT( "내적의 기하학적 정리" );
				OUTPUT_COMMENT( "A dot B = ||A|| * ||B|| * cos(θ)" );
				OUTPUT_COMMENT( "\t" "||A|| = 벡터 A 의 크기" );
				OUTPUT_COMMENT( "\t" "벡터의 크기 = sqrt( x^2 + y^2 + z^2 )" );

				LF();

				OUTPUT_SUBJECT( "각을 구하기 위한 공식 변환" );
				OUTPUT_COMMENT( "cos(θ) = ( A dot B ) / ( ||A|| * ||B|| )" );
				OUTPUT_COMMENT( "θ = arccosine( ( A dot B ) / ( ||A|| * ||B|| ) )" );
				OUTPUT_COMMENT( "\t" "arccosine/acos = cos의 역함수" );
			}

			LS();

			OUTPUT_SOURCE_BEGIN;
			const auto A = []( const Vec3& v1, const Vec3& v2 )->float
			{
				return std::acos(
					  vec3_dot( v1, v2 )
					/ ( vec3_length( v1 ) * vec3_length( v2 ) )
				);
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				EXPECT_EP_EQ( 45, Rad2Deg( A( Vec3( 0, 1, 0 ), Vec3( 1, 1, 0 ) ) ) );

				LF();

				EXPECT_EP_EQ( 90, Rad2Deg( A( Vec3( 0, 1, 0 ), Vec3( 1, 0, 0 ) ) ) );

				LF();

				EXPECT_EP_EQ( 135, Rad2Deg( A( Vec3( 0, 1, 0 ), Vec3( 1, -1, 0 ) ) ) );

				LF();

				EXPECT_EP_EQ( 180, Rad2Deg( A( Vec3( 0, 10, 0 ), Vec3( 0, -10, 0 ) ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "0 ~ 180도 사이로 나온다." );

				LF();

				EXPECT_EP_NE( 270, Rad2Deg( A( Vec3( 0, 1, 0 ), Vec3( -1, 0, 0 ) ) ) );
				EXPECT_EP_EQ( 90, Rad2Deg( A( Vec3( 0, 1, 0 ), Vec3( -1, 0, 0 ) ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Angle_Between_Two_Unit_Vectors::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector : Angle Between Two Unit Vectors";
		};
	}
	r2tm::DoFunctionT Angle_Between_Two_Unit_Vectors::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			OUTPUT_SUBJECT( "두 단위 벡터의 각 계산은 단순해진다." );

			LS();

			{
				OUTPUT_SUBJECT( "내적의 기하학적 정리" );
				OUTPUT_COMMENT( "A dot B = ||A|| * ||B|| * cos(θ)" );

				LF();

				OUTPUT_SUBJECT( "각을 구하기 위한 공식 변환" );
				OUTPUT_COMMENT( "cos(θ) = ( A dot B ) / ( ||A|| * ||B|| )" );
				OUTPUT_COMMENT( "θ = arccosine( ( A dot B ) / ( ||A|| * ||B|| ) )" );
				OUTPUT_COMMENT( "θ = arccosine( ( A dot B ) / ( 1 * 1 ) )" );
				OUTPUT_COMMENT( "θ = arccosine( ( A dot B ) / 1 )" );
				OUTPUT_COMMENT( "θ = arccosine( ( A dot B ) )" );
			}

			LS();

			OUTPUT_SOURCE_BEGIN;
			const auto A = []( const Vec3& u_v1, const Vec3& u_v2 )->float
			{
				return std::acos( vec3_dot( u_v1, u_v2 ) );
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				EXPECT_EP_EQ( 45, Rad2Deg( A( vec3_normalize( 0, 3, 0 ), vec3_normalize( 3, 3, 0 ) ) ) );

				LF();

				EXPECT_EP_EQ( 90, Rad2Deg( A( vec3_normalize( 0, 3, 0 ), vec3_normalize( 3, 0, 0 ) ) ) );

				LF();

				EXPECT_EP_EQ( 135, Rad2Deg( A( vec3_normalize( 0, 3, 0 ), vec3_normalize( 3, -3, 0 ) ) ) );

				LF();

				EXPECT_EP_EQ( 180, Rad2Deg( A( vec3_normalize( 0, 30, 0 ), vec3_normalize( 0, -30, 0 ) ) ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "0 ~ 180도 사이로 나온다." );

				LF();

				EXPECT_EP_NE( 270, Rad2Deg( A( vec3_normalize( 0, 3, 0 ), vec3_normalize( -3, 0, 0 ) ) ) );
				EXPECT_EP_EQ( 90, Rad2Deg( A( vec3_normalize( 0, 3, 0 ), vec3_normalize( -3, 0, 0 ) ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}