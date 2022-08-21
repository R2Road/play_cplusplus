#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_window_test
{
	class BufferInfo : public r2cm::iItem, public r2cm::SingleTon<BufferInfo>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ChangeWindowSize : public r2cm::iItem, public r2cm::SingleTon<ChangeWindowSize>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class FullScreen : public r2cm::iItem, public r2cm::SingleTon<FullScreen>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class Focus : public r2cm::iItem, public r2cm::SingleTon<Focus>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class WindowPosition : public r2cm::iItem, public r2cm::SingleTon<WindowPosition>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ChangeWindowName : public r2cm::iItem, public r2cm::SingleTon<ChangeWindowName>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class HideTitleBar : public r2cm::iItem, public r2cm::SingleTon<HideTitleBar>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class HideScrollBar : public r2cm::iItem, public r2cm::SingleTon<HideScrollBar>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class DisableMaximize : public r2cm::iItem, public r2cm::SingleTon<DisableMaximize>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class LockWindowResizingByDragging : public r2cm::iItem, public r2cm::SingleTon<LockWindowResizingByDragging>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MenuItem : public r2cm::iItem, public r2cm::SingleTon<MenuItem>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};



	class CursorMove : public r2cm::iItem, public r2cm::SingleTon<CursorMove>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class CursorVisibility : public r2cm::iItem, public r2cm::SingleTon<CursorVisibility>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class QuickEdit : public r2cm::iItem, public r2cm::SingleTon<QuickEdit>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}