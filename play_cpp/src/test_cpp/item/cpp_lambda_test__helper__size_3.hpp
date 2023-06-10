#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace cpp_lambda_test__helper__size_3
{
	struct S
	{
		int i = 0;
		void Do() {

			OUTPUT_BINARY( this );

			LF();

			auto l = [this, j = 255ll]() { ( this->i ); };
			OUTPUT_VALUE( sizeof( l ) );
			OUTPUT_BINARY( l );
		}
	};
}