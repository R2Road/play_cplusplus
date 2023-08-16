namespace enum_test_xmacro_2
{

	enum eTestEnum4XM2
	{
#define X( e ) e,
		#include "enum_test_xmacro_2.def"
#undef X
	};

	const char* STR_TestEnum4XM2[] = {
#define X( e ) #e,
		#include "enum_test_xmacro_2.def"
#undef X
	};

}