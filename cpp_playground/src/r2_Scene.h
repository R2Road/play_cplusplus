#pragma once

#include "r2_iScene.h"

namespace r2
{
	class Scene : public iScene
	{
	public:
		int Do() override;
	};
}