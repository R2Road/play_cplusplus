#include "pch.h"
#include "locale_test.h"

#include <conio.h>
#include <locale>

#include "r2cm/r2cm_eTestEndAction.h"

namespace locale_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Locale";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::locale l( \"\" );" << r2::linefeed2;

				std::locale l( "" );
				std::cout << r2::tab2 << "Locale Name : " << l.name().c_str() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ std::locale l( \"en_US.utf8\" );" << r2::linefeed2;

				std::locale l( "en_US.utf8" );
				std::cout << r2::tab2 << "Locale Name : " << l.name().c_str() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				const std::string current_locale = setlocale( LC_ALL, nullptr );

				std::cout << r2::tab << "+ Current Locale" << r2::linefeed2;
				std::cout << r2::tab2 << "const std::string current_locale = setlocale( LC_ALL, nullptr );" << r2::linefeed2;
				std::cout << r2::tab2 << "Locale Name : " << current_locale << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab << "** Need nullptr in call setlocale" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				const std::string current_locale = setlocale( LC_ALL, "" );

				std::cout << r2::tab << "+ Set OS Default Locale" << r2::linefeed2;
				std::cout << r2::tab2 << "const std::string current_locale = setlocale( LC_ALL, \"\" );" << r2::linefeed2;
				std::cout << r2::tab2 << "Locale Name : " << current_locale << r2::linefeed;
			}

			std::cout << r2::split;

			{
				const char* kor = "�ѱ� �׽�Ʈ";
				const wchar_t* wkor = L"�ѱ� �׽�Ʈ";

				//std::cout << "Locale : " << setlocale( LC_ALL, "C" ) << r2::linefeed;
				//std::cout << "Print Korean : " << kor << r2::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2::linefeed;

				std::cout << std::endl;

				//std::cout << "Locale : " << setlocale( LC_ALL, "ja_JP.utf8" ) << r2::linefeed;
				//std::cout << "Print Korean : " << kor << r2::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2::linefeed;

				std::cout << std::endl;

				//std::cout << "Locale : " << setlocale( LC_ALL, "Korean" ) << r2::linefeed;
				//std::cout << "Print Korean : " << kor << r2::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2::linefeed;

				std::cout << std::endl;

				std::cout << "Locale : " << setlocale( LC_ALL, "ko_KR.utf8" ) << r2::linefeed;
				std::cout << "Print Korean : " << kor << r2::linefeed;
				std::wcout << "Print W Korean : " << wkor;// << r2::linefeed;
			}

			std::cout << r2::split;

			{
				const std::string current_locale = setlocale( LC_ALL, "C" );

				std::cout << r2::tab << "+ Roll Back Locale" << r2::linefeed2;
				std::cout << r2::tab2 << "const std::string current_locale = setlocale( LC_ALL, \"C\" );" << r2::linefeed2;
				std::cout << r2::tab2 << "Locale Name : " << current_locale << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}