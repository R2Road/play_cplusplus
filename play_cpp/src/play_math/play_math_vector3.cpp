#include "play_math_vector3.h"
#include "play_math___helper_common.h"
#include "play_math___helper_vector3.h"
using namespace play_math;

#include "r2tm/r2tm_Inspector.h"

namespace play_math_vector3
{
	r2tm::TitleFunctionT Length::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Length";
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
			return "Vector3 : Normalize";
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
			return "Vector3 : Dot Product 1";
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
				OUTPUT_SUBJECT( "( Y x Y ), ( Y x -Y ) : 앞/뒤 방향 알 수 있다 : 수평에 1" );

				LF();

				EXPECT_EP_EQ( 1.f, DOT( VEC3_Y, VEC3_Y ) );
				EXPECT_EP_EQ( -1.f, DOT( VEC3_Y, -VEC3_Y ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "( Y x X ), ( Y x -X ) : 좌/우 방향 알 수 없다. : 수직에 0" );

				LF();

				EXPECT_EP_EQ( 0.f, DOT( VEC3_Y, VEC3_X ) );
				EXPECT_EP_EQ( 0.f, DOT( VEC3_Y, -VEC3_X ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "교환 법칙 성립" );

				LF();

				EXPECT_EP_EQ( -1.f, DOT( VEC3_Y, -VEC3_Y ) );
				EXPECT_EP_EQ( -1.f, DOT( -VEC3_Y, VEC3_Y ) );

				LF();

				EXPECT_EP_EQ( 0.f, DOT( VEC3_Y, VEC3_X ) );
				EXPECT_EP_EQ( 0.f, DOT( VEC3_X, VEC3_Y ) );

				LF();

				EXPECT_EP_EQ( 0.f, DOT( VEC3_Y, -VEC3_X ) );
				EXPECT_EP_EQ( 0.f, DOT( -VEC3_X, VEC3_Y ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Dot_Product_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Dot Product 2";
		};
	}
	r2tm::DoFunctionT Dot_Product_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "내적의 대수적 정의" );
				OUTPUT_COMMENT( "A dot B = AxBx + AyBy + AzBz + AwBw" );
			}

			LS();

