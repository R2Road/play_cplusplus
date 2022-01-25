#include "pch.h"
#include "optional_test.h"

#include <optional>

#include "base/r2_eTestResult.h"

namespace
{
	struct TestStruct
	{
		TestStruct() { std::cout << "- Call : TestStruct::TestStruct()" << r2::linefeed; }
		TestStruct( const int i ) : I( i ) { std::cout << "- Call : TestStruct::TestStruct( const int i )" << r2::linefeed; }
		TestStruct( const TestStruct& ) { std::cout << "- Call : TestStruct::TestStruct( const TestStruct& )" << r2::linefeed; }

		int I = 111;
	};

	static const TestStruct test_structs[2] = { { 222 }, { 333 } };

	std::optional<TestStruct> GetTestStruct( const std::size_t index )
	{
		if( 2 > index )
		{
			return test_structs[index];
		}
		else
		{
			return std::nullopt;
		}
	}
}
namespace optional_test
{
	r2::iTest::TitleFunc Basic_discard::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Basic( discard )";
		};
	}
	r2::iTest::DoFunc Basic_discard::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Make Test Struct" << r2::linefeed;
			std::cout << r2::tab2 << "- TestStruct ts;" << r2::linefeed;
			std::cout << r2::tab3;
			TestStruct ts;


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << r2::tab << "+ Make Optional" << r2::linefeed;
			std::cout << r2::tab2 << "- std::optional<TestStruct> op_ts;" << r2::linefeed;
			std::optional<TestStruct> op_ts;
			std::cout << r2::tab2 << "- Call : has_value()" << r2::linefeed;
			std::cout << r2::tab3 << op_ts.has_value() << r2::linefeed;
			//std::cout << r2::tab3 << op_ts.value().i << r2::linefeed; // throw exception : op_ts is nullopt


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << r2::tab << "+ Assign 2 Optional " << r2::linefeed;
			std::cout << r2::tab2 << "- op_ts = ts" << r2::linefeed;
			std::cout << r2::tab3;
			op_ts = ts;
			std::cout << r2::tab2 << "- Call : has_value()" << r2::linefeed;
			std::cout << r2::tab3 << op_ts.has_value() << r2::linefeed;


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << r2::tab << "+ Value() " << r2::linefeed;
			std::cout << r2::tab2 << "- op_ts.value().I;" << r2::linefeed;
			std::cout << r2::tab3 << op_ts.value().I << r2::linefeed;


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << r2::tab << "+ GetTestStruct() " << r2::linefeed;
			{
				std::cout << r2::tab2 << "- GetTestStruct( 0 );" << r2::linefeed;
				std::cout << r2::tab3;
				const auto result = GetTestStruct( 0 );
				std::cout << r2::tab2 << "- Call : has_value()" << r2::linefeed;
				std::cout << r2::tab3 << result.has_value() << r2::linefeed << r2::linefeed;
			}
			{
				std::cout << r2::tab2 << "- GetTestStruct( 1 );" << r2::linefeed;
				std::cout << r2::tab3;
				const auto result = GetTestStruct( 1 );
				std::cout << r2::tab2 << "- Call : has_value()" << r2::linefeed;
				std::cout << r2::tab3 << result.has_value() << r2::linefeed << r2::linefeed;
			}
			{
				std::cout << r2::tab2 << "- GetTestStruct( 2 );" << r2::linefeed;
				const auto result = GetTestStruct( 2 );
				std::cout << r2::tab2 << "- Call : has_value()" << r2::linefeed;
				std::cout << r2::tab3 << result.has_value() << r2::linefeed << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << r2::tab << "+ Reference " << r2::linefeed;

				std::cout << r2::tab2 << "- TestStruct t_1;" << r2::linefeed;
				std::cout << r2::tab3;
				TestStruct t_1;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "- TestStruct t_2;" << r2::linefeed;
				std::cout << r2::tab3;
				TestStruct t_2;
				std::cout << r2::linefeed;

				//
				//std::optional<TestStruct&> maybe_test_struct_ref = t_1;
				//
				std::cout << r2::tab2 << "- Not Working : std::optional<TestStruct&> maybe_test_struct_ref = t_1;" << r2::linefeed << r2::linefeed;

				std::optional<std::reference_wrapper<TestStruct>> maybe_test_struct_ref = t_1;
				std::cout << r2::tab2 << "- Working : std::optional<std::reference_wrapper<TestStruct>> maybe_test_struct_ref = t_1;" << r2::linefeed << r2::linefeed;

				maybe_test_struct_ref = t_2;
				std::cout << r2::tab2 << "- Working : maybe_test_struct_ref = t_2;" << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}