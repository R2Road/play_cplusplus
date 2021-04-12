#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace align_test
{
	class Basic : public r2::iNode, public r2::SingleTon<Basic>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class MixedStruct : public r2::iNode, public r2::SingleTon<MixedStruct>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class AlignAs : public r2::iNode, public r2::SingleTon<AlignAs>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class Align : public r2::iNode, public r2::SingleTon<Align>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}