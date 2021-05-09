#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

#include "r2_FrameBuffer.h"
#include "r2_Renderer.h"

namespace renderer_test
{
	class FrameBuffer_FillAll : public r2::iTest, public r2::SingleTon<FrameBuffer_FillAll>
	{
	public:
		FrameBuffer_FillAll();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};
	class FrameBuffer_Fill : public r2::iTest, public r2::SingleTon<FrameBuffer_Fill>
	{
	public:
		FrameBuffer_Fill();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};
	class FrameBuffer_DrawWithPosition : public r2::iTest, public r2::SingleTon<FrameBuffer_DrawWithPosition>
	{
	public:
		FrameBuffer_DrawWithPosition();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};
	class FrameBuffer_InitWithChars : public r2::iTest, public r2::SingleTon<FrameBuffer_InitWithChars>
	{
	public:
		FrameBuffer_InitWithChars();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};



	class TestRenderer : public r2::iTest, public r2::SingleTon<TestRenderer>
	{
	public:
		TestRenderer();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::Renderer mRenderer;
	};
}