#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_test
{
	class FontInfo : public r2cm::iItem, public r2cm::SingleTon<FontInfo>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class FontChange : public r2cm::iItem, public r2cm::SingleTon<FontChange>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Pixel : public r2cm::iItem, public r2cm::SingleTon<Pixel>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}