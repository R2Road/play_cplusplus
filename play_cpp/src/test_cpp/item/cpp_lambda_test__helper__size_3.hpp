#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace cpp_lambda_test__helper__size_3
{
	struct S
	{
		int i = 0;
		void Do() {

			OUTPUT_BINARY( this );

			std::cout << r2cm::linefeed;

			auto l = [this, j = 255ll]() { ( this->i ); };
			OUTPUT_VALUE( sizeof( l ) );
			OUTPUT_BINARY( l );
		}
	};
}