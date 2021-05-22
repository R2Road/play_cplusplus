#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace console_test
{
	class GetWindowSize : public r2::iTest, public r2::SingleTon<GetWindowSize>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class ChangeWindowSize : public r2::iTest, public r2::SingleTon<ChangeWindowSize>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class WindowPosition : public r2::iTest, public r2::SingleTon<WindowPosition>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class ChangeWindowName : public r2::iTest, public r2::SingleTon<ChangeWindowName>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class CursorMove : public r2::iTest, public r2::SingleTon<CursorMove>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
	class CursorVisibility : public r2::iTest, public r2::SingleTon<CursorVisibility>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



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

	class Pixel : public r2::iTest, public r2::SingleTon<Pixel>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}