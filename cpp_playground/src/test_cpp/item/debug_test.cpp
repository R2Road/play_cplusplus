#include "pch.h"
#include "debug_test.h"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <Windows.h>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"
#include "utility/r2utility_FileUtil.h"

namespace debug_test
{
#define ShowCodeInfo()											\
{																\
	std::cout << "File : " << __FILE__ << r2cm::linefeed;			\
	std::cout << "Function : " << __FUNCTION__ << r2cm::linefeed;	\
	std::cout << "Line : " << __LINE__ << r2cm::linefeed;			\
}

	r2cm::iItem::TitleFuncT PredefinedMacro::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Predefined Macro";
		};
	}
	r2cm::iItem::DoFuncT PredefinedMacro::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "#define ShowCodeInfo()" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "std::cout << \"File : \" << __FILE__ << r2cm::linefeed;" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "std::cout << \"Function : \" << __FUNCTION__ << r2cm::linefeed;" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "std::cout << \"Line : \" << __LINE__ << r2cm::linefeed;" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "}" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "ShowCodeInfo();" << r2cm::linefeed2;

				ShowCodeInfo();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT OutPutDebugString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "OutPutDebugString";
		};
	}
	r2cm::iItem::DoFuncT OutPutDebugString::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "OutputDebugStringW( L\"What The Fuck\" );" << r2cm::linefeed;

				OutputDebugStringW( L"What The Fuck" );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Has Some Problem" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "C1189 : #include <debugapi.h>" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "use <Windows.h> instead <debugapi.h>" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Assertion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Assert";
		};
	}
	r2cm::iItem::DoFuncT Assertion::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "assert( 1 > 2 && \"What The Fuck\" );" << r2cm::linefeed;

				std::cout << r2cm::split;
			}

			assert( 1 > 2 && "What The Fuck" );

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT DebugBreak::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Debug Break";
		};
	}
	r2cm::iItem::DoFuncT DebugBreak::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "__debugbreak();" << r2cm::linefeed;

				__debugbreak();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT MyAssertion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MyAssertion";
		};
	}
	r2cm::iItem::DoFuncT MyAssertion::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			SHOW_FILE( "src/r2/r2_Assert.h" );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;

				DECLARATION_MAIN( int a = 1 );
				DECLARATION_MAIN( int b = 2 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( R2ASSERT( a > b, "What The Fuck" ) );

			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	const char* GetSimpleLogFilePath()
	{
		static std::string temp_string = r2utility::MakeOutPutPath( "debug_test__simple_log.txt" );
		return temp_string.c_str();
	}
	r2cm::iItem::TitleFuncT SimpleLog::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Simple Log";
		};
	}
	r2cm::iItem::DoFuncT SimpleLog::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ File Open" << r2cm::linefeed2;

			DECLARATION_MAIN( const char* const file_path = GetSimpleLogFilePath() );
			DECLARATION_MAIN( std::ofstream log_stream( file_path ) );

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Redirection" << r2cm::linefeed2;

			DECLARATION_MAIN( std::streambuf * const orig = std::cerr.rdbuf() );
			PROCESS_MAIN( std::cerr.rdbuf( log_stream.rdbuf() ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( std::cerr << "[Test]" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "std::cerr" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "redirection 2 file" );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ End" << r2cm::linefeed2;

				PROCESS_MAIN( std::cerr.set_rdbuf( orig ) );
				PROCESS_MAIN( log_stream.close() );
			}

			std::cout << r2cm::split;

			{
				SHOW_FILE( file_path );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}