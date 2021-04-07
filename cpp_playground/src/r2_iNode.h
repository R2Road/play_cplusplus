#pragma once

#include <functional>

namespace r2
{
	enum class eTestResult;

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