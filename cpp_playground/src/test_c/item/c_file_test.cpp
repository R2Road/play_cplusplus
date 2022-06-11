#include "c_file_test.h"

#include <stdio.h>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace c_file_test
{
	r2cm::iItem::TitleFuncT OpenAndClose::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C File : Open And Close";
		};
	}
	r2cm::iItem::DoFuncT OpenAndClose::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()()  << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FILE* fp = nullptr );
				EXPECT_EQ( 0, fopen_s( &fp, "src/test_c/item/c_file_test_openandclose_1.txt", "rb" ) );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( fclose( fp ) );

				std::cout << r2cm::linefeed2;
				std::cout << r2cm::tab << "+ 한 번 더 불러도 문제가 없다." << r2cm::linefeed2;

				PROCESS_MAIN( fclose( fp ) );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ 터짐" << r2cm::linefeed2;

				OUTPUT_CODE( fclose( nullptr ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT ShowAll::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "C File : ShowAll";
		};
	}
	r2cm::iItem::DoFuncT ShowAll::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FILE* fp = nullptr );
				EXPECT_EQ( 0, fopen_s( &fp, "src/test_c/item/c_file_test_openandclose_1.txt", "rb" ) );

				std::cout << r2cm::linefeed2;

				char temp = 0;
				while( true )
				{
					temp = fgetc( fp );
					if( temp == EOF )
					{
						break;
					}

					printf( "%c", temp );
				}

				std::cout << r2cm::linefeed2;

				PROCESS_MAIN( fclose( fp ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}