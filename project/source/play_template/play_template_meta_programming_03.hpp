#pragma once

#include "r2tm/r2tm_interface_item.hpp"

namespace play_template_meta_programming_01
{
	class MultiTypePackage : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}