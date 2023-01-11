#pragma once

#include "r2cm/r2cm_iItem.h"

namespace list_based_on_array_play
{
	class Basic : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class PushFront : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class IteratorOperator_Indirection_StructureDereference : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class EndIterator : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class BeginIterator : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class Clear : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class PushBack : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class Erase : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class RBegin_REnd : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}