#pragma once

namespace r2
{
	class Random
	{
	public:
		static char GetChar( const char min, const char max );


		static int GetInt( const int min, const int max );
		static int GetInt_0To1();
		static int GetInt_0To100();



		static unsigned int GetUInt( const unsigned int min, const unsigned int max );



		static float GetFloat( const float min, const float max );
		static float GetFloat_0To100();



		static bool GetBool();
	};
}

