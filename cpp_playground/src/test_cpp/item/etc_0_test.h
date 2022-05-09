#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace etc_test
{
	class XOR_Swap : public r2cm::iItem, public r2cm::SingleTon<XOR_Swap>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class InitArray : public r2cm::iItem, public r2cm::SingleTon<InitArray>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Macro2String : public r2cm::iItem, public r2cm::SingleTon<Macro2String>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Pointer2Index : public r2cm::iItem, public r2cm::SingleTon<Pointer2Index>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}