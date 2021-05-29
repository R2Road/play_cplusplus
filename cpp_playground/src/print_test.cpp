#include "pch.h"
#include "print_test.h"

#include <bitset>

#include "r2_eTestResult.h"

namespace print_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Print : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
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
				std::cout << r2::tab << "+ Show Number : Use std::cout" << r2::linefeed << r2::linefeed;

				int i = 0xde81;

				std::cout << r2::tab << "int i = 0xde81;" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "Print( 8 : oct ) : " << std::oct << i << r2::linefeed;
				std::cout << r2::tab2 << "Print( 10 : dec ) : " << std::dec << i << r2::linefeed;
				std::cout << r2::tab2 << "Print( 16 : hex ) : " << std::hex << i << r2::linefeed;

				// rollback
				std::cout << std::dec;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show Number : Use printf" << r2::linefeed << r2::linefeed;

				int i = 0xde81;

				std::cout << r2::tab << "int i = 0xde81;" << r2::linefeed;
				std::cout << r2::linefeed;

				printf( "\t\tPrint( 8 : oct ) : %o\n", i );
				printf( "\t\tPrint( 10 : dec ) : %d\n", i );
				printf( "\t\tPrint( 16 : hex ) : %x\n", i );
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Show Binary : Use For" << r2::linefeed << r2::linefeed;

				int num = 0b10110010101;

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

				int i = 0b0011001;
				std::bitset<16u> b( i );

				std::cout << r2::tab << "int i = 0b0011001;" << r2::linefeed;
				std::cout << r2::tab << "std::bitset<32u> b( i );" << r2::linefeed;
				std::cout << r2::linefeed;

				std::cout << r2::tab2 << "Print : " << b << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}