#include "std_tuple_test.h"

#include <string>
#include <tuple>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_tuple_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::tuple : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				using T = std::tuple<int, std::string, char>;
				std::cout << "using T = std::tuple<int, std::string, char>;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( T t );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::get<0>( t ) );
				OUTPUT_VALUE( std::get<1>( t ) );
				OUTPUT_VALUE( std::get<2>( t ) );
			}


			std::cout << r2cm::split;


			{
				using T = std::tuple<int, std::string, bool>;
				std::cout << "using T = std::tuple<int, std::string, bool>;" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( T t( { 2, "park", true } ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::get<0>( t ) );
				OUTPUT_VALUE( std::get<1>( t ) );
				OUTPUT_VALUE( std::get<2>( t ) );
			}


			std::cout << r2cm::split;


			{
				DECLARATION_MAIN( auto t = std::make_tuple( 10, "Kim", 'c' ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::get<0>( t ) );
				OUTPUT_VALUE( std::get<1>( t ) );
				OUTPUT_VALUE( std::get<2>( t ) );
			}


			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}