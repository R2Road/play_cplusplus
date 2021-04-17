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
}