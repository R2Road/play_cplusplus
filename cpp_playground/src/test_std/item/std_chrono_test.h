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

	class Chrono : public r2cm::iItem, public r2cm::SingleTon<Chrono>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class TimePoint : public r2cm::iItem, public r2cm::SingleTon<TimePoint>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}