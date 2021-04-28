#include "pch.h"
#include "r2_game_PathFinder.h"

#include <functional>
#include <optional>

#include "r2_eTestResult.h"

namespace r2_game
{
	PathFinder::PathFinder() : mFrameBuffer( 10, 10 ) {}

	const r2::iTest::TitleFunc PathFinder::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Path Finder( In Progress )";
		};
	}
	const r2::iTest::DoFunc PathFinder::GetDoFunction() const
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