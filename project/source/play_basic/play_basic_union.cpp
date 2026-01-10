#include "play_basic_union.hpp"

#include <string>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_basic_union
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SOURCE_READY_N_BEGIN;
			union U {
				int32_t a;
				int64_t b;
			};
			OUT_SOURCE_END;

			LS();

			{
				OUT_SUBJECT( "공용체 구성요소는 메모리 주소가 같다." );

				LF();

				DECL_MAIN( U u );

				LF();

				OUT_VALUE( &u.a );
				OUT_VALUE( &u.b );
			}

			LS();

			{
				DECL_MAIN( U u );

				LF();

				OUT_NOTE( "아래의 초기화 코드가 없으면..." );
				OUT_NOTE( "[error C4700: 초기화되지 않은 'u' 지역 변수를 사용했습니다.]" );
				OUT_NOTE( "...가 발생한다." );

				LF();

				PROC_MAIN( u.a = 0 );
				OUT_VALUE( u.a );
			}

			LS();

			{
				OUT_SOURCE_BEGIN;
				union {
					int32_t a = 0;
					int64_t b;
				} u;
				OUT_SOURCE_END;

				LF();

				OUT_NOTE( "공용체 내부에서 직접 초기화 해도 된다." );

				LF();

				OUT_VALUE( u.a );
			}

			LS();

			{
				OUT_CODE( union { int32_t a = 0; int64_t b = 0; } u );

				LF();

				OUT_NOTE( "공영체 내에서 초기화를 진행 할 때는 1개의 멤버만 초기화 해야 한다." );
				OUT_NOTE( "그렇지 않으면..." );
				OUT_NOTE( "error C2836 : 공용 구조체에서 한 개의 비정적 데이터 멤버만 기본 멤버 이니셜라이저를 가질 수 있습니다." );
				OUT_NOTE( "...가 발생한다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Memory::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Memory";
		};
	}
	r2tm::DoFunctionT Memory::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "다뤄지는 type 의 크기 만큼만 메모리에 접근한다." );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			union {
				char c;
				int64_t i64 = -1ll;
			} u;
			OUT_SOURCE_END;

			LS();

			{
				{
					OUT_BINARY( u );
				}

				SS();

				{
					OUT_COMMENT( "char type에 0 을 대입하면 8bit만 0 이 할당된다." );

					LF();

					PROC_MAIN( u.c = 0 );
					OUT_BINARY( u );
				}

				SS();

				{
					PROC_MAIN( u.i64 = 255 );
					OUT_BINARY( u );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Assign::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Assign";
		};
	}
	r2tm::DoFunctionT Assign::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "공용체의 대입은 전체 메모리 복사이다." );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			union U {
				char c;
				int64_t i64;
			};
			OUT_SOURCE_END;

			LS();

			DECL_MAIN( U u_1 );
			DECL_MAIN( U u_2 );

			LS();

			{
				PROC_MAIN( u_1.i64 = -1ll );
				PROC_MAIN( u_1.c = 0 );
				OUT_BINARY( u_1 );
			}

			LS();

			{
				PROC_MAIN( u_2.i64 = 0 );
				PROC_MAIN( u_2.c = -1 );
				OUT_BINARY( u_2 );
			}

			LS();

			{
				PROC_MAIN( u_1 = u_2 );
				OUT_BINARY( u_1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Complex::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Complex";
		};
	}
	r2tm::DoFunctionT Complex::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "Not Working" );

				LF();

				OUT_CODE( union U { char c; std::string s = ""; } );
				OUT_CODE( U u_1 );
			}

			LS();

			{
				OUT_SUBJECT( "Working" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				class A
				{
					int i = 0;
				};

				union U {
					char c;
					A a;
				};
				OUT_SOURCE_END;

				LF();

				OUT_SUBJECT( "공용체 안에 기본 제공 타입 이외의 것이 들어가려면..." );
				OUT_COMMENT( "금지 : 사용자 정의 생성자/소멸자" );
				OUT_COMMENT( "금지 : 사용자 정의 복사 생성자/이동 생성자/대입 연산자" );
				OUT_COMMENT( "금지 : 가상 함수/가상 기본 클래스" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Unnamed_Union_With_Struct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Struct";
		};
	}
	r2tm::DoFunctionT Unnamed_Union_With_Struct::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_NOTE( "struct 안의 익명 공용체는 공용체 안에 선언된 멤버들을 struct 의 멤버처럼 접근하게 해준다." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct
				{
					bool b;

					union
					{
						int i;
						long long ll;
					};
				} s;
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( &s.b );
				OUT_VALUE( &s.i );
				OUT_VALUE( &s.ll );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Unnamed_Union_With_Vector3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3";
		};
	}
	r2tm::DoFunctionT Unnamed_Union_With_Vector3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_NOTE( "MS 확장(/Ze)에서 선언자가 없는 구조를 다른 구조체 또는 공용 구조체의 멤버로 지정할 수 있다." );
			OUT_NOTE( "이러한 구조체는 ANSI 호환성(/Za)에서 오류를 생성한다." );
			OUT_NOTE( "https://learn.microsoft.com/ko-kr/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4201?view=msvc-170" );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
