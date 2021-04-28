#include "pch.h"
#include "r2_game_test_TestFrameBuffer.h"

#include <functional>
#include <optional>

#include "r2_eTestResult.h"

namespace r2_game_test
{
	TestFrameBuffer::TestFrameBuffer() : mFrameBuffer( 10, 10 ) {}

	const r2::iNode::TitleFunc TestFrameBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Game Test : Frame Buffer";
		};
	}
	const r2::iNode::DoFunc TestFrameBuffer::GetDoFunction() const
	{
		const auto& fb = GetInstance().mFrameBuffer;

		return [fb]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			fb.Draw();

			return r2::eTestResult::RunTest;
		};
	}
}