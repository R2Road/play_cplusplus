#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace array_based_list_test
{
	class Basic : public r2cm::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PushFront : public r2cm::iItem, public r2::SingleTon<PushFront>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class IteratorOperator_Indirection_StructureDereference : public r2cm::iItem, public r2::SingleTon<IteratorOperator_Indirection_StructureDereference>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class EndIterator : public r2cm::iItem, public r2::SingleTon<EndIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class BeginIterator : public r2cm::iItem, public r2::SingleTon<BeginIterator>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Clear : public r2cm::iItem, public r2::SingleTon<Clear>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PushBack : public r2cm::iItem, public r2::SingleTon<PushBack>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Erase : public r2cm::iItem, public r2::SingleTon<Erase>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class RBegin_REnd : public r2cm::iItem, public r2::SingleTon<RBegin_REnd>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}