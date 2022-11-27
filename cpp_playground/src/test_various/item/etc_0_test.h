#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace etc_test
{
	class ShowBinary : public r2cm::iItem, public r2cm::SingleTon<ShowBinary>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class LifeTimeTest : public r2cm::iItem, public r2cm::SingleTon<LifeTimeTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}