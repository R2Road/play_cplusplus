#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace pointer_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class ConstPointer : public r2::iItem, public r2::SingleTon<ConstPointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}