#include "pch.h"
#include "lambda_test.h"

#include <cassert>
#include <memory>
#include <utility>

#include "r2cm/r2cm_eTestEndAction.h"

namespace lambda_test
{
	r2cm::iItem::TitleFuncT CaptureValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Value";
		};
	}
	r2cm::iItem::DoFuncT CaptureValue::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int i = 888;
				auto lambda_1 = [i]()
				{
					std::cout << i;
				};

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "int i = 888;" << r2::linefeed;
				std::cout << r2::tab2 << "auto lambda_1 = [i]()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "std::cout << i;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed2;

				std::cout << r2::tab << "+ Call Lambda" << r2::linefeed2;
				std::cout << r2::tab2 << "lambda_1();" << r2::linefeed2;

				std::cout << r2::tab2 << "> ";
				lambda_1();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Message" << r2::linefeed2;
				std::cout << r2::tab2 << "Captures Default to Const Value" << r2::linefeed;
				std::cout << r2::tab2 << "https://www.learncpp.com/cpp-tutorial/lambda-captures/" << r2::linefeed2;


				//int i = 0;
				//auto lambda_1 = [i]()
				//{
				//	++i;
				//};

				std::cout << r2::tab << "+ Not working this" << r2::linefeed2;
				std::cout << r2::tab2 << "int i = 0;" << r2::linefeed;
				std::cout << r2::tab2 << "auto lambda_1 = [i]()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "++i; // X - i is const" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
			}

			std::cout << r2::split;


			{
				int i = 0;
				auto lambda_1 = [i]()
				{
					std::cout << std::is_const<decltype( i )>::value ? "O" : "X";
				};

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "int i = 0;" << r2::linefeed;
				std::cout << r2::tab2 << "auto lambda_1 = [i]()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "std::cout << std::is_const<decltype( i )>::value ? \"O\" : \"X\";" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed2;

				std::cout << r2::tab << "+ Call Lambda" << r2::linefeed2;
				std::cout << r2::tab2 << "lambda_1();" << r2::linefeed2;

				std::cout << r2::tab2 << "> ";
				lambda_1();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT CaptureValueWithMutable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Value with Mutable";
		};
	}
	r2cm::iItem::DoFuncT CaptureValueWithMutable::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Mutable" << r2::linefeed << r2::linefeed;

				int i = 0;
				auto lambda_1 = [i]() mutable
				{
					++i;

					std::cout << r2::tab2 << "i : " << i << r2::linefeed;
				};

				std::cout << r2::tab2 << "int i = 0;" << r2::linefeed;
				std::cout << r2::tab2 << "auto lambda_1 = [i]() mutable" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "++i;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Call Lambda" << r2::linefeed;
				lambda_1();
				lambda_1();
				lambda_1();
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT CaptureReference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Reference";
		};
	}
	r2cm::iItem::DoFuncT CaptureReference::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ REF Capture 1" << r2::linefeed << r2::linefeed;

				int i = 0;
				int& ref_i = i;
				std::cout << r2::tab2 << "int i = 0;" << r2::linefeed;
				std::cout << r2::tab2 << "int& ref_i = i;" << r2::linefeed << r2::linefeed;

				auto test_func = [&ref_i]()
				{
					++ref_i;
				};
				std::cout << r2::tab2 << "auto test_func = [&ref_i]()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "++ref_i;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				std::cout << r2::tab2 << "- Call Lambda" << r2::linefeed;
				test_func();
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "- Print : i" << r2::linefeed;
				std::cout << r2::tab3 << i << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ REF Capture 2" << r2::linefeed << r2::linefeed;

				int i = 0;
				std::cout << r2::tab2 << "int i = 0;" << r2::linefeed << r2::linefeed;

				auto test_func = [&ref_i = i]()
				{
					++ref_i;
				};
				std::cout << r2::tab2 << "auto test_func = [&ref_i = i]()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "++ref_i;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				std::cout << r2::tab2 << "- Call Lambda" << r2::linefeed;
				test_func();
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "- Print : i" << r2::linefeed;
				std::cout << r2::tab3 << i << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT CaptureUniquePtr::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Unique Ptr";
		};
	}
	r2cm::iItem::DoFuncT CaptureUniquePtr::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Unique_Ptr Capture With Move 1" << r2::linefeed << r2::linefeed;

				auto test_up = std::unique_ptr<int>( new int() );
				std::cout << r2::tab2 << "auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2::linefeed;
				std::cout << r2::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				auto test_func = [moved_up = std::move( test_up )]() {};
				std::cout << r2::tab2 << "auto test_func = [moved_up = std::move( test_up )]() {}" << r2::linefeed;
				std::cout << r2::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Unique_Ptr Capture With Move 2" << r2::linefeed << r2::linefeed;

				struct TestStruct {};
				std::cout << r2::tab2 << "struct TestStruct;" << r2::linefeed << r2::linefeed;

				auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );
				std::cout << r2::tab2 << "auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2::linefeed;
				std::cout << r2::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				//
				// Not Working
				// - Not Same : std::function<void()> != auto
				//
				//std::function<void()> test_func = [moved_up = std::move( test_up )]() {};

				std::cout << r2::tab2 << "std::function<void()> test_func = [moved_up = std::move( test_up )]() {}" << r2::linefeed;
				std::cout << r2::tab3 << "- Not Working" << r2::linefeed;
				std::cout << r2::tab3 << "- Not Same : std::function<void()> != auto" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT CaptureValueWithAssign::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Capture Value with Assign";
		};
	}
	r2cm::iItem::DoFuncT CaptureValueWithAssign::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Capture with initialization" << r2::linefeed << r2::linefeed;

				auto lambda_1 = [i = 999]()
				{
					std::cout << r2::tab2 << "i : " << i << r2::linefeed;
				};

				std::cout << r2::tab2 << "auto lambda_1 = [i = 999]()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "std::cout << i << r2::linefeed;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Call Lambda" << r2::linefeed;
				lambda_1();
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Not working this" << r2::linefeed << r2::linefeed;

				//auto lambda_1 = [&i = 999]()
				//{
				//	std::cout << r2::tab2 << "i : " << i << r2::linefeed;
				//};

				std::cout << r2::tab2 << "auto lambda_1 = [&i = 999]()  // X - &i required lvalue" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "std::cout << i << r2::linefeed;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Capture with Change Value" << r2::linefeed << r2::linefeed;

				int i = 111;
				auto lambda_1 = [&i2 = i = 222]()
				{
					std::cout << r2::tab2 << "i2 : " << i2 << r2::linefeed;
				};

				std::cout << r2::tab2 << "int i = 111;" << r2::linefeed;
				std::cout << r2::tab2 << "auto lambda_1 = [&i2 = i = 222]()" << r2::linefeed;
				std::cout << r2::tab2 << "{" << r2::linefeed;
				std::cout << r2::tab3 << "std::cout << i2 << r2::linefeed;" << r2::linefeed;
				std::cout << r2::tab2 << "};" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Call Lambda" << r2::linefeed;
				lambda_1();
				std::cout << r2::tab2 << "i : " << i << r2::linefeed;
				std::cout << r2::linefeed;

				i = 777;
				std::cout << r2::tab2 << "i = 777;" << r2::linefeed2;

				std::cout << r2::tab << "+ Call Lambda" << r2::linefeed2;
				lambda_1();

				std::cout << r2::tab2 << "i : " << i << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}