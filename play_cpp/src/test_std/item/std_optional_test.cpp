#include "std_optional_test.h"

#include <optional>

#include "r2tm/r2tm_ostream.h"

namespace std_optional_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "+ Message : " "Optional Use Placement New" << r2tm::linefeed;

			LS();

			struct TestOptional { int i = 8; };
			std::optional<TestOptional> op_ts;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "struct TestOptional { int i = 8; };" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "std::optional<TestOptional> op_ts;" << r2tm::linefeed;

			LS();

			{
				std::cout << r2tm::tab << "+ Process 1" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_ts.has_value();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "> " << op_ts.has_value() << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "Message : " << "op_ts.value()" " > throw exception : op_ts is nullopt" << r2tm::linefeed2;

				op_ts = TestOptional{};

				std::cout << r2tm::tab << "+ Process 2" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_ts = TestOptional{};" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "op_ts.has_value();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "> " << op_ts.has_value() << r2tm::linefeed;
				std::cout << r2tm::tab2 << "op_ts.value().i;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "> " << op_ts.value().i << r2tm::linefeed2;

				op_ts.reset();

				std::cout << r2tm::tab << "+ Process 3" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_ts.reset();" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "op_ts.has_value();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "> " << op_ts.has_value() << r2tm::linefeed2;

				op_ts = TestOptional{};
				op_ts = std::nullopt;

				std::cout << r2tm::tab << "+ Process 4" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_ts = TestOptional{};" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "op_ts = std::nullopt;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "op_ts.has_value();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "> " << op_ts.has_value() << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	struct TestOptional
	{
		TestOptional()
		{
			std::cout << "> Call : TestOptional()" << r2tm::tab;
		}
		TestOptional( const int )
		{
			std::cout << "> Call : TestOptional( const int i )" << r2tm::tab;
		}
		TestOptional( const TestOptional& )
		{
			std::cout << "> Call : TestOptional( const TestStruct& )" << r2tm::tab;
		}
		TestOptional( TestOptional&& )
		{
			std::cout << "> Call : TestOptional( TestStruct&& )" << r2tm::tab;
		}

		TestOptional& operator=( const TestOptional& )
		{
			std::cout << "> Call : TestOptional& operator=( const TestOptional& )" << r2tm::tab;
			return *this;
		}

		int i = 8;
	};
	std::optional<TestOptional> GetTestOptional()
	{
		return std::optional<TestOptional>( TestOptional{} );
	}
	r2tm::TitleFunctionT Constructor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Constructor";
		};
	}
	r2tm::DoFunctionT Constructor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::optional<TestOptional> op_1;
			std::optional<TestOptional> op_2;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "struct TestOptional;" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "std::optional<TestOptional> op_1;" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "std::optional<TestOptional> op_2;" << r2tm::linefeed;

			LS();

			{
				std::cout << r2tm::tab << "+ Process 1" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_1 = op_2;" << r2tm::linefeed;
				std::cout << r2tm::tab3;
				op_1 = op_2;
				std::cout << "> Nothing";
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process 2" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_1 = TestOptional{};" << r2tm::linefeed;
				std::cout << r2tm::tab3;
				op_1 = TestOptional{};
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process 3" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_2 = op_1;" << r2tm::linefeed;
				std::cout << r2tm::tab3;
				op_2 = op_1;
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process 4" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::optional<TestOptional> temp_op = op_1;" << r2tm::linefeed;
				std::cout << r2tm::tab3;
				std::optional<TestOptional> temp_op = op_1;
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process 5" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "op_1 = GetTestOptional();" << r2tm::linefeed;
				std::cout << r2tm::tab3;
				op_1 = GetTestOptional();
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Process 5" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "std::optional<TestOptional> temp_op = GetTestOptional();" << r2tm::linefeed;
				std::cout << r2tm::tab3;
				std::optional<TestOptional> temp_op = GetTestOptional();
				std::cout << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Reference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Reference";
		};
	}
	r2tm::DoFunctionT Reference::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			struct EmptyStruct {};
			EmptyStruct t_1;
			EmptyStruct t_2;

			std::cout << r2tm::tab << "+ Declaration " << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "struct EmptyStruct {};" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "EmptyStruct t_1;" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "EmptyStruct t_2;" << r2tm::linefeed;

			LS();

			{
				//
				//std::optional<EmptyStruct&> maybe_test_struct_ref = t_1;
				//
				std::cout << r2tm::tab << "std::optional<EmptyStruct&> maybe_test_struct_ref = t_1;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "> Not Working" << r2tm::linefeed;
			}

			LS();

			{
				std::optional<std::reference_wrapper<EmptyStruct>> maybe_test_struct_ref = t_1;
				std::cout << r2tm::tab << "std::optional<std::reference_wrapper<EmptyStruct>> maybe_test_struct_ref = t_1;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "> Working" << r2tm::linefeed2;

				maybe_test_struct_ref = t_2;
				std::cout << r2tm::tab << "maybe_test_struct_ref = t_2;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "> Working" << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}