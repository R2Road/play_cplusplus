#include "play_debug.h"

#include <cassert>
#include <chrono>
#include <filesystem>
#include <fstream>

#define NOMINMAX
#include <Windows.h>

#include "r2/r2_assert.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"
#include "utility/play_cpp_utility_PathBuilder.h"

namespace play_debug
{
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
				OUT_SOURCE_READY_N_BEGIN;
#define ShowCodeInfo()                                          \
{                                                               \
	std::cout << "File : " << __FILE__ << r2tm::linefeed;		\
	std::cout << "Func : " << __FUNCTION__ << r2tm::linefeed;	\
	std::cout << "Line : " << __LINE__ << r2tm::linefeed;		\
}
				OUT_SOURCE_END;
			}

			LS();

			{
				OUT_SUBJECT( "Process" );

				LF();

				PROC_MAIN( ShowCodeInfo() );
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
				OUT_SUBJECT( "Visual Studio 의 ""출력창"" 에 메세지 출력" );

				LF();

				PROC_MAIN( OutputDebugStringW( L"What The Fuck" ) );
			}

			LS();

			{
				OUT_NOTE( "Has Some Problem" );

				LF();

				OUT_COMMENT( "C1189 : #include <debugapi.h>" );
				OUT_COMMENT( "use <Windows.h> instead <debugapi.h>" );
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

			OUT_SOURCE_READY_N_BEGIN;
			const auto P = []()->void
			{
				assert( 1 > 2 && "What The Fuck" );
			};
			OUT_SOURCE_END;

			LS();

			{
				OUT_SUBJECT( "키 누르면 위 람다 실행" );

				LF();

				WAIT_ANY_KEY;

				PROC_MAIN( P() );
			}

			LS();

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

			OUT_SOURCE_READY_N_BEGIN;
			const auto P = []()->void
			{
				__debugbreak();
			};
			OUT_SOURCE_END;

			LS();

			{
				OUT_SUBJECT( "키 누르면 위 람다 실행" );

				LF();

				WAIT_ANY_KEY;

				PROC_MAIN( P() );
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

			OUT_FILE( "external/r2/r2_assert.hpp" );

			LS();

			{
				DECL_MAIN( int a = 1 );
				DECL_MAIN( int b = 2 );

				LF();

				PROC_MAIN( R2ASSERT( a > b, "What The Fuck" ) );

			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	const char* GetSimpleLogFilePath()
	{
		static std::string temp_string = play_cpp_utility::BuildOutPutPath( "debug_test__simple_log.txt" );
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

			OUT_SUBJECT( "File Open" );

			LF();

			DECL_MAIN( const char* const file_path = GetSimpleLogFilePath() );
			DECL_MAIN( std::ofstream log_stream( file_path ) );

			LS();

			OUT_SUBJECT( "Redirection" );

			LF();

			DECL_MAIN( std::streambuf * const orig = std::cerr.rdbuf() );
			PROC_MAIN( std::cerr.rdbuf( log_stream.rdbuf() ) );

			LS();

			{
				OUT_SUBJECT( "Output Log" );

				LF();

				PROC_MAIN( std::cerr << "[Test] " );
				PROC_MAIN( std::cerr << std::chrono::system_clock::now().time_since_epoch().count() );
				PROC_MAIN( std::cerr << std::endl );
				PROC_MAIN( std::cerr << "std::cerr" );
				PROC_MAIN( std::cerr << std::endl );
				PROC_MAIN( std::cerr << "redirection 2 file" );
			}

			LS();

			{
				OUT_SUBJECT( "End" );

				LF();

				PROC_MAIN( std::cerr.set_rdbuf( orig ) );
				PROC_MAIN( log_stream.close() );
			}

			LS();

			{
				OUT_FILE( file_path );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}