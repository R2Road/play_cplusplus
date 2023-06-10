#include "various_debug_test.h"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <Windows.h>

#include "r2/r2_Assert.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"
#include "utility/r2utility_FileUtil.h"

namespace various_debug_test
{
#define ShowCodeInfo()											\
{																\
	std::cout << "File : " << __FILE__ << r2tm::linefeed;			\
	std::cout << "Function : " << __FUNCTION__ << r2tm::linefeed;	\
	std::cout << "Line : " << __LINE__ << r2tm::linefeed;			\
}

	r2tm::TitleFunctionT PredefinedMacro::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Predefined Macro";
		};
	}
	r2tm::DoFunctionT PredefinedMacro::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "#define ShowCodeInfo()" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "{" << r2tm::linefeed;
			std::cout << r2tm::tab3 << "std::cout << \"File : \" << __FILE__ << r2tm::linefeed;" << r2tm::linefeed;
			std::cout << r2tm::tab3 << "std::cout << \"Function : \" << __FUNCTION__ << r2tm::linefeed;" << r2tm::linefeed;
			std::cout << r2tm::tab3 << "std::cout << \"Line : \" << __LINE__ << r2tm::linefeed;" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "}" << r2tm::linefeed;

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "ShowCodeInfo();" << r2tm::linefeed2;

				ShowCodeInfo();
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT OutPutDebugString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "OutPutDebugString";
		};
	}
	r2tm::DoFunctionT OutPutDebugString::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "OutputDebugStringW( L\"What The Fuck\" );" << r2tm::linefeed;

				OutputDebugStringW( L"What The Fuck" );
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Has Some Problem" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "C1189 : #include <debugapi.h>" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "use <Windows.h> instead <debugapi.h>" << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Assertion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Assert";
		};
	}
	r2tm::DoFunctionT Assertion::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "assert( 1 > 2 && \"What The Fuck\" );" << r2tm::linefeed;

				std::cout << r2tm::split;
			}

			assert( 1 > 2 && "What The Fuck" );

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT DebugBreak::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Debug Break";
		};
	}
	r2tm::DoFunctionT DebugBreak::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "__debugbreak();" << r2tm::linefeed;

				__debugbreak();
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MyAssertion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MyAssertion";
		};
	}
	r2tm::DoFunctionT MyAssertion::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_FILE( "src/r2/r2_Assert.h" );

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;

				DECLARATION_MAIN( int a = 1 );
				DECLARATION_MAIN( int b = 2 );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( R2ASSERT( a > b, "What The Fuck" ) );

			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	const char* GetSimpleLogFilePath()
	{
		static std::string temp_string = r2utility::MakeOutPutPath( "debug_test__simple_log.txt" );
		return temp_string.c_str();
	}
	r2tm::TitleFunctionT SimpleLog::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Simple Log";
		};
	}
	r2tm::DoFunctionT SimpleLog::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			std::cout << r2tm::tab << "+ File Open" << r2tm::linefeed2;

			DECLARATION_MAIN( const char* const file_path = GetSimpleLogFilePath() );
			DECLARATION_MAIN( std::ofstream log_stream( file_path ) );

			std::cout << r2tm::split;

			std::cout << r2tm::tab << "+ Redirection" << r2tm::linefeed2;

			DECLARATION_MAIN( std::streambuf * const orig = std::cerr.rdbuf() );
			PROCESS_MAIN( std::cerr.rdbuf( log_stream.rdbuf() ) );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( std::cerr << "[Test]" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "std::cerr" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "redirection 2 file" );
			}

			std::cout << r2tm::split;

			{
				std::cout << r2tm::tab << "+ End" << r2tm::linefeed2;

				PROCESS_MAIN( std::cerr.set_rdbuf( orig ) );
				PROCESS_MAIN( log_stream.close() );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_FILE( file_path );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}