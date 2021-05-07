#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

#include "r2_FrameBuffer.h"
#include "r2_Renderer.h"

namespace renderer_test
{
	class TestFrameBuffer1 : public r2::iTest, public r2::SingleTon<TestFrameBuffer1>
	{
	public:
		TestFrameBuffer1();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};



	class TestFrameBuffer2 : public r2::iTest, public r2::SingleTon<TestFrameBuffer2>
	{
	public:
		TestFrameBuffer2();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};



	class TestRenderer : public r2::iTest, public r2::SingleTon<TestRenderer>
	{
	public:
		class TestRenderable : r2::Renderable
		{
			void Draw() override;
		};

		TestRenderer();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::Renderer mRenderer;
	};
}