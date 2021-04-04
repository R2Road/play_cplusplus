#pragma once

#include "r2_iNode.h"

namespace const_pointer_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "Const Pointer : Basic"; }
		void Do() override;
	};
}