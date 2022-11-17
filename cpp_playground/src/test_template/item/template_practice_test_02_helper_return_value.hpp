#include <stdint.h>
#include "r2cm/r2cm_ostream.h"

namespace template_practice_test_02_return_value
{
	template<typename ReturnValueT>
	ReturnValueT ReturnValueTestFunction()
	{
		return ReturnValueT();
	}

	template<typename ReturnValueT>
	ReturnValueT ReturnValueTestFunction_With_Argument1( ReturnValueT a1 )
	{
		return ReturnValueT( a1 );
	}
}