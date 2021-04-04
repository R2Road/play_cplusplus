#pragma once

#include "r2_iNode.h"

namespace optional_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "Optional : Basic"; }
		void Do() override;
	};
}