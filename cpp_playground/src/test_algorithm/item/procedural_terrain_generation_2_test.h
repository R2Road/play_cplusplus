#pragma once

#include "r2cm/r2cm_iItem.h"

namespace procedural_terrain_generation_2_test
{
	class Bone : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}