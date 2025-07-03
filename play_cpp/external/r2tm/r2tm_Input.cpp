#include "r2tm_Input.h"

#include <conio.h>

namespace r2tm
{
	void WaitAnyKey()
	{
#pragma warning( push )
#pragma warning( disable : 6031 )
		_getch();
#pragma warning( pop )
	}

	int GetKey()
	{
		return _getch();
	}

	int KeyboardHit()
	{
		return _kbhit();
	}
}