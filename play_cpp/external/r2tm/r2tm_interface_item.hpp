#pragma once

#include "r2tm_menu_constant.hpp"

namespace r2tm
{
	class iItem
	{
	public:
		virtual ~iItem() {}

		virtual TitleFunctionT GetTitleFunction() const = 0;
		virtual DoFunctionT GetDoFunction() const = 0;
	};
}