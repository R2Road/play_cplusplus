#pragma once

#include "r2_iNode.h"

namespace variant_test
{
	class Basic : public r2::iNode<Basic>
	{
	private:
		Basic() = delete;

	public:
		static const char* GetTitle() { return "Variant : Basic"; }
		static void Do();
	};
}