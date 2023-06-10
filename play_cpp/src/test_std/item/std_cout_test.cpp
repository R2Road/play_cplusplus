#include "std_cout_test.h"

#include <iomanip> // Manipulator : 조작자, 조정자

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace std_cout_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				PROCESS_MAIN( std::cout << "1234" "5678" "90" );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( std::cout.write( "1234" "5678" "90", 6 ) );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( std::cout.write( "1234", 6 ) );
				LF();
				std::cout << r2tm::tab << "+ 출력할 문자의 숫자가 문자열의 길이를 넘어가도 터지지 않는다." << r2tm::linefeed;
				std::cout << r2tm::tab << "+ 내부에 예외 처리를 위한 try-catch 구문이 있다." << r2tm::linefeed;

				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FMTStatus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "FMTStatus";
		};
	}
	r2tm::DoFunctionT FMTStatus::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "+ Note : 표기 방식등의 Format은 유지된다." << r2tm::linefeed;

			LS();

			std::cout << r2tm::tab << "+ Status Save" << r2tm::linefeed2;

			DECLARATION_MAIN( std::ios last_fmt( nullptr ) );
			PROCESS_MAIN( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				std::cout << r2tm::tab << "+ Format" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::hex; );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Test 1" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << 10 << r2tm::linefeed );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Status Rollback" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Test 2" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << 10 << r2tm::linefeed );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT NumberFormat_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 1";
		};
	}
	r2tm::DoFunctionT NumberFormat_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				std::cout << r2tm::tab << "+ std::oct, hex, dec" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::oct << 10 << r2tm::linefeed );
				PROCESS_MAIN( std::cout << std::hex << 10 << r2tm::linefeed );
				PROCESS_MAIN( std::cout << std::dec << 10 << r2tm::linefeed );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ std::showbase" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::showbase );

				LF();

				PROCESS_MAIN( std::cout << std::oct << 10 << r2tm::linefeed );
				PROCESS_MAIN( std::cout << std::hex << 10 << r2tm::linefeed );
				PROCESS_MAIN( std::cout << std::dec << 10 << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT NumberFormat_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 2";
		};
	}
	r2tm::DoFunctionT NumberFormat_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				std::cout << r2tm::tab << "+ std::showpos : show positive : 10진수 양수에 + 를 표시 한다." << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::showpos );

				LF();

				PROCESS_MAIN( std::cout << 10 << r2tm::linefeed );

				LF();

				PROCESS_MAIN( std::cout << std::noshowpos );

				LF();

				PROCESS_MAIN( std::cout << 10 << r2tm::linefeed );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ std::uppercase : 16진수의 영문자를 대문자 표기로 바꾼다." << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::showbase );
				PROCESS_MAIN( std::cout << std::uppercase );

				LF();

				PROCESS_MAIN( std::cout << std::hex << 10 << r2tm::linefeed );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::nouppercase );

				LF();

				PROCESS_MAIN( std::cout << std::hex << 10 << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT NumberFormat_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 3";
		};
	}
	r2tm::DoFunctionT NumberFormat_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				std::cout << r2tm::tab << "+ std::showpoint" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::showpoint );

				LF();

				PROCESS_MAIN( std::cout << 10.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2tm::linefeed );


				std::cout << r2tm::linefeed2;


				PROCESS_MAIN( std::cout << std::noshowpoint );

				LF();

				PROCESS_MAIN( std::cout << 10.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2tm::linefeed );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ std::setprecision" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::setprecision( 10 ) );

				LF();

				PROCESS_MAIN( std::cout << 1110.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 123.45f << r2tm::linefeed );


				std::cout << r2tm::linefeed2;


				PROCESS_MAIN( std::cout << std::setprecision( 5 ) );

				LF();

				PROCESS_MAIN( std::cout << 1110.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 123.45f << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT NumberFormat_4::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 4";
		};
	}
	r2tm::DoFunctionT NumberFormat_4::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				std::cout << r2tm::tab << "+ Note : 소수점 이하 4자리 출력으로 고정." << r2tm::linefeed2;

				std::cout << r2tm::tab << "+ std::fixed" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::fixed );
				PROCESS_MAIN( std::cout << std::setprecision( 4 ) );

				LF();

				PROCESS_MAIN( std::cout << 10.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2tm::linefeed );


				std::cout << r2tm::linefeed2;


				PROCESS_MAIN( std::cout << std::defaultfloat );

				LF();

				PROCESS_MAIN( std::cout << 10.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Align::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align";
		};
	}
	r2tm::DoFunctionT Align::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::right << "align right" << r2tm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::left << "align left" << r2tm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::internal << std::showpos << 1234 << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::right << "1234" << r2tm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::left << "1234" << r2tm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::internal << std::showpos << 1234 << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_MAIN( std::cout << "1234" << "5678" << r2tm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << "1234" << "5678" << r2tm::linefeed );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Note : std::setw, std::right 등은 한 번 작동한다. 유지되지 않는다." << r2tm::linefeed;
				std::cout << r2tm::tab << "+ Note : std::setfill 은 유지 된다." << r2tm::linefeed;
			}

			LS();

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Flag::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flag";
		};
	}
	r2tm::DoFunctionT Flag::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				std::cout << r2tm::tab << "+ std::setiosflags" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::setiosflags( std::ios::fixed ) );
				PROCESS_MAIN( std::cout << std::setprecision( 4 ) );

				LF();

				PROCESS_MAIN( std::cout << 10.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2tm::linefeed );


				std::cout << r2tm::linefeed2;


				PROCESS_MAIN( std::cout << std::resetiosflags( std::ios::fixed ) );

				LF();

				PROCESS_MAIN( std::cout << 10.f << r2tm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	
	r2tm::TitleFunctionT BoolAlpha::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "BoolAlpha";
		};
	}
	r2tm::DoFunctionT BoolAlpha::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			LS();

			{
				std::cout << r2tm::tab << "+ std::boolalpha" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::boolalpha );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << true << r2tm::linefeed );
				PROCESS_MAIN( std::cout << false << r2tm::linefeed );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ std::noboolalpha" << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << std::noboolalpha );

				std::cout << r2tm::linefeed2;

				PROCESS_MAIN( std::cout << true << r2tm::linefeed );
				PROCESS_MAIN( std::cout << false << r2tm::linefeed );
			}

			LS();

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	struct A
	{
		friend std::ostream& operator<<( std::ostream& os, const A /*a*/ )
		{
			os << r2tm::tab << "Call - struct A : friend std::ostream& operator<<( std::ostream& os, const A a )" << r2tm::linefeed;
			return os;
		}
	};
	r2tm::TitleFunctionT UserDefinedType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "UserDefinedType";
		};
	}
	r2tm::DoFunctionT UserDefinedType::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				PROCESS_MAIN( std::cout << A() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}