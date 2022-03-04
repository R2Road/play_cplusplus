#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace std_vector_test
{
	class Basic : public r2::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class NoneDefaultConstructor : public r2::iItem, public r2::SingleTon<NoneDefaultConstructor>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class BoolVector : public r2::iItem, public r2::SingleTon<BoolVector>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class OthersIterator : public r2::iItem, public r2::SingleTon<OthersIterator>
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
}