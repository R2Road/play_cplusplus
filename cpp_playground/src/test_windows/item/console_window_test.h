#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_window_test
{
	class BufferInfo : public r2cm::iItem, public r2cm::SingleTon<BufferInfo>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ChangeWindowSize : public r2cm::iItem, public r2cm::SingleTon<ChangeWindowSize>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class FullScreen : public r2cm::iItem, public r2cm::SingleTon<FullScreen>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class WindowPosition : public r2cm::iItem, public r2cm::SingleTon<WindowPosition>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ChangeWindowName : public r2cm::iItem, public r2cm::SingleTon<ChangeWindowName>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class HideTitleBar : public r2cm::iItem, public r2cm::SingleTon<HideTitleBar>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class HideScrollBar : public r2cm::iItem, public r2cm::SingleTon<HideScrollBar>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class LockWindowResizingByDragging : public r2cm::iItem, public r2cm::SingleTon<LockWindowResizingByDragging>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MenuItem : public r2cm::iItem, public r2cm::SingleTon<MenuItem>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};



	class CursorMove : public r2cm::iItem, public r2cm::SingleTon<CursorMove>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class CursorVisibility : public r2cm::iItem, public r2cm::SingleTon<CursorVisibility>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}