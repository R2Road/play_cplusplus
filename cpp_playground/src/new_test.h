#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace new_test
{
	class Basic : public r2::iNode, public r2::SingleTon<Basic>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};

	class PlacementNew : public r2::iNode, public r2::SingleTon<PlacementNew>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}