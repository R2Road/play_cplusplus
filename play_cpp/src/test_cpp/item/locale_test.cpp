#include "locale_test.h"

#include <conio.h>
#include <locale>

#include "r2tm/r2tm_ostream.h"

namespace locale_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Char : Locale";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ std::locale l( \"\" );" << r2tm::linefeed2;

				std::locale l( "" );
				std::cout << r2tm::tab2 << "Locale Name : " << l.name().c_str() << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ std::locale l( \"en_US.utf8\" );" << r2tm::linefeed2;

				std::locale l( "en_US.utf8" );
				std::cout << r2tm::tab2 << "Locale Name : " << l.name().c_str() << r2tm::linefeed;
			}

			LS();

			{
				const std::string current_locale = setlocale( LC_ALL, nullptr );

				std::cout << r2tm::tab << "+ Current Locale" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "const std::string current_locale = setlocale( LC_ALL, nullptr );" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "Locale Name : " << current_locale << r2tm::linefeed;

				LF();

				std::cout << r2tm::tab << "** Need nullptr in call setlocale" << r2tm::linefeed;
			}

			LS();

			{
				const std::string current_locale = setlocale( LC_ALL, "" );

				std::cout << r2tm::tab << "+ Set OS Default Locale" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "const std::string current_locale = setlocale( LC_ALL, \"\" );" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "Locale Name : " << current_locale << r2tm::linefeed;
			}

			LS();

			{
				const char* kor = "한글 테스트";
				const wchar_t* wkor = L"한글 테스트";

				//std::cout << "Locale : " << setlocale( LC_ALL, "C" ) << r2tm::linefeed;
				//std::cout << "Print Korean : " << kor << r2tm::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2tm::linefeed;

				std::cout << std::endl;

				//std::cout << "Locale : " << setlocale( LC_ALL, "ja_JP.utf8" ) << r2tm::linefeed;
				//std::cout << "Print Korean : " << kor << r2tm::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2tm::linefeed;

				std::cout << std::endl;

				//std::cout << "Locale : " << setlocale( LC_ALL, "Korean" ) << r2tm::linefeed;
				//std::cout << "Print Korean : " << kor << r2tm::linefeed;
				//std::wcout << "Print W Korean : " << wkor << r2tm::linefeed;

				std::cout << std::endl;

				std::cout << "Locale : " << setlocale( LC_ALL, "ko_KR.utf8" ) << r2tm::linefeed;
				std::cout << "Print Korean : " << kor << r2tm::linefeed;
				std::wcout << "Print W Korean : " << wkor;// << r2tm::linefeed;
			}

			LS();

			{
				const std::string current_locale = setlocale( LC_ALL, "C" );

				std::cout << r2tm::tab << "+ Roll Back Locale" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "const std::string current_locale = setlocale( LC_ALL, \"C\" );" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << "Locale Name : " << current_locale << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}