#include "std_optional_test.h"

#include <optional>

#include "r2cm/r2cm_ostream.h"

namespace std_optional_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Message : " "Optional Use Placement New" << r2cm::linefeed;

			std::cout << r2cm::split;

			struct TestOptional { int i = 8; };
			std::optional<TestOptional> op_ts;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "struct TestOptional { int i = 8; };" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "std::optional<TestOptional> op_ts;" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process 1" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_ts.has_value();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << op_ts.has_value() << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "Message : " << "op_ts.value()" " > throw exception : op_ts is nullopt" << r2cm::linefeed2;

				op_ts = TestOptional{};

				std::cout << r2cm::tab << "+ Process 2" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_ts = TestOptional{};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "op_ts.has_value();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << op_ts.has_value() << r2cm::linefeed;
				std::cout << r2cm::tab2 << "op_ts.value().i;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << op_ts.value().i << r2cm::linefeed2;

				op_ts.reset();

				std::cout << r2cm::tab << "+ Process 3" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_ts.reset();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "op_ts.has_value();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << op_ts.has_value() << r2cm::linefeed2;

				op_ts = TestOptional{};
				op_ts = std::nullopt;

				std::cout << r2cm::tab << "+ Process 4" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_ts = TestOptional{};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "op_ts = std::nullopt;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "op_ts.has_value();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << op_ts.has_value() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	struct TestOptional
	{
		TestOptional()
		{
			std::cout << "> Call : TestOptional()" << r2cm::tab;
		}
		TestOptional( const int )
		{
			std::cout << "> Call : TestOptional( const int i )" << r2cm::tab;
		}
		TestOptional( const TestOptional& )
		{
			std::cout << "> Call : TestOptional( const TestStruct& )" << r2cm::tab;
		}
		TestOptional( TestOptional&& )
		{
			std::cout << "> Call : TestOptional( TestStruct&& )" << r2cm::tab;
		}

		TestOptional& operator=( const TestOptional& )
		{
			std::cout << "> Call : TestOptional& operator=( const TestOptional& )" << r2cm::tab;
			return *this;
		}

		int i = 8;
	};
	std::optional<TestOptional> GetTestOptional()
	{
		return std::optional<TestOptional>( TestOptional{} );
	}
	r2cm::iItem::TitleFunctionT Constructor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Constructor";
		};
	}
	r2cm::iItem::DoFunctionT Constructor::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::optional<TestOptional> op_1;
			std::optional<TestOptional> op_2;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "struct TestOptional;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "std::optional<TestOptional> op_1;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "std::optional<TestOptional> op_2;" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process 1" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_1 = op_2;" << r2cm::linefeed;
				std::cout << r2cm::tab3;
				op_1 = op_2;
				std::cout << "> Nothing";
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process 2" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_1 = TestOptional{};" << r2cm::linefeed;
				std::cout << r2cm::tab3;
				op_1 = TestOptional{};
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process 3" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_2 = op_1;" << r2cm::linefeed;
				std::cout << r2cm::tab3;
				op_2 = op_1;
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process 4" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::optional<TestOptional> temp_op = op_1;" << r2cm::linefeed;
				std::cout << r2cm::tab3;
				std::optional<TestOptional> temp_op = op_1;
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process 5" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "op_1 = GetTestOptional();" << r2cm::linefeed;
				std::cout << r2cm::tab3;
				op_1 = GetTestOptional();
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process 5" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::optional<TestOptional> temp_op = GetTestOptional();" << r2cm::linefeed;
				std::cout << r2cm::tab3;
				std::optional<TestOptional> temp_op = GetTestOptional();
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Reference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Reference";
		};
	}
	r2cm::iItem::DoFunctionT Reference::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			struct EmptyStruct {};
			EmptyStruct t_1;
			EmptyStruct t_2;

			std::cout << r2cm::tab << "+ Declaration " << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "struct EmptyStruct {};" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "EmptyStruct t_1;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "EmptyStruct t_2;" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				//
				//std::optional<EmptyStruct&> maybe_test_struct_ref = t_1;
				//
				std::cout << r2cm::tab << "std::optional<EmptyStruct&> maybe_test_struct_ref = t_1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "> Not Working" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::optional<std::reference_wrapper<EmptyStruct>> maybe_test_struct_ref = t_1;
				std::cout << r2cm::tab << "std::optional<std::reference_wrapper<EmptyStruct>> maybe_test_struct_ref = t_1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "> Working" << r2cm::linefeed2;

				maybe_test_struct_ref = t_2;
				std::cout << r2cm::tab << "maybe_test_struct_ref = t_2;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "> Working" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}