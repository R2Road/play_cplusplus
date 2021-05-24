#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

#include "r2_Renderer.h"
#include "r2_VisibleResource.h"

namespace visibleresource_test
{
	class FillAll : public r2::iTest, public r2::SingleTon<FillAll>
	{
	public:
		FillAll();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::VisibleResource mVisibleResource;
	};

	class Fill : public r2::iTest, public r2::SingleTon<Fill>
	{
	public:
		Fill();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::VisibleResource mVisibleResource;
	};

	class DrawWithPosition : public r2::iTest, public r2::SingleTon<DrawWithPosition>
	{
	public:
		DrawWithPosition();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::VisibleResource mVisibleResource;
	};

	class InitWithChars : public r2::iTest, public r2::SingleTon<InitWithChars>
	{
	public:
		InitWithChars();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::VisibleResource mVisibleResource1;
		r2::VisibleResource mVisibleResource2;
	};

	class VisibleRect : public r2::iTest, public r2::SingleTon<VisibleRect>
	{
	public:
		VisibleRect();

	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;

	private:
		r2::VisibleResource mVisibleResource;
	};
}