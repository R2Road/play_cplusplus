#include <stdint.h>
#include "r2cm/r2cm_ostream.h"

namespace template_specialization_test
{
	template<typename T>
	void TemplateFunc( const T value )
	{
		std::cout << "T Call : " << value << r2cm::linefeed;
	}

	template<>
	void TemplateFunc( const uint8_t value )
	{
		std::cout << "unsigned char Call : " << value << r2cm::linefeed;
	}
}