#include "pch.h"
#include "filesystem_test.h"

#include <conio.h>
#include <filesystem>
#include <stdlib.h>

#include "base/r2cm_eTestEndAction.h"

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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::filesystem::path p = std::filesystem::current_path();

				std::cout << r2::tab << "+ Current Directory" << r2::linefeed2;
				std::cout << r2::tab2 << "std::filesystem::path p = std::filesystem::current_path();" << r2::linefeed2;
				std::cout << r2::tab3 << "> " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::filesystem::path p = std::filesystem::temp_directory_path();

				std::cout << r2::tab << "+ Temp Directory" << r2::linefeed2;
				std::cout << r2::tab2 << "std::filesystem::path p = std::filesystem::temp_directory_path();" << r2::linefeed2;
				std::cout << r2::tab3 << "> " << p << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::filesystem::path p = std::filesystem::current_path();

				std::cout << r2::tab << "+ Target Path" << r2::linefeed2;
				std::cout << r2::tab2 << "std::filesystem::path p = std::filesystem::current_path();" << r2::linefeed2;
				std::cout << r2::tab3 << "> " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ View Directory" << r2::linefeed2;
				std::cout << r2::tab2 << "std::filesystem::directory_iterator itr( std::filesystem::current_path() );" << r2::linefeed;
				std::cout << r2::tab2 << "for( auto i : itr ) ..." << r2::linefeed;
				
				std::cout << r2::linefeed3;

				std::filesystem::directory_iterator itr( std::filesystem::current_path() );
				for( auto i : itr )
				{
					std::cout << r2::tab2 << i.path() << r2::linefeed;
					std::cout << r2::tab3 << ( std::filesystem::is_regular_file( i.path() ) ? "file" : "directory" ) << r2::linefeed2;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			{
				int i = 0;

				std::filesystem::recursive_directory_iterator itr( std::filesystem::current_path() / "src" );
				for( auto p : itr )
				{
					std::cout << p.path() << r2::linefeed;

					++i;
					if( 40 > i )
					{
						i = 0;
						
						std::cout << r2::linefeed << r2::tab3 << "[ESC] Exit, [Other Key] Continue" << r2::linefeed2;

						if( 27 == _getch() ) // ESC
						{
							break;
						}
					}
				}
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::filesystem::path p = std::filesystem::current_path();

			{
				std::cout << r2::tab << "+ Target Path" << r2::linefeed2;
				std::cout << r2::tab2 << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Append with Operator /" << r2::linefeed2;

				p /= "test.txt";
				std::cout << r2::tab2 << "p /= \"test.txt\"" << r2::linefeed;

				std::cout << r2::tab3 << p << r2::linefeed2;


				std::cout << r2::tab << "+ Remove File Name" << r2::linefeed2;

				p.remove_filename();
				std::cout << r2::tab2 << "p.remove_filename();" << r2::linefeed;
				std::cout << r2::tab3 << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Remove File Name And Separator" << r2::linefeed2;

				p /= "test.txt";
				std::cout << r2::tab3 << "orig : " << p << r2::linefeed2;

				p._Remove_filename_and_separator();
				std::cout << r2::tab2 << "p._Remove_filename_and_separator();" << r2::linefeed;
				std::cout << r2::tab3 << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Replace Extension" << r2::linefeed2;

				p /= "test.txt";
				std::cout << r2::tab3 << "orig : " << p << r2::linefeed2;

				p.replace_extension( "json" );
				std::cout << r2::tab2 << "p.replace_extension( \"json\" );" << r2::linefeed;
				std::cout << r2::tab3 << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Replace File Name" << r2::linefeed2;

				std::cout << r2::tab3 << "orig : " << p << r2::linefeed2;

				p.replace_filename( "new_filename" );
				std::cout << r2::tab2 << "p.replace_filename( \"new_filename\" );" << r2::linefeed;
				std::cout << r2::tab3 << "result : " << p << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::filesystem::path p = std::filesystem::current_path();

			{
				std::cout << r2::tab << "+ Directory : " << r2::linefeed2;
				std::cout << r2::tab2 << p << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Has Parent Path" << r2::linefeed2;

				std::cout << r2::tab2 << "p.has_parent_path();" << r2::linefeed;
				std::cout << r2::tab3 << "result : " << ( p.has_parent_path() ? "True" : "False" ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Get Parent Path" << r2::linefeed2;

				std::cout << r2::tab2 << "p.parent_path();" << r2::linefeed;
				std::cout << r2::tab3 << "result : " << ( p.has_parent_path() ? p.parent_path() : "Nothing" ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}