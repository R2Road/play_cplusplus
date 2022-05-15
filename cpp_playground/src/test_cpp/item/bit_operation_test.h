#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace bit_operation_test
{
	class Add_Remove_Toggle : public r2cm::iItem, public r2cm::SingleTon<Add_Remove_Toggle>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class Mask : public r2cm::iItem, public r2cm::SingleTon<Mask>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class XOR_Swap : public r2cm::iItem, public r2cm::SingleTon<XOR_Swap>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}