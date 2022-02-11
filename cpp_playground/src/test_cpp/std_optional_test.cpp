#include "pch.h"
#include "std_optional_test.h"

#include <optional>

#include "base/r2_eTestEndAction.h"

namespace std_optional_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Message : " "Optional Use Placement New" << r2::linefeed;

			std::cout << r2::split;

			struct TestOptional { int i = 8; };
			std::optional<TestOptional> op_ts;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "struct TestOptional { int i = 8; };" << r2::linefeed;
			std::cout << r2::tab2 << "std::optional<TestOptional> op_ts;" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process 1" << r2::linefeed2;
				std::cout << r2::tab2 << "op_ts.has_value();" << r2::linefeed;
				std::cout << r2::tab3 << "> " << op_ts.has_value() << r2::linefeed2;

				std::cout << r2::tab2 << "Message : " << "op_ts.value()" " > throw exception : op_ts is nullopt" << r2::linefeed2;

				op_ts = TestOptional{};

				std::cout << r2::tab << "+ Process 2" << r2::linefeed2;
				std::cout << r2::tab2 << "op_ts = TestOptional{};" << r2::linefeed;
				std::cout << r2::tab2 << "op_ts.has_value();" << r2::linefeed;
				std::cout << r2::tab3 << "> " << op_ts.has_value() << r2::linefeed;
				std::cout << r2::tab2 << "op_ts.value().i;" << r2::linefeed;
				std::cout << r2::tab3 << "> " << op_ts.value().i << r2::linefeed2;

				op_ts.reset();

				std::cout << r2::tab << "+ Process 3" << r2::linefeed2;
				std::cout << r2::tab2 << "op_ts.reset();" << r2::linefeed;
				std::cout << r2::tab2 << "op_ts.has_value();" << r2::linefeed;
				std::cout << r2::tab3 << "> " << op_ts.has_value() << r2::linefeed2;

				op_ts = TestOptional{};
				op_ts = std::nullopt;

				std::cout << r2::tab << "+ Process 4" << r2::linefeed2;
				std::cout << r2::tab2 << "op_ts = TestOptional{};" << r2::linefeed;
				std::cout << r2::tab2 << "op_ts = std::nullopt;" << r2::linefeed;
				std::cout << r2::tab2 << "op_ts.has_value();" << r2::linefeed;
				std::cout << r2::tab3 << "> " << op_ts.has_value() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	struct TestOptional
	{
		TestOptional()
		{
			std::cout << "> Call : TestOptional()" << r2::tab;
		}
		TestOptional( const int )
		{
			std::cout << "> Call : TestOptional( const int i )" << r2::tab;
		}
		TestOptional( const TestOptional& )
		{
			std::cout << "> Call : TestOptional( const TestStruct& )" << r2::tab;
		}
		TestOptional( TestOptional&& )
		{
			std::cout << "> Call : TestOptional( TestStruct&& )" << r2::tab;
		}

		TestOptional& operator=( const TestOptional& )
		{
			std::cout << "> Call : TestOptional& operator=( const TestOptional& )" << r2::tab;
			return *this;
		}

		int i = 8;
	};
	std::optional<TestOptional> GetTestOptional()
	{
		return std::optional<TestOptional>( TestOptional{} );
	}
	r2::iTest::TitleFunc Constructor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Constructor";
		};
	}
	r2::iTest::DoFunc Constructor::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::optional<TestOptional> op_1;
			std::optional<TestOptional> op_2;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "struct TestOptional;" << r2::linefeed;
			std::cout << r2::tab2 << "std::optional<TestOptional> op_1;" << r2::linefeed;
			std::cout << r2::tab2 << "std::optional<TestOptional> op_2;" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process 1" << r2::linefeed2;
				std::cout << r2::tab2 << "op_1 = op_2;" << r2::linefeed;
				std::cout << r2::tab3;
				op_1 = op_2;
				std::cout << "> Nothing";
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process 2" << r2::linefeed2;
				std::cout << r2::tab2 << "op_1 = TestOptional{};" << r2::linefeed;
				std::cout << r2::tab3;
				op_1 = TestOptional{};
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process 3" << r2::linefeed2;
				std::cout << r2::tab2 << "op_2 = op_1;" << r2::linefeed;
				std::cout << r2::tab3;
				op_2 = op_1;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process 4" << r2::linefeed2;
				std::cout << r2::tab2 << "std::optional<TestOptional> temp_op = op_1;" << r2::linefeed;
				std::cout << r2::tab3;
				std::optional<TestOptional> temp_op = op_1;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process 5" << r2::linefeed2;
				std::cout << r2::tab2 << "op_1 = GetTestOptional();" << r2::linefeed;
				std::cout << r2::tab3;
				op_1 = GetTestOptional();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process 5" << r2::linefeed2;
				std::cout << r2::tab2 << "std::optional<TestOptional> temp_op = GetTestOptional();" << r2::linefeed;
				std::cout << r2::tab3;
				std::optional<TestOptional> temp_op = GetTestOptional();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	r2::iTest::TitleFunc Reference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Reference";
		};
	}
	r2::iTest::DoFunc Reference::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			struct EmptyStruct {};
			EmptyStruct t_1;
			EmptyStruct t_2;

			std::cout << r2::tab << "+ Declaration " << r2::linefeed2;
			std::cout << r2::tab2 << "struct EmptyStruct {};" << r2::linefeed;
			std::cout << r2::tab2 << "EmptyStruct t_1;" << r2::linefeed;
			std::cout << r2::tab2 << "EmptyStruct t_2;" << r2::linefeed;

			std::cout << r2::split;

			{
				//
				//std::optional<EmptyStruct&> maybe_test_struct_ref = t_1;
				//
				std::cout << r2::tab << "std::optional<EmptyStruct&> maybe_test_struct_ref = t_1;" << r2::linefeed;
				std::cout << r2::tab2 << "> Not Working" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::optional<std::reference_wrapper<EmptyStruct>> maybe_test_struct_ref = t_1;
				std::cout << r2::tab << "std::optional<std::reference_wrapper<EmptyStruct>> maybe_test_struct_ref = t_1;" << r2::linefeed;
				std::cout << r2::tab2 << "> Working" << r2::linefeed2;

				maybe_test_struct_ref = t_2;
				std::cout << r2::tab << "maybe_test_struct_ref = t_2;" << r2::linefeed;
				std::cout << r2::tab2 << "> Working" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}