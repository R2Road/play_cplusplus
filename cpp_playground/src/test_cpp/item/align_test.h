#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace align_test
{
	class Align_0 : public r2cm::iItem, public r2cm::SingleTon<Align_0>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Align_1 : public r2cm::iItem, public r2cm::SingleTon<Align_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Align_2 : public r2cm::iItem, public r2cm::SingleTon<Align_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}