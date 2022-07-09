#include "std_string_test.h"

#include <string>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace std_string_test
{
	r2cm::iItem::TitleFunctionT Find::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "String : Find";
		};
	}
	r2cm::iItem::DoFunctionT Find::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

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



	void StringSplit( const std::string& str )
	{
		std::cout << r2cm::linefeed;

		DECLARATION_MAIN( const std::string key_string = "\n" );
		OUTPUT_VALUE( key_string.size() );

		std::cout << r2cm::linefeed;

		OUTPUT_VALUE( str.size() );

		std::cout << r2cm::linefeed;

		DECLARATION_MAIN( std::size_t pivot_pos = 0u );
		DECLARATION_MAIN( std::size_t find_pos = 0u; );

		int i = 0;
		while( std::string::npos != find_pos )
		{
			find_pos = str.find( key_string, pivot_pos );
			if( std::string::npos == find_pos )
			{
				break;
			}

			std::cout << r2cm::tab << i << "[" << pivot_pos << " ~ " << find_pos << "]" << " > ";
			std::cout.write( &str[pivot_pos], find_pos - pivot_pos );
			std::cout << r2cm::linefeed;

			pivot_pos = find_pos + key_string.size();

			++i;
		}
	}
	r2cm::iItem::TitleFunctionT Find_And_Split::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "String : Find And Split";
		};
	}
	r2cm::iItem::DoFunctionT Find_And_Split::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( "\n" "\n" "012345" "\n" "6789abcd" "\n" "\n" "efghij" "\n" "klmnopqrstu" "\n" "\n" "\n" "vwxyz" "\n" ) );

			std::cout << r2cm::split;

			PROCESS_MAIN( StringSplit( "\n" "\n" "123" "\n" "456" "\n" "\n" "789" "\n" "abc" "\n" "\n" "\n" "defg" ) );

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
			return "String : Line Count";
		};
	}
	r2cm::iItem::DoFunctionT Line_Count::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

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
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}