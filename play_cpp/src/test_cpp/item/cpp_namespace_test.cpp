#include "cpp_namespace_test.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace cpp_namespace_test
{
	namespace A
	{
		namespace B
		{
			namespace C
			{
				struct T
				{
					int Do();
				};
			}
		}
	}
}

namespace cpp_namespace_test::A::B::C
{
	int T::Do()
	{
		return 777;
	}
}

namespace cpp_namespace_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "namespace : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_NOTE( "C++ 17 부터는 namespace 를 붙여 쓸 수 있다." );

			std::cout << r2tm::split;

			OUTPUT_FILE_RANGE( "src/test_cpp/item/cpp_namespace_test.cpp", 6, 29 );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( cpp_namespace_test::A::B::C::T t );
				OUTPUT_VALUE( t.Do() );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Alias::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "namespace : Alias";
		};
	}
	r2tm::DoFunctionT Alias::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_NOTE( "namespace 에 별칭 지정 가능" );

			std::cout << r2tm::split;

			OUTPUT_FILE_RANGE( "src/test_cpp/item/cpp_namespace_test.cpp", 6, 29 );

			std::cout << r2tm::split;

			DECLARATION_MAIN( namespace alias_test = cpp_namespace_test::A::B::C; );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( alias_test::T t );
				OUTPUT_VALUE( t.Do() );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}