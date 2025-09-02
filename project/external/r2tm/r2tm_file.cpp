#include "r2tm_file.hpp"

#include <cstdlib>
#include <filesystem>

namespace r2tm
{
	bool ExistPath( const char* const utf8_path )
	{
		return std::filesystem::exists( std::filesystem::path( utf8_path ) );
	}

	bool DirectoryOpen( const char* const utf8_path )
	{
		std::filesystem::path p( utf8_path );
		p._Remove_filename_and_separator();

		if( !std::filesystem::exists( p ) )
		{
			return false;
		}

		std::string s( "explorer " );
		s += p.string().c_str();
		std::system( s.c_str() );

		return true;
	}
}