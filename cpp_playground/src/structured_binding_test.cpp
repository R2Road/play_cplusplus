#include "pch.h"
#include "structured_binding_test.h"

#include <tuple>
#include <utility> // pair

#include "r2_eTestResult.h"

namespace
{
	std::pair<int, float> GetDummyPair()
	{
		return std::make_pair( 1, 3.14f );
	}

	std::tuple<int, float, char> GetDummyTuple()
	{
		return std::make_tuple( 2, 6.28f, 'b' );
	}
}
namespace structured_binding_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Structured Binding : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ Basic" << r2::linefeed;

				std::cout << "\t\t" << "struct TestStruct" << r2::linefeed;
				std::cout << "\t\t" << "{" << r2::linefeed;
				std::cout << "\t\t\t" << "int i = 1;" << r2::linefeed;
				std::cout << "\t\t\t" << "char c = 'a';" << r2::linefeed;
				std::cout << "\t\t\t" << "float f = 3.14f;" << r2::linefeed;
				std::cout << "\t\t" << "};" << r2::linefeed << r2::linefeed;

				struct TestStruct
				{
					int i = 1;
					char c = 'a';
					float f = 3.14f;
				};

				std::cout << "\t\t" << "TestStruct t;" << r2::linefeed << r2::linefeed;
				TestStruct t;

				std::cout << "\t\t" << "auto[i, c, f] = t;" << r2::linefeed;
				auto[i, c, f] = t;

				std::cout << "\t\t\t" << " - i : " << i << r2::linefeed;
				std::cout << "\t\t\t" << " - c : " << c << r2::linefeed;
				std::cout << "\t\t\t" << " - f : " << f << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ with Pair" << r2::linefeed;

				std::cout << "\t\t" << "auto temp_pair = std::make_pair( 2, 'b' );" << r2::linefeed << r2::linefeed;
				auto temp_pair = std::make_pair( 2, 'b' );

				std::cout << "\t\t" << "auto[first, second] = temp_pair;" << r2::linefeed;
				auto[first, second] = temp_pair;

				std::cout << "\t\t\t" << " - first : " << first << r2::linefeed;
				std::cout << "\t\t\t" << " - second : " << second << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ with Tuple" << r2::linefeed;

				std::cout << "\t\t" << "auto temp_tuple = std::make_tuple( 3, 'c', 6.28f );" << r2::linefeed << r2::linefeed;
				auto temp_tuple = std::make_tuple( 3, 'c', 6.28f );

				std::cout << "\t\t" << "auto[first, second, third] = temp_tuple;" << r2::linefeed;
				auto[first, second, third] = temp_tuple;

				std::cout << "\t\t\t" << " - first : " << first << r2::linefeed;
				std::cout << "\t\t\t" << " - second : " << second << r2::linefeed;
				std::cout << "\t\t\t" << " - third : " << third << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ with Function x 1" << r2::linefeed;

				std::cout << "\t\t" << "auto[first, second] = GetDummyPair();" << r2::linefeed;
				auto[first, second] = GetDummyPair();

				std::cout << "\t\t\t" << " - first : " << first << r2::linefeed;
				std::cout << "\t\t\t" << " - second : " << second << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ with Function x 2" << r2::linefeed;

				std::cout << "\t\t" << "auto[first, second, third] = GetDummyTuple();" << r2::linefeed;
				auto[first, second, third] = GetDummyTuple();

				std::cout << "\t\t\t" << " - first : " << first << r2::linefeed;
				std::cout << "\t\t\t" << " - second : " << second << r2::linefeed;
				std::cout << "\t\t\t" << " - third : " << third << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}