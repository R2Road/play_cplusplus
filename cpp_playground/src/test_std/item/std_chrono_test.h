#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_chrono_test
{
	class Epoch : public r2cm::iItem, public r2cm::SingleTon<Epoch>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class SystemClock : public r2cm::iItem, public r2cm::SingleTon<SystemClock>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class SteadyClock : public r2cm::iItem, public r2cm::SingleTon<SteadyClock>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Demo : public r2cm::iItem, public r2cm::SingleTon<Demo>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}