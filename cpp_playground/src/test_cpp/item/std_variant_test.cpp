#include "pch.h"
#include "std_variant_test.h"

#include <variant>

#include "r2cm/r2cm_eTestEndAction.h"


namespace std_variant_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Variant : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::variant<int, float, bool> v;" << r2::linefeed;
				std::variant<int, float, bool> v;

				std::cout << r2::tab2 << "- Default Type is First T : int : index 0" << r2::linefeed;

				std::cout << r2::tab2 << "- Check T Index" << r2::linefeed;
				std::cout << r2::tab3 << "- Call : v.index();" << r2::linefeed;
				std::cout << r2::tab4 << v.index() << r2::linefeed;

				std::cout << r2::tab2 << "- Get Value" << r2::linefeed;
				std::cout << r2::tab3 << "- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << r2::tab4 << std::get<0>( v ) << r2::linefeed;
			}


			std::cout << r2::split;


			{
				std::cout << r2::tab << "+ std::variant<int, int> v;" << r2::linefeed;

				std::variant<int, int> v;
				std::cout << r2::tab2 << "- Has Problem Using Same Type" << r2::linefeed2;
				std::cout << r2::tab2 << "- Not Working : v = 1;" << r2::linefeed;
				//
				//v = 1;
				//
			}


			std::cout << r2::split;


			{
				std::cout << r2::tab << "+ std::variant<int, float> v;" << r2::linefeed;

				std::variant<int, float> v;


				v = 1;
				std::cout << r2::tab2 << "- v = 1;" << r2::linefeed;
				std::cout << r2::tab3 << "- Call : v.index();" << r2::linefeed;
				std::cout << r2::tab4 << v.index() << r2::linefeed;
				std::cout << r2::tab3 << "- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << r2::tab4 << std::get<0>( v ) << r2::linefeed;


				v = 2.1f;
				std::cout << r2::tab2 << "- v = 2.1f;" << r2::linefeed;
				std::cout << r2::tab3 << "- Call : v.index();" << r2::linefeed;
				std::cout << r2::tab4 << v.index() << r2::linefeed;
				std::cout << r2::tab3 << "- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << r2::tab4 << std::get<1>( v ) << r2::linefeed;
			}


			std::cout << r2::split;


			{
				struct TestStruct
				{
					TestStruct( int i ) : mI( i ) {}
					int mI;
				};

				std::cout << r2::tab << "+ std::monostate" << r2::linefeed;
				std::cout << r2::tab2 << "- std::monostate is Empty Struct" << r2::linefeed2;

				std::cout << r2::tab2 << "struct TestStruct" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "TestStruct( int i ) : mI( i ) {}" << r2::linefeed;
				std::cout << r2::tab3 << "int mI;" << r2::linefeed;
				std::cout << r2::tab2 << "}" << r2::linefeed2;

				std::cout << r2::tab2 << "- Not Working : std::variant<TestStruct, int, float> v;" << r2::linefeed;
				std::cout << r2::tab3 << "First Type Need Default Constructor" << r2::linefeed2;
				//
				//std::variant<TestStruct, int, float> v;
				//

				{
					std::cout << r2::tab2 << "- Working : std::variant<std::monostate, TestStruct, int, float> v;" << r2::linefeed2;
					std::variant<std::monostate, TestStruct, int, float> v;
				}

				{
					std::cout << r2::tab2 << "- Working : std::variant<char, TestStruct, int, float> v;" << r2::linefeed;
					std::variant<char, TestStruct, int, float> v;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}