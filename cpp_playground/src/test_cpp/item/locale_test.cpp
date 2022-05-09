#include "pch.h"
#include "locale_test.h"

#include <conio.h>
#include <locale>

#include "r2cm/r2cm_constant.h"

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
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::locale l( \"\" );" << r2cm::linefeed2;

				std::locale l( "" );
				std::cout << r2cm::tab2 << "Locale Name : " << l.name().c_str() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ std::locale l( \"en_US.utf8\" );" << r2cm::linefeed2;

				std::locale l( "en_US.utf8" );
				std::cout << r2cm::tab2 << "Locale Name : " << l.name().c_str() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const std::string current_locale = setlocale( LC_ALL, nullptr );

				std::cout << r2cm::tab << "+ Current Locale" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "const std::string current_locale = setlocale( LC_ALL, nullptr );" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "Locale Name : " << current_locale << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "** Need nullptr in call setlocale" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const std::string current_locale = setlocale( LC_ALL, "" );

				std::cout << r2cm::tab << "+ Set OS Default Locale" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "const std::string current_locale = setlocale( LC_ALL, \"\" );" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "Locale Name : " << current_locale << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const char* kor = "한글 테스트";
				const wchar_t* wkor = L"한글 테스트";

				//std::cout << "Locale : " << setlocale( LC_ALL, "C" ) << r2cm::linefeed;
				//std::cout << "Print Korean : " << kor << r2cm::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2cm::linefeed;

				std::cout << std::endl;

				//std::cout << "Locale : " << setlocale( LC_ALL, "ja_JP.utf8" ) << r2cm::linefeed;
				//std::cout << "Print Korean : " << kor << r2cm::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2cm::linefeed;

				std::cout << std::endl;

				//std::cout << "Locale : " << setlocale( LC_ALL, "Korean" ) << r2cm::linefeed;
				//std::cout << "Print Korean : " << kor << r2cm::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2cm::linefeed;

				std::cout << std::endl;

				std::cout << "Locale : " << setlocale( LC_ALL, "ko_KR.utf8" ) << r2cm::linefeed;
				std::cout << "Print Korean : " << kor << r2cm::linefeed;
				std::wcout << "Print W Korean : " << wkor;// << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				const std::string current_locale = setlocale( LC_ALL, "C" );

				std::cout << r2cm::tab << "+ Roll Back Locale" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "const std::string current_locale = setlocale( LC_ALL, \"C\" );" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "Locale Name : " << current_locale << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}