#pragma warning( push )
#pragma warning( disable : 4201 )

				struct
				{
					union
					{
						float r[3];

						struct
						{
							float x;
							float y;
							float z;
						};
					};
				} v;

#pragma warning( pop )
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( v ) );

				LF();

				EXPECT_EQ( &v.r[0], &v.x );
				EXPECT_EQ( &v.r[1], &v.y );
				EXPECT_EQ( &v.r[2], &v.z );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Unnamed_Union_With_Vector3_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3 2";
		};
	}
	r2tm::DoFunctionT Unnamed_Union_With_Vector3_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "Warning 없이 MS 전용 기능을 흉내내보자." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct Vector3
				{
					Vector3() :
						r()
						, x( r[0] )
						, y( r[1] )
						, z( r[2] )
					{}

					float r[3];
					float& x;
					float& y;
					float& z;
				} v;
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( v ) );

				LF();

				EXPECT_EQ( &v.r[0], &v.x );
				EXPECT_EQ( &v.r[1], &v.y );
				EXPECT_EQ( &v.r[2], &v.z );

				LF();

				OUT_VALUE( &v.r[0] );
				OUT_VALUE( &v.r[1] );
				OUT_VALUE( &v.r[2] );
				OUT_VALUE( &v.x );
				OUT_VALUE( &v.y );
				OUT_VALUE( &v.z );
			}

			LS();

			OUT_NOTE( "이건 아닌 것 같다. 크기가 증가하는 것은 용납할 수 없다." );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Unnamed_Union_With_Vector3_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3 3";
		};
	}
	r2tm::DoFunctionT Unnamed_Union_With_Vector3_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "Warning 없이 MS 전용 기능을 흉내내보자." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct
				{
					float x;
					float y;
					float z;

					const float& operator[]( int i ) const
					{
						if( 3 <= i )
						{
							static float dummy = 0.f;
							return dummy;
						}

						return reinterpret_cast<const float*>( this )[i];
					}
				} v;
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( v ) );

				LF();

				EXPECT_EQ( &v[0], &v.x );
				EXPECT_EQ( &v[1], &v.y );
				EXPECT_EQ( &v[2], &v.z );

				LF();

				OUT_VALUE( &v[0] );
				OUT_VALUE( &v[1] );
				OUT_VALUE( &v[2] );
			}

			LS();

			OUT_NOTE( "operator[] 를 재정의 하는 것이 적절한 선택 같다." );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Unnamed_Union_With_Vector3_4::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3 4";
		};
	}
	r2tm::DoFunctionT Unnamed_Union_With_Vector3_4::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "Warning 없이 MS 전용 기능을 흉내내보자." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct
				{
					float x;
					float y;
					float z;

					const float& operator[]( int i ) const
					{
						switch( i )
						{
						case 0:
							return x;
						case 1:
							return y;
						case 2:
							return z;
						default:
							static float dummy = 0.f;
							return dummy;
						}
					}
				} v;
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( v ) );

				LF();

				EXPECT_EQ( &v[0], &v.x );
				EXPECT_EQ( &v[1], &v.y );
				EXPECT_EQ( &v[2], &v.z );

				LF();

				OUT_VALUE( &v[0] );
				OUT_VALUE( &v[1] );
				OUT_VALUE( &v[2] );
			}

			LS();

			OUT_NOTE( "operator[] 안에서 reinterpret_cast 를 쓰는 것 보다는 switch를 쓰는 것이 괜찮아 보인다." );
			OUT_NOTE( "REF : https://github.com/g-truc/glm/blob/master/glm/detail/type_vec4.inl" );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Unnamed_Union_With_Vector3_5::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3 5";
		};
	}
	r2tm::DoFunctionT Unnamed_Union_With_Vector3_5::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "다소의 난잡함을 감수하면 적절한 편의성에 도달 할 수 있다." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct
				{
					union{
						float x;
						float r;
					};
					union{
						float y;
						float g;
					};
					union{
						float z;
						float b;
					};
				} v;
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( sizeof( v ) );

				LF();

				EXPECT_EQ( &v.r, &v.x );
				EXPECT_EQ( &v.g, &v.y );
				EXPECT_EQ( &v.b, &v.z );

				LF();

				OUT_VALUE( &v.r );
				OUT_VALUE( &v.g );
				OUT_VALUE( &v.b );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}