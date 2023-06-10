#pragma once

#include "r2tm/r2tm_iItem.h"

namespace procedural_terrain_generation_2_test
{
	class Bone : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}