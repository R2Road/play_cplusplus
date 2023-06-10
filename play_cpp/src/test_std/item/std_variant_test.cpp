#include "std_variant_test.h"

#include <variant>

#include "r2tm/r2tm_ostream.h"


namespace std_variant_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::variant : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ std::variant<int, float, bool> v;" << r2tm::linefeed;
				std::variant<int, float, bool> v;

				std::cout << r2tm::tab2 << "- Default Type is First T : int : index 0" << r2tm::linefeed;

				std::cout << r2tm::tab2 << "- Check T Index" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Call : v.index();" << r2tm::linefeed;
				std::cout << r2tm::tab4 << v.index() << r2tm::linefeed;

				std::cout << r2tm::tab2 << "- Get Value" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Call : std::get<0>( v );" << r2tm::linefeed;
				std::cout << r2tm::tab4 << std::get<0>( v ) << r2tm::linefeed;
			}


			std::cout << r2tm::split;


			{
				std::cout << r2tm::tab << "+ std::variant<int, int> v;" << r2tm::linefeed;

				std::variant<int, int> v;
				std::cout << r2tm::tab2 << "- Has Problem Using Same Type" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "- Not Working : v = 1;" << r2tm::linefeed;
				//
				//v = 1;
				//
			}


			std::cout << r2tm::split;


			{
				std::cout << r2tm::tab << "+ std::variant<int, float> v;" << r2tm::linefeed;

				std::variant<int, float> v;


				v = 1;
				std::cout << r2tm::tab2 << "- v = 1;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Call : v.index();" << r2tm::linefeed;
				std::cout << r2tm::tab4 << v.index() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Call : std::get<0>( v );" << r2tm::linefeed;
				std::cout << r2tm::tab4 << std::get<0>( v ) << r2tm::linefeed;


				v = 2.1f;
				std::cout << r2tm::tab2 << "- v = 2.1f;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Call : v.index();" << r2tm::linefeed;
				std::cout << r2tm::tab4 << v.index() << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Call : std::get<1>( v );" << r2tm::linefeed;
				std::cout << r2tm::tab4 << std::get<1>( v ) << r2tm::linefeed;
			}


			std::cout << r2tm::split;


			{
				struct TestStruct
				{
					TestStruct( int i ) : mI( i ) {}
					int mI;
				};

				std::cout << r2tm::tab << "+ std::monostate" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- std::monostate is Empty Struct" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "struct TestStruct" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "TestStruct( int i ) : mI( i ) {}" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "int mI;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "}" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "- Not Working : std::variant<TestStruct, int, float> v;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "First Type Need Default Constructor" << r2tm::linefeed2;
				//
				//std::variant<TestStruct, int, float> v;
				//

				{
					std::cout << r2tm::tab2 << "- Working : std::variant<std::monostate, TestStruct, int, float> v;" << r2tm::linefeed2;
					std::variant<std::monostate, TestStruct, int, float> v;
				}

				{
					std::cout << r2tm::tab2 << "- Working : std::variant<char, TestStruct, int, float> v;" << r2tm::linefeed;
					std::variant<char, TestStruct, int, float> v;
				}
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}