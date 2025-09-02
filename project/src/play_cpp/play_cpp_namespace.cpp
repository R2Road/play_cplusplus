#include "play_cpp_namespace.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_cpp_namespace
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

namespace play_cpp_namespace::A::B::C
{
	int T::Do()
	{
		return 777;
	}
}

namespace play_cpp_namespace
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
			LS();

			OUT_NOTE( "C++ 17 부터는 namespace 를 붙여 쓸 수 있다." );

			LS();

			OUT_FILE_RANGE( "src/play_cpp/play_cpp_namespace.cpp", 6, 29 );

			LS();

			{
				DECL_MAIN( play_cpp_namespace::A::B::C::T t );
				OUT_VALUE( t.Do() );
			}

			LS();

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
			LS();

			OUT_NOTE( "namespace 에 별칭 지정 가능" );

			LS();

			OUT_FILE_RANGE( "src/play_cpp/play_cpp_namespace.cpp", 6, 29 );

			LS();

			DECL_MAIN( namespace alias_test = play_cpp_namespace::A::B::C; );

			LS();

			{
				DECL_MAIN( alias_test::T t );
				OUT_VALUE( t.Do() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}