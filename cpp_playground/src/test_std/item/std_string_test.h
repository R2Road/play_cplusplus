#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_string_test
{
	class Find : public r2cm::iItem, public r2cm::SingleTon<Find>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Find_And_Split : public r2cm::iItem, public r2cm::SingleTon<Find_And_Split>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Line_Count : public r2cm::iItem, public r2cm::SingleTon<Line_Count>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}