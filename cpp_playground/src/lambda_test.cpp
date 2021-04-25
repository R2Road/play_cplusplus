#include "pch.h"
#include "lambda_test.h"

#include <cassert>
#include <functional>
#include <memory>
#include <utility>

#include "r2_eTestResult.h"

namespace lambda_test
{
	const r2::iNode::TitleFunc Capture::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lamabda : Basic";
		};
	}

	const r2::iNode::DoFunc Capture::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "REF Capture" << r2::linefeed << r2::linefeed;

				int i = 0;
				std::cout << "\t\t" << "int i = 0;" << r2::linefeed << r2::linefeed;

				const std::function<void()> test_func = [ &temp_int = i]()
				{
					++temp_int;
				};
				std::cout << "\t\t" << "const std::function<void()> test_func = [&temp_int = i]()" << r2::linefeed;
				std::cout << "\t\t\t" << "++temp_int;" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				std::cout << "\t\t" << "- Call Lambda" << r2::linefeed;
				test_func();
				std::cout << r2::linefeed;

				std::cout << "\t\t" << "- Print : i" << r2::linefeed;
				std::cout << "\t\t\t" << i << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Pointer Capture" << r2::linefeed << r2::linefeed;

				int i = 0;
				int* pI = &i;
				std::cout << "\t\t" << "int i = 0;" << r2::linefeed;
				std::cout << "\t\t" << "int* pI = &i;" << r2::linefeed;
				std::cout << r2::linefeed;

				const std::function<void()> test_func = [&temp_int = pI]()
				{
					++( *temp_int );
				};
				std::cout << "\t\t" << "const std::function<void()> test_func = [&temp_int = i]()" << r2::linefeed;
				std::cout << "\t\t\t" << "++( *temp_int );" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				std::cout << "\t\t" << "- Call Lambda" << r2::linefeed;
				test_func();
				std::cout << r2::linefeed;

				std::cout << "\t\t" << "- Print : i" << r2::linefeed;
				std::cout << "\t\t\t" << i << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Unique_Ptr Capture With Move" << r2::linefeed << r2::linefeed;

				struct TestStruct
				{
					TestStruct()
					{
						std::cout << "\t\t" << "Constructor" << r2::linefeed;
					}
					~TestStruct()
					{
						std::cout << "\t\t" << "Destructor" << r2::linefeed;
					}
				};
				std::cout << "\t\t" << "struct TestStruct;" << r2::linefeed << r2::linefeed;

				auto test_struct_up = std::unique_ptr<TestStruct>( new TestStruct() );
				std::cout << "\t\t" << "auto test_struct_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2::linefeed;
				std::cout << "\t\t\t" << "test_struct_up Validation : " << ( nullptr != test_struct_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed;

				auto test_func = [copied_up = std::move( test_struct_up )]() {};
				std::cout << "\t\t" << "const std::function<void()> test_func = [copied_up = std::move( test_struct_up )]() {}" << r2::linefeed;
				std::cout << "\t\t\t" << "test_struct_up Validation : " << ( nullptr != test_struct_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}