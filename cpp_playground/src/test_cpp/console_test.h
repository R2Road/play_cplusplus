#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_test
{
	class FontInfo : public r2::iTest, public r2::SingleTon<FontInfo>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Pixel : public r2::iTest, public r2::SingleTon<Pixel>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}