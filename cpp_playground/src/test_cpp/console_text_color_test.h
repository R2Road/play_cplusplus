#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace console_text_color_test
{
	class ColorTable : public r2::iItem, public r2::SingleTon<ColorTable>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class TextColor1 : public r2::iItem, public r2::SingleTon<TextColor1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class TextColor2 : public r2::iItem, public r2::SingleTon<TextColor2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class AdjustColorTable : public r2::iItem, public r2::SingleTon<AdjustColorTable>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ColorTable2 : public r2::iItem, public r2::SingleTon<ColorTable2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class TextColor3 : public r2::iItem, public r2::SingleTon<TextColor3>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}