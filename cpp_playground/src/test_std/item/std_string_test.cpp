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

			DECLARATION_MAIN( const std::string key_string = "\n" );
			OUTPUT_VALUE( key_string.size() );

			std::cout << r2cm::linefeed;

			DECLARATION_MAIN( const std::string orig_string = "\n" "\n" "012345" "\n" "6789abcd" "\n" "\n" "efghij" "\n" "klmnopqrstu" "\n" "\n" "\n" "vwxyz" "\n" );
			OUTPUT_VALUE( orig_string.size() );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::size_t pivot_pos = 0u );
				DECLARATION_MAIN( std::size_t find_pos = 0u; );

				int i = 0;
				while( std::string::npos != find_pos )
				{
					find_pos = orig_string.find( key_string, pivot_pos );
					if( std::string::npos == find_pos )
					{
						break;
					}

					std::cout << r2cm::tab << i << "[" << pivot_pos << " ~ " << find_pos << "]" << " > ";
					std::cout.write( &orig_string[pivot_pos], find_pos - pivot_pos );
					std::cout << r2cm::linefeed;

					pivot_pos = find_pos + key_string.size();

					++i;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}