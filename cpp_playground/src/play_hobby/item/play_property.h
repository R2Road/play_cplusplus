#pragma once

#include "r2cm/r2cm_iItem.h"

namespace play_property
{
	class Functor : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}