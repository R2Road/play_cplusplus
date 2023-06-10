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
			LS();

			OUTPUT_NOTE( "C++ 17 ���ʹ� namespace �� �ٿ� �� �� �ִ�." );

			LS();

			OUTPUT_FILE_RANGE( "src/test_cpp/item/cpp_namespace_test.cpp", 6, 29 );

			LS();

			{
				DECLARATION_MAIN( cpp_namespace_test::A::B::C::T t );
				OUTPUT_VALUE( t.Do() );
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

			OUTPUT_NOTE( "namespace �� ��Ī ���� ����" );

			LS();

			OUTPUT_FILE_RANGE( "src/test_cpp/item/cpp_namespace_test.cpp", 6, 29 );

			LS();

			DECLARATION_MAIN( namespace alias_test = cpp_namespace_test::A::B::C; );

			LS();

			{
				DECLARATION_MAIN( alias_test::T t );
				OUTPUT_VALUE( t.Do() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}