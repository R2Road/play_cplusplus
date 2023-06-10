#include "c_union_test.h"
#include "c_union_test_helper_unnamedunion_with_struct.hpp"
#include "c_union_test_helper_unnamedunion_with_vector3.hpp"
#include "c_union_test_helper_unnamedunion_with_vector3_2.hpp"

#include <string>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_union_test
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

			{
				DECLARATION_MAIN( union { int32_t a; int64_t b; } u );

				LF();

				OUTPUT_VALUE( &u.a );
				OUTPUT_VALUE( &u.b );
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

			OUTPUT_NOTE( "다뤄지는 type 의 크기 만큼만 메모리에 접근한다." );
			OUTPUT_NOTE( "char type에 0 을 대입하면 8bit만 0 이 할당된다." );

			LS();

			DECLARATION_MAIN( union U { char c; int64_t i64; } );
			DECLARATION_MAIN( U u );

			LS();

			{
				PROCESS_MAIN( u.c = 0 );
				PROCESS_MAIN( u.i64 = 0ll );
				OUTPUT_BINARY( u );
			}

			LS();

			{
				PROCESS_MAIN( u.i64 = -1ll );
				OUTPUT_BINARY( u );
			}

			LS();

			{
				PROCESS_MAIN( u.c = 0 );
				OUTPUT_BINARY( u );
			}

			LS();

			{
				PROCESS_MAIN( u.i64 = 255 );
				OUTPUT_BINARY( u );
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

			DECLARATION_MAIN( union U { char c; int64_t i64; } );
			DECLARATION_MAIN( U u_1 );
			DECLARATION_MAIN( U u_2 );

			LS();

			{
				PROCESS_MAIN( u_1.i64 = -1ll );
				PROCESS_MAIN( u_1.c = 0 );
				OUTPUT_BINARY( u_1 );
			}

			LS();

			{
				PROCESS_MAIN( u_2.i64 = 0 );
				PROCESS_MAIN( u_2.c = -1 );
				OUTPUT_BINARY( u_2 );
			}

			LS();

			{
				PROCESS_MAIN( u_1 = u_2 );
				OUTPUT_BINARY( u_1 );
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

			OUTPUT_NOTE( "Not Working" );

			LS();

			{
				OUTPUT_CODE( union U { char c; std::string s = ""; } );
				OUTPUT_CODE( U u_1 );
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

			OUTPUT_NOTE( "struct 안의 익명 공용체는 공용체 안에 선언된 멤버들을 struct 의 멤버처럼 접근하게 해준다." );

			LS();

			OUTPUT_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_struct.hpp" );

			LS();

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_struct::TestStruct s );

				LF();

				OUTPUT_VALUE( &s.b );
				OUTPUT_VALUE( &s.i );
				OUTPUT_VALUE( &s.ll );
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

			OUTPUT_NOTE( "MS 확장(/Ze)에서 선언자가 없는 구조를 다른 구조체 또는 공용 구조체의 멤버로 지정할 수 있다." );
			OUTPUT_NOTE( "이러한 구조체는 ANSI 호환성(/Za)에서 오류를 생성한다." );
			OUTPUT_NOTE( "https://learn.microsoft.com/ko-kr/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4201?view=msvc-170" );

			LS();

			OUTPUT_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_vector3.hpp" );

			LS();

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_vector3::Vector3 v );

				LF();

				OUTPUT_VALUE( sizeof( v ) );

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

			OUTPUT_NOTE( "Warning 없이 MS 전용 기능을 흉내내보자." );

			LS();

			OUTPUT_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_vector3_2.hpp" );

			LS();

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_vector3_2::Vector3 v );

				LF();

				OUTPUT_VALUE( sizeof( v ) );

				LF();

				EXPECT_EQ( &v.r[0], &v.x );
				EXPECT_EQ( &v.r[1], &v.y );
				EXPECT_EQ( &v.r[2], &v.z );

				LF();

				OUTPUT_VALUE( &v.r[0] );
				OUTPUT_VALUE( &v.r[1] );
				OUTPUT_VALUE( &v.r[2] );
				OUTPUT_VALUE( &v.x );
				OUTPUT_VALUE( &v.y );
				OUTPUT_VALUE( &v.z );
			}

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

			OUTPUT_NOTE( "Warning 없이 MS 전용 기능을 흉내내보자." );

			LS();

			DECLARATION_MAIN( struct { float x; float y; float z; } v );
			OUTPUT_VALUE( sizeof( v ) );

			LS();

			{
				DECLARATION_MAIN( float* f = (float*)&v );

				LF();

				EXPECT_EQ( &f[0], &v.x );
				EXPECT_EQ( &f[1], &v.y );
				EXPECT_EQ( &f[2], &v.z );

				LF();

				OUTPUT_VALUE( &f[0] );
				OUTPUT_VALUE( &f[1] );
				OUTPUT_VALUE( &f[2] );
				OUTPUT_VALUE( &v.x );
				OUTPUT_VALUE( &v.y );
				OUTPUT_VALUE( &v.z );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}