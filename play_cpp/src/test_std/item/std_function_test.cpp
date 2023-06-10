#include "std_function_test.h"

#include <functional>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace
{
	void TestFunction_1()
	{
		std::cout << "TestFunction_1";
	}
	void TestFunction_2()
	{
		std::cout << "TestFunction_2";
	}

	void LocalFunction( int ) {}
}

namespace std_function_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "REF : https://en.cppreference.com/w/cpp/utility/functional/function" );

			LS();
			
			{
				DECLARATION_MAIN( std::function<void()> f );
				EXPECT_TRUE( nullptr == f );
				EXPECT_FALSE( f );
			}

			LS();

			{
				DECLARATION_MAIN( std::function<void()> f = TestFunction_1 );
				EXPECT_TRUE( nullptr != f );
				EXPECT_TRUE( f );
			}

			LS();

			{
				DECLARATION_MAIN( std::function<void()> f = []() {} );
				EXPECT_TRUE( nullptr != f );
				EXPECT_TRUE( f );
			}

			LS();

			{
				DECLARATION_MAIN( std::function<void()> f = std::bind( LocalFunction, 10 ) );
				EXPECT_TRUE( nullptr != f );
				EXPECT_TRUE( f );
			}

			LS();

			{
				DECLARATION_MAIN( struct S { void Do( int ) {} } );
				DECLARATION_MAIN( S s );
				DECLARATION_MAIN( std::function<void( S&, int )> f = &S::Do );
				EXPECT_TRUE( nullptr != f );
				EXPECT_TRUE( f );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( f( s, 1 ) );
			}

			LS();

			{
				DECLARATION_MAIN( struct S { int i = 1234; } );
				DECLARATION_MAIN( S s );
				DECLARATION_MAIN( std::function<int( S& )> f = &S::i );
				EXPECT_TRUE( nullptr != f );
				EXPECT_TRUE( f );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( f( s ) );
			}

			LS();

			{
				DECLARATION_MAIN( struct S { int operator()() { return 0; } } );
				DECLARATION_MAIN( std::function<int()> f = S() );
				EXPECT_TRUE( nullptr != f );
				EXPECT_TRUE( f );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( f() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Equality_FunctionPointer_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Function Pointer 1";
		};
	}
	r2tm::DoFunctionT Equality_FunctionPointer_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "using FunctionPointerT = void(*)();" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "using STDFunctionT = std::function<void()>;" << r2tm::linefeed;


			LS();

			{
				std::cout << r2tm::tab << "+ std::function::target<T>()" << r2tm::linefeed2;

				STDFunctionT sf1 = TestFunction_1;
				auto fn_1 = sf1.target<void()>();
				auto fn_2 = sf1.target<void(*)()>();

				std::cout << r2tm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "auto fn_1 = sf1.target<void()>();" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "auto fn_2 = sf1.target<void(*)()>();" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "nullptr == fn_1" << r2tm::linefeed;
				if( nullptr == fn_1 )
				{
					std::cout << r2tm::tab3 << "- Is Null" << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- Convert Failed" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Null" << r2tm::linefeed;
				}

				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab2 << "nullptr == fn_2" << r2tm::linefeed;
				if( nullptr == fn_2 )
				{
					std::cout << r2tm::tab3 << "- Is Null" << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- Convert Failed" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Null" << r2tm::linefeed;
				}
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Empty" << r2tm::linefeed2;

				STDFunctionT tf1;
				STDFunctionT tf2;

				std::cout << r2tm::tab2 << "STDFunctionT tf1;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "STDFunctionT tf2;" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "tf1.target<FunctionPointerT>() == tf2.target<FunctionPointerT>()" << r2tm::linefeed;
				if( tf1.target<FunctionPointerT>() == tf2.target<FunctionPointerT>() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Equality_FunctionPointer_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Function Pointer 2";
		};
	}
	r2tm::DoFunctionT Equality_FunctionPointer_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "using FunctionPointerT = void(*)();" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "using STDFunctionT = std::function<void()>;" << r2tm::linefeed;


			LS();

			{
				std::cout << r2tm::tab << "+ Not Empty" << r2tm::linefeed2;

				STDFunctionT sf1 = TestFunction_1;
				STDFunctionT sf2 = sf1;
				STDFunctionT sf3 = TestFunction_1;
				STDFunctionT sf4 = TestFunction_2;

				std::cout << r2tm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "STDFunctionT sf2 = sf1;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "STDFunctionT sf3 = TestFunction_1;" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "STDFunctionT sf4 = TestFunction_2;" << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>()" << r2tm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed;
				}

				std::cout << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "sf1.target<FunctionPointerT>() == sf2.target<FunctionPointerT>()" << r2tm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf2.target<FunctionPointerT>() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal???" << r2tm::linefeed;

					std::cout << r2tm::tab3 << "- sf1.target<FunctionPointerT>() : " << sf1.target<FunctionPointerT>() << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- sf2.target<FunctionPointerT>() : " << sf2.target<FunctionPointerT>() << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- TestFunction_1 : " << TestFunction_1 << r2tm::linefeed2;

					std::cout << r2tm::tab3 << "- *sf1.target<FunctionPointerT>() : " << *sf1.target<FunctionPointerT>() << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- *sf2.target<FunctionPointerT>() : " << *sf2.target<FunctionPointerT>() << r2tm::linefeed;
					std::cout << r2tm::tab3 << "- &TestFunction_1 : " << &TestFunction_1 << r2tm::linefeed;
				}

				std::cout << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "( *sf1.target<FunctionPointerT>() ) == ( *sf3.target<FunctionPointerT>() )" << r2tm::linefeed;
				if( ( *sf1.target<FunctionPointerT>() ) == ( *sf3.target<FunctionPointerT>() ) )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed2;
				}

				std::cout << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "( *sf1.target<FunctionPointerT>() ) == ( *sf4.target<FunctionPointerT>() )" << r2tm::linefeed;
				if( ( *sf1.target<FunctionPointerT>() ) == ( *sf4.target<FunctionPointerT>() ) )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Equality_FunctionPointer_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Function Pointer 3";
		};
	}
	r2tm::DoFunctionT Equality_FunctionPointer_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "using FunctionPointerT = void(*)();" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "using STDFunctionT = std::function<void()>;" << r2tm::linefeed;


			LS();

			{
				std::cout << r2tm::tab << "+ Hash" << r2tm::linefeed2;

				STDFunctionT sf1 = TestFunction_1;
				STDFunctionT sf2 = sf1;
				STDFunctionT sf3 = TestFunction_1;
				STDFunctionT sf4 = TestFunction_2;

				std::cout << r2tm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- sf1.target_type().hash_code() : " << sf1.target_type().hash_code() << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "STDFunctionT sf2 = sf1;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- sf2.target_type().hash_code() : " << sf2.target_type().hash_code() << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "STDFunctionT sf3 = TestFunction_1;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- sf3.target_type().hash_code() : " << sf3.target_type().hash_code() << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "STDFunctionT sf4 = TestFunction_2;" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "- sf4.target_type().hash_code() : " << sf4.target_type().hash_code() << r2tm::linefeed2;

				std::cout << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "sf1.target_type() == sf1.target_type()" << r2tm::linefeed;
				if( sf1.target_type() == sf1.target_type() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed2;
				}

				std::cout << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "sf1.target_type() == sf2.target_type()" << r2tm::linefeed;
				if( sf1.target_type() == sf2.target_type() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed2;
				}

				std::cout << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "sf1.target_type() == sf3.target_type()" << r2tm::linefeed;
				if( sf1.target_type() == sf3.target_type() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed2;
				}

				std::cout << r2tm::linefeed3;

				std::cout << r2tm::tab2 << "sf1.target_type() == sf4.target_type()" << r2tm::linefeed;
				if( sf1.target_type() == sf4.target_type() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed2;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace std_function_test
{
	r2tm::TitleFunctionT Equality_Lambda_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Lambda 1";
		};
	}
	r2tm::DoFunctionT Equality_Lambda_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			using FunctionPointerT = void(*)( );
			using STDFunctionT = std::function<void()>;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "using FunctionPointerT = void(*)();" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "using STDFunctionT = std::function<void()>;" << r2tm::linefeed;


			LS();

			{
				std::cout << r2tm::tab << "+ 람다로 초기화된 std::function 에서 람다의 함수 포인터를 꺼내오는 방법은 모르겠다." << r2tm::linefeed;
				std::cout << r2tm::tab << "+ 꺼내오지 못하니 비교도 할 수 없다." << r2tm::linefeed2;

				STDFunctionT sf1 = []() {};
				STDFunctionT sf2 = sf1;

				std::cout << r2tm::tab2 << "STDFunctionT sf1 = []() {};" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "STDFunctionT tf2 = sf1" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "nullptr == sf1.target<FunctionPointerT>()" << r2tm::linefeed;
				if( nullptr == sf1.target<FunctionPointerT>() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed;
				}

				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab2 << "sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>()" << r2tm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed;
				}

				std::cout << r2tm::linefeed;

				std::cout << r2tm::tab2 << "sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>()" << r2tm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf2.target<FunctionPointerT>() )
				{
					std::cout << r2tm::tab3 << "- Is Equal" << r2tm::linefeed;
				}
				else
				{
					std::cout << r2tm::tab3 << "- Is Not Equal" << r2tm::linefeed;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}