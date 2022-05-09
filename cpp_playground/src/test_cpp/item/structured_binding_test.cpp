#include "pch.h"
#include "structured_binding_test.h"

#include <tuple>
#include <utility> // pair

#include "r2cm/r2cm_constant.h"

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
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Structured Binding : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed << r2cm::linefeed;


			{
				std::cout << r2cm::tab << "+ Basic" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "struct TestStruct" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "int i = 1;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "char c = 'a';" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "float f = 3.14f;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed << r2cm::linefeed;

				struct TestStruct
				{
					int i = 1;
					char c = 'a';
					float f = 3.14f;
				};

				std::cout << r2cm::tab2 << "TestStruct t;" << r2cm::linefeed << r2cm::linefeed;
				TestStruct t;

				std::cout << r2cm::tab2 << "auto[i, c, f] = t;" << r2cm::linefeed;
				auto[i, c, f] = t;

				std::cout << r2cm::tab3 << " - i : " << i << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - c : " << c << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - f : " << f << r2cm::linefeed;
			}


			std::cout << r2cm::linefeed << r2cm::linefeed;


			{
				std::cout << r2cm::tab << "+ with Pair" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "auto temp_pair = std::make_pair( 2, 'b' );" << r2cm::linefeed << r2cm::linefeed;
				auto temp_pair = std::make_pair( 2, 'b' );

				std::cout << r2cm::tab2 << "auto[first, second] = temp_pair;" << r2cm::linefeed;
				auto[first, second] = temp_pair;

				std::cout << r2cm::tab3 << " - first : " << first << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - second : " << second << r2cm::linefeed;
			}


			std::cout << r2cm::linefeed << r2cm::linefeed;


			{
				std::cout << r2cm::tab << "+ with Tuple" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "auto temp_tuple = std::make_tuple( 3, 'c', 6.28f );" << r2cm::linefeed << r2cm::linefeed;
				auto temp_tuple = std::make_tuple( 3, 'c', 6.28f );

				std::cout << r2cm::tab2 << "auto[first, second, third] = temp_tuple;" << r2cm::linefeed;
				auto[first, second, third] = temp_tuple;

				std::cout << r2cm::tab3 << " - first : " << first << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - second : " << second << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - third : " << third << r2cm::linefeed;
			}


			std::cout << r2cm::linefeed << r2cm::linefeed;


			{
				std::cout << r2cm::tab << "+ with Function x 1" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "auto[first, second] = GetDummyPair();" << r2cm::linefeed;
				auto[first, second] = GetDummyPair();

				std::cout << r2cm::tab3 << " - first : " << first << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - second : " << second << r2cm::linefeed;
			}


			std::cout << r2cm::linefeed << r2cm::linefeed;


			{
				std::cout << r2cm::tab << "+ with Function x 2" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "auto[first, second, third] = GetDummyTuple();" << r2cm::linefeed;
				auto[first, second, third] = GetDummyTuple();

				std::cout << r2cm::tab3 << " - first : " << first << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - second : " << second << r2cm::linefeed;
				std::cout << r2cm::tab3 << " - third : " << third << r2cm::linefeed;
			}


			std::cout << r2cm::linefeed << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}