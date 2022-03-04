#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace align_test
{
	class Align_0 : public r2::iItem, public r2::SingleTon<Align_0>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Align_1 : public r2::iItem, public r2::SingleTon<Align_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Align_2 : public r2::iItem, public r2::SingleTon<Align_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}