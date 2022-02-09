#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace array_based_list_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PushFront : public r2::iTest, public r2::SingleTon<PushFront>
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

	class EndIterator : public r2::iTest, public r2::SingleTon<EndIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class BeginIterator : public r2::iTest, public r2::SingleTon<BeginIterator>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Clear : public r2::iTest, public r2::SingleTon<Clear>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PushBack : public r2::iTest, public r2::SingleTon<PushBack>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Erase_1 : public r2::iTest, public r2::SingleTon<Erase_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Erase_2 : public r2::iTest, public r2::SingleTon<Erase_2>
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