			{
				OUTPUT_SUBJECT( "지향성 판단을 원한다면 단위 벡터를 사용해라." );

				SS();

				OUTPUT_COMMENT( "단위 벡터가 아닌 경우" );

				LF();

				EXPECT_EP_EQ( 100.f, vec3_dot( Vec3( 0.f, 10.f, 0.f ), Vec3( 10.f, 10.f, 0.f ) ) );
				EXPECT_EP_EQ( 300.f, vec3_dot( Vec3( 0.f, 10.f, 0.f ), Vec3( 30.f, 30.f, 0.f ) ) );

				SS();

				OUTPUT_COMMENT( "단위 벡터인 경우" );

				LF();

				EXPECT_EP_EQ( 0.7071f, vec3_normalize_dot(
					  Vec3( 0.f, 10.f, 0.f )
					, Vec3( 10.f, 10.f, 0.f )
				) );
				EXPECT_EP_EQ( 0.7071f, vec3_normalize_dot(
					  Vec3( 0.f, 10.f, 0.f )
					, Vec3( 30.f, 30.f, 0.f )
				) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "기준 벡터가 단위 벡터 라면 내적의 결과는 투영된 벡터의 길이" );

				LF();

				EXPECT_EP_EQ( 10.f, vec3_dot( VEC3_Y, Vec3( 10.f, 10.f, 0.f ) ) );
				EXPECT_EP_EQ( 30.f, vec3_dot( VEC3_Y, Vec3( 30.f, 30.f, 0.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Dot_Product__Scalar_Projection::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Dot Product : Scalar Projection";
		};
	}
	r2tm::DoFunctionT Dot_Product__Scalar_Projection::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "스칼라 투영" );
				OUTPUT_COMMENT( "벡터 B가 벡터 A 방향으로 가지는 길이를 나타내는 스칼라 값" );
				OUTPUT_COMMENT( "벡터 B의 끝점에서 벡터 A에 수선을 내렸을 때 A에 드리운 그림자의 길이" );
				OUTPUT_COMMENT( "compbA = ||B|| * cos(θ)" );
				OUTPUT_COMMENT( "\t" "θ = A 와 B의 각도" );

				LF();

				OUTPUT_SUBJECT( "내적의 기하학적 정리" );
				OUTPUT_COMMENT( "A dot B = ||A|| * ||B|| * cos(θ)" );

				LF();

				OUTPUT_SUBJECT( "cos(θ) 를 기준으로 공식 변환" );
				OUTPUT_COMMENT( "cos(θ) = ( A dot B ) / ( ||A|| * ||B|| )" );

				LF();

				OUTPUT_SUBJECT( "적용" );
				OUTPUT_COMMENT( "compbA = ||B|| * ( ( A dot B ) / ( ||A|| * ||B|| ) )" );
				OUTPUT_COMMENT( "compbA = ( A dot B ) / ||A||" );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto C = []( Vec3 v1, Vec3 v2 )->float
				{

					return ( vec3_dot( v1, v2 ) / vec3_length( v1 ) );
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EP_EQ( 1.f, C( Vec3( 0.f, 10.f, 0.f ), Vec3( 0.f, 1.f, 0.f ) ) );
				EXPECT_EP_EQ( 0.8f, C( Vec3( 0.f, 10.f, 0.f ), Vec3( 0.f, 0.8f, 0.f ) ) );
				EXPECT_EP_EQ( 0.4f, C( Vec3( 0.f, 10.f, 0.f ), Vec3( 0.f, 0.4f, 0.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Dot_Product__Vector_Projection::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Dot Product : Vector Projection";
		};
	}
	r2tm::DoFunctionT Dot_Product__Vector_Projection::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "벡터 투영" );
				OUTPUT_COMMENT( "스칼라 투영의 길이를 가지면서" );
				OUTPUT_COMMENT( "기준 벡터와 같은 방향을 향하는 벡터" );

				LF();

				OUTPUT_SUBJECT( "공식 유도" );
				OUTPUT_COMMENT( "1. 벡터의 길이" );
				OUTPUT_COMMENT( "\t" "스칼라 투영으로 얻을 수 있다." );
				OUTPUT_COMMENT( "\t" "compbA = ( A dot B ) / ||A||" );
				OUTPUT_COMMENT( "2. 벡터의 방향" );
				OUTPUT_COMMENT( "\t" "기준 벡터를 단위 벡터로 만들면 된다." );
				OUTPUT_COMMENT( "\t" "NA = A / ||A||" );
				OUTPUT_COMMENT( "3. NA * 길이" );
				OUTPUT_COMMENT( "\t" "projaB = ( ( A dot B ) / ||A|| ) * ( A / ||A|| )" );
				OUTPUT_COMMENT( "\t" "projaB = ( ( A dot B ) / ||A|| ) * ( 1 / ||A|| ) * A" );
				OUTPUT_COMMENT( "\t" "projaB = ( ( A dot B ) / ( ||A|| * ||A|| ) ) * A" );

				LF();

				OUTPUT_SUBJECT( "projaB = ( A dot B / ||A||^2 ) * A" );

			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const auto C = []( Vec3 v1, Vec3 v2 )->Vec3
				{
					const auto l = vec3_length( v1 );
					return v1 * ( vec3_dot( v1, v2 ) / ( l * l ) );
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( Vec3( 0.f, 1.f, 0.f ), C( Vec3( 0.f, 10.f, 0.f ), Vec3( 10.f, 1.f, 0.f ) ) );
				EXPECT_EQ( Vec3( 0.f, 2.f, 0.f ), C( Vec3( 0.f, 10.f, 0.f ), Vec3( 10.f, 2.f, 0.f ) ) );
				EXPECT_EQ( Vec3( 0.f, 4.f, 0.f ), C( Vec3( 0.f, 10.f, 0.f ), Vec3( 10.f, 4.f, 0.f ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Angle_Between_Two_Vectors::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Angle Between Two Vectors";
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
			return "Vector3 : Angle Between Two Unit Vectors";
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



	r2tm::TitleFunctionT Cross_Product::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Cross Product";
		};
	}
	r2tm::DoFunctionT Cross_Product::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "외적이란?" );
			OUTPUT_COMMENT( "두 벡터를 바탕으로 두 벡터 모두에 수직인 새로운 벡터를 생성." );

			LF();

			OUTPUT_SUBJECT( "외적의 오른손 법칙" );
			OUTPUT_COMMENT( "오른손의 엄지를 제외한 4 손가락으로 첫 벡터 방향을 가리킨다." );
			OUTPUT_COMMENT( "엄지는 수직으로" );
			OUTPUT_COMMENT( "4 손가락을 두번째 벡터 방향으로 구부린다.( 이 과정에서 축 회전이 필요 )" );
			OUTPUT_COMMENT( "엄지의 방향이 결과 벡터" );

			LF();

			OUTPUT_SUBJECT( "교환 법칙이 성립하지 않는다." );

			LF();

			OUTPUT_SUBJECT( "외적의 대수적 정의" );
			OUTPUT_COMMENT( "A x B = ( AyBz - AzBy, AzBx - AxBz, AxBy - AyBx )" );

			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			const auto CROSS = []( Vec3 v1, Vec3 v2 )->Vec3
			{
				return Vec3(
					  ( v1.y * v2.z ) - ( v1.z * v2.y )
					, ( v1.z * v2.x ) - ( v1.x * v2.z )
					, ( v1.x * v2.y ) - ( v1.y * v2.x )
				);
			};
			OUTPUT_SOURCE_END;

			LS();


			{
				OUTPUT_SUBJECT( "Y x Y" );

				LF();

				EXPECT_EQ( VEC3_0, CROSS( VEC3_Y, VEC3_Y ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "X x Y" );

				LF();

				EXPECT_EQ( VEC3_Z, CROSS( VEC3_X, VEC3_Y ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Y x X : 교환 법칙 확인" );

				LF();

				EXPECT_EQ( -VEC3_Z, CROSS( VEC3_Y, VEC3_X ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}