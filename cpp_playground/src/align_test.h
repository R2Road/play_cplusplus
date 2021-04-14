#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace align_test
{
	class AlignAs : public r2::iNode, public r2::SingleTon<AlignAs>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class Align_0 : public r2::iNode, public r2::SingleTon<Align_0>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class Align_1 : public r2::iNode, public r2::SingleTon<Align_1>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class Align_2 : public r2::iNode, public r2::SingleTon<Align_2>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}