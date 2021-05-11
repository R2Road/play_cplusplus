#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

#include "r2_VisibleResource.h"
#include "r2_Renderer.h"

namespace renderer_test
{
	class VisibleResource_FillAll : public r2::iTest, public r2::SingleTon<VisibleResource_FillAll>
	{
	public:
		VisibleResource_FillAll();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::VisibleResource mVisibleResource;
	};

	class VisibleResource_Fill : public r2::iTest, public r2::SingleTon<VisibleResource_Fill>
	{
	public:
		VisibleResource_Fill();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::VisibleResource mVisibleResource;
	};

	class VisibleResource_DrawWithPosition : public r2::iTest, public r2::SingleTon<VisibleResource_DrawWithPosition>
	{
	public:
		VisibleResource_DrawWithPosition();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::VisibleResource mVisibleResource;
	};

	class VisibleResource_InitWithChars : public r2::iTest, public r2::SingleTon<VisibleResource_InitWithChars>
	{
	public:
		VisibleResource_InitWithChars();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::VisibleResource mVisibleResource1;
		r2::VisibleResource mVisibleResource2;
	};



	class TestRenderable : public r2::iTest, public r2::SingleTon<TestRenderable>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
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



	class TestCamera : public r2::iTest, public r2::SingleTon<TestCamera>
	{
	public:
		TestCamera();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::Renderer mRenderer;
	};
}