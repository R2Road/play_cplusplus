#include "std_cout_test.h"

#include <iomanip> // Manipulator : 조작자, 조정자

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace std_cout_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				PROCESS_MAIN( std::cout << "1234" "5678" "90" );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( std::cout.write( "1234" "5678" "90", 6 ) );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( std::cout.write( "1234", 6 ) );
				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab << "+ 출력할 문자의 숫자가 문자열의 길이를 넘어가도 터지지 않는다." << r2cm::linefeed;
				std::cout << r2cm::tab << "+ 내부에 예외 처리를 위한 try-catch 구문이 있다." << r2cm::linefeed;

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT FMTStatus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "FMTStatus";
		};
	}
	r2cm::iItem::DoFunctionT FMTStatus::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Note : 표기 방식등의 Format은 유지된다." << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Status Save" << r2cm::linefeed2;

			DECLARATION_MAIN( std::ios last_fmt( nullptr ) );
			PROCESS_MAIN( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Format" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::hex; );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Test 1" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << 10 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Status Rollback" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Test 2" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << 10 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT NumberFormat_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 1";
		};
	}
	r2cm::iItem::DoFunctionT NumberFormat_1::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::oct, hex, dec" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::oct << 10 << r2cm::linefeed );
				PROCESS_MAIN( std::cout << std::hex << 10 << r2cm::linefeed );
				PROCESS_MAIN( std::cout << std::dec << 10 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::showbase" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::showbase );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << std::oct << 10 << r2cm::linefeed );
				PROCESS_MAIN( std::cout << std::hex << 10 << r2cm::linefeed );
				PROCESS_MAIN( std::cout << std::dec << 10 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT NumberFormat_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 2";
		};
	}
	r2cm::iItem::DoFunctionT NumberFormat_2::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::showpos : show positive : 10진수 양수에 + 를 표시 한다." << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::showpos );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10 << r2cm::linefeed );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << std::noshowpos );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::uppercase : 16진수의 영문자를 대문자 표기로 바꾼다." << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::showbase );
				PROCESS_MAIN( std::cout << std::uppercase );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << std::hex << 10 << r2cm::linefeed );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::nouppercase );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << std::hex << 10 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT NumberFormat_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 3";
		};
	}
	r2cm::iItem::DoFunctionT NumberFormat_3::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::showpoint" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::showpoint );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2cm::linefeed );


				std::cout << r2cm::linefeed2;


				PROCESS_MAIN( std::cout << std::noshowpoint );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::setprecision" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::setprecision( 10 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 1110.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 123.45f << r2cm::linefeed );


				std::cout << r2cm::linefeed2;


				PROCESS_MAIN( std::cout << std::setprecision( 5 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 1110.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 123.45f << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT NumberFormat_4::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Number Format 4";
		};
	}
	r2cm::iItem::DoFunctionT NumberFormat_4::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Note : 소수점 이하 4자리 출력으로 고정." << r2cm::linefeed2;

				std::cout << r2cm::tab << "+ std::fixed" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::fixed );
				PROCESS_MAIN( std::cout << std::setprecision( 4 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2cm::linefeed );


				std::cout << r2cm::linefeed2;


				PROCESS_MAIN( std::cout << std::defaultfloat );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Align::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align";
		};
	}
	r2cm::iItem::DoFunctionT Align::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::right << "align right" << r2cm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::left << "align left" << r2cm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::internal << std::showpos << 1234 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::right << "1234" << r2cm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::left << "1234" << r2cm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::internal << std::showpos << 1234 << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( std::cout << "1234" << "5678" << r2cm::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << "1234" << "5678" << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Note : std::setw, std::right 등은 한 번 작동한다. 유지되지 않는다." << r2cm::linefeed;
				std::cout << r2cm::tab << "+ Note : std::setfill 은 유지 된다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Flag::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flag";
		};
	}
	r2cm::iItem::DoFunctionT Flag::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::setiosflags" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::setiosflags( std::ios::fixed ) );
				PROCESS_MAIN( std::cout << std::setprecision( 4 ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2cm::linefeed );


				std::cout << r2cm::linefeed2;


				PROCESS_MAIN( std::cout << std::resetiosflags( std::ios::fixed ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2cm::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}


	
	r2cm::iItem::TitleFunctionT BoolAlpha::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "BoolAlpha";
		};
	}
	r2cm::iItem::DoFunctionT BoolAlpha::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::boolalpha" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::boolalpha );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << true << r2cm::linefeed );
				PROCESS_MAIN( std::cout << false << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::noboolalpha" << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << std::noboolalpha );

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( std::cout << true << r2cm::linefeed );
				PROCESS_MAIN( std::cout << false << r2cm::linefeed );
			}

			std::cout << r2cm::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	struct A
	{
		friend std::ostream& operator<<( std::ostream& os, const A /*a*/ )
		{
			os << r2cm::tab << "Call - struct A : friend std::ostream& operator<<( std::ostream& os, const A a )" << r2cm::linefeed;
			return os;
		}
	};
	r2cm::iItem::TitleFunctionT UserDefinedType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "UserDefinedType";
		};
	}
	r2cm::iItem::DoFunctionT UserDefinedType::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				PROCESS_MAIN( std::cout << A() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}