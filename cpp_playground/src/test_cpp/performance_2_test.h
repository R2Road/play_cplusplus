#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace performance_2_test
{
	class BuiltInArrayIteration : public r2::iTest, public r2::SingleTon<BuiltInArrayIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class STDArrayIteration : public r2::iTest, public r2::SingleTon<STDArrayIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class VectorIteration: public r2::iTest, public r2::SingleTon<VectorIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class ListIteration : public r2::iTest, public r2::SingleTon<ListIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class MapIteration : public r2::iTest, public r2::SingleTon<MapIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class UnorderedMapIteration : public r2::iTest, public r2::SingleTon<UnorderedMapIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class SetIteration : public r2::iTest, public r2::SingleTon<SetIteration>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}