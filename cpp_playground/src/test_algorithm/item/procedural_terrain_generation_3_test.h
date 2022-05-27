#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace procedural_terrain_generation_3_test
{
	class Weights : public r2cm::iItem, public r2cm::SingleTon<Weights>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}