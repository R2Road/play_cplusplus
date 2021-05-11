#include "pch.h"
#include "variant_test.h"

#include <variant>

#include "r2_eTestResult.h"


namespace variant_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Variant : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t+ std::variant<int, float, bool> v;" << r2::linefeed;
				std::variant<int, float, bool> v;

				std::cout << "\t\t- Default Type is First T : int : index 0" << r2::linefeed;

				std::cout << "\t\t- Check T Index" << r2::linefeed;
				std::cout << "\t\t\t- Call : v.index();" << r2::linefeed;
				std::cout << "\t\t\t\t" << v.index() << r2::linefeed;

				std::cout << "\t\t- Get Value" << r2::linefeed;
				std::cout << "\t\t\t- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << "\t\t\t\t" << std::get<0>( v ) << r2::linefeed;
			}


			std::cout << r2::split;


			{
				std::cout << "\t+ std::variant<int, int> v;" << r2::linefeed;

				std::variant<int, int> v;
				std::cout << "\t\t- Has Problem Using Same Type" << r2::linefeed << r2::linefeed;
				std::cout << "\t\t- Not Working : v = 1;" << r2::linefeed;
				//
				//v = 1;
				//
			}


			std::cout << r2::split;


			{
				std::cout << "\t+ std::variant<int, float> v;" << r2::linefeed;

				std::variant<int, float> v;


				v = 1;
				std::cout << "\t\t- v = 1;" << r2::linefeed;
				std::cout << "\t\t\t- Call : v.index();" << r2::linefeed;
				std::cout << "\t\t\t\t" << v.index() << r2::linefeed;
				std::cout << "\t\t\t- Call : std::get<0>( v );" << r2::linefeed;
				std::cout << "\t\t\t\t" << std::get<0>( v ) << r2::linefeed;


				v = 2.1f;
				std::cout << "\t\t- v = 2.1f;" << r2::linefeed;
				std::cout << "\t\t\t- Call : v.index();" << r2::linefeed;
				std::cout << "\t\t\t\t" << v.index() << r2::linefeed;
				std::cout << "\t\t\t- Call : std::get<1>( v );" << r2::linefeed;
				std::cout << "\t\t\t\t" << std::get<1>( v ) << r2::linefeed;
			}


			std::cout << r2::split;


			{
				struct TestStruct
				{
					TestStruct( int i ) : mI( i ) {}
					int mI;
				};

				std::cout << "\t+ std::monostate" << r2::linefeed;
				std::cout << "\t\t- std::monostate is Empty Struct" << r2::linefeed << r2::linefeed;

				std::cout << "\t\t struct TestStruct" << r2::linefeed;
				std::cout << "\t\t {" << r2::linefeed;
				std::cout << "\t\t\t TestStruct( int i ) : mI( i ) {}" << r2::linefeed;
				std::cout << "\t\t\t int mI;" << r2::linefeed;
				std::cout << "\t\t }" << r2::linefeed << r2::linefeed;

				std::cout << "\t\t- Not Working : std::variant<TestStruct, int, float> v;" << r2::linefeed;
				std::cout << "\t\t\tFirst Type Need Default Constructor" << r2::linefeed << r2::linefeed;
				//
				//std::variant<TestStruct, int, float> v;
				//

				{
					std::cout << "\t\t- Working : std::variant<std::monostate, TestStruct, int, float> v;" << r2::linefeed << r2::linefeed;
					std::variant<std::monostate, TestStruct, int, float> v;
				}

				{
					std::cout << "\t\t- Working : std::variant<char, TestStruct, int, float> v;" << r2::linefeed;
					std::variant<char, TestStruct, int, float> v;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}