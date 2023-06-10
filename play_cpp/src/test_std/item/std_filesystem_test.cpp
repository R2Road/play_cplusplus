#include "std_filesystem_test.h"

#include <conio.h>
#include <filesystem>
#include <stdlib.h>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace std_filesystem_test
{
	r2tm::TitleFunctionT DirectoryPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directory Path";
		};
	}
	r2tm::DoFunctionT DirectoryPath::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ Current Path" << r2tm::linefeed2;
				DECLARATION_MAIN( const std::filesystem::path p = std::filesystem::current_path() );
				OUTPUT_VALUE( p );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Temp Directory Path" << r2tm::linefeed2;
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::temp_directory_path() );
				OUTPUT_VALUE( p );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT DirectoryIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directory Iterator";
		};
	}
	r2tm::DoFunctionT DirectoryIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "+ Target Path" << r2tm::linefeed2;
			DECLARATION_MAIN( const std::filesystem::path p = std::filesystem::current_path() );
			OUTPUT_VALUE( p );

			LS();

			{
				std::cout << r2tm::tab << "+ View Directory" << r2tm::linefeed2;
				DECLARATION_MAIN( std::filesystem::directory_iterator itr( p ) );

				std::cout << r2tm::tab << "for( auto i : itr ) ..." << r2tm::linefeed;
				
				std::cout << r2tm::linefeed3;

				for( auto i : itr )
				{
					std::cout << r2tm::tab << i.path() << r2tm::linefeed;
					std::cout << r2tm::tab2 << ( std::filesystem::is_regular_file( i.path() ) ? "file" : "directory" ) << r2tm::linefeed2;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT RecursiveDirectoryIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Recursive Directory Iterator";
		};
	}
	r2tm::DoFunctionT RecursiveDirectoryIterator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				int i = 0;

				std::filesystem::recursive_directory_iterator itr( std::filesystem::current_path() / "src" );
				for( auto p : itr )
				{
					std::cout << p.path() << r2tm::linefeed;

					++i;
					if( 40 > i )
					{
						i = 0;
						
						std::cout << r2tm::linefeed << r2tm::tab3 << "[ESC] Exit, [Other Key] Continue" << r2tm::linefeed2;

						if( 27 == _getch() ) // ESC
						{
							break;
						}
					}
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PathOperation_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Path Operation 1";
		};
	}
	r2tm::DoFunctionT PathOperation_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::filesystem::path p = std::filesystem::current_path();

			{
				std::cout << r2tm::tab << "+ Target Path" << r2tm::linefeed2;
				std::cout << r2tm::tab2 << p << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Append with Operator /" << r2tm::linefeed2;

				p /= "test.txt";
				std::cout << r2tm::tab2 << "p /= \"test.txt\"" << r2tm::linefeed;

				std::cout << r2tm::tab3 << p << r2tm::linefeed2;


				std::cout << r2tm::tab << "+ Remove File Name" << r2tm::linefeed2;

				p.remove_filename();
				std::cout << r2tm::tab2 << "p.remove_filename();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "result : " << p << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Remove File Name And Separator" << r2tm::linefeed2;

				p /= "test.txt";
				std::cout << r2tm::tab3 << "orig : " << p << r2tm::linefeed2;

				p._Remove_filename_and_separator();
				std::cout << r2tm::tab2 << "p._Remove_filename_and_separator();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "result : " << p << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Replace Extension" << r2tm::linefeed2;

				p /= "test.txt";
				std::cout << r2tm::tab3 << "orig : " << p << r2tm::linefeed2;

				p.replace_extension( "json" );
				std::cout << r2tm::tab2 << "p.replace_extension( \"json\" );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "result : " << p << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Replace File Name" << r2tm::linefeed2;

				std::cout << r2tm::tab3 << "orig : " << p << r2tm::linefeed2;

				p.replace_filename( "new_filename" );
				std::cout << r2tm::tab2 << "p.replace_filename( \"new_filename\" );" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "result : " << p << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT PathOperation_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Path Operation 2";
		};
	}
	r2tm::DoFunctionT PathOperation_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::filesystem::path p = std::filesystem::current_path();

			{
				std::cout << r2tm::tab << "+ Directory : " << r2tm::linefeed2;
				std::cout << r2tm::tab2 << p << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Has Parent Path" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "p.has_parent_path();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "result : " << ( p.has_parent_path() ? "True" : "False" ) << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Get Parent Path" << r2tm::linefeed2;

				std::cout << r2tm::tab2 << "p.parent_path();" << r2tm::linefeed;
				std::cout << r2tm::tab3 << "result : " << ( p.has_parent_path() ? p.parent_path() : "Nothing" ) << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}