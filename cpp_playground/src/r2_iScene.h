#pragma once

#include <memory>

namespace r2
{
	using SceneUp = std::unique_ptr<class iScene>;

	class iScene
	{
	public:
		virtual ~iScene() {}

		virtual void ShowMenu() = 0;
		virtual int Do( const int key_code ) = 0;
	};
}