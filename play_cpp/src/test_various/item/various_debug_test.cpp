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
#define ShowCodeInfo()	\
{	\
	std::cout << "File : " << __FILE__ << r2tm::linefeed;		\
	std::cout << "Func : " << __FUNCTION__ << r2tm::linefeed;	\
	std::cout << "Line : " << __LINE__ << r2tm::linefeed;		\
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
			LS();

			{
				OUTPUT_FILE_RANGE( "src/test_various/item/various_debug_test.cpp", 15, 20 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Process" );

				LF();

				PROCESS_MAIN( ShowCodeInfo() );
			}

			LS();

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
			LS();

			{
				OUTPUT_SUBJECT( "Visual Studio 의 ""출력창"" 에 메세지 출력" );

				LF();

				PROCESS_MAIN( OutputDebugStringW( L"What The Fuck" ) );
			}

			LS();

			{
				OUTPUT_NOTE( "Has Some Problem" );

				LF();

				OUTPUT_COMMENT( "C1189 : #include <debugapi.h>" );
				OUTPUT_COMMENT( "use <Windows.h> instead <debugapi.h>" );
			}

			LS();

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
			LS();

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "assert( 1 > 2 && \"What The Fuck\" );" << r2tm::linefeed;

				LS();
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
			LS();

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "__debugbreak();" << r2tm::linefeed;

				__debugbreak();
			}

			LS();

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
			LS();

			OUTPUT_FILE( "src/r2/r2_Assert.h" );

			LS();

			{
				std::cout << r2tm::tab << "+ Process" << r2tm::linefeed2;

				DECLARATION_MAIN( int a = 1 );
				DECLARATION_MAIN( int b = 2 );

				LF();

				PROCESS_MAIN( R2ASSERT( a > b, "What The Fuck" ) );

			}

			LS();

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
			LS();

			std::cout << r2tm::tab << "+ File Open" << r2tm::linefeed2;

			DECLARATION_MAIN( const char* const file_path = GetSimpleLogFilePath() );
			DECLARATION_MAIN( std::ofstream log_stream( file_path ) );

			LS();

			std::cout << r2tm::tab << "+ Redirection" << r2tm::linefeed2;

			DECLARATION_MAIN( std::streambuf * const orig = std::cerr.rdbuf() );
			PROCESS_MAIN( std::cerr.rdbuf( log_stream.rdbuf() ) );

			LS();

			{
				PROCESS_MAIN( std::cerr << "[Test]" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "std::cerr" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "redirection 2 file" );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ End" << r2tm::linefeed2;

				PROCESS_MAIN( std::cerr.set_rdbuf( orig ) );
				PROCESS_MAIN( log_stream.close() );
			}

			LS();

			{
				OUTPUT_FILE( file_path );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}