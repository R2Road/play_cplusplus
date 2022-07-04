#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace performance_container_iteration_test
{
	class BuiltInArrayIteration : public r2cm::iItem, public r2cm::SingleTon<BuiltInArrayIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class STDArrayIteration : public r2cm::iItem, public r2cm::SingleTon<STDArrayIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class VectorIteration: public r2cm::iItem, public r2cm::SingleTon<VectorIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class ListIteration : public r2cm::iItem, public r2cm::SingleTon<ListIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MapIteration : public r2cm::iItem, public r2cm::SingleTon<MapIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class UnorderedMapIteration : public r2cm::iItem, public r2cm::SingleTon<UnorderedMapIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class SetIteration : public r2cm::iItem, public r2cm::SingleTon<SetIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class UnorderedSetIteration : public r2cm::iItem, public r2cm::SingleTon<UnorderedSetIteration>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};


	class STDArrayIteration_WithPointer : public r2cm::iItem, public r2cm::SingleTon<STDArrayIteration_WithPointer>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}