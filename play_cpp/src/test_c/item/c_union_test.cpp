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
			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( union { int32_t a; int64_t b; } u );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( &u.a );
				OUTPUT_VALUE( &u.b );
			}

			std::cout << r2tm::split;

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
			std::cout << r2tm::split;

			OUTPUT_NOTE( "�ٷ����� type �� ũ�� ��ŭ�� �޸𸮿� �����Ѵ�." );
			OUTPUT_NOTE( "char type�� 0 �� �����ϸ� 8bit�� 0 �� �Ҵ�ȴ�." );

			std::cout << r2tm::split;

			DECLARATION_MAIN( union U { char c; int64_t i64; } );
			DECLARATION_MAIN( U u );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( u.c = 0 );
				PROCESS_MAIN( u.i64 = 0ll );
				OUTPUT_BINARY( u );
			}

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( u.i64 = -1ll );
				OUTPUT_BINARY( u );
			}

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( u.c = 0 );
				OUTPUT_BINARY( u );
			}

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( u.i64 = 255 );
				OUTPUT_BINARY( u );
			}

			std::cout << r2tm::split;

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
			std::cout << r2tm::split;

			DECLARATION_MAIN( union U { char c; int64_t i64; } );
			DECLARATION_MAIN( U u_1 );
			DECLARATION_MAIN( U u_2 );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( u_1.i64 = -1ll );
				PROCESS_MAIN( u_1.c = 0 );
				OUTPUT_BINARY( u_1 );
			}

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( u_2.i64 = 0 );
				PROCESS_MAIN( u_2.c = -1 );
				OUTPUT_BINARY( u_2 );
			}

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( u_1 = u_2 );
				OUTPUT_BINARY( u_1 );
			}

			std::cout << r2tm::split;

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
			std::cout << r2tm::split;

			OUTPUT_NOTE( "Not Working" );

			std::cout << r2tm::split;

			{
				OUTPUT_CODE( union U { char c; std::string s = ""; } );
				OUTPUT_CODE( U u_1 );
			}

			std::cout << r2tm::split;

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
			std::cout << r2tm::split;

			OUTPUT_NOTE( "struct ���� �͸� ����ü�� ����ü �ȿ� ����� ������� struct �� ���ó�� �����ϰ� ���ش�." );

			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_struct.hpp" );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_struct::TestStruct s );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( &s.b );
				OUTPUT_VALUE( &s.i );
				OUTPUT_VALUE( &s.ll );
			}

			std::cout << r2tm::split;

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
			std::cout << r2tm::split;

			OUTPUT_NOTE( "MS Ȯ��(/Ze)���� �����ڰ� ���� ������ �ٸ� ����ü �Ǵ� ���� ����ü�� ����� ������ �� �ִ�." );
			OUTPUT_NOTE( "�̷��� ����ü�� ANSI ȣȯ��(/Za)���� ������ �����Ѵ�." );
			OUTPUT_NOTE( "https://learn.microsoft.com/ko-kr/cpp/error-messages/compiler-warnings/compiler-warning-level-4-c4201?view=msvc-170" );

			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_vector3.hpp" );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_vector3::Vector3 v );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( sizeof( v ) );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( &v.r[0], &v.x );
				EXPECT_EQ( &v.r[1], &v.y );
				EXPECT_EQ( &v.r[2], &v.z );
			}

			std::cout << r2tm::split;

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
			std::cout << r2tm::split;

			OUTPUT_NOTE( "Warning ���� MS ���� ����� �䳻������." );

			std::cout << r2tm::split;

			OUTPUT_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_vector3_2.hpp" );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_vector3_2::Vector3 v );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( sizeof( v ) );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( &v.r[0], &v.x );
				EXPECT_EQ( &v.r[1], &v.y );
				EXPECT_EQ( &v.r[2], &v.z );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( &v.r[0] );
				OUTPUT_VALUE( &v.r[1] );
				OUTPUT_VALUE( &v.r[2] );
				OUTPUT_VALUE( &v.x );
				OUTPUT_VALUE( &v.y );
				OUTPUT_VALUE( &v.z );
			}

			std::cout << r2tm::split;

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
			std::cout << r2tm::split;

			OUTPUT_NOTE( "Warning ���� MS ���� ����� �䳻������." );

			std::cout << r2tm::split;

			DECLARATION_MAIN( struct { float x; float y; float z; } v );
			OUTPUT_VALUE( sizeof( v ) );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( float* f = (float*)&v );

				std::cout << r2tm::linefeed;

				EXPECT_EQ( &f[0], &v.x );
				EXPECT_EQ( &f[1], &v.y );
				EXPECT_EQ( &f[2], &v.z );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( &f[0] );
				OUTPUT_VALUE( &f[1] );
				OUTPUT_VALUE( &f[2] );
				OUTPUT_VALUE( &v.x );
				OUTPUT_VALUE( &v.y );
				OUTPUT_VALUE( &v.z );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}