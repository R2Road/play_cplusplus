#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace array_based_list_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PushFront : public r2::iItem, public r2::SingleTon<PushFront>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class IteratorOperator_Indirection_StructureDereference : public r2::iItem, public r2::SingleTon<IteratorOperator_Indirection_StructureDereference>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class EndIterator : public r2::iItem, public r2::SingleTon<EndIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class BeginIterator : public r2::iItem, public r2::SingleTon<BeginIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Clear : public r2::iItem, public r2::SingleTon<Clear>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PushBack : public r2::iItem, public r2::SingleTon<PushBack>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Erase : public r2::iItem, public r2::SingleTon<Erase>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class RBegin_REnd : public r2::iItem, public r2::SingleTon<RBegin_REnd>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}