#pragma once

#include "r2_iNode.h"

namespace variant_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "Variant : Basic"; }
		void Do() override;
	};
}