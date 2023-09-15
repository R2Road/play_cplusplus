#include "play_cpp_utility_FileUtil.h"

#include <filesystem>

namespace play_cpp_utility
{
	std::string BuildOutPutPath( const char* file_name )
	{
		std::string temp_string =
#if defined( _WIN64 )
	#if defined( DEBUG ) || defined( _DEBUG )
			( std::filesystem::current_path() / "x64" / "Debug" / file_name ).string();
	#else
			( std::filesystem::current_path() / "x64" / "Release" / file_name ).string();
	#endif
#else
	#if defined( DEBUG ) || defined( _DEBUG )
			( std::filesystem::current_path() / "Debug" / file_name ).string();
	#else
			( std::filesystem::current_path() / "Release" / file_name ).string();
	#endif
#endif
		return temp_string;
	}

	std::string BuildSFXPath( const char* file_name )
	{
		std::string ret = ( std::filesystem::current_path() / "resources" / "sound" / "sfx" / file_name ).string();
		return ret;
	}
}