#include "std_unordered_map_test.h"
#include "std_unordered_map_test_helper_cstring.hpp"
using namespace std_unordered_map_test_helper_cstring;

#include <unordered_map>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_unordered_map_test
{
	r2tm::TitleFunctionT CString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::unordered_map : CString";
		};
	}
	r2tm::DoFunctionT CString::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_std/item/std_unordered_map_test_helper_cstring.hpp" );

			LS();

			DECLARATION_MAIN( UM4CStringT container );

			LF();

			{
				PROCESS_MAIN( container.insert( std::make_pair( CStringNSize{ "1", 1 }, 123 ) ) );
				PROCESS_MAIN( container.insert( std::make_pair( CStringNSize{ "2", 1 }, 234 ) ) );
				PROCESS_MAIN( container.insert( std::make_pair( CStringNSize{ "3", 1 }, 345 ) ) );
				PROCESS_MAIN( container.insert( std::make_pair( CStringNSize{ "4", 1 }, 456 ) ) );

				LF();

				for( const auto& i : container )
				{
					std::cout << i.first.str << "   " << i.second << r2tm::linefeed;
				}
			}

			LS();

			{
				DECLARATION_MAIN( const auto itr = container.find( CStringNSize{ "1", 1 } ) );
				OUTPUT_VALUE( itr->second );
			}

			LS();

			{
				DECLARATION_MAIN( const auto itr = container.find( CStringNSize{ "4", 1 } ) );
				OUTPUT_VALUE( itr->second );
			}

			LS();

			{
				OUTPUT_NOTE( "char* 의 메모리 관리를 직접 해야 한다." );
				OUTPUT_NOTE( "char* 대신에 std::string_view 를 쓰는게 좋겠다." );
				OUTPUT_NOTE( "그냥 std::string 을 쓰는게 좋지 않을까?" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}