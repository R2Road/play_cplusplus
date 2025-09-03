#pragma once

#include "r2tm/r2tm_interface_item.hpp"

namespace play_std_function_2
{
	class Equality_STDBind_1 : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}