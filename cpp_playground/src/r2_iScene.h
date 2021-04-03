#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class iScene>;

	class iScene
	{
	public:
		virtual int Do() = 0;
	};
}