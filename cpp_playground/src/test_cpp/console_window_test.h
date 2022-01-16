#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_window_test
{
	class BufferInfo : public r2::iTest, public r2::SingleTon<BufferInfo>
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

	class HideTitleBar : public r2::iTest, public r2::SingleTon<HideTitleBar>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class HideScrollBar : public r2::iTest, public r2::SingleTon<HideScrollBar>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class LockWindowResizingByDragging : public r2::iTest, public r2::SingleTon<LockWindowResizingByDragging>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}