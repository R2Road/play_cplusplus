#pragma once

#include "r2_iNode.h"

namespace shared_pointer_test
{
	class SharedPtr : public r2::iNode<SharedPtr>
	{
	public:
		static const char* GetTitle() { return "Memory : Shared Pointer"; }
		static void Do();
	};
}