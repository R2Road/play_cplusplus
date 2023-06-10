#include "c_pointer_test.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

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
				DECLARATION_MAIN( const int i = 123 );
				DECLARATION_MAIN( const int* ip = &i );

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

			DECLARATION_MAIN( int ip[3] );

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
				DECLARATION_MAIN( const auto t1 = reinterpret_cast<std::size_t>( ip ) );
				DECLARATION_MAIN( const auto t2 = reinterpret_cast<std::size_t>( ip + 1 ) );
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
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int* pi = &i );
				DECLARATION_MAIN( int32_t i32 = (int32_t)( &i ) );
				DECLARATION_MAIN( int64_t i64_1 = (int64_t)( &i ) );
				DECLARATION_MAIN( int64_t i64_2 = reinterpret_cast<int64_t>( &i ) );

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

			DECLARATION_MAIN( const char* empty_string = "" );

			LS();

			{
				EXPECT_EQ( 0, strlen( empty_string ) );
				EXPECT_NE( nullptr, empty_string );
			}

			LS();

			{
				DECLARATION_MAIN( const char* other_empty_string = "" );

				LF();

				EXPECT_EQ( empty_string, other_empty_string );
				OUTPUT_VALUE( (void*)empty_string );
				OUTPUT_VALUE( (void*)other_empty_string );
			}

			LS();

			{
				OUTPUT_NOTE( "같은 내용의 정적 문자열들은 주소가 같다." );

				LF();

				DECLARATION_MAIN( const char* space_x1_string_1 = " " );
				DECLARATION_MAIN( const char* space_x1_string_2 = " " );
				DECLARATION_MAIN( const char* space_x2_string_1 = "  " );
				DECLARATION_MAIN( const char* space_x2_string_2 = "  " );

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
}