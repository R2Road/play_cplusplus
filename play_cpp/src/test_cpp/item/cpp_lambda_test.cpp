#include "cpp_lambda_test.h"
#include "cpp_lambda_test__helper__size_3.hpp"

#include <functional>
#include <memory>
#include <utility>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace cpp_lambda_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "lambda 특성" );
			OUTPUT_COMMENT( "익명 클래스와 operator() 의 조합." );
			OUTPUT_COMMENT( "class의 this pointer를 capture 하면 friend 로 지정된다." );

			LS();

			{
				DECLARATION_MAIN( auto l = []() {}; );
				PROCESS_MAIN( l() );
			}

			LS();

			{
				DECLARATION_MAIN( auto l = []()->int { return 1; }; );
				OUTPUT_VALUE( l() );
			}

			LS();

			{
				DECLARATION_MAIN( auto l = []( const int i )->int { return i; }; );
				OUTPUT_VALUE( l( 3 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CaptureValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Value";
		};
	}
	r2tm::DoFunctionT CaptureValue::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int i = 888 );
				DECLARATION_MAIN( auto l = [i]() { printf( "i : %d", i ); } );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( l() );
			}

			LS();

			{
				OUTPUT_NOTE( "Captures Default to Const Value" );
				OUTPUT_NOTE( "https://www.learncpp.com/cpp-tutorial/lambda-captures/" );

				std::cout << r2tm::linefeed;

				//int i = 0;
				//auto lambda_1 = [i]()
				//{
				//	++i;
				//};

				std::cout << r2tm::tab << "+ Not working this" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "int i = 0;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "auto lambda_1 = [i]()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "++i; // X - i is const" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
			}

			LS();


			{
				int i = 0;
				auto lambda_1 = [i]()
				{
					std::cout << std::is_const<decltype( i )>::value ? "O" : "X";
				};

				std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "int i = 0;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "auto lambda_1 = [i]()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "std::cout << std::is_const<decltype( i )>::value ? \"O\" : \"X\";" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed2;

				std::cout << r2tm::tab << "+ Call Lambda" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "lambda_1();" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "> ";
				lambda_1();
				std::cout << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CaptureValueWithMutable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Value with Mutable";
		};
	}
	r2tm::DoFunctionT CaptureValueWithMutable::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ Mutable" << r2tm::linefeed << r2tm::linefeed;

				int i = 0;
				auto lambda_1 = [i]() mutable
				{
					++i;

					std::cout << r2tm::tab2 << "i : " << i << r2tm::linefeed;
				};

				std::cout << r2tm::tab2 << "int i = 0;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "auto lambda_1 = [i]() mutable" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "++i;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Call Lambda" << r2tm::linefeed;
				lambda_1();
				lambda_1();
				lambda_1();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CaptureReference::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Reference";
		};
	}
	r2tm::DoFunctionT CaptureReference::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ REF Capture 1" << r2tm::linefeed << r2tm::linefeed;

				int i = 0;
				int& ref_i = i;
				std::cout << r2tm::tab2 << "int i = 0;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "int& ref_i = i;" << r2tm::linefeed << r2tm::linefeed;

				auto test_func = [&ref_i]()
				{
					++ref_i;
				};
				std::cout << r2tm::tab2 << "auto test_func = [&ref_i]()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "++ref_i;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
				std::cout << r2tm::linefeed << r2tm::linefeed;

				std::cout << r2tm::tab2 << "- Call Lambda" << r2tm::linefeed;
				test_func();
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab2 << "- Print : i" << r2tm::linefeed;
				std::cout << r2tm::tab3 << i << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ REF Capture 2" << r2tm::linefeed << r2tm::linefeed;

				int i = 0;
				std::cout << r2tm::tab2 << "int i = 0;" << r2tm::linefeed << r2tm::linefeed;

				auto test_func = [&ref_i = i]()
				{
					++ref_i;
				};
				std::cout << r2tm::tab2 << "auto test_func = [&ref_i = i]()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "++ref_i;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
				std::cout << r2tm::linefeed << r2tm::linefeed;

				std::cout << r2tm::tab2 << "- Call Lambda" << r2tm::linefeed;
				test_func();
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab2 << "- Print : i" << r2tm::linefeed;
				std::cout << r2tm::tab3 << i << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CaptureUniquePtr::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Unique Ptr";
		};
	}
	r2tm::DoFunctionT CaptureUniquePtr::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ Unique_Ptr Capture With Move 1" << r2tm::linefeed << r2tm::linefeed;

				auto test_up = std::unique_ptr<int>( new int() );
				std::cout << r2tm::tab2 << "auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2tm::linefeed;
				std::cout << r2tm::linefeed << r2tm::linefeed;

				auto test_func = [moved_up = std::move( test_up )]() {};
				std::cout << r2tm::tab2 << "auto test_func = [moved_up = std::move( test_up )]() {}" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2tm::linefeed;
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Unique_Ptr Capture With Move 2" << r2tm::linefeed << r2tm::linefeed;

				struct TestStruct {};
				std::cout << r2tm::tab2 << "struct TestStruct;" << r2tm::linefeed << r2tm::linefeed;

				auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );
				std::cout << r2tm::tab2 << "auto test_up = std::unique_ptr<TestStruct>( new TestStruct() );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "test_up Validation : " << ( nullptr != test_up.get() ? "O" : "X" ) << r2tm::linefeed;
				std::cout << r2tm::linefeed << r2tm::linefeed;

				//
				// Not Working
				// - Not Same : std::function<void()> != auto
				//
				//std::function<void()> test_func = [moved_up = std::move( test_up )]() {};

				std::cout << r2tm::tab2 << "std::function<void()> test_func = [moved_up = std::move( test_up )]() {}" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Not Working" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- Not Same : std::function<void()> != auto" << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CaptureValueWithAssign::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Capture Value with Assign";
		};
	}
	r2tm::DoFunctionT CaptureValueWithAssign::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ Capture with initialization" << r2tm::linefeed << r2tm::linefeed;

				auto lambda_1 = [i = 999]()
				{
					std::cout << r2tm::tab2 << "i : " << i << r2tm::linefeed;
				};

				std::cout << r2tm::tab2 << "auto lambda_1 = [i = 999]()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "std::cout << i << r2tm::linefeed;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Call Lambda" << r2tm::linefeed;
				lambda_1();
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Not working this" << r2tm::linefeed << r2tm::linefeed;

				//auto lambda_1 = [&i = 999]()
				//{
				//	std::cout << r2tm::tab2 << "i : " << i << r2tm::linefeed;
				//};

				std::cout << r2tm::tab2 << "auto lambda_1 = [&i = 999]()  // X - &i required lvalue" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "std::cout << i << r2tm::linefeed;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
				std::cout << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Capture with Change Value" << r2tm::linefeed << r2tm::linefeed;

				int i = 111;
				auto lambda_1 = [&i2 = i = 222]()
				{
					std::cout << r2tm::tab2 << "i2 : " << i2 << r2tm::linefeed;
				};

				std::cout << r2tm::tab2 << "int i = 111;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "auto lambda_1 = [&i2 = i = 222]()" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "std::cout << i2 << r2tm::linefeed;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "};" << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab << "+ Call Lambda" << r2tm::linefeed;
				lambda_1();
				std::cout << r2tm::tab2 << "i : " << i << r2tm::linefeed;
				std::cout << r2tm::linefeed;

				i = 777;
				std::cout << r2tm::tab2 << "i = 777;" << r2tm::linefeed2;

				std::cout << r2tm::tab << "+ Call Lambda" << r2tm::linefeed2;
				lambda_1();

				std::cout << r2tm::tab2 << "i : " << i << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size - Basic";
		};
	}
	r2tm::DoFunctionT Size_Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( auto l = []() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			LS();

			{
				DECLARATION_MAIN( auto l = []() { int i = 0; i = 1; } );
				OUTPUT_VALUE( sizeof( l ) );
			}

			LS();

			{
				DECLARATION_MAIN( auto l = [i = 0]() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			LS();

			{
				DECLARATION_MAIN( auto l = [ll = 0ll]() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_CopyCapture::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size - Copy Capture";
		};
	}
	r2tm::DoFunctionT Size_CopyCapture::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int64_t i = 1 );
				DECLARATION_MAIN( int64_t j = 255 );
				( i ); ( j ); // warning 제거
				DECLARATION_MAIN( auto l = [=]() {} );
				OUTPUT_VALUE( sizeof( l ) );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( l() );
			}

			LS();

			{
				DECLARATION_MAIN( int64_t i = 1 );
				DECLARATION_MAIN( int64_t j = 255 );
				( j ); // warning 제거
				DECLARATION_MAIN( auto l = [=]() { std::cout << i << r2tm::linefeed; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( l() );
			}

			LS();

			{
				OUTPUT_NOTE( "capture 했지만 사용하지 않은 변수들은 제거되는 모양이다. 스팩? 최적화?" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( int64_t i = 1 );
				DECLARATION_MAIN( int64_t j = 255 );
				DECLARATION_MAIN( auto l = [=]() { std::cout << i << j << r2tm::linefeed; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( l() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_ReferenceCapture::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size - Reference Capture";
		};
	}
	r2tm::DoFunctionT Size_ReferenceCapture::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( struct S { int i = 1; int j = 255; int arr[10]; } );

			LS();

			{
				DECLARATION_MAIN( S s1 );
				DECLARATION_MAIN( S s2 );
				( s1 ); ( s2 ); // warning 제거
				DECLARATION_MAIN( auto l = [&]() {} );
				OUTPUT_VALUE( sizeof( l ) );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( l() );
			}

			LS();

			{
				DECLARATION_MAIN( S s1 );
				DECLARATION_MAIN( S s2 );
				( s2 ); // warning 제거
				DECLARATION_MAIN( auto l = [&]() { std::cout << s1.i << r2tm::linefeed; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( l() );
			}

			LS();

			{
				OUTPUT_NOTE( "capture 했지만 사용하지 않은 변수들은 제거되는 모양이다. 스팩? 최적화?" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( S s1 );
				DECLARATION_MAIN( S s2 );
				DECLARATION_MAIN( auto l = [&]() { std::cout << s1.i << s2.j << r2tm::linefeed; } );
				OUTPUT_VALUE( sizeof( l ) );
				OUTPUT_BINARY( l );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( l() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size_ThisCapture::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size - This Capture";
		};
	}
	r2tm::DoFunctionT Size_ThisCapture::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "this capture는 익명 class 안에 this를 담는 멤버 변수가 하나 추가된다." );
				OUTPUT_NOTE( "람다 안에서 사용한 this는 capture 한 this로 여겨진다." );

				std::cout << r2tm::linefeed;

				OUTPUT_FILE( "src/test_cpp/item/cpp_lambda_test__helper__size_3.hpp" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( cpp_lambda_test__helper__size_3::S s );
				PROCESS_MAIN( s.Do() );
			}

			LS();

			{
				OUTPUT_NOTE( "람다 안에서 자신의 this pointer를 목표로한 this 사용이 안된다." );

				std::cout << r2tm::linefeed;

				OUTPUT_CODE( int i = 0 );
				OUTPUT_CODE( auto l = [=]() { std::cout << this->i << r2tm::linefeed; } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	void LocalFunction() {}
	r2tm::TitleFunctionT Size_With_STDFunction::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "lambda : Size with std::function";
		};
	}
	r2tm::DoFunctionT Size_With_STDFunction::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( auto l = []() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			LS();

			{
				DECLARATION_MAIN( std::function<void()> f = []() {} );
				OUTPUT_VALUE( sizeof( f ) );
			}

			LS();

			{
				DECLARATION_MAIN( auto l = [ll = 10ll]() {} );
				OUTPUT_VALUE( sizeof( l ) );
			}

			LS();

			{
				DECLARATION_MAIN( std::function<void()> f = [ll = 10ll]() {} );
				OUTPUT_VALUE( sizeof( f ) );
			}

			LS();

			{
				DECLARATION_MAIN( std::function<void()> f = LocalFunction );
				OUTPUT_VALUE( sizeof( f ) );
			}

			LS();

			{
				DECLARATION_MAIN( struct S
				{
					int i[100];
					void f() {}
				} );
				DECLARATION_MAIN( S s );
				DECLARATION_MAIN( std::function<void()> f = std::bind( &S::f, &s ) );
				OUTPUT_VALUE( sizeof( f ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}