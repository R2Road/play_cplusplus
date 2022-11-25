#include "c_union_test.h"
#include "c_union_test_helper_unnamedunion_with_struct.hpp"
#include "c_union_test_helper_unnamedunion_with_vector3.hpp"
#include "c_union_test_helper_unnamedunion_with_vector3_2.hpp"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_union_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( union { int32_t a; int64_t b; } u );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( &u.a );
				OUTPUT_VALUE( &u.b );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Unnamed_Union_With_Struct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Struct";
		};
	}
	r2cm::iItem::DoFunctionT Unnamed_Union_With_Struct::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "struct 안의 익명 공용체는 공용체 안에 선언된 멤버들을 struct 의 멤버처럼 접근하게 해준다." );

			std::cout << r2cm::split;

			SHOW_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_struct.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_struct::TestStruct s );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( &s.b );
				OUTPUT_VALUE( &s.i );
				OUTPUT_VALUE( &s.ll );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Unnamed_Union_With_Vector3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3";
		};
	}
	r2cm::iItem::DoFunctionT Unnamed_Union_With_Vector3::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "MS 확장(/Ze)에서 선언자가 없는 구조를 다른 구조체 또는 공용 구조체의 멤버로 지정할 수 있다." );
			OUTPUT_NOTE( "이러한 구조체는 ANSI 호환성(/Za)에서 오류를 생성한다." );
			OUTPUT_NOTE( "https://learn.microsoft.com/ko-kr/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4201?view=msvc-170" );

			std::cout << r2cm::split;

			SHOW_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_vector3.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_vector3::Vector3 v );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( sizeof( v ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( &v.r[0], &v.x );
				EXPECT_EQ( &v.r[1], &v.y );
				EXPECT_EQ( &v.r[2], &v.z );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Unnamed_Union_With_Vector3_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3 2";
		};
	}
	r2cm::iItem::DoFunctionT Unnamed_Union_With_Vector3_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "Warning 없이 MS 전용 기능을 흉내내보자." );

			std::cout << r2cm::split;

			SHOW_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_vector3_2.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_vector3_2::Vector3 v );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( sizeof( v ) );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( &v.r[0], &v.x );
				EXPECT_EQ( &v.r[1], &v.y );
				EXPECT_EQ( &v.r[2], &v.z );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( &v.r[0] );
				OUTPUT_VALUE( &v.r[1] );
				OUTPUT_VALUE( &v.r[2] );
				OUTPUT_VALUE( &v.x );
				OUTPUT_VALUE( &v.y );
				OUTPUT_VALUE( &v.z );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Unnamed_Union_With_Vector3_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Vector3 3";
		};
	}
	r2cm::iItem::DoFunctionT Unnamed_Union_With_Vector3_3::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "Warning 없이 MS 전용 기능을 흉내내보자." );

			std::cout << r2cm::split;

			DECLARATION_MAIN( struct { float x; float y; float z; } v );
			OUTPUT_VALUE( sizeof( v ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( float* f = (float*)&v );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( &f[0], &v.x );
				EXPECT_EQ( &f[1], &v.y );
				EXPECT_EQ( &f[2], &v.z );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( &f[0] );
				OUTPUT_VALUE( &f[1] );
				OUTPUT_VALUE( &f[2] );
				OUTPUT_VALUE( &v.x );
				OUTPUT_VALUE( &v.y );
				OUTPUT_VALUE( &v.z );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}