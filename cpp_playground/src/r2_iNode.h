#pragma once

#include <functional>

#include "r2_eTestResult.h"

namespace r2
{
	class iNode
	{
	public:
		using TitleFunc = std::function<const char*()>;
		using DoFunc = std::function<const eTestResult()>;

		virtual ~iNode() {}

		virtual const TitleFunc GetTitleFunction() const = 0;
		virtual const DoFunc GetDoFunction() const = 0;
	};
}