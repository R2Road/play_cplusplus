#pragma once

#include "r2tm/r2tm_inspector.hpp"

namespace template_basic_test
{
	template<class R, class ... A>
	class ParenthesesHelper;

	template<class R, class ... A>
	class ParenthesesHelper<R( A... )>
	{
	public:
		int i = 0;
	};



	void Do_ParenthesesHelper()
	{
		ParenthesesHelper<int( int )> helper;

		OUTPUT_VALUE( helper.i );
	}
}
