#include "pch.h"
#include "debug_test.h"

#include <cassert>
#include <Windows.h>

#include "base/r2_eTestResult.h"

namespace debug_test
{
#define ShowCodeInfo()											\
{																\
	std::cout << "File : " << __FILE__ << r2::linefeed;			\
	std::cout << "Function : " << __FUNCTION__ << r2::linefeed;	\
	std::cout << "Line : " << __LINE__ << r2::linefeed;			\
}

	r2::iTest::TitleFunc PredefinedMacro::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Predefined Macro";
		};
	}
	r2::iTest::DoFunc PredefinedMacro::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "#define ShowCodeInfo()" << r2::linefeed;
			std::cout << r2::tab2 << "{" << r2::linefeed;
			std::cout << r2::tab3 << "std::cout << \"File : \" << __FILE__ << r2::linefeed;" << r2::linefeed;
			std::cout << r2::tab3 << "std::cout << \"Function : \" << __FUNCTION__ << r2::linefeed;" << r2::linefeed;
			std::cout << r2::tab3 << "std::cout << \"Line : \" << __LINE__ << r2::linefeed;" << r2::linefeed;
			std::cout << r2::tab2 << "}" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "ShowCodeInfo();" << r2::linefeed2;

				ShowCodeInfo();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc OutPutDebugString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "OutPutDebugString";
		};
	}
	r2::iTest::DoFunc OutPutDebugString::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "OutputDebugStringW( L\"What The Fuck\" );" << r2::linefeed;

				OutputDebugStringW( L"What The Fuck" );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Has Some Problem" << r2::linefeed2;
				std::cout << r2::tab2 << "C1189 : #include <debugapi.h>" << r2::linefeed;
				std::cout << r2::tab2 << "use <Windows.h> instead <debugapi.h>" << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc Assertion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Assert";
		};
	}
	r2::iTest::DoFunc Assertion::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "assert( 1 > 2 && \"What The Fuck\" );" << r2::linefeed;

				std::cout << r2::split;
			}

			assert( 1 > 2 && "What The Fuck" );

			return r2::eTestResult::RunTest;
		};
	}



	r2::iTest::TitleFunc DebugBreak::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Debug Break";
		};
	}
	r2::iTest::DoFunc DebugBreak::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "__debugbreak();" << r2::linefeed;

				__debugbreak();
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



#define	MyAssert( cond, message )					\
do {												\
	if( !( cond ) )									\
	{												\
		__debugbreak();								\
		printf( "+ MyAssert" "\nMessage : %s" "\nFile : %s" "\nLine : %d" "\nFunction : %s", message, __FILE__, __LINE__, __FUNCTION__ ); \
		throw std::runtime_error( message );		\
	}												\
} while( false )

	r2::iTest::TitleFunc MyAssertion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MyAssertion";
		};
	}
	r2::iTest::DoFunc MyAssertion::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
			std::cout << r2::tab2 << "#define	MyAssert( cond, message )" << r2::linefeed;
			std::cout << r2::tab2 << "do {" << r2::linefeed;
			std::cout << r2::tab3 << "if( !( cond ) )	" << r2::linefeed;
			std::cout << r2::tab3 << "{" << r2::linefeed;
			std::cout << r2::tab4 << "__debugbreak();" << r2::linefeed;
			std::cout << r2::tab4 << "printf( ... );" << r2::linefeed;
			std::cout << r2::tab4 << "throw std::runtime_error( message );" << r2::linefeed;
			std::cout << r2::tab3 << "}" << r2::linefeed;
			std::cout << r2::tab2 << "} while( false )" << r2::linefeed3;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "int a = 1;" << r2::linefeed;
				std::cout << r2::tab2 << "int b = 2;" << r2::linefeed;
				std::cout << r2::tab2 << "MyAssert( a > b, \"What The Fuck\" );" << r2::linefeed;
				std::cout << r2::linefeed;

				int a = 1;
				int b = 2;
				MyAssert( a > b, "What The Fuck" );

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}