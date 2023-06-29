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



	r2tm::TitleFunctionT Directory_Check_Make_Delete::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directory Check, Make, Delete";
		};
	}
	r2tm::DoFunctionT Directory_Check_Make_Delete::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_MAIN( p /= "Directory_Check_Make_Delete" );

			LS();

			{
				EXPECT_FALSE( std::filesystem::exists( p ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "디렉토리 생성" );

				LF();

				EXPECT_TRUE( std::filesystem::create_directory( p ) );
				EXPECT_TRUE( std::filesystem::exists( p ) );
			}
			
			LS();

			{
				OUTPUT_SUBJECT( "이미 있는 디렉토리 생성 시도" );

				LF();

				EXPECT_FALSE( std::filesystem::create_directory( p ) );
			}

			LS();

			OUTPUT_COMMENT( "아무 키 누르면 디렉토리 삭제" );
			_getch();

			LS();

			{
				OUTPUT_SUBJECT( "디렉토리 삭제" );

				LF();

				EXPECT_TRUE( std::filesystem::remove( p ) );
				EXPECT_FALSE( std::filesystem::exists( p ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "없는 디렉토리 삭제 시도" );

				LF();

				EXPECT_FALSE( std::filesystem::remove( p ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Directories_Make::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directories Make";
		};
	}
	r2tm::DoFunctionT Directories_Make::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::filesystem::path pivot_path = std::filesystem::current_path() );
			PROCESS_MAIN( pivot_path /= "temp" );

			LS();

			{
				OUTPUT_SUBJECT( "디렉토리 목록 생성" );

				LF();

				DECLARATION_MAIN( std::filesystem::path p = pivot_path );
				PROCESS_MAIN( p /= "a" );
				PROCESS_MAIN( p /= "b" );
				PROCESS_MAIN( p /= "c" );


				EXPECT_TRUE( std::filesystem::create_directories( p ) );
				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUTPUT_NOTE( "현재 경로와 생성 하려는 경로가 바로 맞닿을 수 없는 경우 중간 경로를 함께 생성한다." );

				LS();

				OUTPUT_SUBJECT( "이미 있는 디렉토리 목록 생성 시도" );

				LF();

				EXPECT_FALSE( std::filesystem::create_directory( p ) );
			}

			LS();

			OUTPUT_COMMENT( "아무 키 누르면 디렉토리 목록 삭제" );
			_getch();

			LS();

			{
				OUTPUT_SUBJECT( "자식 디렉토리가 있는 경우 함께 삭제한다." );

				LF();

				EXPECT_TRUE( std::filesystem::remove_all( pivot_path ) );
				EXPECT_FALSE( std::filesystem::exists( pivot_path ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "없는 디렉토리 목록 삭제 시도" );

				LF();

				EXPECT_FALSE( std::filesystem::remove( pivot_path ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}




	r2tm::TitleFunctionT FileStatus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "File Status";
		};
	}
	r2tm::DoFunctionT FileStatus::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_MAIN( p /= "play_cpp.sln" );

			LS();

			{
				OUTPUT_VALUE( std::filesystem::file_size( p ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}