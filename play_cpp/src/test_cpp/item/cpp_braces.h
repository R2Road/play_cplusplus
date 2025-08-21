#pragma once

#include "r2tm/r2tm_interface_item.hpp"

namespace cpp_braces
{
	class Braces_PrimitiveType : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}