#include "std_string_test.h"

#include <string>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace std_string_test
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
				DECLARATION_MAIN( const std::string s );
				OUTPUT_VALUE( sizeof( s ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "빈 std::string 은 같은 것으로 간주된다." );

				LF();

				DECLARATION_MAIN( const std::string empty_string_1 );
				DECLARATION_MAIN( const std::string empty_string_2 );
				EXPECT_EQ( empty_string_1, empty_string_2 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "같은 문자열이니까 같다." );

				LF();

				DECLARATION_MAIN( const std::string string_1( " " ) );
				DECLARATION_MAIN( const std::string string_2( " " ) );
				EXPECT_EQ( string_1, string_2 );

				LF();

				OUTPUT_VALUE( (void*)string_1.c_str() );
				OUTPUT_VALUE( (void*)string_2.c_str() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "다른 문자열을 저장했더라도 clear() 를 호출하면 같은 것으로 판단된다." );

				LF();

				DECLARATION_MAIN( std::string string_1( "              " ) );
				DECLARATION_MAIN( std::string string_2( "                         " ) );
				EXPECT_NE( string_1, string_2 );

				LF();

				PROCESS_MAIN( string_1.clear() );
				PROCESS_MAIN( string_2.clear() );

				LF();

				EXPECT_EQ( string_1, string_2 );

				LF();

				OUTPUT_VALUE( (void*)string_1.c_str() );
				OUTPUT_VALUE( (void*)string_2.c_str() );
			}

			LS();

			OUTPUT_NOTE( "할당된 메모리의 주소, capacity 등이 operator== 의 결과에 영향을 주지 않는다." );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Memory_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory 1";
		};
	}
	r2tm::DoFunctionT Memory_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "최초 생성시 heap에서 메모리를 할당 받지 않는다." );
			OUTPUT_NOTE( "member buffer 를 사용한다." );

			LS();

			DECLARATION_MAIN( std::string s );

			LS();

			{
				OUTPUT_SUBJECT( "Heap 에서 메모리를 할당 받기 전 버퍼의 크기" );

				LF();

				OUTPUT_VALUE( s.capacity() );

				LF();

				OUTPUT_VALUE( (void*)s.c_str() );
				OUTPUT_BINARY( s );
			}

			LS();

			{
				OUTPUT_SUBJECT( "단일 값으로 채워넣어 기본 버퍼로 사용되는 Local Variable의 변화를 확인해보자." );

				LF();

				PROCESS_MAIN( s.resize( 15, 0b01111111 ) );

				LF();

				OUTPUT_VALUE( (void*)s.c_str() );
				OUTPUT_BINARY( s );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Memory_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory 2";
		};
	}
	r2tm::DoFunctionT Memory_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::string s );

			LF();

			OUTPUT_VALUE( s.capacity() );

			LF();

			OUTPUT_VALUE( (void*)s.c_str() );
			OUTPUT_BINARY( s );

			LS();

			{
				OUTPUT_SUBJECT( "member buffer의 크기를 넘는 문자열을 할당하면 heap 에서 메모리를 할당 받는다." );

				LF();

				PROCESS_MAIN( s = "1234567890123456" );

				LF();

				OUTPUT_VALUE( (void*)s.c_str() );
				OUTPUT_BINARY( s );
			}

			LS();

			{
				OUTPUT_SUBJECT( "clear() 를 호출해도 member buffer를 사용하게 되지는 않는다." );
				OUTPUT_SUBJECT( "되돌리는 방법이 없을까?" );

				LF();

				PROCESS_MAIN( s.clear() );

				LF();

				OUTPUT_VALUE( (void*)s.c_str() );
				OUTPUT_BINARY( s );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Move::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Move";
		};
	}
	r2tm::DoFunctionT Move::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "짧은 문자열의 경우 move가 작동하지 않는다." );
			OUTPUT_NOTE( "xstring 의 ""_Assign_rv_contents_with_alloc_always_equal"" 함수 참조" );

			LS();

			{
				OUTPUT_NOTE( "move : X" );

				LF();

				DECLARATION_MAIN( std::string s_1( "123456789012345" ) );
				DECLARATION_MAIN( std::string s_2( "234567890123456" ) );

				LF();

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );

				LF();

				PROCESS_MAIN( s_1 = std::move( s_2 ) );
				OUTPUT_VALUE( s_1 );
				OUTPUT_VALUE( s_2 );

				LF();

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );
			}

			LS();

			{
				OUTPUT_NOTE( "move : O" );

				LF();

				DECLARATION_MAIN( std::string s_1( "1234567890123456" ) );
				DECLARATION_MAIN( std::string s_2( "2345678901234567" ) );

				LF();

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );

				LF();

				PROCESS_MAIN( s_1 = std::move( s_2 ) );
				OUTPUT_VALUE( s_1 );
				OUTPUT_VALUE( s_2 );

				LF();

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Find::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Find";
		};
	}
	r2tm::DoFunctionT Find::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const std::string key_string = "\n" );
			OUTPUT_VALUE( key_string.size() );

			LS();

			{
				OUTPUT_SUBJECT( "실패 결과 확인" );

				LF();

				OUTPUT_VALUE( std::string().find( key_string, 0 ) );
				OUTPUT_VALUE( std::string::npos );
			}

			LS();

			DECLARATION_MAIN( const std::string orig_string = "\n\n012345\n6789abcd\n\nefghij\nklmnopqrstu\n\n\nvwxyz\n" );
			OUTPUT_VALUE( orig_string.size() );

			LS();

			{
				DECLARATION_MAIN( std::size_t pivot_pos = 0u );
				DECLARATION_MAIN( std::size_t find_pos = 0u );

				PROCESS_MAIN( find_pos = orig_string.find( key_string, pivot_pos ) );
				OUTPUT_VALUE( find_pos );
				PROCESS_MAIN( pivot_pos = find_pos + key_string.size() );
				OUTPUT_VALUE( pivot_pos );
				OUTPUT_VALUE( orig_string[pivot_pos] );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( find_pos = orig_string.find( key_string, pivot_pos ) );
				OUTPUT_VALUE( find_pos );
				PROCESS_MAIN( pivot_pos = find_pos + key_string.size() );
				OUTPUT_VALUE( pivot_pos );
				OUTPUT_VALUE( orig_string[pivot_pos] );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( find_pos = orig_string.find( key_string, pivot_pos ) );
				OUTPUT_VALUE( find_pos );
				PROCESS_MAIN( pivot_pos = find_pos + key_string.size() );
				OUTPUT_VALUE( pivot_pos );
				OUTPUT_VALUE( orig_string[pivot_pos] );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	void StringSplit( const std::string& str, const std::string& key_string )
	{
		if( str.empty() )
		{
			std::cout << r2tm::tab << "> Empty" << r2tm::linefeed;
			return;
		}

		OUTPUT_VALUE( str.size() );

		LF();

		std::size_t pivot_pos = 0u;
		std::size_t find_pos = 0u;

		int i = 0;
		do
		{
			find_pos = str.find( key_string, pivot_pos );

			//
			// \n 을 찾지 못했다.
			//
			if( std::string::npos == find_pos )
			{
				std::cout << r2tm::tab << i << "[" << pivot_pos << " ~ " << str.size() - 1u << "]" << " > ";
				std::cout << ( &str[pivot_pos] );
				LF();

				// find_pos 가 npos 라면 pivot_pos 의 정상 갱신이 불가능 하다.
				// break 로 여기서 loop를 끝내준다.
				break;
			}

			//
			// \n 을 찾았는데 pivot 과 find 의 위치가 같다.
			//
			else if( pivot_pos == find_pos )
			{
				std::cout << r2tm::tab << i << "[" << pivot_pos << " ~ " << find_pos << "]" << " > ";
				std::cout << "\\n";
				LF();
			}

			//
			// \n 을 찾았다.
			//
			else if( pivot_pos != find_pos )
			{
				find_pos = find_pos - 1;

				std::cout << r2tm::tab << i << "[" << pivot_pos << " ~ " << find_pos << "]" << " > ";
				std::cout.write( &str[pivot_pos], find_pos - pivot_pos + 1 );
				LF();
			}

			pivot_pos = find_pos + key_string.size();
			if( str.size() <= pivot_pos )
			{
				break;
			}

			++i;
		} while( str.size() > pivot_pos );
	}
	r2tm::TitleFunctionT Find_And_Split_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Find And Split 1";
		};
	}
	r2tm::DoFunctionT Find_And_Split_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const std::string key_string = "\n" );
			OUTPUT_VALUE( key_string.size() );

			LS();

			PROCESS_MAIN( StringSplit( "", key_string ) );

			LS();

			PROCESS_MAIN( StringSplit( " ", key_string ) );

			LS();

			PROCESS_MAIN( StringSplit( "\n ", key_string ) );

			LS();

			PROCESS_MAIN( StringSplit( " \n", key_string ) );

			LS();

			PROCESS_MAIN( StringSplit( "\n \n", key_string ) );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT Find_And_Split_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Find And Split 2";
		};
	}
	r2tm::DoFunctionT Find_And_Split_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const std::string key_string = "\n" );
			OUTPUT_VALUE( key_string.size() );

			LS();

			PROCESS_MAIN( StringSplit( "\n" "\n" "1" "\n" "23" "\n" "\n" "efg" "\n" " " "\n" "vwx" "\n", key_string ) );

			LS();

			PROCESS_MAIN( StringSplit( "\n" "\n" "123" "\n" "456" "\n" "\n" "789" "\n" "\n" "\n" "defg", key_string ) );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	std::size_t CalculateLineCount( const std::string& str )
	{
		if( str.empty() )
		{
			return 0u;
		}

		const char* key_string = "\n";

		std::size_t pivot_pos = 0u;
		std::size_t find_pos = 0u;

		int line_count = 1;
		while( std::string::npos != find_pos )
		{
			find_pos = str.find( key_string, pivot_pos );
			if( std::string::npos == find_pos )
			{
				break;
			}

			pivot_pos = find_pos + 1u;
			++line_count;
		}

		return line_count;
	}
	r2tm::TitleFunctionT Line_Count::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Line Count";
		};
	}
	r2tm::DoFunctionT Line_Count::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_VALUE( CalculateLineCount( "" ) );

				LF();

				OUTPUT_VALUE( CalculateLineCount( " " ) );

				LF();

				OUTPUT_VALUE( CalculateLineCount( "\n" " " ) );

				LF();

				OUTPUT_VALUE( CalculateLineCount( " " "\n" ) );

				LF();

				OUTPUT_VALUE( CalculateLineCount( "\n" " " "\n" ) );

				LF();

				OUTPUT_VALUE( CalculateLineCount( "\n" "\n" "ab" "\n" "cd" "\n" "\n" "ef" "\n" "gh" "\n" "\n" "\n" "ijk" "\n" ) );

				LF();

				OUTPUT_VALUE( CalculateLineCount( "\n" "\n" "ab" "\n" "cd" "\n" "\n" "ef" "\n" "gh" "\n" "\n" "\n" "i" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}