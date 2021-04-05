#include "variant_test.h"

#include <iostream>
#include <variant>


namespace variant_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Variant : Basic";
		};
	}
	r2::eTestResult Basic::Do()
	{
		std::cout << "== Variant : Basic ==" << std::endl << std::endl;


		{
			std::cout << "\t+ std::variant<int, float, bool> v;" << std::endl;
			std::variant<int, float, bool> v;

			std::cout << "\t\t- Default Type is First T : int : index 0" << std::endl;

			std::cout << "\t\t- Check T Index" << std::endl;
			std::cout << "\t\t\t- Call : v.index();" << std::endl;
			std::cout << "\t\t\t\t" << v.index() << std::endl;

			std::cout << "\t\t- Get Value" << std::endl;
			std::cout << "\t\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t\t" << std::get<0>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::variant<int, int> v;" << std::endl;

			std::variant<int, int> v;
			std::cout << "\t\t- Has Problem Using Same Type" << std::endl << std::endl;
			std::cout << "\t\t- Not Working : v = 1;" << std::endl << std::endl;
			//
			//v = 1;
			//
		}


		std::cout << std::endl << std::endl;


		{
			std::cout << "\t+ std::variant<int, float> v;" << std::endl;

			std::variant<int, float> v;


			v = 1;
			std::cout << "\t\t- v = 1;" << std::endl;
			std::cout << "\t\t\t- Call : v.index();" << std::endl;
			std::cout << "\t\t\t\t" << v.index() << std::endl;
			std::cout << "\t\t\t- Call : std::get<0>( v );" << std::endl;
			std::cout << "\t\t\t\t" << std::get<0>( v ) << std::endl;
			
			
			v = 2.1f;
			std::cout << "\t\t- v = 2.1f;" << std::endl;
			std::cout << "\t\t\t- Call : v.index();" << std::endl;
			std::cout << "\t\t\t\t" << v.index() << std::endl;
			std::cout << "\t\t\t- Call : std::get<1>( v );" << std::endl;
			std::cout << "\t\t\t\t" << std::get<1>( v ) << std::endl;
		}


		std::cout << std::endl << std::endl;


		{
			struct TestStruct
			{
				TestStruct( int i ) : mI( i ) {}
				int mI;
			};

			std::cout << "\t+ std::monostate" << std::endl;
			std::cout << "\t\t- std::monostate is Empty Struct" << std::endl << std::endl;

			std::cout << "\t\t struct TestStruct" << std::endl;
			std::cout << "\t\t {" << std::endl;
			std::cout << "\t\t\t TestStruct( int i ) : mI( i ) {}" << std::endl;
			std::cout << "\t\t\t int mI;" << std::endl;
			std::cout << "\t\t }" << std::endl << std::endl;

			std::cout << "\t\t- Not Working : std::variant<TestStruct, int, float> v;" << std::endl;
			std::cout << "\t\t\tFirst Type Need Default Constructor" << std::endl << std::endl;
			//
			//std::variant<TestStruct, int, float> v;
			//
			
			{
				std::cout << "\t\t- Working : std::variant<std::monostate, TestStruct, int, float> v;" << std::endl << std::endl;
				std::variant<std::monostate, TestStruct, int, float> v;
			}

			{
				std::cout << "\t\t- Working : std::variant<char, TestStruct, int, float> v;" << std::endl << std::endl;
				std::variant<char, TestStruct, int, float> v;
			}
		}

		return r2::eTestResult::RunTest;
	}
}