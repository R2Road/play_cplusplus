#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_window_etc_test
{
	class FontInfo : public r2cm::iItem, public r2cm::SingleTon<FontInfo>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class FontChange : public r2cm::iItem, public r2cm::SingleTon<FontChange>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Pixel : public r2cm::iItem, public r2cm::SingleTon<Pixel>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}