#include "template_specialization_test.h"

#include <algorithm>

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

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Specialization : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				TemplateFunc( int( 1 ) );
				TemplateFunc( uint8_t( 1 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}
