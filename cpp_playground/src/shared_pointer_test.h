#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace shared_pointer_test
{
	class SharedPtr : public r2::iNode, public r2::SingleTon<SharedPtr>
	{
	public:
		const char* GetTitle() const override { return "Memory : Shared Pointer"; }
		void Do() override;
	};
}