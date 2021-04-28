#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

namespace pointer_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class ConstPointer : public r2::iTest, public r2::SingleTon<ConstPointer>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}