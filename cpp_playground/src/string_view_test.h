#pragma once

#include "r2_iNode.h"

namespace stringview_test
{
	class Basic : public r2::iNode<Basic>
	{
	public:
		const char* GetTitle() const override { return "StringView : Basic"; }
		void Do() override;
	};
}