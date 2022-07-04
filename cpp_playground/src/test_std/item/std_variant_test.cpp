#include "std_variant_test.h"

#include <variant>

#include "r2cm/r2cm_constant.h"


namespace std_variant_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Variant : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::variant<int, float, bool> v;" << r2cm::linefeed;
				std::variant<int, float, bool> v;

				std::cout << r2cm::tab2 << "- Default Type is First T : int : index 0" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Check T Index" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Call : v.index();" << r2cm::linefeed;
				std::cout << r2cm::tab4 << v.index() << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Get Value" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Call : std::get<0>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab4 << std::get<0>( v ) << r2cm::linefeed;
			}


			std::cout << r2cm::split;


			{
				std::cout << r2cm::tab << "+ std::variant<int, int> v;" << r2cm::linefeed;

				std::variant<int, int> v;
				std::cout << r2cm::tab2 << "- Has Problem Using Same Type" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- Not Working : v = 1;" << r2cm::linefeed;
				//
				//v = 1;
				//
			}


			std::cout << r2cm::split;


			{
				std::cout << r2cm::tab << "+ std::variant<int, float> v;" << r2cm::linefeed;

				std::variant<int, float> v;


				v = 1;
				std::cout << r2cm::tab2 << "- v = 1;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Call : v.index();" << r2cm::linefeed;
				std::cout << r2cm::tab4 << v.index() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Call : std::get<0>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab4 << std::get<0>( v ) << r2cm::linefeed;


				v = 2.1f;
				std::cout << r2cm::tab2 << "- v = 2.1f;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Call : v.index();" << r2cm::linefeed;
				std::cout << r2cm::tab4 << v.index() << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Call : std::get<1>( v );" << r2cm::linefeed;
				std::cout << r2cm::tab4 << std::get<1>( v ) << r2cm::linefeed;
			}


			std::cout << r2cm::split;


			{
				struct TestStruct
				{
					TestStruct( int i ) : mI( i ) {}
					int mI;
				};

				std::cout << r2cm::tab << "+ std::monostate" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- std::monostate is Empty Struct" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "struct TestStruct" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "TestStruct( int i ) : mI( i ) {}" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "int mI;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "- Not Working : std::variant<TestStruct, int, float> v;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "First Type Need Default Constructor" << r2cm::linefeed2;
				//
				//std::variant<TestStruct, int, float> v;
				//

				{
					std::cout << r2cm::tab2 << "- Working : std::variant<std::monostate, TestStruct, int, float> v;" << r2cm::linefeed2;
					std::variant<std::monostate, TestStruct, int, float> v;
				}

				{
					std::cout << r2cm::tab2 << "- Working : std::variant<char, TestStruct, int, float> v;" << r2cm::linefeed;
					std::variant<char, TestStruct, int, float> v;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}