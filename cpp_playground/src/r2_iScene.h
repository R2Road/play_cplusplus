#pragma once

#include <memory>

namespace r2
{
	class Director;

	using SceneUp = std::unique_ptr<class iScene>;

	class iScene
	{
	public:
		iScene( Director* const director ) : mDirector( director ) {}
		virtual ~iScene() {}

		virtual void ShowMenu() = 0;
		virtual bool Do( const int key_code ) = 0;

	private:
		Director* mDirector;
	};
}