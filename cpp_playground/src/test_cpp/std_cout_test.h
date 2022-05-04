#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace std_cout_test
{
	class Align : public r2cm::iItem, public r2::SingleTon<Align>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class FMTStatus : public r2cm::iItem, public r2::SingleTon<FMTStatus>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class NumberFormat : public r2cm::iItem, public r2::SingleTon<NumberFormat>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}