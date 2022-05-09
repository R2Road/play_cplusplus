#include "pch.h"
#include "filesystem_test.h"

#include <conio.h>
#include <filesystem>
#include <stdlib.h>

#include "r2cm/r2cm_constant.h"

namespace filesystem_test
{
	r2cm::iItem::TitleFuncT DirectoryPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directory Path";
		};
	}
	r2cm::iItem::DoFuncT DirectoryPath::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::filesystem::path p = std::filesystem::current_path();

				std::cout << r2cm::tab << "+ Current Directory" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::filesystem::path p = std::filesystem::current_path();" << r2cm::linefeed2;
				std::cout << r2cm::tab3 << "> " << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::filesystem::path p = std::filesystem::temp_directory_path();

				std::cout << r2cm::tab << "+ Temp Directory" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::filesystem::path p = std::filesystem::temp_directory_path();" << r2cm::linefeed2;
				std::cout << r2cm::tab3 << "> " << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT DirectoryIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Directory Iterator";
		};
	}
	r2cm::iItem::DoFuncT DirectoryIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::filesystem::path p = std::filesystem::current_path();

				std::cout << r2cm::tab << "+ Target Path" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::filesystem::path p = std::filesystem::current_path();" << r2cm::linefeed2;
				std::cout << r2cm::tab3 << "> " << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ View Directory" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "std::filesystem::directory_iterator itr( std::filesystem::current_path() );" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "for( auto i : itr ) ..." << r2cm::linefeed;
				
				std::cout << r2cm::linefeed3;

				std::filesystem::directory_iterator itr( std::filesystem::current_path() );
				for( auto i : itr )
				{
					std::cout << r2cm::tab2 << i.path() << r2cm::linefeed;
					std::cout << r2cm::tab3 << ( std::filesystem::is_regular_file( i.path() ) ? "file" : "directory" ) << r2cm::linefeed2;
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT RecursiveDirectoryIterator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Recursive Directory Iterator";
		};
	}
	r2cm::iItem::DoFuncT RecursiveDirectoryIterator::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			{
				int i = 0;

				std::filesystem::recursive_directory_iterator itr( std::filesystem::current_path() / "src" );
				for( auto p : itr )
				{
					std::cout << p.path() << r2cm::linefeed;

					++i;
					if( 40 > i )
					{
						i = 0;
						
						std::cout << r2cm::linefeed << r2cm::tab3 << "[ESC] Exit, [Other Key] Continue" << r2cm::linefeed2;

						if( 27 == _getch() ) // ESC
						{
							break;
						}
					}
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PathOperation_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Path Operation 1";
		};
	}
	r2cm::iItem::DoFuncT PathOperation_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::filesystem::path p = std::filesystem::current_path();

			{
				std::cout << r2cm::tab << "+ Target Path" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Append with Operator /" << r2cm::linefeed2;

				p /= "test.txt";
				std::cout << r2cm::tab2 << "p /= \"test.txt\"" << r2cm::linefeed;

				std::cout << r2cm::tab3 << p << r2cm::linefeed2;


				std::cout << r2cm::tab << "+ Remove File Name" << r2cm::linefeed2;

				p.remove_filename();
				std::cout << r2cm::tab2 << "p.remove_filename();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "result : " << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Remove File Name And Separator" << r2cm::linefeed2;

				p /= "test.txt";
				std::cout << r2cm::tab3 << "orig : " << p << r2cm::linefeed2;

				p._Remove_filename_and_separator();
				std::cout << r2cm::tab2 << "p._Remove_filename_and_separator();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "result : " << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Replace Extension" << r2cm::linefeed2;

				p /= "test.txt";
				std::cout << r2cm::tab3 << "orig : " << p << r2cm::linefeed2;

				p.replace_extension( "json" );
				std::cout << r2cm::tab2 << "p.replace_extension( \"json\" );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "result : " << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Replace File Name" << r2cm::linefeed2;

				std::cout << r2cm::tab3 << "orig : " << p << r2cm::linefeed2;

				p.replace_filename( "new_filename" );
				std::cout << r2cm::tab2 << "p.replace_filename( \"new_filename\" );" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "result : " << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFuncT PathOperation_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Path Operation 2";
		};
	}
	r2cm::iItem::DoFuncT PathOperation_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::filesystem::path p = std::filesystem::current_path();

			{
				std::cout << r2cm::tab << "+ Directory : " << r2cm::linefeed2;
				std::cout << r2cm::tab2 << p << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Has Parent Path" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "p.has_parent_path();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "result : " << ( p.has_parent_path() ? "True" : "False" ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Get Parent Path" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "p.parent_path();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "result : " << ( p.has_parent_path() ? p.parent_path() : "Nothing" ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}