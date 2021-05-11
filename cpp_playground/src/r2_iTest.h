#pragma once

#include <functional>

namespace r2
{
	enum class eTestResult;

	class iTest
	{
	public:
		using TitleFunc = std::function<const char*()>;
		using DoFunc = std::function<const eTestResult()>;

		virtual ~iTest() {}

		virtual TitleFunc GetTitleFunction() const = 0;
		virtual DoFunc GetDoFunction() const = 0;
	};
}