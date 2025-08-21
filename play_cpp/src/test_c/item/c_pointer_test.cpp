#include "c_pointer_test.h"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace c_pointer_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( const int i = 123 );
				DECL_MAIN( const int* ip = &i );

				LF();

				EXPECT_EQ( &i, ip );

				LF();

				std::cout << r2tm::tab << "+ adress" << r2tm::linefeed;
				OUTPUT_VALUE( &i );
				OUTPUT_VALUE( ip );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Offset::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Offset";
		};
	}
	r2tm::DoFunctionT Offset::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( int ip[3] );

			LS();

			{
				OUTPUT_NOTE( "adress of ip" );
				OUTPUT_VALUE( ip );

				LF();

				OUTPUT_NOTE( "adress of ip + 1" );
				OUTPUT_VALUE( ip + 1 );

				LF();

				OUTPUT_NOTE( "offset : ( ip + 1 ) ~ ip" );
				OUTPUT_VALUE( ip + 1 );
				OUTPUT_VALUE( ( ( ip + 1 ) - ip ) );

				LF();

				OUTPUT_NOTE( "offset : ( ip + 2 ) ~ ip" );
				OUTPUT_VALUE( ip + 2 );
				OUTPUT_VALUE( ( ( ip + 2 ) - ip ) );
			}

			LS();

			{
				OUTPUT_NOTE( "offset : ( char* )( ip + 2 ) ~ ( char* )ip" );
				OUTPUT_VALUE( ( (char*)( ip + 2 ) ) - ( (char*)ip ) );

				LF();

				OUTPUT_NOTE( "포인터간 연산은 Type의 영향을 받는다." );
			}

			LS();
			
			{
				DECL_MAIN( const auto t1 = reinterpret_cast<std::size_t>( ip ) );
				DECL_MAIN( const auto t2 = reinterpret_cast<std::size_t>( ip + 1 ) );
				OUTPUT_VALUE( t1 );
				OUTPUT_VALUE( t2 );

				std::cout << r2tm::linefeed2;

				OUTPUT_NOTE( "offset : t2 ~ t1" );
				OUTPUT_VALUE( t2 - t1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#pragma warning( disable : 4311 )
#pragma warning( disable : 4302 )

	r2tm::TitleFunctionT Pointer2Index::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Pointer 2 Index";
		};
	}
	r2tm::DoFunctionT Pointer2Index::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( int i = 0 );
				DECL_MAIN( int* pi = &i );
				DECL_MAIN( int32_t i32 = (int32_t)( &i ) );
				DECL_MAIN( int64_t i64_1 = (int64_t)( &i ) );
				DECL_MAIN( int64_t i64_2 = reinterpret_cast<int64_t>( &i ) );

				std::cout << r2tm::linefeed2;

				std::cout << r2tm::tab << "pi : " << pi << r2tm::linefeed;
				std::cout << r2tm::tab << "i32 : " << i32 << r2tm::tab4 << "<< 64bit 에서 잘림 Platform 신경써." << r2tm::linefeed;
				std::cout << r2tm::tab << "i64_1 dec : " << std::dec << i64_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "i64_1 hex : " << std::hex << i64_1 << r2tm::linefeed;
				std::cout << r2tm::tab << "i64_2 hex : " << i64_2 << r2tm::linefeed;

				// rollback
				std::cout << std::dec;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT ConstPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Const Pointer";
		};
	}
	r2tm::DoFunctionT ConstPointer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "int temp_int_1 = 0;" << r2tm::linefeed;
				std::cout << r2tm::tab << "int temp_int_2 = 0;" << r2tm::linefeed;
				int temp_int_1 = 0;
				int temp_int_2 = 0;

				LF();

				std::cout << r2tm::tab << "+ const int* temp_const_pointer = &temp_int_1;" << r2tm::linefeed << r2tm::linefeed;
				const int* temp_const_pointer = &temp_int_1;

				std::cout << r2tm::tab2 << "OK : temp_const_pointer = &temp_int_2;" << r2tm::linefeed;
				temp_const_pointer = &temp_int_2;

				std::cout << r2tm::tab2 << "Error : *temp_const_pointer = temp_int_2; " << r2tm::linefeed;
				//*temp_const_pointer = temp_int_2;


				std::cout << r2tm::linefeed << r2tm::linefeed;


				std::cout << r2tm::tab << "+ int* const temp_pointer_const = &temp_int_1;" << r2tm::linefeed << r2tm::linefeed;
				int* const temp_pointer_const = &temp_int_1;

				std::cout << r2tm::tab2 << "Error : temp_pointer_const = &temp_int_2;" << r2tm::linefeed;
				//temp_pointer_const = &temp_int_2;

				std::cout << r2tm::tab2 << "OK : *temp_pointer_const = temp_int_2;" << r2tm::linefeed;
				*temp_pointer_const = temp_int_2;
			}

			LS();

			{
				std::cout << r2tm::tab << "const int temp_const_int_1 = 0;" << r2tm::linefeed;
				//const int temp_const_int_1 = 0;

				LF();

				std::cout << r2tm::tab << "OK : const int* temp_pointer_const = &temp_const_int_1;" << r2tm::linefeed;
				//const int* temp_pointer_const = &temp_const_int_1;

				LF();

				std::cout << r2tm::tab << "Error : int* const temp_pointer_const = &temp_const_int_1;" << r2tm::linefeed;
				//int* const temp_pointer_const = &temp_const_int_1;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CharacterPointer_Length_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "char* : Length 0";
		};
	}
	r2tm::DoFunctionT CharacterPointer_Length_0::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( const char* empty_string = "" );

			LS();

			{
				EXPECT_EQ( 0, strlen( empty_string ) );
				EXPECT_NE( nullptr, empty_string );
			}

			LS();

			{
				DECL_MAIN( const char* other_empty_string = "" );

				LF();

				EXPECT_EQ( empty_string, other_empty_string );
				OUTPUT_VALUE( (void*)empty_string );
				OUTPUT_VALUE( (void*)other_empty_string );
			}

			LS();

			{
				OUTPUT_NOTE( "같은 내용의 정적 문자열들은 주소가 같다." );

				LF();

				DECL_MAIN( const char* space_x1_string_1 = " " );
				DECL_MAIN( const char* space_x1_string_2 = " " );
				DECL_MAIN( const char* space_x2_string_1 = "  " );
				DECL_MAIN( const char* space_x2_string_2 = "  " );

				LF();

				OUTPUT_VALUE( (void*)space_x1_string_1 );
				OUTPUT_VALUE( (void*)space_x1_string_2 );
				OUTPUT_VALUE( (void*)space_x2_string_1 );
				OUTPUT_VALUE( (void*)space_x2_string_2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MemberAddress::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Member Address";
		};
	}
	r2tm::DoFunctionT MemberAddress::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN(
				struct S
				{
					int i = 0;
					int j = 0;
				}
			);

			LF();

			DECL_MAIN( S* s = new S );

			LS();

			{
				OUTPUT_SUBJECT( "본체 주소" );

				LF();

				OUTPUT_VALUE( s );
				OUTPUT_VALUE( ( int64_t )s);
			}

			LS();

			{
				OUTPUT_SUBJECT( "첫 멤버의 주소는 본체의 주소와 같다." );

				LF();

				OUTPUT_VALUE( &s->i );
				OUTPUT_VALUE( ( int64_t )( &s->i ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "첫 멤버 주소 + 첫 멤버 크기" );

				LF();

				OUTPUT_VALUE( &s->j );
				OUTPUT_VALUE( ( int64_t )( &s->j ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "멤버의 거리" );

				LF();

				OUTPUT_VALUE( ( int64_t )( &s->j ) - ( int64_t )( &s->i ) );
			}

			LS();

			PROC_MAIN( delete s );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT StackAddress::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stack Address";
		};
	}
	r2tm::DoFunctionT StackAddress::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN(
				struct S
				{
					int i = 0;
					int j = 0;
				}
			);

			LF();

			DECL_MAIN( S stack_s );
			DECL_MAIN( S* heap_s = new S );

			LS();

			{
				OUTPUT_SUBJECT( "Stack S" );

				LF();

				OUTPUT_VALUE( &stack_s );
				OUTPUT_VALUE( ( int64_t )( &stack_s ) );

				LF();

				OUTPUT_VALUE( &stack_s.i );
				OUTPUT_VALUE( ( int64_t )( &stack_s.i ) );

				LF();

				OUTPUT_VALUE( &stack_s.j );
				OUTPUT_VALUE( ( int64_t )( &stack_s.j ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Heap S" );

				LF();

				OUTPUT_VALUE( heap_s );
				OUTPUT_VALUE( ( int64_t )heap_s );

				LF();

				OUTPUT_VALUE( &heap_s->i );
				OUTPUT_VALUE( ( int64_t )( &heap_s->i ) );

				LF();

				OUTPUT_VALUE( &heap_s->j );
				OUTPUT_VALUE( ( int64_t )( &heap_s->j ) );
			}

			LS();

			PROC_MAIN( delete heap_s );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}