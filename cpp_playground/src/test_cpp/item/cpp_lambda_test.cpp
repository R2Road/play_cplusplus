#include "cpp_lambda_test.h"
#include "cpp_lambda_test__helper__size_3.hpp"

#include <cassert>
#include <memory>
#include <utility>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace cpp_lambda_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "lambda 특성" );
			OUTPUT_COMMENT( "익명 클래스와 operator() 의 조합." );
			OUTPUT_COMMENT( "class의 this pointer를 capture 하면 friend 로 지정된다." );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto l = []() {}; );
				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto l = []()->int { return 1; }; );
				OUTPUT_VALUE( l() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto l = []( const int i )->int { return i; }; );
				OUTPUT_VALUE( l( 3 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT CaptureValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Value";
		};
	}
	r2cm::iItem::DoFunctionT CaptureValue::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 888 );
				DECLARATION_MAIN( auto l = [i]() { printf( "i : %d", i ); } );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "Captures Default to Const Value" );
				OUTPUT_NOTE( "https://www.learncpp.com/cpp-tutorial/lambda-captures/" );

				std::cout << r2cm::linefeed;

				//int i = 0;
				//auto lambda_1 = [i]()
				//{
				//	++i;
				//};

				std::cout << r2cm::tab << "+ Not working this" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "int i = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto lambda_1 = [i]()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "++i; // X - i is const" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
			}

			std::cout << r2cm::split;


			{
				int i = 0;
				auto lambda_1 = [i]()
				{
					std::cout << std::is_const<decltype( i )>::value ? "O" : "X";
				};

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "int i = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto lambda_1 = [i]()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "std::cout << std::is_const<decltype( i )>::value ? \"O\" : \"X\";" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Call Lambda" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "lambda_1();" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "> ";
				lambda_1();
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT CaptureValueWithMutable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Value with Mutable";
		};
	}
	r2cm::iItem::DoFunctionT CaptureValueWithMutable::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Mutable" << r2cm::linefeed << r2cm::linefeed;

				int i = 0;
				auto lambda_1 = [i]() mutable
				{
					++i;

					std::cout << r2cm::tab2 << "i : " << i << r2cm::linefeed;
				};

				std::cout << r2cm::tab2 << "int i = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto lambda_1 = [i]() mutable" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "++i;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Call Lambda" << r2cm::linefeed;
				lambda_1();
				lambda_1();
				lambda_1();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT CaptureReference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Reference";
		};
	}
	r2cm::iItem::DoFunctionT CaptureReference::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ REF Capture 1" << r2cm::linefeed << r2cm::linefeed;

				int i = 0;
				int& ref_i = i;
				std::cout << r2cm::tab2 << "int i = 0;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "int& ref_i = i;" << r2cm::linefeed << r2cm::linefeed;

				auto test_func = [&ref_i]()
				{
					++ref_i;
				};
				std::cout << r2cm::tab2 << "auto test_func = [&ref_i]()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "++ref_i;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
				std::cout << r2cm::linefeed << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call Lambda" << r2cm::linefeed;
				test_func();
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Print : i" << r2cm::linefeed;
				std::cout << r2cm::tab3 << i << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ REF Capture 2" << r2cm::linefeed << r2cm::linefeed;

				int i = 0;
				std::cout << r2cm::tab2 << "int i = 0;" << r2cm::linefeed << r2cm::linefeed;

				auto test_func = [&ref_i = i]()
				{
					++ref_i;
				};
				std::cout << r2cm::tab2 << "auto test_func = [&ref_i = i]()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "++ref_i;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
				std::cout << r2cm::linefeed << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Call Lambda" << r2cm::linefeed;
				test_func();
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Print : i" << r2cm::linefeed;
				std::cout << r2cm::tab3 << i << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT CaptureUniquePtr::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Unique Ptr";
		};
	}
	r2cm::iItem::DoFunctionT CaptureUniquePtr::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Unique_Ptr Capture With Move 1" << r2cm::linefeed << r2cm::linefeed;

				auto test_up = std::unique_ptr<int>( new int() );
				std::cout << r2cm::tab2 << "auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2cm::linefeed;
				std::cout << r2cm::linefeed << r2cm::linefeed;

				auto test_func = [moved_up = std::move( test_up )]() {};
				std::cout << r2cm::tab2 << "auto test_func = [moved_up = std::move( test_up )]() {}" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2cm::linefeed;
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Unique_Ptr Capture With Move 2" << r2cm::linefeed << r2cm::linefeed;

				struct TestStruct {};
				std::cout << r2cm::tab2 << "struct TestStruct;" << r2cm::linefeed << r2cm::linefeed;

				auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );
				std::cout << r2cm::tab2 << "auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2cm::linefeed;
				std::cout << r2cm::linefeed << r2cm::linefeed;

				//
				// Not Working
				// - Not Same : std::function<void()> != auto
				//
				//std::function<void()> test_func = [moved_up = std::move( test_up )]() {};

				std::cout << r2cm::tab2 << "std::function<void()> test_func = [moved_up = std::move( test_up )]() {}" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Not Working" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- Not Same : std::function<void()> != auto" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT CaptureValueWithAssign::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Value with Assign";
		};
	}
	r2cm::iItem::DoFunctionT CaptureValueWithAssign::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Capture with initialization" << r2cm::linefeed << r2cm::linefeed;

				auto lambda_1 = [i = 999]()
				{
					std::cout << r2cm::tab2 << "i : " << i << r2cm::linefeed;
				};

				std::cout << r2cm::tab2 << "auto lambda_1 = [i = 999]()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "std::cout << i << r2cm::linefeed;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Call Lambda" << r2cm::linefeed;
				lambda_1();
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Not working this" << r2cm::linefeed << r2cm::linefeed;

				//auto lambda_1 = [&i = 999]()
				//{
				//	std::cout << r2cm::tab2 << "i : " << i << r2cm::linefeed;
				//};

				std::cout << r2cm::tab2 << "auto lambda_1 = [&i = 999]()  // X - &i required lvalue" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "std::cout << i << r2cm::linefeed;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Capture with Change Value" << r2cm::linefeed << r2cm::linefeed;

				int i = 111;
				auto lambda_1 = [&i2 = i = 222]()
				{
					std::cout << r2cm::tab2 << "i2 : " << i2 << r2cm::linefeed;
				};

				std::cout << r2cm::tab2 << "int i = 111;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto lambda_1 = [&i2 = i = 222]()" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "std::cout << i2 << r2cm::linefeed;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "};" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Call Lambda" << r2cm::linefeed;
				lambda_1();
				std::cout << r2cm::tab2 << "i : " << i << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				i = 777;
				std::cout << r2cm::tab2 << "i = 777;" << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ Call Lambda" << r2cm::linefeed2;
				lambda_1();

				std::cout << r2cm::tab2 << "i : " << i << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Size_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size 1";
		};
	}
	r2cm::iItem::DoFunctionT Size_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto l = []() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto l = []() { int i = 0; i = 1; } );
				OUTPUT_VALUE( sizeof( l ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto l = [i = 0]() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto l = [ll = 0ll]() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Size_CopyCapture::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size - Copy Capture";
		};
	}
	r2cm::iItem::DoFunctionT Size_CopyCapture::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int64_t i = 1 );
				DECLARATION_MAIN( int64_t j = 255 );
				( i ); ( j ); // warning 제거
				DECLARATION_MAIN( auto l = [=]() {} );
				OUTPUT_VALUE( sizeof( l ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int64_t i = 1 );
				DECLARATION_MAIN( int64_t j = 255 );
				( j ); // warning 제거
				DECLARATION_MAIN( auto l = [=]() { std::cout << i << r2cm::linefeed; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "capture 했지만 사용하지 않은 변수들은 제거되는 모양이다. 스팩? 최적화?" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( int64_t i = 1 );
				DECLARATION_MAIN( int64_t j = 255 );
				DECLARATION_MAIN( auto l = [=]() { std::cout << i << j << r2cm::linefeed;; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Size_ReferenceCapture::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size - Reference Capture";
		};
	}
	r2cm::iItem::DoFunctionT Size_ReferenceCapture::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( struct S { int i = 1; int j = 255; int arr[10]; } );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( S s1 );
				DECLARATION_MAIN( S s2 );
				( s1 ); ( s2 ); // warning 제거
				DECLARATION_MAIN( auto l = [&]() {} );
				OUTPUT_VALUE( sizeof( l ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( S s1 );
				DECLARATION_MAIN( S s2 );
				( s2 ); // warning 제거
				DECLARATION_MAIN( auto l = [&]() { std::cout << s1.i << r2cm::linefeed; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "capture 했지만 사용하지 않은 변수들은 제거되는 모양이다. 스팩? 최적화?" );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( S s1 );
				DECLARATION_MAIN( S s2 );
				DECLARATION_MAIN( auto l = [&]() { std::cout << s1.i << s2.j << r2cm::linefeed;; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( l() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Size_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size 3";
		};
	}
	r2cm::iItem::DoFunctionT Size_3::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_lambda_test__helper__size_3.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_lambda_test__helper__size_3::S s );
				PROCESS_MAIN( s.Do() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}