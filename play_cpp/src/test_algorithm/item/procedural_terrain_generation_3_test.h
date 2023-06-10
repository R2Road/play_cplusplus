#pragma once

#include "r2tm/r2tm_iItem.h"

namespace procedural_terrain_generation_3_test
{
	class Weights : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}