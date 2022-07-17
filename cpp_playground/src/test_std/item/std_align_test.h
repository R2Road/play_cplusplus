#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace align_test
{
	class Basic : public r2cm::iItem, public r2cm::SingleTon<Basic>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Bound : public r2cm::iItem, public r2cm::SingleTon<Bound>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Play : public r2cm::iItem, public r2cm::SingleTon<Play>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}