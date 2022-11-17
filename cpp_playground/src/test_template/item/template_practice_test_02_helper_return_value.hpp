#include <stdint.h>
#include "r2cm/r2cm_ostream.h"

namespace template_practice_test_02_return_value
{
	template<typename ReturnValueT>
	ReturnValueT ReturnValueTestFunction()
	{
		return ReturnValueT();
	}
}