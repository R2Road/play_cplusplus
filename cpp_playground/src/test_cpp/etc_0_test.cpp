#include "pch.h"
#include "etc_0_test.h"

#include <list>
#include <numeric> // std::iota

#include "base/r2_eTestResult.h"

namespace etc_test
{
	r2::iTest::TitleFunc XOR_Swap::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XOR Swap";
		};
	}
	r2::iTest::DoFunc XOR_Swap::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int a = 123;
				int b = 456;

				std::cout << r2::tab << "int a = 123;" << r2::linefeed;
				std::cout << r2::tab << "int b = 456;" << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				a = a ^ b;
				std::cout << r2::tab << "a = a ^ b;" << r2::linefeed;
				std::cout << r2::tab2 << "a : " << a << r2::linefeed;
				std::cout << r2::linefeed;

				b = b ^ a;
				std::cout << r2::tab << "b = b ^ a;" << r2::linefeed;
				std::cout << r2::tab2 << "b : " << b << r2::linefeed;
				std::cout << r2::linefeed;

				a = a ^ b;
				std::cout << r2::tab << "a = a ^ b;" << r2::linefeed;
				std::cout << r2::tab2 << "a : " << a << r2::linefeed;
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}

namespace etc_test
{
	r2::iTest::TitleFunc InitArray::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Init Array";
		};
	}
	r2::iTest::DoFunc InitArray::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int array[10];
				std::cout << r2::tab2 << "int array[10];" << r2::linefeed;

				std::cout << r2::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int array[10] = { 0, };
				std::cout << r2::tab2 << "int array[10] = { 0, };" << r2::linefeed;

				std::cout << r2::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int array[10] = { '\0', };
				std::cout << r2::tab2 << "int array[10] = { \'\\0\', };" << r2::linefeed;

				std::cout << r2::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				int array[10] = {};
				std::cout << r2::tab2 << "int array[10] = {};" << r2::linefeed;

				std::cout << r2::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}

namespace etc_test
{
	r2::iTest::TitleFunc FillSequenceNumber::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Fill Container";
		};
	}
	r2::iTest::DoFunc FillSequenceNumber::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::list<int> temp_list( 10, 0 );

				std::cout << r2::tab << "+ Variable" << r2::linefeed;
				std::cout << r2::tab2 << "std::list<int> temp_list( 10, 0 );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::iota( temp_list.begin(), temp_list.end(), 11 ); // fill : 0, 1, 2, 3, 4 ......

				std::cout << r2::tab << "+ Process" << r2::linefeed;
				std::cout << r2::tab2 << "std::iota( temp_list.begin(), temp_list.end(), 11 )" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Result" << r2::linefeed;
				std::cout << r2::tab2;
				for( auto i : temp_list )
				{
					std::cout << i << r2::tab;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}

namespace etc_test
{
#define MACRO2STRING( x ) #x

	r2::iTest::TitleFunc Macro2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Macro 2 String";
		};
	}
	r2::iTest::DoFunc Macro2String::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int test_int = 3456;

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "#define MACRO2STRING( x ) #x" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "int test_int = " << test_int << ";" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << MACRO2STRING( test_int ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}


#define ShowCodeInfo()	\
{	\
	std::cout << "File : " << __FILE__ << r2::linefeed;	\
	std::cout << "Function : " << __FUNCTION__ << r2::linefeed;	\
	std::cout << "Line : " << __LINE__ << r2::linefeed;	\
}

	r2::iTest::TitleFunc MacroShowCodeInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Macro Show Code Info";
		};
	}
	r2::iTest::DoFunc MacroShowCodeInfo::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "#define MACRO2STRING( x ) #x" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				ShowCodeInfo();
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}