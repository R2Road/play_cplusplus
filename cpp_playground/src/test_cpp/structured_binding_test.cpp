#include "pch.h"
#include "structured_binding_test.h"

#include <tuple>
#include <utility> // pair

#include "base/r2_eTestResult.h"

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
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;


			{
				std::cout << r2::tab << "+ Basic" << r2::linefeed;

				std::cout << r2::tab2 << "struct TestStruct" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "int i = 1;" << r2::linefeed;
				std::cout << r2::tab3 << "char c = 'a';" << r2::linefeed;
				std::cout << r2::tab3 << "float f = 3.14f;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed << r2::linefeed;

				struct TestStruct
				{
					int i = 1;
					char c = 'a';
					float f = 3.14f;
				};

				std::cout << r2::tab2 << "TestStruct t;" << r2::linefeed << r2::linefeed;
				TestStruct t;

				std::cout << r2::tab2 << "auto[i, c, f] = t;" << r2::linefeed;
				auto[i, c, f] = t;

				std::cout << r2::tab3 << " - i : " << i << r2::linefeed;
				std::cout << r2::tab3 << " - c : " << c << r2::linefeed;
				std::cout << r2::tab3 << " - f : " << f << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << r2::tab << "+ with Pair" << r2::linefeed;

				std::cout << r2::tab2 << "auto temp_pair = std::make_pair( 2, 'b' );" << r2::linefeed << r2::linefeed;
				auto temp_pair = std::make_pair( 2, 'b' );

				std::cout << r2::tab2 << "auto[first, second] = temp_pair;" << r2::linefeed;
				auto[first, second] = temp_pair;

				std::cout << r2::tab3 << " - first : " << first << r2::linefeed;
				std::cout << r2::tab3 << " - second : " << second << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << r2::tab << "+ with Tuple" << r2::linefeed;

				std::cout << r2::tab2 << "auto temp_tuple = std::make_tuple( 3, 'c', 6.28f );" << r2::linefeed << r2::linefeed;
				auto temp_tuple = std::make_tuple( 3, 'c', 6.28f );

				std::cout << r2::tab2 << "auto[first, second, third] = temp_tuple;" << r2::linefeed;
				auto[first, second, third] = temp_tuple;

				std::cout << r2::tab3 << " - first : " << first << r2::linefeed;
				std::cout << r2::tab3 << " - second : " << second << r2::linefeed;
				std::cout << r2::tab3 << " - third : " << third << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << r2::tab << "+ with Function x 1" << r2::linefeed;

				std::cout << r2::tab2 << "auto[first, second] = GetDummyPair();" << r2::linefeed;
				auto[first, second] = GetDummyPair();

				std::cout << r2::tab3 << " - first : " << first << r2::linefeed;
				std::cout << r2::tab3 << " - second : " << second << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << r2::tab << "+ with Function x 2" << r2::linefeed;

				std::cout << r2::tab2 << "auto[first, second, third] = GetDummyTuple();" << r2::linefeed;
				auto[first, second, third] = GetDummyTuple();

				std::cout << r2::tab3 << " - first : " << first << r2::linefeed;
				std::cout << r2::tab3 << " - second : " << second << r2::linefeed;
				std::cout << r2::tab3 << " - third : " << third << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestEndAction::Pause;
		};
	}
}