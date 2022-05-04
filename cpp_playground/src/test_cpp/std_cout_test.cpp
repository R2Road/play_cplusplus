#include "pch.h"
#include "std_cout_test.h"

#include <iomanip>

#include "base/r2cm_eTestEndAction.h"
#include "r2/r2_Inspector.h"

namespace std_cout_test
{
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
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::right << "align right" << r2::linefeed2 );
				PROCESS_MAIN( std::cout << std::setw( 20 ) << std::left << "align left" << r2::linefeed2 );

				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::right << "1234" << r2::linefeed2 );
				PROCESS_MAIN( std::cout << std::setfill( 'x' ) << std::setw( 20 ) << std::left << "1234" << r2::linefeed2 );

				PROCESS_MAIN( std::cout << "1234" << "5678" <<  r2::linefeed2 );

				std::cout << r2::tab << "+ Note : ������ Format�� �� �� �۵��Ѵ�. �������� �ʴ´�." << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}