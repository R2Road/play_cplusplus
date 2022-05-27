#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace procedural_terrain_generation_2_test
{
	class Bone : public r2cm::iItem, public r2cm::SingleTon<Bone>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}