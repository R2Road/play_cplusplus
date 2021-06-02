#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

#include "renderer/r2_Camera.h"
#include "renderer/r2_Renderer.h"

namespace animation_test
{
	class Basic : public r2::iTest, public r2::SingleTon<Basic>
	{
	public:
		Basic();

		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::Camera mCamera;
		r2::Renderer mRenderer;
	};
}