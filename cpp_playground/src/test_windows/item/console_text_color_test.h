#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_text_color_test
{
	class ColorTable : public r2cm::iItem, public r2cm::SingleTon<ColorTable>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class TextColor1 : public r2cm::iItem, public r2cm::SingleTon<TextColor1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class TextColor2 : public r2cm::iItem, public r2cm::SingleTon<TextColor2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class AdjustColorTable : public r2cm::iItem, public r2cm::SingleTon<AdjustColorTable>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ColorTable2 : public r2cm::iItem, public r2cm::SingleTon<ColorTable2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class TextColor3 : public r2cm::iItem, public r2cm::SingleTon<TextColor3>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}