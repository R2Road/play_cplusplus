#include "pch.h"
#include "optional_test.h"

#include <functional>
#include <optional>

#include "r2_eTestResult.h"

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
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Optional : Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;


			std::cout << "\t+ Make Test Struct" << r2::linefeed;
			std::cout << "\t\t- TestStruct ts;" << r2::linefeed;
			std::cout << "\t\t\t";
			TestStruct ts;


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << "\t+ Make Optional" << r2::linefeed;
			std::cout << "\t\t- std::optional<TestStruct> op_ts;" << r2::linefeed;
			std::optional<TestStruct> op_ts;
			std::cout << "\t\t- Call : has_value()" << r2::linefeed;
			std::cout << "\t\t\t" << op_ts.has_value() << r2::linefeed;
			//std::cout << "\t\t\t" << op_ts.value().i << r2::linefeed; // throw exception : op_ts is nullopt


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << "\t+ Assign 2 Optional " << r2::linefeed;
			std::cout << "\t\t- op_ts = ts" << r2::linefeed;
			std::cout << "\t\t\t";
			op_ts = ts;
			std::cout << "\t\t- Call : has_value()" << r2::linefeed;
			std::cout << "\t\t\t" << op_ts.has_value() << r2::linefeed;


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << "\t+ Value() " << r2::linefeed;
			std::cout << "\t\t- op_ts.value().I;" << r2::linefeed;
			std::cout << "\t\t\t" << op_ts.value().I << r2::linefeed;


			std::cout << r2::linefeed << r2::linefeed;


			std::cout << "\t+ GetTestStruct() " << r2::linefeed;
			{
				std::cout << "\t\t- GetTestStruct( 0 );" << r2::linefeed;
				std::cout << "\t\t\t";
				const auto result = GetTestStruct( 0 );
				std::cout << "\t\t- Call : has_value()" << r2::linefeed;
				std::cout << "\t\t\t" << result.has_value() << r2::linefeed << r2::linefeed;
			}
			{
				std::cout << "\t\t- GetTestStruct( 1 );" << r2::linefeed;
				std::cout << "\t\t\t";
				const auto result = GetTestStruct( 1 );
				std::cout << "\t\t- Call : has_value()" << r2::linefeed;
				std::cout << "\t\t\t" << result.has_value() << r2::linefeed << r2::linefeed;
			}
			{
				std::cout << "\t\t- GetTestStruct( 2 );" << r2::linefeed;
				const auto result = GetTestStruct( 2 );
				std::cout << "\t\t- Call : has_value()" << r2::linefeed;
				std::cout << "\t\t\t" << result.has_value() << r2::linefeed << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;


			{
				std::cout << "\t+ Reference " << r2::linefeed;

				std::cout << "\t\t- TestStruct t_1;" << r2::linefeed;
				std::cout << "\t\t\t";
				TestStruct t_1;
				std::cout << r2::linefeed;

				std::cout << "\t\t- TestStruct t_2;" << r2::linefeed;
				std::cout << "\t\t\t";
				TestStruct t_2;
				std::cout << r2::linefeed;

				//
				//std::optional<TestStruct&> maybe_test_struct_ref = t_1;
				//
				std::cout << "\t\t- Not Working : std::optional<TestStruct&> maybe_test_struct_ref = t_1;" << r2::linefeed << r2::linefeed;

				std::optional<std::reference_wrapper<TestStruct>> maybe_test_struct_ref = t_1;
				std::cout << "\t\t- Working : std::optional<std::reference_wrapper<TestStruct>> maybe_test_struct_ref = t_1;" << r2::linefeed << r2::linefeed;

				maybe_test_struct_ref = t_2;
				std::cout << "\t\t- Working : maybe_test_struct_ref = t_2;" << r2::linefeed << r2::linefeed;
			}


			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}