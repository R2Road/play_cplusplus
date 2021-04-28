#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

#include "r2_game_FrameBuffer.h"

namespace r2_game_test
{
	class TestFrameBuffer : public r2::iNode, public r2::SingleTon<TestFrameBuffer>
	{
	public:
		TestFrameBuffer();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2_game::FrameBuffer mFrameBuffer;
	};
}