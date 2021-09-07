#include "pch.h"
#include "lambda_test.h"

#include <cassert>
#include <memory>
#include <utility>

#include "base/r2_eTestResult.h"

namespace lambda_test
{
	r2::iTest::TitleFunc CaptureValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Value";
		};
	}
	r2::iTest::DoFunc CaptureValue::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Basic" << r2::linefeed << r2::linefeed;

				int i = 0;
				auto lambda_1 = [i]()
				{
					std::cout << "\t\t" << "i : " << i << r2::linefeed;
				};

				std::cout << "\t\t" << "int i = 0;" << r2::linefeed;
				std::cout << "\t\t" << "auto lambda_1 = [i]()" << r2::linefeed;
				std::cout << "\t\t" << "{" << r2::linefeed;
				std::cout << "\t\t\t" << "std::cout << i << r2::linefeed;" << r2::linefeed;
				std::cout << "\t\t" << "};" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t + " << "Call Lambda" << r2::linefeed;
				lambda_1();
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Captures Default to Const Value" << r2::linefeed << r2::linefeed;
				std::cout << "\t\t - " << "https://www.learncpp.com/cpp-tutorial/lambda-captures/" << r2::linefeed << r2::linefeed;
				std::cout << r2::linefeed;


				//int i = 0;
				//auto lambda_1 = [i]()
				//{
				//	++i;
				//};

				std::cout << "\t + " << "Not working this" << r2::linefeed << r2::linefeed;

				std::cout << "\t\t" << "int i = 0;" << r2::linefeed;
				std::cout << "\t\t" << "auto lambda_1 = [i]()" << r2::linefeed;
				std::cout << "\t\t" << "{" << r2::linefeed;
				std::cout << "\t\t\t" << "++i; // X - i is const" << r2::linefeed;
				std::cout << "\t\t" << "};" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Capture with initialization" << r2::linefeed << r2::linefeed;

				auto lambda_1 = [i = int( 999 )]()
				{
					std::cout << "\t\t" << "i : " << i << r2::linefeed;
				};

				std::cout << "\t\t" << "auto lambda_1 = [i = int( 999 )]()" << r2::linefeed;
				std::cout << "\t\t" << "{" << r2::linefeed;
				std::cout << "\t\t\t" << "std::cout << i << r2::linefeed;" << r2::linefeed;
				std::cout << "\t\t" << "};" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t + " << "Call Lambda" << r2::linefeed;
				lambda_1();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc CaptureValueWithMutable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Value with Mutable";
		};
	}
	r2::iTest::DoFunc CaptureValueWithMutable::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Mutable" << r2::linefeed << r2::linefeed;

				int i = 0;
				auto lambda_1 = [i]() mutable
				{
					++i;

					std::cout << "\t\t" << "i : " << i << r2::linefeed;
				};

				std::cout << "\t\t" << "int i = 0;" << r2::linefeed;
				std::cout << "\t\t" << "auto lambda_1 = [i]() mutable" << r2::linefeed;
				std::cout << "\t\t" << "{" << r2::linefeed;
				std::cout << "\t\t\t" << "++i;" << r2::linefeed;
				std::cout << "\t\t" << "};" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << "\t + " << "Call Lambda" << r2::linefeed;
				lambda_1();
				lambda_1();
				lambda_1();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc CaptureReference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Reference";
		};
	}
	r2::iTest::DoFunc CaptureReference::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "REF Capture 1" << r2::linefeed << r2::linefeed;

				int i = 0;
				int& ref_i = i;
				std::cout << "\t\t" << "int i = 0;" << r2::linefeed;
				std::cout << "\t\t" << "int& ref_i = i;" << r2::linefeed << r2::linefeed;

				auto test_func = [&ref_i]()
				{
					++ref_i;
				};
				std::cout << "\t\t" << "auto test_func = [&ref_i]()" << r2::linefeed;
				std::cout << "\t\t" << "{" << r2::linefeed;
				std::cout << "\t\t\t" << "++ref_i;" << r2::linefeed;
				std::cout << "\t\t" << "};" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				std::cout << "\t\t" << "- Call Lambda" << r2::linefeed;
				test_func();
				std::cout << r2::linefeed;

				std::cout << "\t\t" << "- Print : i" << r2::linefeed;
				std::cout << "\t\t\t" << i << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "REF Capture 2" << r2::linefeed << r2::linefeed;

				int i = 0;
				std::cout << "\t\t" << "int i = 0;" << r2::linefeed << r2::linefeed;

				auto test_func = [&ref_i = i]()
				{
					++ref_i;
				};
				std::cout << "\t\t" << "auto test_func = [&ref_i = i]()" << r2::linefeed;
				std::cout << "\t\t" << "{" << r2::linefeed;
				std::cout << "\t\t\t" << "++ref_i;" << r2::linefeed;
				std::cout << "\t\t" << "};" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				std::cout << "\t\t" << "- Call Lambda" << r2::linefeed;
				test_func();
				std::cout << r2::linefeed;

				std::cout << "\t\t" << "- Print : i" << r2::linefeed;
				std::cout << "\t\t\t" << i << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc CaptureUniquePtr::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Unique Ptr";
		};
	}
	r2::iTest::DoFunc CaptureUniquePtr::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Unique_Ptr Capture With Move 1" << r2::linefeed << r2::linefeed;

				struct TestStruct {};
				std::cout << "\t\t" << "struct TestStruct;" << r2::linefeed << r2::linefeed;

				auto test_struct_up = std::unique_ptr<TestStruct>( new TestStruct() );
				std::cout << "\t\t" << "auto test_struct_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2::linefeed;
				std::cout << "\t\t\t" << "test_struct_up Validation : " << ( nullptr != test_struct_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				auto test_func = [copied_up = std::move( test_struct_up )]() {};
				std::cout << "\t\t" << "auto test_func = [copied_up = std::move( test_struct_up )]() {}" << r2::linefeed;
				std::cout << "\t\t\t" << "test_struct_up Validation : " << ( nullptr != test_struct_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t + " << "Unique_Ptr Capture With Move 2" << r2::linefeed << r2::linefeed;

				struct TestStruct {};
				std::cout << "\t\t" << "struct TestStruct;" << r2::linefeed << r2::linefeed;

				auto test_struct_up = std::unique_ptr<TestStruct>( new TestStruct() );
				std::cout << "\t\t" << "auto test_struct_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2::linefeed;
				std::cout << "\t\t\t" << "test_struct_up Validation : " << ( nullptr != test_struct_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				//
				// Not Working
				// - Not Same : std::function<void()> != auto
				//
				//std::function<void()> test_func = [copied_up = std::move( test_struct_up )]() {};

				std::cout << "\t\t" << "std::function<void()> test_func = [copied_up = std::move( test_struct_up )]() {}" << r2::linefeed;
				std::cout << "\t\t\t" << "- Not Working" << r2::linefeed;
				std::cout << "\t\t\t" << "- Not Same : std::function<void()> != auto" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}