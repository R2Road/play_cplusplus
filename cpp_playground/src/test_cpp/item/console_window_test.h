#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace console_window_test
{
	class BufferInfo : public r2cm::iItem, public r2::SingleTon<BufferInfo>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ChangeWindowSize : public r2cm::iItem, public r2::SingleTon<ChangeWindowSize>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class FullScreen : public r2cm::iItem, public r2::SingleTon<FullScreen>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowPosition : public r2cm::iItem, public r2::SingleTon<WindowPosition>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ChangeWindowName : public r2cm::iItem, public r2::SingleTon<ChangeWindowName>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class HideTitleBar : public r2cm::iItem, public r2::SingleTon<HideTitleBar>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class HideScrollBar : public r2cm::iItem, public r2::SingleTon<HideScrollBar>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class LockWindowResizingByDragging : public r2cm::iItem, public r2::SingleTon<LockWindowResizingByDragging>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MenuItem : public r2cm::iItem, public r2::SingleTon<MenuItem>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class CursorMove : public r2cm::iItem, public r2::SingleTon<CursorMove>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CursorVisibility : public r2cm::iItem, public r2::SingleTon<CursorVisibility>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}