#include "pch.h"
#include "print_test.h"

#include <bitset>

#include "base/r2_eTestEndAction.h"

namespace print_test
{
	r2::iItem::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print : Basic";
		};
	}
	r2::iItem::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show String : Use printf" << r2::linefeed << r2::linefeed;

				std::cout << r2::tab << "printf( \"1111111\" \"2222222\" \"3333333\" \"   %d\", 456789 );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2;
				printf( "1111111" "2222222" "3333333" "   %d", 456789 );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show String : Use std::cout.write" << r2::linefeed << r2::linefeed;

				const char* str = "1111111222222233333334";

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "const char* str = \"1111111222222233333334\";" << r2::linefeed2;

				std::cout << r2::tab << "+ Process" << r2::linefeed2;
				std::cout << r2::tab2 << "std::cout.write( str, strlen( str ) / 2 );" << r2::linefeed2;

				std::cout << r2::tab2;
				std::cout.write( str, strlen( str ) / 2 );
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	r2::iItem::TitleFunc ShowNumbers::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print : Number";
		};
	}
	r2::iItem::DoFunc ShowNumbers::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show Number : Use std::cout" << r2::linefeed << r2::linefeed;

				int num = 01743; // oct

				std::cout << r2::tab << "int num = 01743;" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "Print( 8 : oct ) : " << std::oct << num << r2::linefeed;
				std::cout << r2::tab2 << "Print( 10 : dec ) : " << std::dec << num << r2::linefeed;
				std::cout << r2::tab2 << "Print( 16 : hex ) : " << std::hex << num << r2::linefeed;

				// rollback
				std::cout << std::dec;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show Number : Use printf" << r2::linefeed << r2::linefeed;

				int num = 0xde81; // hex

				std::cout << r2::tab << "int num = 0xde81;" << r2::linefeed;
				std::cout << r2::linefeed;

				printf( "\t\tPrint( 8 : oct ) : %o\n", num );
				printf( "\t\tPrint( 10 : dec ) : %d\n", num );
				printf( "\t\tPrint( 16 : hex ) : %x\n", num );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show Binary : Use For" << r2::linefeed << r2::linefeed;

				int num = 0b10110010101; // binary

				std::cout << r2::tab << "int num = 0b10110010101;" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2;
				for( int i = 31; 0 <= i; --i )
				{
					const int temp_1 = ( num >> i );
					const int temp_2 = temp_1 & 1;

					std::cout << temp_2;
				}
				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show Binary : Use Bitset" << r2::linefeed << r2::linefeed;

				int num = 0b0011001; // binary
				std::bitset<16u> b( num );

				std::cout << r2::tab << "int num = 0b0011001;" << r2::linefeed;
				std::cout << r2::tab << "std::bitset<32u> b( num );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "Print : " << b << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	r2::iItem::TitleFunc BoolAlpha::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print : BoolAlpha";
		};
	}
	r2::iItem::DoFunc BoolAlpha::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show Bool : Use std::cout and std::boolalpha" << r2::linefeed << r2::linefeed;

				std::cout << std::noboolalpha;
				std::cout << r2::tab2 << "true with noboolalpha : " << true << r2::linefeed;
				std::cout << r2::tab2 << "false with noboolalpha : " << false << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << std::boolalpha;
				std::cout << r2::tab2 << "true with boolalpha : " << true << r2::linefeed;
				std::cout << r2::tab2 << "false with boolalpha : " << false << r2::linefeed;

				// rollback
				std::cout << std::noboolalpha;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}