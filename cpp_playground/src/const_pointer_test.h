#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace const_pointer_test
{
	class Basic : public r2::iNode, public r2::SingleTon<Basic>
	{
	public:
		const char* GetTitle() const override { return "Const Pointer : Basic"; }
		void Do() override;
	};
}