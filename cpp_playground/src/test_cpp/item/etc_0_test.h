#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace etc_test
{
	class XOR_Swap : public r2cm::iItem, public r2::SingleTon<XOR_Swap>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class InitArray : public r2cm::iItem, public r2::SingleTon<InitArray>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Macro2String : public r2cm::iItem, public r2::SingleTon<Macro2String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Pointer2Index : public r2cm::iItem, public r2::SingleTon<Pointer2Index>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}