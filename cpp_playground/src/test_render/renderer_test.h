#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

#include "renderer/r2_Renderer.h"
#include "renderer/r2_VisibleResource.h"

namespace renderer_test
{
	class TestRenderable : public r2::iTest, public r2::SingleTon<TestRenderable>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};



	class TestRenderer : public r2::iTest, public r2::SingleTon<TestRenderer>
	{
	public:
		TestRenderer();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::Renderer mRenderer;
	};
}