#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace tuple_test
{
	class Basic : public r2::iNode, public r2::SingleTon<Basic>
	{
	public:
		const char* GetTitle() const override { return "Tuple : Basic"; }
		void Do() override;
	};
}