#pragma once

#include "r2_iNode.h"

namespace tuple_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "Tuple : Basic"; }
		void Do() override;
	};
}