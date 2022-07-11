#include "std_function_test.h"

#include <functional>

#include "r2cm/r2cm_ostream.h"

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
}

namespace std_function_test
{
	r2cm::iItem::TitleFunctionT Equality_FunctionPointer_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Function Pointer 1";
		};
	}
	r2cm::iItem::DoFunctionT Equality_FunctionPointer_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;


			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "using FunctionPointerT = void(*)();" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "using STDFunctionT = std::function<void()>;" << r2cm::linefeed;


			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::function::target<T>()" << r2cm::linefeed2;

				STDFunctionT sf1 = TestFunction_1;
				auto fn_1 = sf1.target<void()>();
				auto fn_2 = sf1.target<void(*)()>();

				std::cout << r2cm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto fn_1 = sf1.target<void()>();" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "auto fn_2 = sf1.target<void(*)()>();" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "nullptr == fn_1" << r2cm::linefeed;
				if( nullptr == fn_1 )
				{
					std::cout << r2cm::tab3 << "- Is Null" << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- Convert Failed" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Null" << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "nullptr == fn_2" << r2cm::linefeed;
				if( nullptr == fn_2 )
				{
					std::cout << r2cm::tab3 << "- Is Null" << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- Convert Failed" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Null" << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Empty" << r2cm::linefeed2;

				STDFunctionT tf1;
				STDFunctionT tf2;

				std::cout << r2cm::tab2 << "STDFunctionT tf1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "STDFunctionT tf2;" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "tf1.target<FunctionPointerT>() == tf2.target<FunctionPointerT>()" << r2cm::linefeed;
				if( tf1.target<FunctionPointerT>() == tf2.target<FunctionPointerT>() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Equality_FunctionPointer_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Function Pointer 2";
		};
	}
	r2cm::iItem::DoFunctionT Equality_FunctionPointer_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;


			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "using FunctionPointerT = void(*)();" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "using STDFunctionT = std::function<void()>;" << r2cm::linefeed;


			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Not Empty" << r2cm::linefeed2;

				STDFunctionT sf1 = TestFunction_1;
				STDFunctionT sf2 = sf1;
				STDFunctionT sf3 = TestFunction_1;
				STDFunctionT sf4 = TestFunction_2;

				std::cout << r2cm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "STDFunctionT sf2 = sf1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "STDFunctionT sf3 = TestFunction_1;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "STDFunctionT sf4 = TestFunction_2;" << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>()" << r2cm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "sf1.target<FunctionPointerT>() == sf2.target<FunctionPointerT>()" << r2cm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf2.target<FunctionPointerT>() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal???" << r2cm::linefeed;

					std::cout << r2cm::tab3 << "- sf1.target<FunctionPointerT>() : " << sf1.target<FunctionPointerT>() << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- sf2.target<FunctionPointerT>() : " << sf2.target<FunctionPointerT>() << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- TestFunction_1 : " << TestFunction_1 << r2cm::linefeed2;

					std::cout << r2cm::tab3 << "- *sf1.target<FunctionPointerT>() : " << *sf1.target<FunctionPointerT>() << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- *sf2.target<FunctionPointerT>() : " << *sf2.target<FunctionPointerT>() << r2cm::linefeed;
					std::cout << r2cm::tab3 << "- &TestFunction_1 : " << &TestFunction_1 << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "( *sf1.target<FunctionPointerT>() ) == ( *sf3.target<FunctionPointerT>() )" << r2cm::linefeed;
				if( ( *sf1.target<FunctionPointerT>() ) == ( *sf3.target<FunctionPointerT>() ) )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed2;
				}

				std::cout << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "( *sf1.target<FunctionPointerT>() ) == ( *sf4.target<FunctionPointerT>() )" << r2cm::linefeed;
				if( ( *sf1.target<FunctionPointerT>() ) == ( *sf4.target<FunctionPointerT>() ) )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Equality_FunctionPointer_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Function Pointer 3";
		};
	}
	r2cm::iItem::DoFunctionT Equality_FunctionPointer_3::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;


			using FunctionPointerT = void(*)();
			using STDFunctionT = std::function<void()>;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "using FunctionPointerT = void(*)();" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "using STDFunctionT = std::function<void()>;" << r2cm::linefeed;


			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Hash" << r2cm::linefeed2;

				STDFunctionT sf1 = TestFunction_1;
				STDFunctionT sf2 = sf1;
				STDFunctionT sf3 = TestFunction_1;
				STDFunctionT sf4 = TestFunction_2;

				std::cout << r2cm::tab2 << "STDFunctionT sf1 = TestFunction_1;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- sf1.target_type().hash_code() : " << sf1.target_type().hash_code() << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "STDFunctionT sf2 = sf1;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- sf2.target_type().hash_code() : " << sf2.target_type().hash_code() << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "STDFunctionT sf3 = TestFunction_1;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- sf3.target_type().hash_code() : " << sf3.target_type().hash_code() << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "STDFunctionT sf4 = TestFunction_2;" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- sf4.target_type().hash_code() : " << sf4.target_type().hash_code() << r2cm::linefeed2;

				std::cout << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "sf1.target_type() == sf1.target_type()" << r2cm::linefeed;
				if( sf1.target_type() == sf1.target_type() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed2;
				}

				std::cout << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "sf1.target_type() == sf2.target_type()" << r2cm::linefeed;
				if( sf1.target_type() == sf2.target_type() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed2;
				}

				std::cout << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "sf1.target_type() == sf3.target_type()" << r2cm::linefeed;
				if( sf1.target_type() == sf3.target_type() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed2;
				}

				std::cout << r2cm::linefeed3;

				std::cout << r2cm::tab2 << "sf1.target_type() == sf4.target_type()" << r2cm::linefeed;
				if( sf1.target_type() == sf4.target_type() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed2;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_function_test
{
	r2cm::iItem::TitleFunctionT Equality_Lambda_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::function : Equality : Lambda 1";
		};
	}
	r2cm::iItem::DoFunctionT Equality_Lambda_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			using FunctionPointerT = void(*)( );
			using STDFunctionT = std::function<void()>;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "using FunctionPointerT = void(*)();" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "using STDFunctionT = std::function<void()>;" << r2cm::linefeed;


			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 람다로 초기화된 std::function 에서 람다의 함수 포인터를 꺼내오는 방법은 모르겠다." << r2cm::linefeed;
				std::cout << r2cm::tab << "+ 꺼내오지 못하니 비교도 할 수 없다." << r2cm::linefeed2;

				STDFunctionT sf1 = []() {};
				STDFunctionT sf2 = sf1;

				std::cout << r2cm::tab2 << "STDFunctionT sf1 = []() {};" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "STDFunctionT tf2 = sf1" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "nullptr == sf1.target<FunctionPointerT>()" << r2cm::linefeed;
				if( nullptr == sf1.target<FunctionPointerT>() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>()" << r2cm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed;
				}

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "sf1.target<FunctionPointerT>() == sf1.target<FunctionPointerT>()" << r2cm::linefeed;
				if( sf1.target<FunctionPointerT>() == sf2.target<FunctionPointerT>() )
				{
					std::cout << r2cm::tab3 << "- Is Equal" << r2cm::linefeed;
				}
				else
				{
					std::cout << r2cm::tab3 << "- Is Not Equal" << r2cm::linefeed;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}