#pragma once

#include <memory>

#include "r2_eTestResult.h"

namespace r2
{
	class Director;

	using SceneUp = std::unique_ptr<class iScene>;

	class iScene
	{
	public:
		iScene( Director& director ) : mDirector( director ) {}
		virtual ~iScene() {}

		virtual void ShowTitle() const = 0;
		virtual void ShowMenu() const = 0;
		virtual eTestResult Do( const int key_code ) = 0;

	protected:
		Director& mDirector;
	};
}