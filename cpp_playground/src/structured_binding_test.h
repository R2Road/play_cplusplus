#pragma once

#include "r2_iNode.h"

namespace structured_binding_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "Structured Binding : Basic"; }
		void Do() override;
	};
}