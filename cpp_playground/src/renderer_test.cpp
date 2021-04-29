#include "pch.h"
#include "renderer_test.h"

#include <functional>
#include <optional>

#include "r2_eTestResult.h"

namespace renderer_test
{
	TestFrameBuffer::TestFrameBuffer() : mFrameBuffer( 10, 10 ) {}

	const r2::iTest::TitleFunc TestFrameBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Renderer : Frame Buffer";
		};
	}
	const r2::iTest::DoFunc TestFrameBuffer::GetDoFunction() const
	{
		const auto& fb = GetInstance().mFrameBuffer;

		return [fb]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			fb.Draw();

			return r2::eTestResult::RunTest;
		};
	}



	TestRenderer::TestRenderer() {}

	const r2::iTest::TitleFunc TestRenderer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Renderer( In Progress )";
		};
	}
	const r2::iTest::DoFunc TestRenderer::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}