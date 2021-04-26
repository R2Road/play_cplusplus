#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace console_test
{
	class GetWindowSize : public r2::iNode, public r2::SingleTon<GetWindowSize>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class ChangeWindowSize : public r2::iNode, public r2::SingleTon<ChangeWindowSize>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class ChangeWindowPosition : public r2::iNode, public r2::SingleTon<ChangeWindowPosition>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class ChangeWindowName : public r2::iNode, public r2::SingleTon<ChangeWindowName>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class MoveCursor : public r2::iNode, public r2::SingleTon<MoveCursor>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};



	class ColorTable : public r2::iNode, public r2::SingleTon<ColorTable>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class TextColor1 : public r2::iNode, public r2::SingleTon<TextColor1>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class TextColor2 : public r2::iNode, public r2::SingleTon<TextColor2>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class ColorTable2 : public r2::iNode, public r2::SingleTon<ColorTable2>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class TextColor3 : public r2::iNode, public r2::SingleTon<TextColor3>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
	class TextColor4 : public r2::iNode, public r2::SingleTon<TextColor4>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}