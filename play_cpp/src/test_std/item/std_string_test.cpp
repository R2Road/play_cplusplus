#include "std_string_test.h"

#include <string>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace std_string_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string s );
				OUTPUT_VALUE( sizeof( s ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string empty_string_1 );
				DECLARATION_MAIN( const std::string empty_string_2 );
				EXPECT_EQ( empty_string_1, empty_string_2 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const std::string string_1( " " ) );
				DECLARATION_MAIN( const std::string string_2( " " ) );
				EXPECT_EQ( string_1, string_2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( (void*)string_1.c_str() );
				OUTPUT_VALUE( (void*)string_2.c_str() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}


	r2cm::iItem::TitleFunctionT Move::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Move";
		};
	}
	r2cm::iItem::DoFunctionT Move::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "ª�� ���ڿ��� ��� move�� �۵����� �ʴ´�." );
			OUTPUT_NOTE( "xstring �� ""_Assign_rv_contents_with_alloc_always_equal"" �Լ� ����" );

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "move : X" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::string s_1( "123456789012345" ) );
				DECLARATION_MAIN( std::string s_2( "234567890123456" ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( s_1 = std::move( s_2 ) );
				OUTPUT_VALUE( s_1 );
				OUTPUT_VALUE( s_2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "move : O" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::string s_1( "1234567890123456" ) );
				DECLARATION_MAIN( std::string s_2( "2345678901234567" ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( s_1 = std::move( s_2 ) );
				OUTPUT_VALUE( s_1 );
				OUTPUT_VALUE( s_2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( (void*)s_1.c_str() );
				OUTPUT_VALUE( (void*)s_2.c_str() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Find::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Find";
		};
	}
	r2cm::iItem::DoFunctionT Find::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const std::string key_string = "\n" );
			OUTPUT_VALUE( key_string.size() );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( const std::string orig_string = "\n\n012345\n6789abcd\n\nefghij\nklmnopqrstu\n\n\nvwxyz\n" );
			OUTPUT_VALUE( orig_string.size() );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::size_t pivot_pos = 0u );
				DECLARATION_MAIN( std::size_t find_pos = 0u );

				PROCESS_MAIN( find_pos = orig_string.find( key_string, pivot_pos ) );
				OUTPUT_VALUE( find_pos );
				PROCESS_MAIN( pivot_pos = find_pos + key_string.size() );
				OUTPUT_VALUE( pivot_pos );
				OUTPUT_VALUE( orig_string[pivot_pos] );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( find_pos = orig_string.find( key_string, pivot_pos ) );
				OUTPUT_VALUE( find_pos );
				PROCESS_MAIN( pivot_pos = find_pos + key_string.size() );
				OUTPUT_VALUE( pivot_pos );
				OUTPUT_VALUE( orig_string[pivot_pos] );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( find_pos = orig_string.find( key_string, pivot_pos ) );
				OUTPUT_VALUE( find_pos );
				PROCESS_MAIN( pivot_pos = find_pos + key_string.size() );
				OUTPUT_VALUE( pivot_pos );
				OUTPUT_VALUE( orig_string[pivot_pos] );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	void StringSplit( const std::string& str, const std::string& key_string )
	{
		if( str.empty() )
		{
			std::cout << r2cm::tab << "> Empty" << r2cm::linefeed;
			return;
		}

		OUTPUT_VALUE( str.size() );

		std::cout << r2cm::linefeed;

		std::size_t pivot_pos = 0u;
		std::size_t find_pos = 0u;

		int i = 0;
		do
		{
			find_pos = str.find( key_string, pivot_pos );

			//
			// \n �� ã�� ���ߴ�.
			//
			if( std::string::npos == find_pos )
			{
				std::cout << r2cm::tab << i << "[" << pivot_pos << " ~ " << str.size() - 1u << "]" << " > ";
				std::cout << ( &str[pivot_pos] );
				std::cout << r2cm::linefeed;

				// find_pos �� npos ��� pivot_pos �� ���� ������ �Ұ��� �ϴ�.
				// break �� ���⼭ loop�� �����ش�.
				break;
			}

			//
			// \n �� ã�Ҵµ� pivot �� find �� ��ġ�� ����.
			//
			else if( pivot_pos == find_pos )
			{
				std::cout << r2cm::tab << i << "[" << pivot_pos << " ~ " << find_pos << "]" << " > ";
				std::cout << "\\n";
				std::cout << r2cm::linefeed;
			}

			//
			// \n �� ã�Ҵ�.
			//
			else if( pivot_pos != find_pos )
			{
				find_pos = find_pos - 1;

				std::cout << r2cm::tab << i << "[" << pivot_pos << " ~ " << find_pos << "]" << " > ";
				std::cout.write( &str[pivot_pos], find_pos - pivot_pos + 1 );
				std::cout << r2cm::linefeed;
			}

			pivot_pos = find_pos + key_string.size();
			if( str.size() <= pivot_pos )
			{
				break;
			}

			++i;
		} while( str.size() > pivot_pos );
	}
	r2cm::iItem::TitleFunctionT Find_And_Split_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Find And Split 1";
		};
	}
	r2cm::iItem::DoFunctionT Find_And_Split_1::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const std::string key_string = "\n" );
			OUTPUT_VALUE( key_string.size() );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( "", key_string ) );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( " ", key_string ) );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( "\n ", key_string ) );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( " \n", key_string ) );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( "\n \n", key_string ) );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT Find_And_Split_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Find And Split 2";
		};
	}
	r2cm::iItem::DoFunctionT Find_And_Split_2::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const std::string key_string = "\n" );
			OUTPUT_VALUE( key_string.size() );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( "\n" "\n" "1" "\n" "23" "\n" "\n" "efg" "\n" " " "\n" "vwx" "\n", key_string ) );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( "\n" "\n" "123" "\n" "456" "\n" "\n" "789" "\n" "\n" "\n" "defg", key_string ) );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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
	r2cm::iItem::TitleFunctionT Line_Count::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Line Count";
		};
	}
	r2cm::iItem::DoFunctionT Line_Count::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( CalculateLineCount( "" ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( CalculateLineCount( " " ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( CalculateLineCount( "\n" " " ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( CalculateLineCount( " " "\n" ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( CalculateLineCount( "\n" " " "\n" ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( CalculateLineCount( "\n" "\n" "ab" "\n" "cd" "\n" "\n" "ef" "\n" "gh" "\n" "\n" "\n" "ijk" "\n" ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( CalculateLineCount( "\n" "\n" "ab" "\n" "cd" "\n" "\n" "ef" "\n" "gh" "\n" "\n" "\n" "i" ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}