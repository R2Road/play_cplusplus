#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace align_test
{
	class Align_0 : public r2cm::iItem, public r2::SingleTon<Align_0>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Align_1 : public r2cm::iItem, public r2::SingleTon<Align_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Align_2 : public r2cm::iItem, public r2::SingleTon<Align_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}