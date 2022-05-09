#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_text_color_test
{
	class ColorTable : public r2cm::iItem, public r2cm::SingleTon<ColorTable>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class TextColor1 : public r2cm::iItem, public r2cm::SingleTon<TextColor1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class TextColor2 : public r2cm::iItem, public r2cm::SingleTon<TextColor2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class AdjustColorTable : public r2cm::iItem, public r2cm::SingleTon<AdjustColorTable>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ColorTable2 : public r2cm::iItem, public r2cm::SingleTon<ColorTable2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class TextColor3 : public r2cm::iItem, public r2cm::SingleTon<TextColor3>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}