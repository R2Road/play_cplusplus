#pragma once

#include "r2_eTestResult.h"

namespace r2
{
	class iNode
	{
	public:
		virtual ~iNode() {}

		virtual const char* GetTitle() const = 0;
		virtual eTestResult Do() = 0;
	};
}