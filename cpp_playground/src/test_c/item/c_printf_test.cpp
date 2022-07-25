#include "c_printf_test.h"

#include <bitset>

#include "r2cm/r2cm_ostream.h"

namespace print_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Show String : Use printf" << r2cm::linefeed << r2cm::linefeed;

				std::cout << r2cm::tab << "printf( \"1111111\" \"2222222\" \"3333333\" \"   %d\", 456789 );" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2;
				printf( "1111111" "2222222" "3333333" "   %d", 456789 );
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ShowNumbers::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print : Number";
		};
	}
	r2cm::iItem::DoFunctionT ShowNumbers::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Show Number : Use printf" << r2cm::linefeed << r2cm::linefeed;

				int num = 0xde81; // hex

				std::cout << r2cm::tab << "int num = 0xde81;" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				printf( "\t\tPrint( 8 : oct ) : %o\n", num );
				printf( "\t\tPrint( 10 : dec ) : %d\n", num );
				printf( "\t\tPrint( 16 : hex ) : %x\n", num );
			}

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