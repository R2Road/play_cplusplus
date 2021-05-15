#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

#include "r2_Camera.h"
#include "r2_Renderer.h"

namespace renderer_test
{
	class CameraRect : public r2::iTest, public r2::SingleTon<CameraRect>
	{
	public:
		CameraRect();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::Camera mCamera;
	};

	class TestCamera : public r2::iTest, public r2::SingleTon<TestCamera>
	{
	public:
		TestCamera();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::Camera mCamera;
		r2::Renderer mRenderer;
	};
}