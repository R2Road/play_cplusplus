#include "pch.h"
#include "r2_game_PathFinder.h"

#include <functional>
#include <optional>

#include "r2_eTestResult.h"

namespace r2_game
{
	const r2::iNode::TitleFunc PathFinder::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Path Finder( In Progress )";
		};
	}
	const r2::iNode::DoFunc PathFinder::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}