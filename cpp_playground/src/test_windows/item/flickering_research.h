#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace flickering_research
{
	class OneByOne : public r2cm::iItem, public r2cm::SingleTon<OneByOne>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class OneByOne_WithOut_CLS : public r2cm::iItem, public r2cm::SingleTon<OneByOne_WithOut_CLS>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class LineByLine : public r2cm::iItem, public r2cm::SingleTon<LineByLine>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class PageByPage : public r2cm::iItem, public r2cm::SingleTon<PageByPage>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class PageByPage_WithOut_CLS_1 : public r2cm::iItem, public r2cm::SingleTon<PageByPage_WithOut_CLS_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class PageByPage_WithOut_CLS_2 : public r2cm::iItem, public r2cm::SingleTon<PageByPage_WithOut_CLS_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}