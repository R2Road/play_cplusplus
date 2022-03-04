#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace console_test
{
	class FontInfo : public r2::iItem, public r2::SingleTon<FontInfo>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class FontChange : public r2::iItem, public r2::SingleTon<FontChange>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Pixel : public r2::iItem, public r2::SingleTon<Pixel>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}