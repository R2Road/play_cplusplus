#include "std_tuple_test.h"

#include <string>
#include <tuple>

#include "r2cm/r2cm_ostream.h"

namespace std_tuple_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Tuple : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;


			{
				std::cout << r2cm::tab << "+ std::tuple<int, std::string, char> v;" << r2cm::linefeed;
				std::tuple<int, std::string, char> v;

				std::cout << r2cm::tab2 << "- Call : std::get<0>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<0>( v ) << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call : std::get<1>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<1>( v ) << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call : std::get<2>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<2>( v ) << r2cm::linefeed;
			}


			std::cout << r2cm::split;


			{
				std::cout << r2cm::tab << "+ std::tuple<int, std::string, bool> v{ 2, \"park\", 'b' };" << r2cm::linefeed;
				std::tuple<int, std::string, char> v{ 2, "park", 'b' };

				std::cout << r2cm::tab2  << "- Call : std::get<0>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<0>( v ) << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call : std::get<1>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<1>( v ) << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call : std::get<2>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<2>( v ) << r2cm::linefeed;
			}


			std::cout << r2cm::split;


			{
				std::cout << r2cm::tab << "+ auto v = std::make_tuple( 10, \"Kim\", 'c' );" << r2cm::linefeed;
				auto v = std::make_tuple( 10, "Kim", 'c' );

				std::cout << r2cm::tab2 << "- Call : std::get<0>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<0>( v ) << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call : std::get<1>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<1>( v ) << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call : std::get<2>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << std::get<2>( v ) << r2cm::linefeed;
			}


			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}