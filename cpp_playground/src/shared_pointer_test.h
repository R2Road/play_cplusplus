#pragma once

#include "r2_iNode.h"

namespace shared_pointer_test
{
	class SharedPtr : public r2::iNode<SharedPtr>
	{
	public:
		const char* GetTitle() const override { return "Memory : Shared Pointer"; }
		void Do() override;
	};
}