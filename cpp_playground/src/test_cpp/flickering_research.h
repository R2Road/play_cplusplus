#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace flickering_research
{
	class OneByOne : public r2cm::iItem, public r2::SingleTon<OneByOne>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
	class OneByOne_WithOut_CLS : public r2cm::iItem, public r2::SingleTon<OneByOne_WithOut_CLS>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class LineByLine : public r2cm::iItem, public r2::SingleTon<LineByLine>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PageByPage : public r2cm::iItem, public r2::SingleTon<PageByPage>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PageByPage_WithOut_CLS_1 : public r2cm::iItem, public r2::SingleTon<PageByPage_WithOut_CLS_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PageByPage_WithOut_CLS_2 : public r2cm::iItem, public r2::SingleTon<PageByPage_WithOut_CLS_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}