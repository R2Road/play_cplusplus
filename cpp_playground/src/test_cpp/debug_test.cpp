#include "pch.h"
#include "debug_test.h"

#include <cassert>
#include <fstream>
#include <Windows.h>

#include "base/r2cm_eTestEndAction.h"
#include "r2/r2_Inspector.h"

namespace debug_test
{
#define ShowCodeInfo()											\
{																\
	std::cout << "File : " << __FILE__ << r2::linefeed;			\
	std::cout << "Function : " << __FUNCTION__ << r2::linefeed;	\
	std::cout << "Line : " << __LINE__ << r2::linefeed;			\
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
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
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

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "assert( 1 > 2 && \"What The Fuck\" );" << r2::linefeed;

				std::cout << r2::split;
			}

			assert( 1 > 2 && "What The Fuck" );

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "__debugbreak();" << r2::linefeed;

				__debugbreak();
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			SHOW_FILE( "src/r2/r2_Assert.h" );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Process" << r2::linefeed2;

				DECLARATION_MAIN( int a = 1 );
				DECLARATION_MAIN( int b = 2 );

				std::cout << r2::linefeed;

				PROCESS_MAIN( R2ASSERT( a > b, "What The Fuck" ) );

			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ File Open" << r2::linefeed2;

			DECLARATION_MAIN( const char* const file_path = "debug_test__simple_log.txt" );
			DECLARATION_MAIN( std::ofstream log_stream( file_path ) );

			std::cout << r2::split;

			std::cout << r2::tab << "+ Redirection" << r2::linefeed2;

			DECLARATION_MAIN( std::streambuf * const orig = std::cerr.rdbuf() );
			PROCESS_MAIN( std::cerr.rdbuf( log_stream.rdbuf() ) );

			std::cout << r2::split;

			{
				PROCESS_MAIN( std::cerr << "[Test]" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "std::cerr" );
				PROCESS_MAIN( std::cerr << std::endl );
				PROCESS_MAIN( std::cerr << "redirection 2 file" );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ End" << r2::linefeed2;

				PROCESS_MAIN( std::cerr.set_rdbuf( orig ) );
				PROCESS_MAIN( log_stream.close() );
			}

			std::cout << r2::split;

			{
				SHOW_FILE( file_path );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}