#include "pch.h"
#include "std_cout_test.h"

#include <iomanip> // Manipulator : ������, ������

#include "r2cm/r2cm_eTestEndAction.h"
#include "r2/r2_Inspector.h"

namespace std_cout_test
{
	r2cm::iItem::TitleFuncT FMTStatus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : FMTStatus";
		};
	}
	r2cm::iItem::DoFuncT FMTStatus::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Note : ǥ�� ��ĵ��� Format�� �����ȴ�." << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "+ Status Save" << r2::linefeed2;

			DECLARATION_MAIN( std::ios last_fmt( nullptr ) );
			PROCESS_MAIN( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Format" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::hex; );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Test 1" << r2::linefeed2;

				PROCESS_MAIN( std::cout << 10 << r2::linefeed );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Status Rollback" << r2::linefeed2;

				PROCESS_MAIN( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Test 2" << r2::linefeed2;

				PROCESS_MAIN( std::cout << 10 << r2::linefeed );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT NumberFormat_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : Number Format 1";
		};
	}
	r2cm::iItem::DoFuncT NumberFormat_1::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::oct, hex, dec" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::oct << 10 << r2::linefeed );
				PROCESS_MAIN( std::cout << std::hex << 10 << r2::linefeed );
				PROCESS_MAIN( std::cout << std::dec << 10 << r2::linefeed );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::showbase" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::showbase );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << std::oct << 10 << r2::linefeed );
				PROCESS_MAIN( std::cout << std::hex << 10 << r2::linefeed );
				PROCESS_MAIN( std::cout << std::dec << 10 << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT NumberFormat_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : Number Format 2";
		};
	}
	r2cm::iItem::DoFuncT NumberFormat_2::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::showpos : show positive : 10���� ����� + �� ǥ�� �Ѵ�." << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::showpos );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10 << r2::linefeed );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << std::noshowpos );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10 << r2::linefeed );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::uppercase : 16������ �����ڸ� �빮�� ǥ��� �ٲ۴�." << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::showbase );
				PROCESS_MAIN( std::cout << std::uppercase );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << std::hex << 10 << r2::linefeed );

				std::cout << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::nouppercase );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << std::hex << 10 << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT NumberFormat_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : Number Format 3";
		};
	}
	r2cm::iItem::DoFuncT NumberFormat_3::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::showpoint" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::showpoint );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2::linefeed );


				std::cout << r2::linefeed2;


				PROCESS_MAIN( std::cout << std::noshowpoint );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2::linefeed );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::setprecision" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::setprecision( 10 ) );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 1110.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 123.45f << r2::linefeed );


				std::cout << r2::linefeed2;


				PROCESS_MAIN( std::cout << std::setprecision( 5 ) );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 1110.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 123.45f << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT NumberFormat_4::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : Number Format 4";
		};
	}
	r2cm::iItem::DoFuncT NumberFormat_4::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Note : �Ҽ��� ���� 4�ڸ� ������� ����." << r2::linefeed2;

				std::cout << r2::tab << "+ std::fixed" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::fixed );
				PROCESS_MAIN( std::cout << std::setprecision( 4 ) );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2::linefeed );


				std::cout << r2::linefeed2;


				PROCESS_MAIN( std::cout << std::defaultfloat );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Align::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : Align";
		};
	}
	r2cm::iItem::DoFuncT Align::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::right << "align right" << r2::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::left << "align left" << r2::linefeed );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::internal << std::showpos << 1234 << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::right << "1234" << r2::linefeed2 );
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::left << "1234" << r2::linefeed );
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::internal << std::showpos << 1234 << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_MAIN( std::cout << "1234" << "5678" << r2::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << "1234" << "5678" << r2::linefeed );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Note : std::setw, std::right ���� �� �� �۵��Ѵ�. �������� �ʴ´�." << r2::linefeed;
				std::cout << r2::tab << "+ Note : std::setfill �� ���� �ȴ�." << r2::linefeed;
			}

			std::cout << r2::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT Flag::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : Flag";
		};
	}
	r2cm::iItem::DoFuncT Flag::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::setiosflags" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::setiosflags( std::ios::fixed ) );
				PROCESS_MAIN( std::cout << std::setprecision( 4 ) );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2::linefeed );


				std::cout << r2::linefeed2;


				PROCESS_MAIN( std::cout << std::resetiosflags( std::ios::fixed ) );

				std::cout << r2::linefeed;

				PROCESS_MAIN( std::cout << 10.f << r2::linefeed );
				PROCESS_MAIN( std::cout << 11.2f << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT BoolAlpha::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::cout : BoolAlpha";
		};
	}
	r2cm::iItem::DoFuncT BoolAlpha::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_SUB( std::ios last_fmt( nullptr ) );
			PROCESS_SUB( last_fmt.copyfmt( std::cout ) );

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::boolalpha" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::boolalpha );

				std::cout << r2::linefeed2;

				PROCESS_MAIN( std::cout << true << r2::linefeed );
				PROCESS_MAIN( std::cout << false << r2::linefeed );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::noboolalpha" << r2::linefeed2;

				PROCESS_MAIN( std::cout << std::noboolalpha );

				std::cout << r2::linefeed2;

				PROCESS_MAIN( std::cout << true << r2::linefeed );
				PROCESS_MAIN( std::cout << false << r2::linefeed );
			}

			std::cout << r2::split;

			{
				PROCESS_SUB( std::cout.copyfmt( last_fmt ) );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}