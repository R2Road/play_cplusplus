#pragma once

#include "r2cm/r2cm_iItem.h"

namespace windows_terminal_text_color_test
{
	class ColorTable : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
	class TextColor1 : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
	class TextColor2 : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
	class AdjustColorTable : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class ColorTable2 : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
	class TextColor3 : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}