#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace std_vector_test
{
	class Resize : public r2cm::iItem, public r2cm::SingleTon<Resize>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Resize_And_Memory : public r2cm::iItem, public r2cm::SingleTon<Resize_And_Memory>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Clear : public r2cm::iItem, public r2cm::SingleTon<Clear>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class Reserve : public r2cm::iItem, public r2cm::SingleTon<Reserve>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class NoneDefaultConstructor : public r2cm::iItem, public r2cm::SingleTon<NoneDefaultConstructor>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class BoolVector : public r2cm::iItem, public r2cm::SingleTon<BoolVector>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class OthersIterator : public r2cm::iItem, public r2cm::SingleTon<OthersIterator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class EndIterator : public r2cm::iItem, public r2cm::SingleTon<EndIterator>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}