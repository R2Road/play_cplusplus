#include <stdint.h>
#include "r2tm/r2tm_ostream.h"

namespace template_specialization_test
{
	template<typename T>
	void TemplateFunc( const T value )
	{
		std::cout << "T Call : " << value << r2tm::linefeed;
	}

	template<>
	void TemplateFunc( const uint8_t value )
	{
		std::cout << "uint8_t Call : " << value << r2tm::linefeed;
	}

	template<>
	void TemplateFunc( const int64_t value )
	{
		std::cout << "int64_t Call : " << value << r2tm::linefeed;
	}
}