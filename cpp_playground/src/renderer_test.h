#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

#include "r2_FrameBuffer.h"

namespace renderer_test
{
	class TestFrameBuffer : public r2::iNode, public r2::SingleTon<TestFrameBuffer>
	{
	public:
		TestFrameBuffer();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};
}