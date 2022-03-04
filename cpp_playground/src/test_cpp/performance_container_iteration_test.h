#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace performance_container_iteration_test
{
	class BuiltInArrayIteration : public r2::iItem, public r2::SingleTon<BuiltInArrayIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class STDArrayIteration : public r2::iItem, public r2::SingleTon<STDArrayIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class VectorIteration: public r2::iItem, public r2::SingleTon<VectorIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class ListIteration : public r2::iItem, public r2::SingleTon<ListIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MapIteration : public r2::iItem, public r2::SingleTon<MapIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class UnorderedMapIteration : public r2::iItem, public r2::SingleTon<UnorderedMapIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SetIteration : public r2::iItem, public r2::SingleTon<SetIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class UnorderedSetIteration : public r2::iItem, public r2::SingleTon<UnorderedSetIteration>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};


	class STDArrayIteration_WithPointer : public r2::iItem, public r2::SingleTon<STDArrayIteration_WithPointer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}