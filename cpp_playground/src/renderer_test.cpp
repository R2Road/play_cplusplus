#include "pch.h"
#include "renderer_test.h"

#include <functional>
#include <optional>

#include "r2_eTestResult.h"

namespace renderer_test
{
	TestFrameBuffer::TestFrameBuffer() : mFrameBuffer( 30, 20 ) {}

	const r2::iTest::TitleFunc TestFrameBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Frame Buffer";
		};
	}
	const r2::iTest::DoFunc TestFrameBuffer::GetDoFunction() const
	{
		GetInstance().mFrameBuffer.Fill( 0, 0, '0' );
		GetInstance().mFrameBuffer.Fill( GetInstance().mFrameBuffer.GetWidth() - 1u, 0, '0' );
		GetInstance().mFrameBuffer.Fill( GetInstance().mFrameBuffer.GetWidth() - 1u, GetInstance().mFrameBuffer.GetHeight() - 1u, '0' );
		GetInstance().mFrameBuffer.Fill( 0, GetInstance().mFrameBuffer.GetHeight() - 1u, '0' );

		const auto& fb = GetInstance().mFrameBuffer;

		return [fb]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			fb.Draw();

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	void TestRenderer::TestRenderable::Draw()
	{

	}
	TestRenderer::TestRenderer() : mRenderer() {}

	const r2::iTest::TitleFunc TestRenderer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Renderer( In Progress )";
		};
	}
	const r2::iTest::DoFunc TestRenderer::GetDoFunction() const
	{
		auto& rd = GetInstance().mRenderer;

		return [&rd]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			rd.Draw();

			return r2::eTestResult::RunTest;
		};
	}
}