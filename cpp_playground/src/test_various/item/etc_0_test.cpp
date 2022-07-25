#include "etc_0_test.h"

#include <bitset>
#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2cm/r2cm_ostream.h"

namespace etc_test
{
#define MACRO2STRING( x ) #x

	r2cm::iItem::TitleFunctionT Macro2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Macro 2 String";
		};
	}
	r2cm::iItem::DoFunctionT Macro2String::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int test_int = 3456;

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "#define MACRO2STRING( x ) #x" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "int test_int = " << test_int << ";" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << MACRO2STRING( test_int ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ShowBinary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Show Binary";
		};
	}
	r2cm::iItem::DoFunctionT ShowBinary::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Show Binary : Use For" << r2cm::linefeed << r2cm::linefeed;

				int num = 0b10110010101; // binary

				std::cout << r2cm::tab << "int num = 0b10110010101;" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2;
				for( int i = 31; 0 <= i; --i )
				{
					const int temp_1 = ( num >> i );
					const int temp_2 = temp_1 & 1;

					std::cout << temp_2;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Show Binary : Use Bitset" << r2cm::linefeed << r2cm::linefeed;

				int num = 0b0011001; // binary
				std::bitset<16u> b( num );

				std::cout << r2cm::tab << "int num = 0b0011001;" << r2cm::linefeed;
				std::cout << r2cm::tab << "std::bitset<32u> b( num );" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : " << b << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}