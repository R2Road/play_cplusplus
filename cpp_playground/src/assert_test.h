#pragma once

#include "r2_iNode.h"

namespace assert_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "Assert : Basic"; }
		void Do() override;
	};
}