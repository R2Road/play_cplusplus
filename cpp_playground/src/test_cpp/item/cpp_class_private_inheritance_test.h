#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace cpp_class_private_inheritance_test
{
	class PureVirtualInterface : public r2cm::iItem, public r2cm::SingleTon<PureVirtualInterface>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class PrivateInheritance_1 : public r2cm::iItem, public r2cm::SingleTon<PrivateInheritance_1>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class PrivateInheritance_2 : public r2cm::iItem, public r2cm::SingleTon<PrivateInheritance_2>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
	class PrivateInheritance_iEnum : public r2cm::iItem, public r2cm::SingleTon<PrivateInheritance_iEnum>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class NoneVirtualInterface : public r2cm::iItem, public r2cm::SingleTon<NoneVirtualInterface>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}