#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace array_based_list_test
{
	class Basic_1 : public r2::iTest, public r2::SingleTon<Basic_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Basic_2 : public r2::iTest, public r2::SingleTon<Basic_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Erase : public r2::iTest, public r2::SingleTon<Erase>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class IteratorOperator_Indirection_StructureDereference : public r2::iTest, public r2::SingleTon<IteratorOperator_Indirection_StructureDereference>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class RBegin_REnd : public r2::iTest, public r2::SingleTon<RBegin_REnd>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}