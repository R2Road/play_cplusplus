#include "r2_Random.h"

#include <random>
#include <algorithm>

namespace r2
{
	std::mt19937& GetRandomEngine()
	{
		static std::random_device random_device;
		static std::mt19937 random_engine( random_device() );

		return random_engine;
	}



	char Random::GetChar( const char min, const char max )
	{
		std::uniform_int_distribution<> dist( std::min( min, max ), std::max( min, max ) );
		return static_cast<char>( dist( GetRandomEngine() ) );
	}



	int Random::GetInt( const int min, const int max )
	{
		std::uniform_int_distribution<> dist( std::min( min, max ), std::max( min, max ) );
		return dist( GetRandomEngine() );
	}
	int Random::GetInt_0To1()
	{
		return GetInt( 0, 1 );
	}
	int Random::GetInt_0To100()
	{
		return GetInt( 0, 100 );
	}



	unsigned int Random::GetUInt( const unsigned int min, const unsigned int max )
	{
		std::uniform_int_distribution<> dist( std::min( min, max ), std::max( min, max ) );
		return static_cast<unsigned int>( dist( GetRandomEngine() ) );
	}



	float Random::GetFloat( const float min, const float max )
	{
		std::uniform_real_distribution<> dist( std::min( min, max ), std::max( min, max ) );
		return static_cast<float>( dist( GetRandomEngine() ) );
	}
	float Random::GetFloat_0To100()
	{
		return GetFloat( 0.f, 100.f );
	}



	bool Random::GetBool()
	{
		return 0 == GetInt_0To1();
	}
}

