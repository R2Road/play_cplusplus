#include "std_tuple_test.h"

#include <string>
#include <tuple>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_tuple_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::tuple : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				using T = std::tuple<int, std::string, char>;
				std::cout << "using T = std::tuple<int, std::string, char>;" << r2tm::linefeed;

				LF();

				DECLARATION_MAIN( T t );

				LF();

				OUTPUT_VALUE( std::get<0>( t ) );
				OUTPUT_VALUE( std::get<1>( t ) );
				OUTPUT_VALUE( std::get<2>( t ) );
			}


			LS();


			{
				using T = std::tuple<int, std::string, bool>;
				std::cout << "using T = std::tuple<int, std::string, bool>;" << r2tm::linefeed;

				LF();

				DECLARATION_MAIN( T t( { 2, "park", true } ) );

				LF();

				OUTPUT_VALUE( std::get<0>( t ) );
				OUTPUT_VALUE( std::get<1>( t ) );
				OUTPUT_VALUE( std::get<2>( t ) );
			}


			LS();


			{
				DECLARATION_MAIN( auto t = std::make_tuple( 10, "Kim", 'c' ) );

				LF();

				OUTPUT_VALUE( std::get<0>( t ) );
				OUTPUT_VALUE( std::get<1>( t ) );
				OUTPUT_VALUE( std::get<2>( t ) );
			}


			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}