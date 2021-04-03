#include "r2_Director.h"

#include "r2_Scene.h"

namespace r2
{
	Director::Director() : mScene()
	{}

	bool Director::Update()
	{
		mScene->Do();

		return true;
	}
}