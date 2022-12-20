#pragma once

#include "r2cm/r2cm_iItem.h"

namespace hobby_fsm_v1_play
{
	class Package_Declaration : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class Package_Add : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}