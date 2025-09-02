namespace play_cpp_enum_helper___xmacro_2
{

	enum eXM2
	{
#define X( e ) e,
		#include "play_cpp_enum_helper___xmacro_2.def"
#undef X
	};

	const char* STR_XM2[] = {
#define X( e ) #e,
		#include "play_cpp_enum_helper___xmacro_2.def"
#undef X
	};

}