#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace console_text_color_test
{
	class ColorTable : public r2::iTest, public r2::SingleTon<ColorTable>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class TextColor1 : public r2::iTest, public r2::SingleTon<TextColor1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class TextColor2 : public r2::iTest, public r2::SingleTon<TextColor2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class AdjustColorTable : public r2::iTest, public r2::SingleTon<AdjustColorTable>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class ColorTable2 : public r2::iTest, public r2::SingleTon<ColorTable2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class TextColor3 : public r2::iTest, public r2::SingleTon<TextColor3>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}