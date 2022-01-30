#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace std_memory_test
{
	class SharedPointer : public r2::iTest, public r2::SingleTon<SharedPointer>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class UniquePointer : public r2::iTest, public r2::SingleTon<UniquePointer>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}