#include <stdint.h>
#include "r2cm/r2cm_ostream.h"

namespace template_practice_test_02_helper_return_value
{
	template<typename ReturnValueT>
	ReturnValueT R_()
	{
		return ReturnValueT();
	}

	template<typename ReturnValueT>
	ReturnValueT R_R1( ReturnValueT a1 )
	{
		return ReturnValueT( a1 );
	}

	template<typename ReturnValueT, typename ArgumentT1>
	ReturnValueT R_A1( ArgumentT1 a1 )
	{
		return ReturnValueT( a1 );
	}
}