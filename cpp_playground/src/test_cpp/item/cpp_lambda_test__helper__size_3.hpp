#include "r2cm/r2cm_Inspector.h"

namespace cpp_lambda_test__helper__size_3
{
	struct S
	{
		int i = 0;
		void Do() {
			auto l = [this]() {};
			OUTPUT_VALUE( sizeof( l ) );
			OUTPUT_VALUE( sizeof( this ) );
		}
	};
}